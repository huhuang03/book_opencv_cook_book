#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#define uchar unsigned char

void sharpen2D(Mat &img, Mat &imgOut) {
    cv::Mat kernel(3, 3, CV_32F, cv::Scalar(0));    
    kernel.at<float>(1, 1) = 5.0;
    kernel.at<float>(0, 1) = -1.0;
    kernel.at<float>(2, 1) = -1.0;
    kernel.at<float>(1, 0) = -1.0;
    kernel.at<float>(1, 2) = -1.0;

    cv::filter2D(img, imgOut, img.depth(), kernel);
}

void sharpen(Mat img, Mat &imgOut) {
    imgOut.create(img.size(), img.type());
    auto nChannels = img.channels();
    auto iMax = img.channels() * (img.cols - 1);

    for (int j = 1; j < img.rows - 1; j++) {
        auto previous = img.ptr<uchar>(j - 1);
        auto current = img.ptr<uchar>(j);
        auto next = img.ptr<uchar>(j + 1);

        uchar* out = imgOut.ptr<uchar>(j);

        for (int i = img.channels(); i < iMax; i++) {
            out[i] = cv::saturate_cast<uchar>(5 * current[i] - current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }

    if (img.type() == CV_8UC3) {
        imgOut.row(0).setTo(cv::Scalar(0, 0, 0));
        imgOut.row(imgOut.rows - 1).setTo(Scalar(0, 0, 0));
        imgOut.col(0).setTo(Scalar(0, 0, 0));
        imgOut.col(imgOut.cols - 1).setTo(Scalar(0, 0, 0));
    } else if (img.type() == CV_8UC1) {
        imgOut.row(0).setTo(Scalar(0));
        imgOut.row(imgOut.rows - 1).setTo(Scalar(0));
        imgOut.col(0).setTo(Scalar(0, 0, 0));
        imgOut.col(imgOut.cols - 1).setTo(Scalar(0));
    }
}

int main() {
    auto img = cv::imread("boldt.jpg");
    if (img.empty()) {
        cout << "Can't open image" << endl;
        return -1;
    }

    auto output = cv::Mat();
    sharpen2D(img, output);

    imshow("Image", output);
    waitKey(0);
    return 0;
}


