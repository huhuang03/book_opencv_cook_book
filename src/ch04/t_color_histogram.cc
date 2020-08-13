#include <opencv2_ex/opencv2_ex.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    auto img = cv::imread("waves.jpg");

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }

    ColorHistogram hc;
    auto imgRoi = img(cv::Rect(0, 0, 100, 45));
    hc.setSize(8);
    cv::Mat shist = hc.process(imgRoi);

    ContentFinder finder;
    finder.setHistogram(shist);
    finder.setThreShold(0.05f);

    cv::Mat rst = finder.find(img);
    
    cv::imshow("Image", img);
    cv::imshow("Roi", imgRoi);
    // why this color is not the same as book?
    cv::imshow("Image1", rst);
    cv::waitKey(0);
}