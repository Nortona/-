#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct element
{
	int weight;
	int parent,lchild,rchild;
};

int get()
{
	char word;
	int a[27];
//	char letter[27]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	if((fopen("SourceFile.txt","r"))==NULL)
	{
		printf("源程序无法打开！\n");	
	}
 	else
 	{
 		
	}
}
void Select(element a[],int n , int &i1 , int &i2)
{
	  for (int i = 0; i < n; i++)
	  {
          if (a[i].parent == -1)// 初始化s1,s1的双亲为-1
          {
              i1 = i;
              break;
          }
      }
      for (int i = 0; i < n; i++)// i1为权值最小的下标
      {
      	if (a[i].parent == -1 && a[i1].weight > a[i].weight)
        	i1 = i;
      }
      for (int j = 0; j < n; j++)
      {
      	if (a[j].parent == -1&&j!=i1)// 初始化i2,i2的双亲为-1
        {
             i2 = j;
             break;
        }
      }
     for (int j = 0; j < n; j++)//i2为另一个权值最小的结点
     {
     	if (a[j].parent == -1 && a[i2].weight > a[j].weight&&j != i1)
        	i2 = j;
     }
}
void HuffmanTree(element huffTree[],  int w[], int n )
{
	int i,k,i1,i2;
	for (i=0;i<2*n-1;i++)
	{
		huffTree[i].parent=-1;
		huffTree [i].lchild=-1;
		huffTree[i].rchild=-1;
	}
	for(i=0;i<n;i++)
		huffTree[i].weight=w[i];
	for(k=n;k<2*n-1;k++)
	{
		Select(huffTree,k,i1,i2);
		huffTree[k].weight = huffTree[i1].weight+huffTree[i2].weight;
		huffTree[i1].parent=k; huffTree[i2].parent=k;
		huffTree[k].lchild=i1; huffTree[k].rchild=i2;
	}
}
int main()
{
	
	return 0;
}
