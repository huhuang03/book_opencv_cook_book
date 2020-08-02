#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    auto img = cv::imread("boldt.jpg");

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }

    cv::Mat hsv;
    cv::cvtColor(img, hsv, cv::COLOR_RGB2HSV);
    std::vector<cv::Mat> channles;
    cv::split(img, channles);
    channles[2] = 255;
    cv::merge(channles, hsv);

    cv::Mat newImg;
    cv::cvtColor(hsv, newImg, cv::COLOR_HSV2BGR);
    
    cv::imshow("Image", img);
    cv::imshow("Image1", newImg);
    cv::waitKey(0);
}