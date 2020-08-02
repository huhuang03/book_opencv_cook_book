#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // h is the color
    // and s is the saturation(饱和度)
    int H_MAX = 180;
    int S_MAX = 256;

    cv::Mat imgHsv(S_MAX, H_MAX, CV_8UC3);
    for (int h = 0; h < H_MAX; h++) {
        for (int s = 0; s < S_MAX; s++) {
            imgHsv.at<cv::Vec3b>(s, h)[0] = h;
            imgHsv.at<cv::Vec3b>(s, h)[1] = s;
            imgHsv.at<cv::Vec3b>(s, h)[2] = 255;
        }
    }

    cv::Mat rst;
    cv::cvtColor(imgHsv, rst, cv::COLOR_HSV2RGB);

    
    cv::imshow("Image", rst);
    cv::waitKey(0);
}