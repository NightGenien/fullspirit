#include <opencv2/opencv.hpp>  
#include <iostream>
void grayImageShow(cv::Mat& input, cv::Mat& output)
{
	for (int i = 0; i < input.rows; ++i)
	{
		for (int j = 0; j < input.cols; ++j)//ÿһ�����ص�ļ���
		{
			output.at<uchar>(i, j) = cv::saturate_cast<uchar>(input.at<cv::Vec3b>(i, j)[0] + input.at<cv::Vec3b>(i, j)[1] + input.at<cv::Vec3b>(i, j)[2])/3;
		}
	}
	cv::imshow("dst", output);
}

int main(void)
{
	cv::Mat src, gray, dst;

	gray = cv::imread("bilibili.jpg", cv::IMREAD_GRAYSCALE);//��imread()�õ��ĻҶ�ͼ��
	src = cv::imread("bilibili.jpg");
	dst.create(src.rows, src.cols, CV_8UC1);

	cv::imshow("scr", src);
	cv::imshow("gray", gray);
	grayImageShow(src, dst);
	cv::waitKey(0);
	return 0;
}
/*RGB��HSV
Mat rgb, hsv;
cvtColor(rgb, hsv, COLOR_BGR2HSV);

RGB
imageΪBGR����
B = image.at<Vec3b>(y, x)[0];
G = image.at<Vec3b>(y, x)[1];
R = image.at<Vec3b>(y, x)[2];

HSV
imageΪHSV����
H = image.at<Vec3b>(y, x)[0];
S = image.at<Vec3b>(y, x)[1];
V = image.at<Vec3b>(y, x)[2];
*/