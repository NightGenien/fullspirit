#include <opencv2/opencv.hpp>  
#include <iostream>
using namespace cv;
int main() {
	Mat srcmat,deepmat,shallowmat;
	srcmat = imread("bilibili.jpg");
	shallowmat = srcmat;//ǳ�������߹���һ���ڴ��ı�
	srcmat.copyTo(deepmat);
	deepmat = srcmat.clone();
	imshow("srcmat", srcmat);
	imshow("shallowmat", shallowmat);
	imshow("deepmat", deepmat);
	waitKey(0);

}