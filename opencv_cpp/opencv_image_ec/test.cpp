#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;


// >>>>>>>>>>>>>>>>>>>>> image <<<<<<<<<<<<<<<<<<
/*
int main() {

	string path = "Resource/image.jpg";
	Mat img = imread(path);

	imshow("imahe", img);
	waitKey(0);

	return 0;
}
*/

// >>>>>>>>>>>>>>>>> video <<<<<<<<<<<<<<<<<<<<
/*
int main() {

	string path = "Resource/song.mp4";

	VideoCapture cap(path);

	Mat img;

	while(true) {
		cap.read(img);

		imshow("video", img);
		waitKey(1);

	}

	return 0;
}
*/

//>>>>>>>>>>>>>>>> webcam <<<<<<<<<<<<<<

int main() {

	//string path = "Resource/song.mp4";

	VideoCapture cap(0);

	Mat img;

	while (true) {
		cap.read(img);

		imshow("video", img);
		waitKey(1);

	}

	return 0;
}
