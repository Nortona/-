#include <iostream>
using namespace std;
struct node
{//���Ľ��ṹ�����������ʾ��
	int data;
	node *lchild,*rchild;
}; 
void merge_tree(node *parent,node *lchild,node *rchild)
{//��parent��lchild��rchild�������ϲ��������γ����νṹ
	parent->lchild=lchild;
	parent->rchild=rchild;
}
/////////
node *create_node(int data)
{//Ϊdata����һ�����
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
{////////����һ����
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

//������������Բ������Ƿ���
InOrderTraverse(b);
	cout<<endl;
PreOrderTraverse(b);
	cout<<endl;
PostOrderTraverse(b);
	cout<<endl;
return 0;	
}

