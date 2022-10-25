#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main() {

	// blank image
	Mat img(512,512,CV_8UC3,Scalar(250,250,250));

	circle(img, Point(256, 256), 150, Scalar(250, 25, 25),5 );

	rectangle(img,Point(130,226),Point(382,286), Scalar(50, 50, 255), 5);

	line(img, Point(130, 296), Point(382, 356), Scalar(50, 150, 150), 2);

	putText(img, "hello !",Point(137,262),FONT_HERSHEY_DUPLEX,5,Scalar(250,50,50),5);

	imshow("image", img);

	waitKey(0);

	return 0;
}