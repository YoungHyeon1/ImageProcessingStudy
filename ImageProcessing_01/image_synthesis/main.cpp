// main.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 학번: 201995020
// 학과: 컴퓨터 소프트웨어 공학부
// 이름: 김영현

#include<opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat input_image_1(500, 500, CV_8UC1, Scalar(0));
	Mat input_image_2(500, 500, CV_8UC1, Scalar(0));
	circle(input_image_1, Point(input_image_1.cols / 2, input_image_1.rows / 2), 150, Scalar(255), -1);
	input_image_2(Rect(0, 0, input_image_2.cols/2, input_image_2.rows)).setTo(255);

	imshow("input_1", input_image_1);
	imshow("input_2", input_image_2);
	Mat result;
	bitwise_not(input_image_1, result);
	imshow("NOT", result);
	bitwise_and(input_image_1, input_image_2, result);
	imshow("AND", result);
	bitwise_or(input_image_1, input_image_2, result);
	imshow("OR", result);
	bitwise_xor(input_image_1, input_image_2, result);
	imshow("XOR", result);
	waitKey(0);

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
