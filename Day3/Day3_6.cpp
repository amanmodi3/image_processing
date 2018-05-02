//Creating binary image

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int binary(Mat img1, Mat img2)
{
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0; j<img1.cols; j++)
		{
			if(img1.at<uchar>(i,j)>=177) img2.at<uchar>(i,j)=255;
			if(img1.at<uchar>(i,j)<177) img2.at<uchar>(i,j)=0;
		}
	}

}


int main()
{
  Mat image=imread("/home/kizontech/lenaTest3.jpg",0);
	Mat img(image.rows,image.cols,CV_8UC1,Scalar(255));
  imshow("Original",image);
	binary(image,img);
	imshow("Modified",img);
	waitKey(0);

}
