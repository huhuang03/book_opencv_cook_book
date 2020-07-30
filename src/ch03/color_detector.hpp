#ifndef _COLOR_DETCTOR
#define _COLOR_DETECTOR

#include <opencv2/core.hpp>

class ColorDetector {
    private:
    int maxDist;
    public:
    void setTarget(int b, int g, int r);
    cv::Mat process(cv::Mat &img);
};

#endif