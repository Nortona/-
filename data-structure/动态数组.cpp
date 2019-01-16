#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int main()
{
	int *array=0,num,i;
	scanf("%d",&num);
	array=(int *)malloc(sizeof(int)*num);
	if(array==0)
	{	
		printf("false");
		exit(0);
	}
	else
		for(i=0;i<num;i++){
			scanf("%d",&array[i]);
		}
		for(i=0;i<num;i++){
			printf("%d", array[i]);
		}
	return 0;
}
