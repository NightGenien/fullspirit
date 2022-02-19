#include <opencv2/core/core.hpp>              
#include <opencv2/highgui/highgui.hpp>              
#include <opencv2/imgproc/imgproc.hpp>             
#include <iostream>            
using namespace std;
using namespace cv;
int main()
{
	//1��ȡԴͼ�񲢼��ͼ���Ƿ��ȡ�ɹ�    
	Mat srcimage = imread("b.png");
	if (!srcimage.data)
	{
		cout << "��ȡͼƬ����������������ȷ·����\n";
		system("pause");
		return -1;
	}
	imshow("ԭͼ��", srcimage);    
	Mat srcgray;
	cvtColor(srcimage, srcgray, COLOR_RGB2GRAY);
	imshow("�Ҷ�ͼ", srcgray);
	//����inRange()������ͼ���ֵ��
	Mat dstimage;
	inRange(srcgray, Scalar(65,65,65), Scalar(95, 95, 95), dstimage);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat outimage;
	dilate(srcgray, outimage, element);
	Mat element1 = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat outimage2;
	Mat outimage1;
	Mat outimage3;
	erode(srcgray, outimage2, element1);
	//������,�ȸ�ʴ������
	erode(outimage, outimage1, element1);
	//�����㣬�����ͺ�ʴ
	dilate(outimage2, outimage3, element);
	imshow("��ֵ��", dstimage);
	imshow("���Ͳ���", outimage);
	imshow("��ʴ����", outimage2);
	imshow("������", outimage1);
	imshow("������",outimage3);
	waitKey(0);
	return 0;
}//��Ҫ�ǽ���������ֵ�ڵ�����ֵ����Ϊ��ɫ��255������������ֵ�����ڵ�����ֵ����Ϊ��ɫ��0�����ù���������֮��������˫��ֵ������