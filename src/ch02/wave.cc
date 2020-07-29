#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#define uchar unsinged char

void wave(Mat &img, Mat &out) {
    out.create(img.size(), img.type());
    cv::Mat xmap(img.size(), CV_32F);
    cv::Mat ymap(img.size(), CV_32F);

    for (int i = 0; i < img.cols; i++) {
        for (int j = 0; j < img.rows; j++) {
            xmap.at<float>(j, i) = i;
            ymap.at<float>(j, i) = j + 5*sin(i/10.0);
        }
    }

    cv::remap(img, out, xmap, ymap, cv::INTER_LINEAR);
}

int main() {
    auto img = cv::imread("boldt.jpg");
    auto output = cv::Mat();
    wave(img, output);
    imshow("Image", output);
    cv::waitKey();
    return 0;
}


