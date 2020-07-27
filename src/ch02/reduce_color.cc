#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

void colorReduce2(const cv::Mat &img, cv::Mat &outImg, int div=64) {
    // use iterator
    cv::Mat_<cv::Vec3b>::const_iterator in = img.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::iterator out = outImg.begin<cv::Vec3b>();

    auto mask = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
    mask = 0xff << mask;
    auto div2 = div >> 1;
    
    auto end = img.end<cv::Vec3b>();
    while (in != end) {
        (*out)[0] = (*in)[0] & mask;
        (*out)[0] += div2;

        (*out)[1] = (*in)[1] & mask;
        (*out)[1] += div2;

        (*out)[2] = (*in)[2] & mask;
        (*out)[2] += div2;

        in++;
        out++;
    }
}

void colorReduce1(const cv::Mat &img, cv::Mat &out, int div=64) {
    // better performance
    out.create(img.rows, img.cols, img.type());
    if (img.isContinuous()) {
        img.reshape(1, 1);
    }

    int nl = img.rows;
    int nc = img.cols * img.channels();

    auto mask = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
    mask = 0xff << mask;

    auto div2 = div >> 1;
    for (int r = 0; r < nl; r++) {
        const unsigned char* line = img.ptr<unsigned char>(r);
        unsigned char *outLine = out.ptr<unsigned char>(r);
        for (int j = 0; j < nc; j++) {
            *outLine = mask & *line;
            *outLine += div2;
            outLine++;
            line++;
        }
    }
}

void colorReduce(const cv::Mat &img, cv::Mat &out, int div=64) {
    cv::Mat rst(out);
    rst.create(img.rows, img.cols, img.type());

    auto rows = img.rows;
    int nc = img.cols * img.channels();
    for (int r = 0; r < rows; r++) {
        const unsigned char* line = img.ptr<unsigned char>(r);
        unsigned char* outLine = rst.ptr<unsigned char>(r);

        for (int i = 0; i < nc; i++) {
            outLine[i] = line[i] / div * div +  div / 2;
            // work also
            // line[i] = line[i] - line[i] % div + div / 2;
        }
    }
}

int main() {
    cv::Mat img = cv::imread("boldt.jpg");
    cv::imshow("Image", img);
    colorReduce2(img, img);
    cv::imshow("Image1", img);
    cv::waitKey(0);
}
