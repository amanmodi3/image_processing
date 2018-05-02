//Noise Reduction using Gaussian

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
  Mat image=imread("/home/kizontech/lena.png",0);
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
      int p=0;
      for(int k=-1;k<2;k++)
      {
        for(int l=-1;l<2;l++)
        {
          if((k==-1 && l==-1)||(k==1 && l==1)||(k==-1 && l==1)||(k==1 && l==-1)) m=16;
          if((k==0 && l==-1)||(k==1 && l==0)||(k==-1 && l==0)||(k==0 && l==1)) m=8;
          if(k==0 && l==0) m=4;
          p+=image.at<uchar>(i+k,j+l)/m;
        }
      }
      img.at<uchar>(i,j)=p;
    }
    }
  }
  imshow("Blur_Image",img);
  waitKey(0);
}
