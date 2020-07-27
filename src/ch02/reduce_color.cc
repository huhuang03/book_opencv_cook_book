#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

void colorReduce(cv::Mat &img, int div=64) {
    auto rows = mat.rows;
    int nc = img.cols * img.channels();
    for (int r = 0; r < rows; r++) {
        unsigned char* line = mat.ptr<unsigned char>(r);

        for (i = 0; i < nc; i++) {
            line[nc] = line[nc] / div * div +  div / 2
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
