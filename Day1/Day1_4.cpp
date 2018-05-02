#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat img=imread("/home/kizontech/joker.jpg",1);
  imshow("original",img);
  Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols; j++)
    {
      img2.at<Vec3b>(i,j)=img.at<Vec3b>(img.rows,img.cols-j-1);
    }
  }
  imshow("image",img2);
  waitKey(0);
}
