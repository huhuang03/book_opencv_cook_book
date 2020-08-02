#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

int main() {
    auto img = cv::imread("boldt.jpg");

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }

    cv::imshow("Image1", img);

    cv::floodFill(img, cv::Point(100, 50), cv::Scalar(255, 255, 255), (cv::Rect*)0, 
            cv::Scalar(35, 35, 35),
            cv::Scalar(35, 35, 35),
            cv::FLOODFILL_FIXED_RANGE);

    cv::imshow("Image2", img);
    cv::waitKey(0);
}

