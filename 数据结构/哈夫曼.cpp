#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char* *HuffmanCode;
void Select(HuffmanTree &HT, int n, int &s1, int &s2);
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
	HuffmanTree p;
	int m, i;
	int s1, s2;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
	{
		p->weight = *w;
		p->parent = 0;
		p->rchild = 0;
		p->lchild = 0;
	}
	for (; i <= m; ++i, ++p)
	{
		p->lchild = 0;
		p->parent = 0;
		p->rchild = 0;
		p->weight = 0;
	}
	for (i = n + 1; i <= m; ++i)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	int start;
	int c, f;
	char* cd;
	cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}
void Select(HuffmanTree &HT, int n, int &s1, int &s2)
{
	int i;
	s1 = s2 = 0;
	int min1 = INT_MAX;//最小值 
	int min2 = INT_MAX;//次小值  

	for (i = 1; i <= n; ++i)
	{
		if (HT[i].parent == 0)
		{
			if (HT[i].weight < min1)
			{  
				min2 = min1;
				s2 = s1;
				min1 = HT[i].weight;
				s1 = i;
			}
			else if ((HT[i].weight >= min1) && (HT[i].weight < min2))
			{ 
				min2 = HT[i].weight;
				s2 = i;
			}
			else
			{
				;
			}
		}
	}
}
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;

	int n;
	printf("请输入权值的个数(大于1): ");
	scanf("%d", &n);

	int* w;
	w = (int*)malloc(n * sizeof(int));
	printf("请输入%d个权值的(整型)： \n", n);
	for (int i = 0; i <= n - 1; i++)
		scanf("%d", w + i);

	HuffmanCoding(HT, HC, w, n);

	for (int i = 1; i <= n; i++)
		puts(HC[i]);
	system("pause");
	return 0;
}
