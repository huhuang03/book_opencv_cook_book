#include "content_finder.hpp"
#include <opencv2/imgproc.hpp>

ContentFinder::ContentFinder(): threshold(0.1f) {
    ranges[0] = hranges;
    ranges[1] = hranges;
    ranges[2] = hranges;
}


void ContentFinder::setHistogram(const cv::Mat &h) {
    histogram = h;
    cv::normalize(histogram, histogram, 1.0);
}

cv::Mat ContentFinder::find(const cv::Mat &img) {
    cv::Mat rst;
    hranges[0] = 0.0;
    hranges[1] = 256.0;
    channels[0] = 0;
    channels[1] = 1;
    channels[2] = 2;
    return find(img, hranges[0], hranges[1], channels);
}

cv::Mat ContentFinder::find(const cv::Mat &img, float minVal, float maxVal, int *channels) {
    cv::Mat result;
    hranges[0] = minVal;
    hranges[1] = maxVal;

    // 为什么说直方图的维度数和通道列表一致？
    for (int i = 0; i < histogram.dims; i++) {
        this->channels[i] = channels[i];
    }
    cv::calcBackProject(&img, 1,
        channels,
        histogram,
        result,
        ranges,
        255.0);

    if (threshold > 0) {
        cv::threshold(result, result, 255 * threshold, 255.0, cv::THRESH_BINARY);
    }

    return result;
}
