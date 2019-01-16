#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int a,b,ans;
	char ch;
	scanf("%d %c %d",&a,&ch,&b);
	switch(ch)
	{
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '/':
			ans = a / b;
			break;
		
	}
	printf("%d",ans);
	return 0;
}
