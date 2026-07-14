
/* Image Detection */
#include <wiringPi.h>

/* GPIO Control */
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

/* Datasets and Settings */
const std::string DATASET_PROTOTXT = "dataset/MobileNetSSD_deploy.prototxt";
const std::string DATASET_CAFFEMODEL = "dataset/MobileNetSSD_deploy.caffemodel";
enum class DATASET_OBJECT_LABEL
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

    bool detect(const DATASET_OBJECT_LABEL label, const int confidence=0.5)
    {
        cap >> frame;
        assert(!frame.empty());

        cv::Mat blob = cv::dnn::blobFromImage(frame, 0.007843, cv::Size(300, 300), cv::Scalar(127.5, 127.5, 127.5), false);
        net.setInput(blob);
        cv::Mat detection = net.forward();


        return false;
    }

private:
    cv::dnn::Net net;
    cv::VideoCapture cap;
    cv::Mat frame;
};

int main()
{
    CameraDetector camera_a(DATASET_PROTOTXT, DATASET_CAFFEMODEL, 0);

    while (true)
    {
        camera_a.detect(DATASET_OBJECT_LABEL::dog, 0);
    }

    return 0;
}
