#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat img=imread("/home/kizontech/joker.jpg",1);
  Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
  Mat img3(img.rows,2*img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols; j++)
    {
      img2.at<Vec3b>(i,j)=img.at<Vec3b>(i,img.cols-j-1);
    }
  }
  for(int c=0; c<img.rows; c++)
  {
    for(int d=0; d<(2*img.cols); d++)
    {
      if(d<img.cols)
      {
        img3.at<Vec3b>(c,d)=img.at<Vec3b>(c,d);
      }
      else
      {
        img3.at<Vec3b>(c,d)=img2.at<Vec3b>(c,d-img.cols);
      }
    }
  }
  imshow("image",img3);
  waitKey(0);
}
