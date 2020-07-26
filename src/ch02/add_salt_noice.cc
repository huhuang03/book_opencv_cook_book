#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <random>

using namespace std;

void salt(cv::Mat &img, int n) {
    default_random_engine generator;
    uniform_int_distribution<int> randomRow(0, img.rows - 1);
    uniform_int_distribution<int> randomCol(0, img.cols - 1);

    for (int k = 0; k < n; k++) {
        int i = randomCol(generator);
        int j = randomRow(generator);

        if (img.type() == CV_8UC1) {
            img.at<uchar>(j, i) = 255;
        } else if (img.type() == CV_8UC3) {
            img.at<cv::Vec3b>(j, i)[0] = 255;
            img.at<cv::Vec3b>(j, i)[1] = 255;
            img.at<cv::Vec3b>(j, i)[2] = 255;
        }
    }
}

int main() {
    // 1 means what? 
    cv::Mat img = cv::imread("boldt.jpg", 1);
    salt(img, 100);
    cv::imshow("Image", img);
    cv::waitKey(0);
}