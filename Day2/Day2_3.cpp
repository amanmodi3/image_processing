//  Controlling Zoom Using TrackBar

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
  Mat img=imread("/home/kizontech/apple.png",1);
  imshow("Original",img);
  int n;
  namedWindow("Zooming",WINDOW_AUTOSIZE);
  createTrackbar("Times_Controller","Zooming",&n,6);
while(1)
{
  Mat img2(n*img.rows,n*img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      for(int l=0;l<n;l++)
      {
        for(int k=0;k<n;k++)
        {
          img2.at<Vec3b>(n*i+k,j*n+l)=img.at<Vec3b>(i,j);
        }
      }
    }
  }
  imshow("Zoomed",img2);
  waitKey(50);
}
  return 0;

}
