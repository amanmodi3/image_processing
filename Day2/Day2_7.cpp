//NON LINEAR reducton using  MEDIAN

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace cv;


int main()
{
  int A[9];
  Mat image=imread("/home/kizontech/veg.jpg",0);
  int m;
  imshow("Original",image);
  Mat img(image.rows,image.cols,CV_8UC1,Scalar(0));
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
        int count=0;
        for(int k=-1;k<2;k++)
        {
          for(int l=-1;l<2;l++)
          {
            A[count]=image.at<uchar>(i+k,j+l);
            count++;
          }
        }
        sort(A,A+8);
        img.at<uchar>(i,j)=A[4];
      }

    }
  }
  imshow("Blur_Image",img);
  waitKey(0);
}
