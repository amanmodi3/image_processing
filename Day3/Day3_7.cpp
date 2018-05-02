// BFS Object Detection

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include <queue>


using namespace std;
using namespace cv;


void BFS(Mat image, int i, int j, int count)
{
	queue<int> que;
	image.at<uchar>(i,j)=255/count;
	que.push(i);
	que.push(j);

	while(!que.empty())
	{
		i=que.front();
		que.pop();
		j=que.front();
		que.pop();
		for(int p=-1;p<=1;p++)
		{
			for(int q=-1;q<=1;q++)
			{

				if((i+p>0&&(i+p)<image.rows-1&&(j+q)>0&&(j+q)<image.cols-1)&&(image.at<uchar>(i+p,j+q)==255))
					{
						que.push(i+p);
						que.push(j+q);
						image.at<uchar>(i+p,j+q)=255/count;

					}
			}
		}
	}
}


int main()
{
	Mat img=imread("/home/kizontech/Binary1.png", 0);
	Mat img2=img.clone();
	int count=3;
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1; j++)
		{
			if((img2.at<uchar>(i,j)==255))
			{
				BFS(img2,i,j,count);
				count++;
			}
		}
	}
	imshow("Image", img2);
	cout<<(count-3);
	waitKey(0);
}
