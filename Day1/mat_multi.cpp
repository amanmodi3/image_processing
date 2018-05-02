#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int i,j,k,sum,A[9][19],B[19][9],C[9][9];
	for(i=0;i<10;i++)
	{for(j=0;j<10;j++){
		A[i][j]=(rand())%(100);
		B[i][j]=(rand())%(100);}
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			sum=0;
			for(k=0;k<10;k++)
			{sum += A[i][k]*B[k][j];}
      C[i][j]=sum;
      sum=0;
		}
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			cout<<C[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
