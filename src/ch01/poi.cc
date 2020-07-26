
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
    auto img = cv::imread("puppy.bmp");
    // channle is 3
    auto imgIcon = cv::imread("smalllogo.png");
    if (img.empty() || imgIcon.empty()) {
        cout << "Can't read image" << endl;
        return -1;
    }

    cv::Mat imageRoi(img, 
        cv::Rect(
            img.cols - imgIcon.cols,
            img.rows - imgIcon.rows,
            imgIcon.cols, imgIcon.rows));

    cv::Mat mask(imgIcon);

    imgIcon.copyTo(imageRoi, mask);

    cv::Mat imageRoi1 = img(cv::Range(0, imgIcon.rows), cv::Range(0, imgIcon.cols));

    imgIcon.copyTo(imageRoi1, mask);


    cv::imshow("Image", img);
    cv::waitKey(0);
}
