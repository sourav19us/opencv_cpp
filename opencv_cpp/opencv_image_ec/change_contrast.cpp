#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	string path = "Resource/car.png";
	Mat img = imread(path);

	if (img.empty()) {

		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	Mat imageContrastHigh2;
	img.convertTo(imageContrastHigh2, -1, 2, 0); //increase the contrast by 2

	Mat imageContrastLow0_5;
	img.convertTo(imageContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

	imshow("image", img);
	imshow("image contrast high", imageContrastHigh2);
	imshow("image contrast Low", imageContrastLow0_5);

	waitKey();
	destroyAllWindows();

	return 0;
}