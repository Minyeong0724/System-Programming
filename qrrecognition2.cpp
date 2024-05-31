#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int main() {
    // 카메라 초기화
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open the camera" << std::endl;
        return -1;
    }

    // QRCodeDetector 객체 생성
    cv::QRCodeDetector qrDecoder;
    cv::Mat frame;

    while (true) {
        // 프레임 캡처
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Error: Unable to capture frame" << std::endl;
            break;
        }

        // QR 코드 감지 및 디코딩
        std::string data = qrDecoder.detectAndDecode(frame);
        if (!data.empty()) {
            std::cout << "Decoded Data: " << data << std::endl;
        }

        // 'q' 키를 눌러 종료
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    // 카메라 릴리즈
    cap.release();
    return 0;
}
