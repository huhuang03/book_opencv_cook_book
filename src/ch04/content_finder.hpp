#ifndef _H_CONTENT_FINDER
#define _H_CONTENT_FILDER

#include <opencv2/core.hpp>

class ContentFinder {
    private:
    float hranges[2];
    const float* ranges[3];
    int channels[3];
    float threshold;
    cv::Mat histogram;

    public:
    ContentFinder();
    void setHistogram(const cv::Mat &h);
    cv::Mat find(const cv::Mat &img);
    cv::Mat find(const cv::Mat &img, float minVal, float maxVal, int *channels);
};

#endif