#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2_ex/opencv2_ex.hpp>

using namespace std;
using namespace cv;

/**
 * Hello in this exec, I can't find baboon3.jpg, so I can't go on
 */
int main() {
    auto img = cv::imread("baboon02.jpg");

    auto beginRoiRect = cv::Rect(110, 260, 35, 40);

    if (img.empty()) {
        cout << "read image failed." << endl;
        return -1;
    }

    

    
    cv::imshow("Image", img);
    cv::waitKey(0);
}