#include <opencv2/opencv.hpp>  
#include <iostream>
using namespace cv;
int main() {
	Mat srcmat,deepmat,shallowmat;
	srcmat = imread("bilibili.jpg");
	shallowmat = srcmat;//浅复制两者公用一块内存会改变
	srcmat.copyTo(deepmat);
	deepmat = srcmat.clone();
	imshow("srcmat", srcmat);
	imshow("shallowmat", shallowmat);
	imshow("deepmat", deepmat);
	waitKey(0);

}