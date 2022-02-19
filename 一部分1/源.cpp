#include <opencv2/opencv.hpp>  
#include <iostream>
void grayImageShow(cv::Mat& input, cv::Mat& output)
{
	for (int i = 0; i < input.rows; ++i)
	{
		for (int j = 0; j < input.cols; ++j)//每一个像素点的计算
		{
			output.at<uchar>(i, j) = cv::saturate_cast<uchar>(input.at<cv::Vec3b>(i, j)[0] + input.at<cv::Vec3b>(i, j)[1] + input.at<cv::Vec3b>(i, j)[2])/3;
		}
	}
	cv::imshow("dst", output);
}

int main(void)
{
	cv::Mat src, gray, dst;

	gray = cv::imread("bilibili.jpg", cv::IMREAD_GRAYSCALE);//由imread()得到的灰度图像
	src = cv::imread("bilibili.jpg");
	dst.create(src.rows, src.cols, CV_8UC1);

	cv::imshow("scr", src);
	cv::imshow("gray", gray);
	grayImageShow(src, dst);
	cv::waitKey(0);
	return 0;
}
/*RGB→HSV
Mat rgb, hsv;
cvtColor(rgb, hsv, COLOR_BGR2HSV);

RGB
image为BGR类型
B = image.at<Vec3b>(y, x)[0];
G = image.at<Vec3b>(y, x)[1];
R = image.at<Vec3b>(y, x)[2];

HSV
image为HSV类型
H = image.at<Vec3b>(y, x)[0];
S = image.at<Vec3b>(y, x)[1];
V = image.at<Vec3b>(y, x)[2];
*/