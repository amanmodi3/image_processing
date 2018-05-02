#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int isvalid(Mat image,int i, int j)
{
  if (i < 0 || j < 0 || i >= image.rows || j >= image.cols) return 0;
	else return 1;
}

int main()
{
  int t;
  float r;
	int low=15;
	int high=20;
  Mat image=imread("/home/kizontech/A3.png",0);
	Mat img(image.rows,image.cols,CV_8UC1,Scalar(0));
	Mat img2(image.rows,image.cols,CV_8UC1,Scalar(0));
  float diag=sqrt(pow(image.rows,2)+pow(image.cols,2))+1;
  Mat hough(2*diag+1,180,CV_8UC1,Scalar(0));

  Mat recovery(image.rows,image.cols,CV_8UC1,Scalar(0));
  //imshow("Original",image);
	GaussianBlur(image,img,Size(11,11),1.5,1.5);

	namedWindow("Hysterisis_Constraint",WINDOW_AUTOSIZE);
	createTrackbar("Low_limit","Hysterisis_Constraint",&low,255);
	createTrackbar("High_limit","Hysterisis_Constraint",&high,255);
  createTrackbar("Intensity","Hysterisis_Constraint",&t,255);


	while(1)
	{
    Mat hough(2*diag+1,180,CV_8UC1,Scalar(0));
		Canny(img,img2,low,high);
    imshow("Canny",img2);
    for(int i=0;i<img2.rows;i++)
  	{
  		for(int j=0; j<img2.cols; j++)
  		{
        if(img2.at<uchar>(i,j)==255)
        {
          for(int u=0;u<180;u++)
          {
            r=j*cos(u*M_PI/180)+i*sin(u*M_PI/180);
            hough.at<uchar>((int)r,u)+=1;
            r=r+diag;
          }
        }
      }
    }



  vector<Point> p;
  Point temp;
  for(int i=0;i<hough.rows;i++)
  {
    for(int j=0;j<hough.cols;j++)
    {
      int counter = 0;
      for(int k=i-1; k<i+2;k++)
      {
        for(int l=j-1; l<j+2;l++)
        {
          if(isvalid(hough,k,l) && !(k==i && l==j))
          {
            if( hough.at<uchar>(k,l)>hough.at<uchar>(i,j) )
            {
              counter=1;
            }
          }
        }
      }
      if(counter==0 && hough.at<uchar>(i,j)>t)
      {
        temp.x=j,temp.y=i;
        p.push_back(temp);
      }
    }
  }

  for(int i=0;i<hough.rows;i++)
  {
    for(int j=0;j<hough.cols;j++)
    {
      for( int z=0; z<p.size(); z++)
      {
        if(j*cos(p[z].x)+i*sin(p[z].x)==p[z].y-diag)
        {
          recovery.at<uchar>(i,j)=255;
            cout<<"hello"<<endl;
        }
        else
        {
          break;
        }

      }

     }
   }


  // namedWindow("Hough Transform",WINDOW_NORMAL);
  // imshow("Hough Transform",hough);
  namedWindow("Recovery",WINDOW_NORMAL);
  imshow("Recovery",recovery);
  //cout<<p.size()<<endl;
  waitKey(50);
}
}
