#include<iostream>
using namespace std;
char str[17]={"0123456789ABCDEF"};   //Ϊ��ʹ����򻯶���ǰ���彫�����������
int main()
{
 int s,t; //sΪҪ�����ʮ��������tΪҪת���Ľ��ơ�
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
  cout<<ans[j];   //���ʱ ��Ҫ�������
 return 0;
}
