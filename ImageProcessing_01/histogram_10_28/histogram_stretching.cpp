// 201995020
// ±è¿µÇö

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


void minMaxLocal(Mat values, double* min, double* max) {

	*min = values.at<uchar>(0, 0);
	*max = values.at<uchar>(0, 0);

	for (int y = 0; y < values.rows; y++) {
		for (int x = 0; x < values.cols; x++) {
			double pixelValue = values.at<uchar>(y, x);
			if (pixelValue < *min) {
				*min = pixelValue;
			}
			if (pixelValue > *max) {
				*max = pixelValue;
			}
		}
	}
}
/*
int main()
{
	Mat image = imread("D:/chrome_download/Crayfish.JPG", IMREAD_GRAYSCALE);
	Mat new_image = image.clone();
	double min, max;
	minMaxLocal(new_image, &min, &max);

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			double pixelValue = image.at<uchar>(y, x);
			double stretchedValue = (pixelValue - min)*255 / (max-min);
			new_image.at<uchar>(y, x) = saturate_cast<uchar>(stretchedValue);
		}
	}
	imshow("input", image);
	imshow("result", new_image);
	waitKey(0);
}
*/
