#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void detectHSColor(cv::Mat &img, int hMin, int hMax, int sMin, int sMax, cv::Mat &mask) {
    mask.create(img.size(), CV_8UC1);
    cv::Mat hsv;
    cv::cvtColor(img, hsv, COLOR_BGR2HSV);

    cv::Mat mask1;
    cv::Mat mask2;

    cv::Mat maskH;
    cv::Mat maskS;

    std::vector<cv::Mat> channels;
    cv::split(hsv, channels);

    cv::threshold(channels[0], mask1, hMin, 255, cv::THRESH_BINARY);
    cv::threshold(channels[0], mask2, hMax, 255, cv::THRESH_BINARY_INV);

    if (hMin <= hMax) {
        maskH = mask1 & mask2;
    } else {
        maskH = mask1 | mask2;
    }

    cv::threshold(channels[1], mask1, sMin, 255, cv::THRESH_BINARY);
    cv::threshold(channels[1], mask2, sMax, 255, cv::THRESH_BINARY_INV);
    maskS = mask1 & mask2;

    mask = maskH & maskS;
}

int main() {
    auto img = cv::imread("girl.jpg");

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }

    cv::Mat rst;
    cv::Mat mask;
    detectHSColor(img, 160, 10, 25, 166, mask);
    cv::copyTo(img, rst, mask);
    
    cv::imshow("Image", img);
    cv::imshow("Image1", rst);
    cv::waitKey(0);
}