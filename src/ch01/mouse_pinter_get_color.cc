#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

void onMouse(int event, int x, int y, int flags, void *param) {
    cv::Mat *image = (cv::Mat*)param;
    switch(event) {
        case cv::EVENT_LBUTTONDOWN:
            cout << "at (" << x << "," << y << ") value is: " << (int)image->at<uchar>(cv::Point(x, y)) << endl;
    }
}

int main() {
    auto windowName = "Original Image";
    cv::Mat image;
    image = cv::imread("puppy.bmp");
    if (image.empty()) {
        cout << "Can't read image" << endl;
        return -1;
    }
    cout << "The image is " << image.rows << "x" << image.cols << endl;

    cv::namedWindow(windowName);
    cv::setMouseCallback(windowName, onMouse, (void*)&image);
    cv::imshow(windowName, image);

    cv::waitKey(0);
}