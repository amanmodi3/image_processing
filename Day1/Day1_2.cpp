#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat image(400,400,CV_8UC3,Scalar(0,0,0));
  for(int i=1;i<401;i++)
  {
    for(int j=1;j<401;j++)
    {
      if(i<(401-j))
      {
        image.at<Vec3b>(j,i)[2]=255;
      }
      else
      {
        image.at<Vec3b>(j,i)[1]=255;
      }

    }
      waitKey(1);
  }
  imshow("IMAGE",image);

}
