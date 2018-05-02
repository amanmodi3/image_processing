//EXTRACTION Using TrackBar

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
  int b,g,r;
  namedWindow("Extraction",WINDOW_AUTOSIZE);
  createTrackbar("Blue_Controller","Extraction",&b,255);
  createTrackbar("Green_Controller","Extraction",&g,255);
  createTrackbar("Red_Controller","Extraction",&r,255);
  while(1)
  {
    for(int i=0; i<img.rows; i++)
    {
      for(int j=0; j< img.cols; j++)
      {
        if(img.at<Vec3b>(i,j)[0]<b && img.at<Vec3b>(i,j)[1]<g && img.at<Vec3b>(i,j)[2]>r)
        {
          img2.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);
        }
        else
        {
          img2.at<Vec3b>(i,j)[0]=0;
          img2.at<Vec3b>(i,j)[1]=0;
          img2.at<Vec3b>(i,j)[2]=0;
        }
      }
    }
    imshow("Extrated",img2);
    waitKey(50);
  }
  return 0;
}
