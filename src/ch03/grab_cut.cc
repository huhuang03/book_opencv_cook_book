#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
    cv::Mat img = cv::imread("boldt.jpg");

    if (img.empty()) {
        cout << "img read failed." << endl;
        return -1;
    }

    cv::Rect fgRect = cv::Rect(5, 70, 260, 120);
    cv::Mat rst;
    cv::Mat fgRst;
    cv::Mat bgRst;
    cv::grabCut(img, rst, fgRect, bgRst, fgRst, 5, cv::GC_INIT_WITH_RECT);

    cv::compare(rst, cv::GC_PR_FGD, rst, cv::CMP_EQ);
    cv::Mat fgImg(img.size(), CV_8UC3, cv::Scalar(255, 255, 255));
    img.copyTo(fgImg, rst);

    cv::imshow("Image1", img);
    cv::imshow("Image2", fgImg);
    cv::waitKey(0);
    return 0;
}
