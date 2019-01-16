#include<iostream>
using namespace std;
char str[17]={"0123456789ABCDEF"};   //为了使程序简化而提前定义将会输出的数字
int main()
{
 int s,t; //s为要输入的十进制数，t为要转换的进制。
 int i=0,j;
 char ans[10000];
 cin>>s>>t;
 while(s>0)
 {
  ans[i]=str[s%t];
  s=s/t;
  i++;
 }
 for(j=i-1;j>=0;j--)
  cout<<ans[j];   //输出时 需要倒着输出
 return 0;
}
