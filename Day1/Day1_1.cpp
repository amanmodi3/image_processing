#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat image(720,1280,CV_8UC3,Scalar(0,200,200));
  imshow("IMAGEs",image);
  waitKey(0);
}
