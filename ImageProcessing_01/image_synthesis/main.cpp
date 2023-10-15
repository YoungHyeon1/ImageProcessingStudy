// main.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
// �й�: 201995020
// �а�: ��ǻ�� ����Ʈ���� ���к�
// �̸�: �迵��

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

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
