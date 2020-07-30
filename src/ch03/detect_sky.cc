#include "color_detector.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

int main() {
    auto img = cv::imread("boldt.jpg");

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }

    cv::imshow("Image", img);
    ColorDetector colorDector;
    colorDector.setTarget(230, 190, 130);

    cv::Mat rst = colorDector.process(img);
    cv::imshow("Image1", rst);

    cv::Mat rst1 = colorDector.processOpencvStand(img);
    cv::imshow("Image2", rst1);

    cv::waitKey();
}
