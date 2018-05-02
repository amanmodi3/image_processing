//Edge Detection with Canny and GaussianBlur

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main()
{
	int low=15;
	int high=20;
  Mat image=imread("/home/kizontech/lenaTest3.jpg",0);
	Mat img(image.rows,image.cols,CV_8UC1,Scalar(255));
	Mat img2(image.rows,image.cols,CV_8UC1,Scalar(255));
  imshow("Original",image);
	GaussianBlur(image,img,Size(11,11),1.5,1.5);

	namedWindow("Hysterisis_Constraint",WINDOW_AUTOSIZE);
	createTrackbar("Low_limit","Hysterisis_Constraint",&low,255);
	createTrackbar("High_limit","Hysterisis_Constraint",&high,255);

	while(1)
	{
		Canny(img,img2,low,high);
		//imshow("Gaussian_Blur",img);
		imshow("Canny",img2);
		waitKey(50);
	}
}
