#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

void colorReduce(cv::Mat &img, int div=64) {
    auto rows = img.rows;
    int nc = img.cols * img.channels();
    for (int r = 0; r < rows; r++) {
        unsigned char* line = img.ptr<unsigned char>(r);

        for (int i = 0; i < nc; i++) {
            line[i] = line[i] / div * div +  div / 2;
        }
    }
}

int main() {
    cv::Mat img = cv::imread("boldt.jpg");
    cv::imshow("Image", img);
    colorReduce(img);
    cv::imshow("Image1", img);
    cv::waitKey(0);
}
