//Using TrackBar

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
  Mat img=imread("/home/kizontech/scenery.png",0);
  int i;
  namedWindow("Threshold",WINDOW_AUTOSIZE);
  creatTracker("Binary_Image","Threshold",&i,255)
  Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));

}
