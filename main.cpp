#include <thread>
#include <chrono>
#include <algorithm>

/* Image Detection */
#include <wiringPi.h>

/* GPIO Control */
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

/* Datasets and Settings */
const auto FRAME_DELAY = std::chrono::milliseconds(50);
const auto ACTIVE_LATCH = std::chrono::seconds(3);
const std::string DATASET_PROTOTXT = "dataset/MobileNetSSD_deploy.prototxt";
const std::string DATASET_CAFFEMODEL = "dataset/MobileNetSSD_deploy.caffemodel";
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
        int camera_id)
        : net(cv::dnn::readNetFromCaffe(prototxt, caffemodel)),
          cap(camera_id)
    {
        net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }

    bool detect(const std::vector<DATASET_OBJECT_LABEL> &labels, const int confidence = 0.5)
    {
        /* Camera Frame Capture*/
        cap >> frame;
        assert(!frame.empty());

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
    cv::Mat frame;
};

int main()
{
    /** @todo this could be optimized to a hashmap for detect(). */
    const std::vector<DATASET_OBJECT_LABEL> TARGET_OBJECT_LABELS = {DATASET_OBJECT_LABEL::person};
    CameraDetector camera_a(DATASET_PROTOTXT, DATASET_CAFFEMODEL, 0);
    CameraDetector camera_b(DATASET_PROTOTXT, DATASET_CAFFEMODEL, 4);

    size_t detection_counter = 0;
    while (true)
    {
        if (camera_a.detect(TARGET_OBJECT_LABELS) || camera_b.detect(TARGET_OBJECT_LABELS))
            std::cout << "detected " << detection_counter++ << std::endl;

        std::this_thread::sleep_for(FRAME_DELAY);
    }

    return 0;
}
