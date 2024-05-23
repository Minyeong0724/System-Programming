#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    QRCodeDetector detector;

    Mat frame, gray;
    frame = imread("qr1.jpg");

    if (frame.empty()) {
        cerr << "Frame load failed!" << endl;
        return -1;
    }

    cvtColor(frame, gray, COLOR_BGR2GRAY);

    vector<Point> points;

    if (detector.detect(gray, points)) {
        polylines(frame, points, true, Scalar(0, 255, 255), 2);

        String info = detector.decode(gray, points);
        if (!info.empty()) {
            polylines(frame, points, true, Scalar(0, 0, 255), 2);
            cout << "Decoded Data : " << info << endl;
        }
    }

    imshow("frame", frame);
    waitKey(0);

    return 0;
}
