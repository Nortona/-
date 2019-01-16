#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
#define INFINITY INT_MAX  
#define MAX_VERTEX_NUM 20

typedef struct ArcCell
{
	int adj;//无权图，用0,1表示相邻否；对带权图，则为权值（本例为int型）
}AreCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

/****   图的邻接表存储表示   ****/
typedef struct ArcNode
{
	int adjvex; //该弧所指向的顶点的位置
	struct ArcNode *nextarc; //指向下一条弧的指针
	int w;//权值
}ArcNode;
typedef struct VNode
{
	char data; //顶点信息
	ArcNode *firstarc; //指向第一条依附该点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; //图的当前顶点数和弧数
	int kind;  //图的种类标志
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
	char v1, v2;//一条边所依附的两个顶点
	int w;//边的权值
	int i, j;
	printf("请输入顶点数和边数:");
	scanf("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		scanf("%c", &G.vertices[i].data);//构造顶点向量
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
	printf("输入任意键返回\n");
	getchar();
	scanf("%c", &r);
	return 0;
}
