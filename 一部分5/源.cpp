#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{
	//1.������ͷ������Ƶ
	VideoCapture cap(0);
	//2.ѭ����ʾÿһ֡
	while (1)
	{
		Mat cam;
		cap >> cam;//��ȡ��ǰ֡ͼ��
		imshow("���", cam);//��ʾ��ǰ֡ͼ��
		waitKey(30);//��ʱ30��
	}
	return 0;
}