#include "histogram_1d.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    auto img = cv::imread("group.jpg", 0);

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }

    cv::Mat rst;
    cv::equalizeHist(img, rst);
    
    cout << rst.size() << endl;
    
    cv::imshow("Image", img);
    cv::imshow("Image1", rst);

    Histogram1D::showHistogram(img, "hist1");
    Histogram1D::showHistogram(rst, "hist2");
    cv::waitKey(0);
}