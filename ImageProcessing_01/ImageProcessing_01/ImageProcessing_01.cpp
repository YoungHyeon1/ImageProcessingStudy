// ImageProcessing_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 학번: 201995020
// 학과: 컴퓨터 소프트웨어 공학부
// 이름: 김영현

#include<opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int mx1, my1, mx2, my2;
bool cropping = false;
string image_path = "D:/chrome_download/Lenna.jpg";
string result_path = "D:/result.jpg";
Rect rect;

Rect getPositiveRect(int x1, int y1, int x2, int y2) {
    return Rect(min(x1, x2), min(y1, y2), abs(x2 - x1), abs(y2 - y1));
}


void onMouse(int event, int x, int y, int flags, void* param) {
    Mat* image = (Mat*)param;
    Mat temp_image = image->clone();
    if (event == EVENT_LBUTTONDOWN) {
        if (!cropping) {
            cout << "new rect" << endl;
        }
        cropping = true;
        rect = Rect(x, y, 0, 0);
    }
    else if (event == EVENT_MOUSEMOVE) {
        if (cropping) {
            *image = imread(image_path);
            rectangle(temp_image, getPositiveRect(rect.x, rect.y, x, y), Scalar(0, 255, 0), 2);
            imshow("image", temp_image);
        }
    }
    else if (event == EVENT_LBUTTONUP) {
        cropping = false;
        rectangle(*image, getPositiveRect(rect.x, rect.y, x, y), Scalar(0, 255, 0), 2);
        imshow("image", *image);
        rect = getPositiveRect(rect.x, rect.y, x, y);
    }
}


int main()
{
    Mat img, roi;
    img = imread(image_path);
    imshow("image", img);
    Mat clone = img.clone();
    setMouseCallback("image", onMouse, &img);
    while (1) {
        int key = waitKey(100);
        if (key == 'q')break;
        else if (key == 'c') {
            roi = clone(rect);
            imwrite(result_path, roi);
        }
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
