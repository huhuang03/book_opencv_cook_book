#include "histogram_1d.hpp"
#include <opencv2/imgproc.hpp>

Histogram1D::Histogram1D() {
    histSize[0] = 256;
    hranges[0] = 0.0;
    hranges[1] = 256.0;
    ranges[0] = hranges;
    channels[0] = 0;
}

cv::Mat Histogram1D::process(const cv::Mat &img) {
    cv::Mat hist;
    cv::calcHist(&img, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
    return hist;
}

cv::Mat Histogram1D::getImageOfHistogram(const cv::Mat &hist, int zoom) {
    double maxVal = 0;
    double minVal = 0;
    cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);

    int histSize = hist.rows;

    cv::Mat histImg(histSize * zoom, histSize * zoom, CV_8U, cv::Scalar(255));

    int hpt = static_cast<int>(0.9 * histSize);

    for (int h = 0; h < histSize; h++) {
        float binVal = hist.at<float>(h);
        if (binVal > 0) {
            int indensity = static_cast<int>(binVal * hpt / maxVal);
            cv::line(histImg, cv::Point(h*zoom, histSize * zoom),
                cv::Point(h*zoom, (histSize - indensity) * zoom),
                cv::Scalar(0), zoom);
        }
    }

    return histImg;
}
