// https://www.google.com/search?q=rpi+usb+camera+image+detection+c%2B%2B&sca_esv=a707d86a229c684a&sxsrf=APpeQnsYozy-p7JnLRqCTvieaKr1drd24Q%3A1783880074237&ei=itlTapyIDoGiqtsPitH0-Qc&ved=0ahUKEwic9ZWR382VAxUBkWoFHYooPX8Q4dUDCBA&uact=5&oq=rpi+usb+camera+image+detection+c%2B%2B&gs_lp=Egxnd3Mtd2l6LXNlcnAiInJwaSB1c2IgY2FtZXJhIGltYWdlIGRldGVjdGlvbiBjKysyBRAhGKABMgUQIRigATIFECEYoAEyBRAhGKABMgUQIRigATIFECEYnwUyBRAhGJ8FSI8NULEGWOULcAF4AJABAJgBXqAB_wKqAQE1uAEDyAEA-AEBmAIFoALmAsICChAAGEcY1gQYsAPCAg4QABjkAhjWBBiwA9gBAcICFxAuGNwGGLgGGNoGGNgCGMgDGLAD2AEBwgIaEC4Y3AYYuAYY2gYY2AIY5QQYyAMYsAPYAQHCAgUQIRirApgDAIgGAZAGD7oGBggBEAEYCZIHATWgB7YxsgcBNLgH3wLCBwUwLjQuMcgHDoAIAQ&sclient=gws-wiz-serp
// g++ -O3 image-detect-test.cpp -o detection `pkg-config --cflags --libs opencv4`

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

int main() {
    // 1. Initialize the USB Camera (Index 0 is default for first USB cam)
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the USB camera." << std::endl;
        return -1;
    }

    // Set lower resolution for higher performance on Raspberry Pi
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    // 2. Load the Pre-trained Model (MobileNet-SSD)
    // Download prototxt and caffemodel files before running
    std::string protoTxt = "MobileNetSSD_deploy.prototxt";
    std::string caffeModel = "MobileNetSSD_deploy.caffemodel";
    
    cv::dnn::Net net = cv::dnn::readNetFromCaffe(protoTxt, caffeModel);
    
    // Use CPU targeting (or OpenCL if configured)
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

    const char* classNames[] = {"background", "aeroplane", "bicycle", "bird", "boat",
                                "bottle", "bus", "car", "cat", "chair", "cow",
                                "diningtable", "dog", "horse", "motorbike", "person",
                                "pottedplant", "sheep", "sofa", "train", "tvmonitor"};

    // const char* classNames[] = {"dog"};

    cv::Mat frame;
    std::cout << "Starting detection. Press 'q' to exit..." << std::endl;

    while (true) {
        cap >> frame; // Capture live frame
        if (frame.empty()) break;

        // 3. Preprocess frame for the neural network (Resize to 300x300, scale pixels)
        cv::Mat blob = cv::dnn::blobFromImage(frame, 0.007843, cv::Size(300, 300), cv::Scalar(127.5, 127.5, 127.5), false);
        net.setInput(blob);
        cv::Mat detection = net.forward();

        // 4. Parse detection results
        cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
        
        for (int i = 0; i < detectionMat.rows; i++) {
            float confidence = detectionMat.at<float>(i, 2);

            // Filter out weak detections (50% threshold)
            if (confidence > 0.5) {
                size_t objectClass = static_cast<size_t>(detectionMat.at<float>(i, 1));
                
                // Get bounding box coordinates scaled back to original frame size
                int xLeftBottom = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
                int yLeftBottom = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
                int xRightTop = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
                int yRightTop = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);

                cv::Rect object(xLeftBottom, yLeftBottom, xRightTop - xLeftBottom, yRightTop - yLeftBottom);

                // Draw bounding box and label
                cv::rectangle(frame, object, cv::Scalar(0, 255, 0), 2);
                std::string label = std::string(classNames[objectClass]) + ": " + std::to_string(confidence).substr(0,4);
                cv::putText(frame, label, cv::Point(xLeftBottom, yLeftBottom - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
            }
        }

        // 5. Display the frame
        cv::imshow("RPi USB Camera Detection", frame);
        
        // Break loop on 'q' key press
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
