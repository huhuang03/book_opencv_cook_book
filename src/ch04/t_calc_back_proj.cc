#include "histogram_1d.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void doCalcBackProject(cv::Mat &img, cv::Mat &rst) {
}

int main() {
    auto img = cv::imread("waves.jpg");
    cout << img.dims << endl;

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }
    auto roi = img(cv::Rect(216, 33, 24, 30));

    auto hist1D = Histogram1D();
    int channels[] = {0};
    auto hist = hist1D.process(img);

    float range[] = {0.0, 256};
    const float* ranges = { range };
    cv::Mat proj;
    cv::calcBackProject(&img, 1, channels, hist, proj, &ranges);
    // cout << proj << endl;
    
    cv::imshow("Image", img);
    cv::imshow("Roi", roi);
    cv::imshow("Back", ~proj);
    cv::waitKey(0);
}