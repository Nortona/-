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
		printf("�ռ䲻��\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		L->data[i] = a[i];
	}
	L->length =n;
	cout << "�����ɹ�\n";
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
	cout << "��������Ҫ�������ݵ�λ��:";
	cin >> i;
	cout << "��������Ҫ���������:";
	cin >> x;
	if(L->length >=MAXSIZE||i<1||i> L->length+1){
		cout << "λ�ó�����Χ\n";
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
	cout << "��������Ҫɾ�����ݵ�λ��:";
	cin >> i;
	if(L->length==0||i<1||i>L->length){
		cout << "ɾ������\n";
		return 0;
	}
	*ptr =L->data[i-1];
	for(int j=i;j< L->length;j++){
		L->data[j-1]=L->data[j];
	}
	L->length--;
	cout << "ɾ���ɹ�\n"; 
	return 1;
}
int main()
{
	int r[]={},i,x,n,choose;
	cout << "1. ����\n";
	cout << "2. ����\n";
	cout << "3. ����\n";
	cout << "4. ����\n";
	cout << "5. ɾ��\n";
	cout << "6. ���\n";
	cout << "0. �˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1:
			SeqList L;
			cout <<"�����뽨�����ȣ�";
			scanf("%d",&n);
			CreatList(&L,r,n);
			break;
		case 2:
			ScanfList(&L);
			break;
		case 3:
			cout <<"������Ҫ���ҵ�Ԫ��ֵ��";
			scanf("%d",&x);
			i=Locate(&L,x);
			printf("Ԫ��%d��λ��Ϊ:%d\n",x,i);
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
