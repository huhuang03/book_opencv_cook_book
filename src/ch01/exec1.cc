// use flip inplace
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
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
    cv::namedWindow(windowName);
    cv::imshow(windowName, image);

    cv::flip(image, image, 1); // 1 means horizontal, 0 means vertical

    cv::namedWindow("Output Image");
    cv::imshow("Output Image", image);


    cv::imwrite("output.bmp", image);
    cv::waitKey(0);
}
