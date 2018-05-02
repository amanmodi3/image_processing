//Object Detection using DFS

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int binary(Mat img1, Mat img2)
{
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0; j<img1.cols; j++)
		{
			if(img1.at<uchar>(i,j)>=177) img2.at<uchar>(i,j)=255;
			else if(img1.at<uchar>(i,j)<177) img2.at<uchar>(i,j)=0;
		}
	}

}

int isvalid(Mat image,int i, int j)
{

	if (i < 0 || j < 0 || i >= image.rows || j >= image.cols) return 0;
	else return 1;
}

int DFS_visit(Mat image,Mat visited,int i, int j,int count)
{
	// cout<<"1"<<endl;
  for(int k=i-1; k<i+2;k++)
  {
    for(int l=j-1; l<j+2;l++)
    {
      if(isvalid(image,k,l))
      {
        if((visited.at<uchar>(k,l)==0) && image.at<uchar>(k,l)==255)
        {
					visited.at<uchar>(k,l)=200/count;
          DFS_visit(image,visited,k,l,count);

        }
      }
    }
  }
	return 0;
}

int main()
{
  Mat img=imread("/home/kizontech/Binary1.png",0);
  imshow("Original",img);
	Mat image(img.rows,img.cols,CV_8UC1,Scalar(0));
	binary(img,image);
  Mat visited(image.rows,image.cols,CV_8UC1,Scalar(0));
  int count=1;
  for(int i=0;i<image.rows;i++)
  {
    for(int j=0; j<image.cols;j++)
    {
      if(visited.at<uchar>(i,j)==0 && image.at<uchar>(i,j)==255)
      {
				visited.at<uchar>(i,j)=200/count;
        DFS_visit(image,visited,i,j,count);
				count++;
				cout<<count<<endl;
      }
    }
  }
  imshow("Modified",visited);
  waitKey(0);
}
