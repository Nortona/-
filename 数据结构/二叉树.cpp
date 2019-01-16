#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct node{
	struct node *lchild;
	struct node *rchild;
	char data;
}BiTreeNode,*BiTree;


void createBiTree(BiTree &T)
{
	char c;
	cin >> c;
	if('#'==c)
	{
		T = NULL;
	}
	else
	{
		T= new BiTreeNode;
		T->data=c;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

void preTraverse(BiTree T)
{
	if(T)
	{
		cout<<T->data<<" ";
		preTraverse(T->lchild);
		preTraverse(T->rchild);
	}
}
void midTraverse(BiTree T)
{
	if(T)
	{
		preTraverse(T->lchild);
		cout<<T->data<<" ";
		preTraverse(T->rchild);
	}
}
void postTraverse(BiTree T)
{
	if(T)
	{
		postTraverse(T->lchild);
		postTraverse(T->rchild);
		cout<<T->data<<" ";
	}
}
int main()
{
	BiTree T;
	int n;        
    createBiTree(T);
    cout<<"二叉树创建完成！"<<endl;
    while(scanf("%d",&n)!=0){
    	if(n==1){
    		cout<<"前序遍历二叉树："<<endl;
    		preTraverse(T);
    		cout<<endl;
	}
    	if(n==2){
    		cout<<"中序遍历二叉树："<<endl;
    		midTraverse(T);
    		cout<<endl;
	}
    	if(n==3){
    		cout<<"后序遍历二叉树："<<endl;
    		postTraverse(T);
	}
    
	}
    
    return 0;
}
