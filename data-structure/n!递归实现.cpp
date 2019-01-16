#include<stdio.h>
#include<stdlib.h>

int rec(int n)
{
	if(0==n){
		return 1;
	}
	else{
		return n*rec(n-1);
	}	
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",rec(n));	
	return 0;
}
