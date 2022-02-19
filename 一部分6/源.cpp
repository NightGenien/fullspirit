#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawTest();

int main(int argc, char** argv)
{
	drawTest();
	waitKey(0);
	return 0;
}

void drawTest() {
	int w = 500;
	Mat img = Mat::zeros(Size(w, w), CV_8UC3); //��һ������500�ĺ�ɫ����

	const int size = 5;
	Point points[1][size];
	for (int i = 0; i < size; i++) {
		points[0][i] = Point(w / (i + 1), w / (size - i));
	}
	const Point* ppt[1] = { points[0] };
	int npt[] = { size };
	fillPoly(img, ppt, npt, 1, Scalar(255, 128, 0), 8, 0); //������� 
	circle(img, Point(w / 2, w / 2), 10, Scalar(0, 0, 255), 3, 0); //��Բ
	line(img, Point(3, 4), Point(100, 220), Scalar(0, 255, 0), 5, LINE_8); //����
	ellipse(img, Point(w / 2, w / 2), Size(w / 4, w / 16), 90, 0, 360, Scalar(255, 0, 0), 2, 0); //����Բ

	rectangle(img, Point(0, 7 * w / 8), Point(400, 350), Scalar(40, 25, 142), FILLED, LINE_8); //������
	imshow("drawTest", img);
}

/*typedef struct Scalar
{
	double val[4];
}Scalar;
Mat M(7,7,CV_32FC2,Scalar(1,3));
����Ĵ����ʾ������һ��2ͨ������ÿ��ͨ����ֵ��Ϊ��1,3�������Ϊ32��7��7�е�ͼ�����CV_32F��ʾÿ��Ԫ�ص�ֵ������Ϊ32λ��������
C2��ʾͨ����Ϊ2��Scalar��1,3����ʾ�Ծ���ÿ��Ԫ�ض���ֵΪ��1,3������һ��ͨ���е�ֵ����1���ڶ���ͨ���е�ֵ����3.*/