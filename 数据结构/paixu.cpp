#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef struct
{
	int key;
	char *otherinfo;
}ElemType;
typedef struct
{
	ElemType *r;
	int length;
}SqList;

void InsertSort(SqList &L)
{
	int i,j;
	for(i=2;i<=L.length;++i)
	{
		if(L.r[i].key<L.r[i-1].key)
		{
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(j=i-2;L.r[0].key<L.r[j].key;--j)
			{
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
}
void BInsertSort(SqList &L)
{
	int i,j,low,high,m;
	for(i=2;i<=L.length;++i)
	{
		L.r[0]=L.r[i];
		low=1;high=i-1;
		while(low<=high)
		{
			m=(low+high)/2;
			if(L.r[0].key< L.r[m].key)
			{
				high=m-1;
			}
			else
				low=m+1;
		}
		for(j=i-1;j>=high+1;--j)
		{
			L.r[j+1]=L.r[j];	
		}
		L.r[high+1]=L.r[0];
	}
}
void Output(SqList &L)
{
	int i;
	for(i=1;i<=L.length;i++)
	{
		//printf("%d",L.r[i].key);
		cout<<L.r[i].key<<endl;
	}
}
int main()
{
	SqList L;
	L.r=new ElemType[MAXSIZE+1];
	int i,j,n,k;
	printf("���������\n");
	scanf("%d",&n);
	L.length=n;
	printf("������%d������\n",n);
	for(i=1;i<=n;i++)
	{
		//scanf("%d",L.r[i].key);
		cin>>L.r[i].key;
	}
	printf("����������ʽ(��������������1,�۰��������������0)\n");
	while(scanf("%d",&k)!=EOF){
		if(k)
	{
		InsertSort(L);
	}
	else
		BInsertSort(L);
	
	Output(L);	
	}
	return 0;
}














