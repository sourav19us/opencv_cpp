#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	string path = "Resource/car.png";
	Mat img = imread(path);

	if (img.empty()) {

		cout << "cuold not open or find the image" << endl;
		cin.get();// wait for any key press
		return -1;
	}

	Mat imgBrighnessHigh50;


	Mat imgBrighnessLow50;


	img.convertTo(imgBrighnessHigh50, -1, 1, 50);
	img.convertTo(imgBrighnessLow50, -1, 1, -50);

	imshow("imgBrighnessHigh50", imgBrighnessHigh50);
	imshow("imgBrighnessLow50", imgBrighnessLow50);
	imshow("image", img);

	waitKey(0);
	destroyAllWindows();

	return 0;
}