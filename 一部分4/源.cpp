#include <opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main() {
	//类型声明
	std::vector<Mat> channels;
	Mat imageBlueChannel;
	Mat imageGreenChannel;
	Mat imageRedChannel;
	Mat srcImage = imread("bilibili.jpg");//flag=1，载入三通道图像
	if (!srcImage.data) {
		std::cout << "图像读入失败！" << std::endl;
		exit(1);
	}
	//把一个三通道图像转化为三个单通道图像
	split(srcImage, channels);
	imageBlueChannel = channels.at(0);
	imageGreenChannel = channels.at(1);
	imageRedChannel = channels.at(2);
	//分别显示分离的单通道图像
	imshow("原图像", srcImage);
	imshow("蓝色通道图像", imageBlueChannel);
	imshow("绿色通道图像", imageGreenChannel);
	imshow("红色通道图像", imageRedChannel);

	waitKey(0);
	return 0;
}
//第一个参数：src或者m填我们需要进行分离的多通道数组；

//第二个参数：mv填输出数组  或者  输出的vector容器。