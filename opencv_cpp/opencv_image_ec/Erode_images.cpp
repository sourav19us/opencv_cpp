#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main() {

	string path = "Resource/image1.jpg";
	Mat img = imread(path);

    // Check for failure
    if (img.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }
    //Erode the image with 3x3 kernel
    Mat image_eroded_with_3x3_kernel;
    erode(img, image_eroded_with_3x3_kernel, getStructuringElement(MORPH_RECT, Size(3, 3)));
    
    imshow("image", img);
    imshow("image image_eroded_with_3x3_kernel", image_eroded_with_3x3_kernel);

    waitKey(0);
    destroyAllWindows();

	return 0;
}

//https://www.opencv-srf.com/p/introduction.html#:~:text=OpenCV%20is%20an%20open%20source,even%20for%20your%20commercial%20applications.