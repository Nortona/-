#include<stdio.h>

#include<stdlib.h>
#define n 4
int t[n*(n+1)/2];
void store(int x,int i,int j)
{
	if(i>=j)
		t[i*(i+1)/2+j]=x;
	else if(x!=0)
		printf("wrong");
}
int main()
{
	int i,j;
	int d[n][n]={2,0,0,0,5,1,0,0,0,3,1,0,4,2,7,0};
	for(i=0;i<n;i++)
	{


		for(j=0;j<n;j++)
		printf("%d ",d[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	{
		 store(d[i][j],i,j);
	}
	}
//	for(i=0;i<0+n*(n+1)/2;i++)
//		printf("%d ",t[i]);
	return 0;
}

