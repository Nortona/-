#include <stdio.h>
#include <stdlib.h>
using namespace std;
void intToBinary(int num)
{ 
	int i;
	int j=15;
	for(i=0;i<16;i++)
	{ 
		printf("%d",(num>>j)&1);
		j--; 
	}
	printf("\n");
}

int main()
{
	int num;
	float m;
	printf("请输入一个整型数字:");
	scanf("%d",&num);
 	intToBinary(num);
	return 0;
}
