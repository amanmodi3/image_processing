#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat image(800,800,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<640000; i++)
  {
    if((d/100)%2==(c/100)%2)
    {
      image.at<Vec3b>(c,d)[0]=255;
      image.at<Vec3b>(c,d)[1]=255;
      image.at<Vec3b>(c,d)[2]=255;
    }
  }
  imshow("IMAGE",image);
  waitKey(0);
}
