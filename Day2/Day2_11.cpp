//BGR Histogram

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  int B[256]={0};
  int G[256]={0};
  int R[256]={0};
  Mat image=imread("/home/kizontech/joker.jpg",1);

  Mat imgb(512,256,CV_8UC1,Scalar(255));
  Mat imgb2=imgb.clone();

  Mat imgg(512,256,CV_8UC1,Scalar(255));
  Mat imgg2=imgg.clone();

  Mat imgr(512,256,CV_8UC1,Scalar(255));
  Mat imgr2=imgr.clone();

  imshow("Original",image);
  for(int i=0;i<image.rows;i++)
  {
    for(int j=0;j<image.cols; j++)
    {
      for(int k=0;k<=255;k++)
      {
        if(image.at<Vec3b>(i,j)[0]==k) B[k]+=1;
        if(image.at<Vec3b>(i,j)[1]==k) G[k]+=1;
        if(image.at<Vec3b>(i,j)[2]==k) R[k]+=1;
      }
    }
  }
  for(int p=0;p<256;p++)
  {
    for(int r=0;r<(B[p]/50);r++)
    {
      imgb.at<uchar>(r,p)=0;
    }
    for(int r=0;r<(G[p]/50);r++)
    {
      imgg.at<uchar>(r,p)=0;
    }
    for(int r=0;r<(R[p]/50);r++)
    {
      imgr.at<uchar>(r,p)=0;
    }

  }

  for(int x=0;x<512;x++)
  {
    for(int y=0;y<256; y++)
    {
      imgb2.at<uchar>(x,y)=imgb.at<uchar>(511-x,y);
      imgg2.at<uchar>(x,y)=imgg.at<uchar>(511-x,y);
      imgr2.at<uchar>(x,y)=imgr.at<uchar>(511-x,y);
    }
  }

  imshow("BLUE_Histogram",imgb2);
  imshow("GREEN_Histogram",imgg2);
  imshow("RED_Histogram",imgr2);
  waitKey(0);
}
