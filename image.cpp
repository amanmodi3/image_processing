
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <queue>

using namespace cv;
using namespace std;

typedef struct{
	int x;
	int y;
}point;
Mat var;
void BFS(point p, int **visited){
	queue <point> s;
	point p2,p3;
	s.push(p);
	while(!s.empty()){
		p2=s.front();
		s.pop();
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(p2.x+i<0 || p2.x+i>=var.rows || p2.y+j<0 || p2.y+j>=var.cols)
					continue;
				if(visited[p2.x+i][p2.y+j]==0 && var.at<uchar>(p2.x+i,p2.y+j)==255){
					p3.x=p2.x+i;
					p3.y=p2.y+j;
					visited[p3.x][p3.y]=1;
					s.push(p3);
				}
			}
		}
	}
}
int main(){
	var=imread("/home/kizontech/Downloads/dfs_path.jpg",2);
	int count=0;
	int **visited= new int*[var.rows];
	point p;
	for(int i=0;i<var.rows;i++){
		visited[i]=new int[var.cols];
	}
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			visited[i][j]=0;
		}
	}
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			if(var.at<uchar>(i,j)==255 && visited[i][j]==0){
				visited[i][j]=1;
				p.x=i;
				p.y=j;
				cout << p.x << ", " << p.y << endl;
				BFS(p,visited);
				count++;
			}
		}
	}
	cout << count <<endl;
}
