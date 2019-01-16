#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
#define INFINITY INT_MAX  
#define MAX_VERTEX_NUM 20

typedef struct ArcCell
{
	int adj;//��Ȩͼ����0,1��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ������Ϊint�ͣ�
}AreCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

/****   ͼ���ڽӱ�洢��ʾ   ****/
typedef struct ArcNode
{
	int adjvex; //�û���ָ��Ķ����λ��
	struct ArcNode *nextarc; //ָ����һ������ָ��
	int w;//Ȩֵ
}ArcNode;
typedef struct VNode
{
	char data; //������Ϣ
	ArcNode *firstarc; //ָ���һ�������õ�Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
	int kind;  //ͼ�������־
}ALGraph;
int LocateVex_biao(ALGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == v) return i;
	}
}


int CreateUDN_biao(ALGraph &G)
{
	char v1, v2;//һ��������������������
	int w;//�ߵ�Ȩֵ
	int i, j;
	printf("�����붥�����ͱ���:");
	scanf("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		scanf("%c", &G.vertices[i].data);//���춥������
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		getchar();
		scanf("%c", &v1);
		getchar();
		scanf("%c", &v2);
		getchar();
		scanf("%d", &w);
		i = LocateVex_biao(G, v1);
		j = LocateVex_biao(G, v2);
		if (G.vertices[i].firstarc == NULL)
		{
			G.vertices[i].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
			G.vertices[i].firstarc->adjvex = j;
			G.vertices[i].firstarc->nextarc = NULL;
			G.vertices[i].firstarc->w = w;
		}
		else
		{
			ArcNode* p = G.vertices[i].firstarc;
			ArcNode* q;
			while (p->nextarc != NULL)
				p = p->nextarc;
			q = (ArcNode*)malloc(sizeof(ArcNode));
			q->adjvex = j;
			q->nextarc = NULL;
			q->w = w;
			p->nextarc = q;
		}
		if (G.vertices[j].firstarc == NULL)
		{
			G.vertices[j].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
			G.vertices[j].firstarc->adjvex =i;
			G.vertices[j].firstarc->nextarc = NULL;
			G.vertices[j].firstarc->w = w;
		}
		else
		{
			ArcNode* p = G.vertices[j].firstarc;
			ArcNode* q;
			while (p->nextarc != NULL)
				p = p->nextarc;
			q = (ArcNode*)malloc(sizeof(ArcNode));
			q->adjvex = i;
			q->nextarc = NULL;
			q->w = w;
			p->nextarc = q;
		}
	}
	return 1;
}

void ShowGraph_biao(ALGraph &G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%d:%c -> ", i, G.vertices[i].data);
		ArcNode *p = G.vertices[i].firstarc;
		while (p != NULL)
		{
				printf("%d,w=%d ->", p->adjvex, p->w);
				p = p->nextarc;		
		}
		printf("NULL\n");
	}
}
int main()
{
	int i;
	char r;
	ALGraph G1;
	system("cls");
	CreateUDN_biao(G1);
	ShowGraph_biao(G1);
	printf("�������������\n");
	getchar();
	scanf("%c", &r);
	return 0;
}
