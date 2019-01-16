#include<stdio.h>
#include<stdlib.h>

#include<cstring>
#include<windows.h>
#include<algorithm>
#include<iostream>
#include<time.h>
using namespace std;
#define MAXSIZE 100
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
	clock_t start,end;
	start = clock();
	SqList L;
	L.r=new ElemType[MAXSIZE+10];
	L.length=MAXSIZE;
	int i,j,n,k,x;
//	DWORD start,stop;
//	unsigned int t = 0;
//	start=GetTickCount();
	srand((unsigned)time(NULL));
	for(i=1;x<=L.length;i++)
	{
		L.r[i].key=rand();
	}
	BInsertSort(L);
//	for(i=1;i<=L.length;i++)
//	{
//		//printf("%d",L.r[i].key);
//		cout<<L.r[i].key<<endl;
//	}
//	printf("请输入个数\n");
//	scanf("%d",&n);
	
//	printf("请输入%d个数据\n",n);
//	for(i=1;i<=n;i++)
//	{
//		cin>>L.r[i].key;
//	}
//	printf("请输入排序方式(插入排序请输入1,折半插入排序请输入0)\n");
//	while(scanf("%d",&k)!=EOF){
//		if(k)
//	{
//		InsertSort(L);
//	}
//	else

//	stop=GetTickCount();
//	printf("time:%d ms",stop-start);
//	Output(L);	
//	}
	end = clock();
	cout<<end-start<<"(ms)"<<endl;
	cout<<end-start <<CLOCKS_PER_SEC <<"(s)"<<endl;
	return 0;
}


