#include <opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main() {
	//��������
	std::vector<Mat> channels;
	Mat imageBlueChannel;
	Mat imageGreenChannel;
	Mat imageRedChannel;
	Mat srcImage = imread("bilibili.jpg");//flag=1��������ͨ��ͼ��
	if (!srcImage.data) {
		std::cout << "ͼ�����ʧ�ܣ�" << std::endl;
		exit(1);
	}
	//��һ����ͨ��ͼ��ת��Ϊ������ͨ��ͼ��
	split(srcImage, channels);
	imageBlueChannel = channels.at(0);
	imageGreenChannel = channels.at(1);
	imageRedChannel = channels.at(2);
	//�ֱ���ʾ����ĵ�ͨ��ͼ��
	imshow("ԭͼ��", srcImage);
	imshow("��ɫͨ��ͼ��", imageBlueChannel);
	imshow("��ɫͨ��ͼ��", imageGreenChannel);
	imshow("��ɫͨ��ͼ��", imageRedChannel);

	waitKey(0);
	return 0;
}
//��һ��������src����m��������Ҫ���з���Ķ�ͨ�����飻

//�ڶ���������mv���������  ����  �����vector������