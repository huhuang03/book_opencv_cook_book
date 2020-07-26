#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;

int main() {
    auto windowName = "Original Image";
    cv::Mat image;
    image = cv::imread("puppy.bmp");
    if (image.empty()) {
        cout << "Can't read image" << endl;
        return -1;
    }
    cout << "The image is " << image.rows << "x" << image.cols << endl;

    cv::circle(image,
        cv::Point(155, 100),
        65,
        0,
        2
        );

    cv::putText(image,
        "Can only english.",
        cv::Point(40, 200),
        cv::FONT_HERSHEY_PLAIN,
        2.0,
        255,
        2);

    cv::namedWindow(windowName);
    cv::imshow(windowName, image);

    cv::waitKey(0);
}