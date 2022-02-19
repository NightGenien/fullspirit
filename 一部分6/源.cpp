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
	Mat img = Mat::zeros(Size(w, w), CV_8UC3); //建一个长宽500的黑色画布

	const int size = 5;
	Point points[1][size];
	for (int i = 0; i < size; i++) {
		points[0][i] = Point(w / (i + 1), w / (size - i));
	}
	const Point* ppt[1] = { points[0] };
	int npt[] = { size };
	fillPoly(img, ppt, npt, 1, Scalar(255, 128, 0), 8, 0); //画多边形 
	circle(img, Point(w / 2, w / 2), 10, Scalar(0, 0, 255), 3, 0); //画圆
	line(img, Point(3, 4), Point(100, 220), Scalar(0, 255, 0), 5, LINE_8); //画线
	ellipse(img, Point(w / 2, w / 2), Size(w / 4, w / 16), 90, 0, 360, Scalar(255, 0, 0), 2, 0); //画椭圆

	rectangle(img, Point(0, 7 * w / 8), Point(400, 350), Scalar(40, 25, 142), FILLED, LINE_8); //画方形
	imshow("drawTest", img);
}

/*typedef struct Scalar
{
	double val[4];
}Scalar;
Mat M(7,7,CV_32FC2,Scalar(1,3));
上面的代码表示：创建一个2通道，且每个通道的值都为（1,3），深度为32，7行7列的图像矩阵。CV_32F表示每个元素的值的类型为32位浮点数，
C2表示通道数为2，Scalar（1,3）表示对矩阵每个元素都赋值为（1,3），第一个通道中的值都是1，第二个通道中的值都是3.*/