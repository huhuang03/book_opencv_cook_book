#ifndef H_HISTOGRAM_1D
#define H_HISTOGRAM_1D

#include <opencv2/core.hpp>

class Histogram1D {
    private:
    int histSize[1];
    float hranges[2];
    const float* ranges[1];
    int channels[1];
    public:
    Histogram1D();
    
    cv::Mat process(const cv::Mat &image);
    static cv::Mat getImageOfHistogram(const cv::Mat &hist, int zoom = 1);
};

#endif