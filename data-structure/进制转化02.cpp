#include<stdio.h>

void change(int num)
{
	if(num==0)
	{
		return ;
	}
	else
	{
		change(num/2);
		printf("%d",num%2);
	}
}
int main()
{
	int num;
	scanf("%d",&num);
	change(num);
	return 0;
}
