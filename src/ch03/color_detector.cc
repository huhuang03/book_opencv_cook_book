#include "color_detector.hpp"
#include <opencv2/imgproc.hpp>

ColorDetector::ColorDetector(): maxDist(100), target(0, 0, 0) {

}

ColorDetector::ColorDetector(uchar blue, uchar green, uchar red, int maxDist)
    :  maxDist(maxDist) {
    setTarget(blue, green, red);
}

cv::Vec3b ColorDetector::getTargetColor() const {
    return target;
}

void ColorDetector::setTarget(uchar b, uchar g, uchar r) {
    target = cv::Vec3b(b, g, r);
}

int getColorDistance(const cv::Vec3b &c1, const cv::Vec3b &c2) {
    return abs(c1[0] - c2[0]) + 
        abs(c1[1] - c2[1]) + 
        abs(c1[2] - c2[2]);
}

int ColorDetector::getDistanceToTargetColor(const cv::Vec3b& c) {
    return getColorDistance(c, target);
}


cv::Mat ColorDetector::operator()(const cv::Mat &image) {
    return this->process(image);
}

cv::Mat ColorDetector::process(const cv::Mat &img) {
    result.create(img.size(), CV_8U);
    cv::Mat_<cv::Vec3b>::const_iterator it = img.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator end = img.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator out = result.begin<uchar>();

    for (; it != end; it++, out++) {
        if (getDistanceToTargetColor(*it) <= maxDist) {
            *out = 255;
        } else {
            *out = 0;
        }
    }
    return result;
}

cv::Mat ColorDetector::processOpencvStand(cv::Mat &img) {
    result.create(img.size(), img.type());
    cv::absdiff(img, cv::Scalar(target), result);
    std::vector<cv::Mat> images;
    cv::split(result, images);
    result = images[0] + images[1] + images[2];
    
    cv::threshold(result, result, maxDist, 255, cv::THRESH_BINARY_INV);
    return result;
}