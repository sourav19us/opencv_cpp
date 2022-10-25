#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	string path = "Resource/song.mp4";

	VideoCapture cap(path);

	if (cap.isOpened() == false) {

		cout << "Cannot open the video file" << endl;
		cin.get();
		return -1;
	}

	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "found the end of the video" << endl;
			break;
		}

		Mat frameBrighnessHigh50;
		frame.convertTo(frameBrighnessHigh50, -1, 1, 50);//increase the brightness by 50

		imshow("fram BrighnessHigh50", frameBrighnessHigh50);

		if (waitKey(10) == 27) {
			cout << "esc key is pressed by user.stopping the video" << endl;
			break;
		}
	}



	return 0;
}