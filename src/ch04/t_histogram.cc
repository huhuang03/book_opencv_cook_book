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

    Histogram1D h;
    cv::Mat histo = h.process(img);

    // for (int i = 0; i < 256; i++) {
    //     cout << "Value " << i << " = " << histo.at<float>(i) << endl;
    // }

    cv::Mat imgHist = Histogram1D::getImageOfHistogram(histo);
    
    cv::Mat thresholded;
    cv::threshold(img, thresholded, 70, 255, cv::THRESH_BINARY);

    cv::imshow("Image", img);
    cv::imshow("Image1", imgHist);
    cv::imshow("Image2", thresholded);
    cv::imshow("Image3", ~thresholded);
    cv::waitKey(0);
}