#ifndef _COLOR_DETCTOR
#define _COLOR_DETECTOR

#include <opencv2/core.hpp>

class ColorDetector {
    private:
    int maxDist;
    cv::Vec3b target;
    cv::Mat result;

    public:
    void setTarget(uchar b, uchar g, uchar r);
    cv::Vec3b getTargetColor() const;
    int getDistanceToTargetColor(const cv::Vec3b& c);

    public:
    ColorDetector();
    ColorDetector(uchar blue, uchar green, uchar red, int maxDist);
    cv::Mat process(cv::Mat &img);
    cv::Mat processOpencvStand(cv::Mat &img);
};

#endif