#include <iostream>
using namespace std;
struct node
{//树的结点结构。二叉链表表示法
	int data;
	node *lchild,*rchild;
}; 
void merge_tree(node *parent,node *lchild,node *rchild)
{//将parent、lchild、rchild三个结点合并起来，形成树形结构
	parent->lchild=lchild;
	parent->rchild=rchild;
}
/////////
node *create_node(int data)
{//为data生成一个结点
	node * p=new node;
	p->data=data;
	p->lchild=p->rchild=0;
	return p;
}

void  PreOrderTraverse(node * t)
{
	if(t!=0)
	{
		printf("%d  ", t->data); 
		PreOrderTraverse(t->lchild);
		
		PreOrderTraverse(t->rchild);
	}
}
 
void InOrderTraverse(node * t)
{
	if(t!=0)
	{
		InOrderTraverse(t->lchild);
		cout<<t->data<<"  ";
		
		InOrderTraverse(t->rchild);
		
	}
}

void PostOrderTraverse(node * t)
{
	if(t!=0)
	{
		PostOrderTraverse(t->lchild);
		
		InOrderTraverse(t->rchild);
		cout<<t->data<<"  ";
		
	}
}

int main()
{////////建立一棵树
	node *a,*b,*c,*d,*e,*f,*g;
	a=create_node(1);
	b=create_node(2);
	c=create_node(3);
	d=create_node(4);
	e=create_node(5);
	f=create_node(6);
	g=create_node(7);

    merge_tree(e,0,g);
	merge_tree(d,e,f);
	merge_tree(b,c,d);
	merge_tree(a,b,0);

//中序遍历，用以测试树是否建立
InOrderTraverse(b);
	cout<<endl;
PreOrderTraverse(b);
	cout<<endl;
PostOrderTraverse(b);
	cout<<endl;
return 0;	
}

