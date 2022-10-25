#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void main() {

	string path = "Resource/image.jpg";

	Mat img = imread(path);

	Mat imgResize;

	Mat imgCrop;

	//cout << img.size() << endl;
	//resize(img, imgResize, Size(640,540));
	resize(img, imgResize, Size(),0.5,0.5);

	//>>>>>>>>>>> crop image <<<<<<<<<<<

	Rect roi(10, 90, 60, 800);
	imgCrop = img(roi);


	imshow("image", img);
	imshow("image_Resize", imgResize);
	imshow("image_Crop", imgCrop);

	waitKey(0);

	//return 0;
}