#include <opencv2/core/core.hpp>              
#include <opencv2/highgui/highgui.hpp>              
#include <opencv2/imgproc/imgproc.hpp>             
#include <iostream>            
using namespace std;
using namespace cv;
int main()
{
	//1读取源图像并检查图像是否读取成功    
	Mat srcimage = imread("b.png");
	if (!srcimage.data)
	{
		cout << "读取图片错误，请重新输入正确路径！\n";
		system("pause");
		return -1;
	}
	imshow("原图像", srcimage);    
	Mat srcgray;
	cvtColor(srcimage, srcgray, COLOR_RGB2GRAY);
	imshow("灰度图", srcgray);
	//利用inRange()函数对图像二值化
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
	//开运算,先腐蚀后膨胀
	erode(outimage, outimage1, element1);
	//闭运算，先膨胀后腐蚀
	dilate(outimage2, outimage3, element);
	imshow("二值化", dstimage);
	imshow("膨胀操作", outimage);
	imshow("腐蚀操作", outimage2);
	imshow("开运算", outimage1);
	imshow("闭运算",outimage3);
	waitKey(0);
	return 0;
}//主要是将在两个阈值内的像素值设置为白色（255），而不在阈值区间内的像素值设置为黑色（0），该功能类似于之间所讲的双阈值化操作