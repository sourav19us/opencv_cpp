#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

// >>>>>>>>>>>>>>>>>>>>> image <<<<<<<<<<<<<<<<<<
int main() {

	string path = "Resource/image1.jpg";
	Mat img = imread(path);

	Mat imagGray;

	Mat imgBlure;

	Mat imgCanny;

	Mat imgDilate;

	Mat imgErode;

	cvtColor(img, imagGray, COLOR_BGR2GRAY);

	GaussianBlur(img, imgBlure, Size(7,7),5,0);

	Canny(imgBlure, imgCanny, 50, 50);


	Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));

	dilate(imgCanny, imgDilate,kernal );// 

	erode(imgDilate, imgErode, kernal);

	imshow("image", img);
	imshow("image_Gray", imagGray);
	imshow("image_Blure", imgBlure);
	imshow("image_Canny", imgCanny);
	imshow("image_dilate", imgDilate);
	imshow("image_erode", imgErode);
	waitKey(0);

	return 0;
}