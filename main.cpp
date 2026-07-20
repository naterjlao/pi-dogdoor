/* System Libraries */
#include <thread>
#include <chrono>
#include <algorithm>

/* Image Detection */
#include <wiringPi.h>

/* GPIO Control */
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

/* Datasets and Settings */
const auto FRAME_DELAY                  = std::chrono::milliseconds(50);            /** Frame delay between camera image captures and detection. */
const auto TRIGGER_TIME                 = std::chrono::milliseconds(1000);          /** The amount of time for a target to be in frame for activation. */ 
const auto ACTIVE_LATCH                 = std::chrono::milliseconds(250);           /** The amount of time to latch the output control pin during detection event. */
const int WIRING_PI_PIN_RF_POWER        = 0;                                        /** Raspberry Pi 5 Wiring PI GPIO Pin. */
const std::string DATASET_PROTOTXT      = "dataset/MobileNetSSD_deploy.prototxt";   /** Dataset Proto Txt Model */
const std::string DATASET_CAFFEMODEL    = "dataset/MobileNetSSD_deploy.caffemodel"; /** Dataset Caffe Model */
enum class DATASET_OBJECT_LABEL : size_t
{
    background,
    aeroplane,
    bicycle,
    bird,
    boat,
    bottle,
    bus,
    car,
    cat,
    chair,
    cow,
    diningtable,
    dog,
    horse,
    motorbike,
    person,
    pottedplant,
    sheep,
    sofa,
    train,
    tvmonitor
};

class CameraDetector
{
public:
    CameraDetector(
        const std::string &prototxt,
        const std::string &caffemodel,
        int camera_id,
        bool rotate = false,
        cv::RotateFlags rotation = cv::RotateFlags::ROTATE_90_CLOCKWISE)
        : net(cv::dnn::readNetFromCaffe(prototxt, caffemodel)),
          cap(camera_id),
          rotate(rotate),
          rotation(rotation)
    {
        net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }

    bool detect(const std::vector<DATASET_OBJECT_LABEL> &labels, const int confidence = 0.5)
    {
        /** @todo @p labels could be optimized to a hashmap. */

        /* Camera Frame Capture*/
        cap >> raw;
        assert(!raw.empty());
        if (this->rotate) cv::rotate(raw, frame, this->rotation);

        /* Run Detection Algorithm */
        cv::Mat blob = cv::dnn::blobFromImage(frame, 0.007843, cv::Size(300, 300), cv::Scalar(127.5, 127.5, 127.5), false);
        net.setInput(blob);
        cv::Mat detection = net.forward();

        /* Parse Detection Results */
        bool result = false;
        cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
        for (int i = 0; i < detectionMat.rows; ++i)
        {
            const float DETECTED_OBJECT_CONFIDENCE = detectionMat.at<float>(i, 2);
            if (DETECTED_OBJECT_CONFIDENCE > confidence)
            {
                const size_t DETECTED_OBJECT_INDEX = static_cast<size_t>(detectionMat.at<float>(i, 1));
                /** Return true if any label in @p lables have been detected with confidence. */
                result = result ||
                         (std::count(
                              labels.begin(),
                              labels.end(),
                              static_cast<DATASET_OBJECT_LABEL>(DETECTED_OBJECT_INDEX)) > 0);
            }
        }

        return result;
    }

private:
    cv::dnn::Net net;
    cv::VideoCapture cap;
    cv::Mat raw;
    cv::Mat frame;
    const bool rotate;
    const cv::RotateFlags rotation;
};

int main()
{
    assert(wiringPiSetup() != -1);
    digitalWrite(WIRING_PI_PIN_RF_POWER, LOW);

    /** Defines the target objects for detection. @note This must correspond to the indices in the datasets. */
    const std::vector<DATASET_OBJECT_LABEL> TARGET_OBJECT_LABELS = {DATASET_OBJECT_LABEL::dog};
    CameraDetector camera_a(DATASET_PROTOTXT, DATASET_CAFFEMODEL, 0, true, cv::RotateFlags::ROTATE_90_COUNTERCLOCKWISE);
    CameraDetector camera_b(DATASET_PROTOTXT, DATASET_CAFFEMODEL, 4, true, cv::RotateFlags::ROTATE_90_CLOCKWISE);

    auto trigger = std::chrono::milliseconds(0);
    auto latch = std::chrono::milliseconds(0);
    while (true)
    {
        if (camera_a.detect(TARGET_OBJECT_LABELS) || camera_b.detect(TARGET_OBJECT_LABELS))
        {
            digitalWrite(WIRING_PI_PIN_RF_POWER, HIGH);
            latch = ACTIVE_LATCH;
        }

        std::this_thread::sleep_for(FRAME_DELAY);
        if (latch > std::chrono::milliseconds(0))
        {
            latch = latch - FRAME_DELAY;
            if (latch <= std::chrono::milliseconds(0))
                digitalWrite(WIRING_PI_PIN_RF_POWER, LOW);
        }
    }

    return 0;
}
