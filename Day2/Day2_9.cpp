//Erosion Dilation

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void erosion(Mat image,Mat img)
{
  for(int i=0;i<(image.rows);i++)
  {
    for(int j=0;j<(image.cols);j++)
    {
      if(i==0 || i==image.rows-1 || j==0 || j==image.cols-1)
      {
        img.at<uchar>(i,j)=image.at<uchar>(i,j);
      }
      else
      {
        for(int k=-1;k<2;k++)
        {
          for(int l=-1;l<2;l++)
          {
            if(image.at<uchar>(i+k,j+l)==0)
            {
              img.at<uchar>(i,j)=0;
            }
          }
        }
      }
    }
  }
}

void dilation(Mat image,Mat img)
{
  for(int i=0;i<(image.rows);i++)
  {
    for(int j=0;j<(image.cols);j++)
    {
      if(i==0 || i==image.rows-1 || j==0 || j==image.cols-1)
      {
        img.at<uchar>(i,j)=image.at<uchar>(i,j);
      }
      else
      {
        for(int k=-1;k<2;k++)
        {
          for(int l=-1;l<2;l++)
          {
            if(image.at<uchar>(i+k,j+l)==255)
            {
              img.at<uchar>(i,j)=255;
            }
            else
            {
              img.at<uchar>(i,j)=image.at<uchar>(i,j);
            }
          }
        }
      }
    }
  }
}


int main()
{
  Mat image=imread("/home/kizontech/erosion4.png",0);
  imshow("Original",image);
  Mat img=image.clone();
  dilation(image,img);
  Mat img2=img.clone();
  erosion(img,img2);
  imshow("Rectified_Image",img2);
  waitKey(0);
}
