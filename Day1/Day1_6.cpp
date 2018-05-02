#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat img=imread("/home/kizontech/scenery.jpg",0);

  imshow("image",img);
  waitKey(0);
}
