#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

int main()
{
	int *array=0,i,j,k,m,n,num;
	int a[100][100];
	printf("请输入数组长度:");
	scanf("%d",&num);
	array= (int *)malloc(sizeof(int) *num);
	printf("请输入%d个数据\n",num);
	for(k=0;k<num;k++)
	{
		scanf("%d",&array[k]);
	}
	k=0;
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=i;j++)
		{
			a[i][j]=array[k];
			k++;
			printf("%d  ",a[i][j]);
		}
		printf("\n");				
	}
	
//	for(m=1;m<=i;m++)
//		{
//			for(n=1;n<=j;n++)
//			{
//				printf("%d",a[m][n]);
//			}
//			printf("/n");
//		}
	
	return 0;	
}
