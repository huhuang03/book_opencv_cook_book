#include <opencv/core.hpp>
#include <opencv/highgui.hpp>
#include <iostream>

using namespace std;
using namespace opencv;

#define uchar unsinged char

void sharpen(Mat img, Mat imgOut) {
    imgOut.create(img.size(), img.type());
    auto nChannels = img.channels();
    auto iMax = img.channels() * (img.cols - 1);

    for (int j = 1; j < img.rows - 1; j++) {
        auto previous = img.ptr<uchar>(j - 1);
        auto current = img.ptr<uchar>(j);
        auto next = img.ptr<uchar>(j + 1);

        uchar* out = imgOut.ptr<uchar>(j);

        for (int i = img.channels(); i < iMax; i++) {
            out[i] = 5 * current[i] - current[i-nChannels] - current[i+nChannels] - previous[i] - next[i];
        }
    }

    if (img.type == CV_8UC3) {
        imgOut.row(0).setTot(Scalar(0, 0, 0));
        imgOut.row(imgOut.rows - 1).setTot(Scalar(0, 0, 0));
        imgOut.col(0).setTot(Scalar(0, 0, 0));
        imgOut.col(imgOut.cols - 1).setTot(Scalar(0, 0, 0));
    } else if (img.type == CV_8UC1) {
        imgOut.row(0).setTot(Scalar(0));
        imgOut.row(imgOut.rows - 1).setTot(Scalar(0));
        imgOut.col(0).setTot(Scalar(0, 0, 0));
        imgOut.col(imgOut.cols - 1).setTot(Scalar(0));
    }
}

int main() {
    auto img = cv::imread("boldt.jpg");
    auto output = cv::Mat();

    sharpen(img, output);

    imshow("Image", output);
    return 0;
}


