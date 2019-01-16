#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl; 
#define MAXSIZE 20
typedef int DataType;
typedef struct{
	DataType data[MAXSIZE];
	int length;
} SeqList;
void InitList(SeqList*L)
{
	L->length=0;
}
int CreatList (SeqList*L,DataType a[],int n)
{
	if(n>MAXSIZE){
		printf("空间不足\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		L->data[i] = a[i];
	}
	L->length =n;
	cout << "建立成功\n";
	return 1;
}
int Empty(SeqList*L)
{
	if(L->length==0) return 1;
	else return 0;
}
int Length(SeqList*L)
{
	return L->length;
}
int ScanfList(SeqList*L)
{
	int x,i;
	while(scanf("%d",&x) !=EOF){
		L->data[i]=x;
		i++;
	}
	return 1;
}
void PrintList(SeqList *L)
{
	for(int i=0;i< L->length; i++){
		printf("%d",L->data[i]);
	}
}
int Locate(SeqList*L,DataType x)
{
	for(int i=0;i< L->length;i++){
		if(L->data[i] == x){
			return i+1;
		}
	}
	return 0;	
}
int Insert(SeqList*L,int i,DataType x)
{
	cout << "请输入所要插入数据的位置:";
	cin >> i;
	cout << "请输入所要插入的数据:";
	cin >> x;
	if(L->length >=MAXSIZE||i<1||i> L->length+1){
		cout << "位置超出范围\n";
		return 0;
	}
	for(int j=L->length;j>=i;j--){
		L->data[j]=L->data[j-1];
	}
	L->data[i-1]=x;
	L->length++;
	return 1; 
	
}
int Delete(SeqList*L,int i,DataType *ptr){
	cout << "请输入所要删除数据的位置:";
	cin >> i;
	if(L->length==0||i<1||i>L->length){
		cout << "删除错误\n";
		return 0;
	}
	*ptr =L->data[i-1];
	for(int j=i;j< L->length;j++){
		L->data[j-1]=L->data[j];
	}
	L->length--;
	cout << "删除成功\n"; 
	return 1;
}
int main()
{
	int r[]={},i,x,n,choose;
	cout << "1. 建立\n";
	cout << "2. 输入\n";
	cout << "3. 查找\n";
	cout << "4. 插入\n";
	cout << "5. 删除\n";
	cout << "6. 输出\n";
	cout << "0. 退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1:
			SeqList L;
			cout <<"请输入建立长度：";
			scanf("%d",&n);
			CreatList(&L,r,n);
			break;
		case 2:
			ScanfList(&L);
			break;
		case 3:
			cout <<"请输入要查找的元素值：";
			scanf("%d",&x);
			i=Locate(&L,x);
			printf("元素%d的位置为:%d\n",x,i);
			break;
		case 4:
			Insert(&L,i,x);
			break;
		case 5:
			Delete(&L,i,&x);
			break;
		case 6:
			PrintList(&L);
			break;
		}
	}	
	return 0;
}
