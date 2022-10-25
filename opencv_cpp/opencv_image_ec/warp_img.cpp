#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

float w = 450, h = 250;

Mat matrix, imgWarp;

void main() {

	string path = "Resource/image1.jpg";

	Mat img = imread(path);

	Point2f src[4] = { {25,25},{500,25},{25,100},{500,100} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f} ,{0.0f,h} ,{w,h} };

	matrix = getPerspectiveTransform(src, dst);

	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++) {

		circle(img,src[i],10,Scalar(0,0,255),-5);
	}

	imshow("image", img);
	imshow("image_warp", imgWarp);
	waitKey(0);
}