// histogram.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 학번: 201995020
// 이름: 김영현
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


int* splitHist(Mat images) {
    int histogram[256] = { 0 };
    for (int y = 0; y < images.rows; y++) {
        for (int x = 0; x < images.cols; x++) {
            histogram[(int)images.at<uchar>(y, x)]++;
        }
    }
    return histogram;
}

int* normarlizeCustom(int histogram[], int rows) {
    int temp = histogram[0];
    for (int i = 1; i < 256; i++)
        temp = (histogram[i]  + temp + abs(histogram[i] - temp)) / 2;
    for (int i = 0; i < 256; i++)
        histogram[i] = floor(((double)histogram[i] / temp) * rows);
    return histogram;
}


void drawHist(vector<Mat> bgr_planes) {
    int hist_w = 512, hist_h = 400;
    int histSize = 256;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255)); 


    int* blue_histogram = splitHist(bgr_planes[0]);
    int* b_histogram = normarlizeCustom(blue_histogram, histImage.rows);
    for (int i = 0; i < 256; i++) {
        line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - b_histogram[i]), Scalar(255, 0, 0));
    }

    int* green_histogram = splitHist(bgr_planes[1]);
    int* g_histogram = normarlizeCustom(green_histogram, histImage.rows);
    for (int i = 0; i < 256; i++) {
        line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - g_histogram[i]), Scalar(0, 255, 0));
    }

    int* red_histogram = splitHist(bgr_planes[2]);
    int* r_histogram = normarlizeCustom(red_histogram, histImage.rows);

    for (int i = 0; i < 256; i++) {
        line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - r_histogram[i]), Scalar(0, 0, 255));
    }

    imshow("Histogram", histImage);
}


//int main()
//{
//    Mat src = imread("D:/chrome_download/Lenna.jpg", IMREAD_COLOR);
//    if (src.empty()) { return -1; }
//
//    /*
//    //Code 5.3
//    vector<Mat> bgr_planes;
//    split(src, bgr_planes);
//    int histSize = 256;
//    float range[] = { 0,256 };
//    const float* histRange = { range };
//    bool uniform = true, accumlate = false;
//    Mat b_hist, g_hist, r_hist;
//
//    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumlate);
//    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumlate);
//    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumlate);
//
//    int hist_w = 512, hist_h = 400;
//    int bin_w = cvRound((double)hist_w / histSize);
//    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
//
//    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//
//    for (int i = 0; i < 256; i++) {
//        line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - b_hist.at<float>(i)), Scalar(255,0,0));
//        line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - g_hist.at<float>(i)), Scalar(0, 255, 0));
//        line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - r_hist.at<float>(i)), Scalar(0, 0, 255));
//
//    }
//
//    imshow("입력영상", src);
//    imshow("Color Histogram", histImage);
//    */
//    vector<Mat> bgr_planes;
//    split(src, bgr_planes);
//
//    imshow("Input Image", src);
//    drawHist(bgr_planes);
//    waitKey(0);
//    return 0;
//}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
