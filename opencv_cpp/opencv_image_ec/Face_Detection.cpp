#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void main() {

	string path = "Resource/face.jpg";

	Mat img = imread(path);

	CascadeClassifier faceCascaade;

	faceCascaade.load("Resource/haarcascade_frontalface_default.xml");

	if (faceCascaade.empty()) {
		cout << "XML file not loaded" << endl;
	}

	vector<Rect> faces;

	faceCascaade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0;i< faces.size(); i++) {
		rectangle(img, faces[i].tl(),faces[i].br(), Scalar(50, 50, 255), 5);
	}

	imshow("image", img);
	waitKey(0);
}
