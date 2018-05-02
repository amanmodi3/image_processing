//Edge Detection both Gx and Gy

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main()
{
	int limit=0;
  Mat image=imread("/home/kizontech/lenaTest3.jpg",0);
	Mat img(image.rows,image.cols,CV_8UC1,Scalar(255));
  imshow("Original",image);

	namedWindow("Limit",WINDOW_AUTOSIZE);
	createTrackbar("Threshold","Limit",&limit,255);
	int m,Gx,Gy,G;
	while(1)
	{
	for(int i=1;i<(image.rows-1);i++)
	{
		for(int j=1;j<(image.cols-1);j++)
		{
			int p=0;
			for(int k=-1;k<2;k++)
			{
				for(int l=-1;l<2;l++)
				{
					if((k==-1 && l==-1)||(k==1 && l==-1)) m=-1;
					else if((k==1 && l==1)||(k==-1 && l==1)) m=1;
          else if((k==0 && l==1)) m=2;
					else if((k==0 && l==-1)) m=-2;
					else if((k==1 && l==0)||(k==-1 && l==0)||(k==0 && l==0)) m=0;
					p+=m*image.at<uchar>(i+k,j+l);
				}
			}
			Gx=(abs(p)/4);

			int q=0;
			for(int k=-1;k<2;k++)
			{
				for(int l=-1;l<2;l++)
				{
					if((k==-1 && l==-1)||(k==1 && l==-1)) m=-1;
					else if((k==1 && l==1)||(k==-1 && l==1)) m=1;
          else if((k==0 && l==1)) m=2;
					else if((k==0 && l==-1)) m=-2;
					else if((k==1 && l==0)||(k==-1 && l==0)||(k==0 && l==0)) m=0;
					q+=m*image.at<uchar>(i+l,j+k);
				}
			}
			Gy=(abs(q)/4);
			G=sqrt(pow(Gx,2)+pow(Gy,2));
			if(G>limit) img.at<uchar>(i,j)=255;
			else img.at<uchar>(i,j)=0;

		}
	}
	imshow("Modified",img);
	waitKey(50);
	}

}
