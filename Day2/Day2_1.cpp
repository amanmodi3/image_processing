//With fixed input
//COLOUR EXTRACTION

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat img=imread("/home/kizontech/fruits.png",1);
  Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0; i<img.rows; i++)
  {
    for(int j=0; j< img.cols; j++)
    {
      if(img.at<Vec3b>(i,j)[0]<50 && img.at<Vec3b>(i,j)[1]<50 && img.at<Vec3b>(i,j)[2]>80)
      {
        img2.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);
      }
    }
  }
  imshow("IMAGE",img);
  imshow("Extrated",img2);
  waitKey(0);
}
