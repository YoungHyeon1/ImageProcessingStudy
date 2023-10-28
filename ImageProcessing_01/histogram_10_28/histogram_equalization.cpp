//201995020
//±è¿µÇö

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


double normalizedHistogram(int value, int total_mat) {
    return (double)value / (double)total_mat;
}
void convertNormalized(Mat image, int cumulativeHist[], Mat& resultImage) {
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            int pixelValue = static_cast<int>(image.at<uchar>(y, x));
            double normalizedPixelValue = static_cast<int>(normalizedHistogram(cumulativeHist[pixelValue], image.rows * image.cols)*255);

            resultImage.at<uchar>(y, x) = static_cast<uchar>(normalizedPixelValue);
        }
    }
}


int* convertHistogram(Mat images) {
    int histogram[256] = { 0 };
    for (int y = 0; y < images.rows; y++) {
        for (int x = 0; x < images.cols; x++) {
            histogram[(int)images.at<uchar>(y, x)]++;
        }
    }
    return histogram;
}

int* cumulativeHistogram(Mat values) {
	int cumulativeHist[256];
    int* histogram = convertHistogram(values);
    cumulativeHist[0] = histogram[0];
    for (int i = 1; i < 256; i++) {
        cumulativeHist[i] = cumulativeHist[i - 1] + histogram[i];
    }
    return cumulativeHist;
}

int main()
{
    Mat image = imread("D:/chrome_download/Crayfish.JPG", IMREAD_GRAYSCALE);
    Mat result_image = image.clone();

    int* convert_histogram = cumulativeHistogram(image);
    convertNormalized(image, convert_histogram, result_image);

    imshow("input", image);
    imshow("result", result_image);
    waitKey(0);
}