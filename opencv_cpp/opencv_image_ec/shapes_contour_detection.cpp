#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void getContours(Mat imgD,Mat img) {


	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;


	findContours(imgD, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	drawContours(img, contours, -1, Scalar(25, 0, 255), 2);

	int area;

	for (int i = 0; i < contours.size(); i++) {
		
		area = contourArea(contours[i]);
		//cout << area << endl;

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		string objectType;

		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i],0.02*peri,true); 
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

			int objCor = (int)conPoly[i].size();

			if (objCor == 3) {
				objectType = "Triangle";
			}

			putText(img, objectType, {boundRect[i].x,boundRect[i].y-5}, FONT_HERSHEY_DUPLEX, 5, Scalar(250, 50, 50), 5);

		}
	}

}


void main() {

	string path = "Resource/shapes1.png";
	Mat img = imread(path);

	Mat imagGray;

	Mat imgBlure; 

	Mat imgCanny;

	Mat imgDilate;

	cvtColor(img, imagGray, COLOR_BGR2GRAY);

	GaussianBlur(imagGray, imgBlure, Size(7, 7), 5, 0);

	Canny(imgBlure, imgCanny, 50, 50);

	Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));

	dilate(imgCanny, imgDilate, kernal);

	getContours(imgDilate,img);

	imshow("image", img);
	/*imshow("image_Gray", imagGray);
	imshow("image_Blure", imgBlure);
	imshow("image_Canny", imgCanny);
	imshow("image_dilate", imgDilate);
	//imshow("image_erode", imgErode); */
	waitKey(0);
}