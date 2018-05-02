//Greyscale Histogram

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  int A[256]={0};
  Mat image=imread("/home/kizontech/scenery.jpg",0);
  Mat img(512,256,CV_8UC1,Scalar(255));
  Mat img2(512,256,CV_8UC1,Scalar(255));
  imshow("Original",image);
  for(int i=0;i<image.rows;i++)
  {
    for(int j=0;j<image.cols; j++)
    {
      for(int k=0;k<=255;k++)
      {
        if(image.at<uchar>(i,j)==k) A[k]+=1;
      }
    }
  }
  for(int p=0;p<256;p++)
  {
    for(int r=0;r<(A[p]/200);r++)
    {
      img.at<uchar>(r,p)=0;
    }

  }

  for(int x=0;x<512;x++)
  {
    for(int y=0;y<256; y++)
    {
      img2.at<uchar>(x,y)=img.at<uchar>(511-x,y);
    }
  }

  imshow("Histogram",img2);
  waitKey(0);
}
