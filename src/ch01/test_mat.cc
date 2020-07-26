// use flip inplace
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

cv::Mat create_img(void) {
    cv::Mat img(500, 500, CV_8U, 50);
    return img;
}

int main() {
    auto windowName = "Original Image";
    cv::Mat img1 = cv::Mat(240, 320, CV_8U, 50);
    cv::imshow("Image", img1);
    cv::waitKey(0);

    img1.create(200, 200, CV_8U);
    img1 = 200;
    cv::imshow("Image", img1);
    cv::waitKey(0);

    cv::Mat img2(240, 320, CV_8UC3, cv::Scalar(0, 0, 255));
    cv::imshow("Image", img2);
    cv::waitKey(0);

    cv::Mat img3 = cv::imread("puppy.bmp");
    // save bytes pointer
    cv::Mat img4(img3);
    img1 = img3;

    // copied
    img3.copyTo(img2);
    cv::Mat img5 = img3.clone();
    
    cv::flip(img3, img3, 1);
    cv::imshow("Image 3", img3);
    cv::imshow("Image 1", img1);
    cv::imshow("Image 4", img4);
    cv::imshow("Image 2", img2);
    cv::imshow("Image 5", img5);
    cv::waitKey(0);

    cv::Mat gray = create_img();
    cv::imshow("Image", gray);
    cv::waitKey(0);

    img1 = cv::imread("puppy.bmp", cv::ImreadModes::IMREAD_GRAYSCALE);
    img1.convertTo(img2, CV_32F, 1/255.0, 0.0);

    cv::imshow("Image", img1);
    cv::waitKey(0);

    cv::imshow("Image", img2);
    cv::waitKey(0);
}
