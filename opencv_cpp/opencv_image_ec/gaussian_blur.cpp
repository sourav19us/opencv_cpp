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

    //Blur the image with 3x3 kernel
    Mat image_blurred_with_3x3_kernel;

    GaussianBlur(img, image_blurred_with_3x3_kernel, Size(3, 3),0);

    //Blur the image with 5x5 kernel
    Mat image_blurred_with_5x5_kernel;

    GaussianBlur(img, image_blurred_with_5x5_kernel, Size(5, 5),0);


    imshow("image", img);
    imshow(" image_blurred_with_3x3_kernel", image_blurred_with_3x3_kernel);
    imshow(" image_blurred_with_5x5_kernel", image_blurred_with_5x5_kernel);

    waitKey(0);
    destroyAllWindows();

    return 0;
}