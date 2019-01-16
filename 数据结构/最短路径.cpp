#include <stdio.h>
 #include <stdlib.h>
 #define MaxInt 32767
 #define MaxVertexNum 10
 typedef char vertexType;
 typedef int edgeType;
 typedef struct{
     vertexType vertexes[MaxVertexNum];
     edgeType edges[MaxVertexNum][MaxVertexNum];
     int numberOfVertex;
     int numberOfEdge;
 }Graph;
 
 void dijkstra(Graph *g, int v, int v1)
 {
	int n = g->numberOfVertex;
	int dist[n];
	int prev[n];
	int S[n];
	for (int i = 0;i < n; ++i)
	{
		dist[i] = g->edges[v][i];
		S[i] = 0;
		if (dist[i] == MaxInt)
		{
			prev[i] = -1;
		}
		else 
		{
			prev[i] = v;
		}
	}
    dist[v] = 0;
    S[v] = 1;
    for (int i = 1; i < n; ++i)
    {
        int mindist = MaxInt;
        int u = v;
        for (int j = 0; j < n; j++)
        {
            if ((!S[j]) && dist[j] < mindist)
            {
                u = j;
                mindist = dist[j];
            }
        }
        S[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if ((!S[j]) && g->edges[u][j] + dist[u]< dist[j])
            {
                dist[j] = dist[u] + g->edges[u][j];
                prev[j] = u;
            }
        }
              
    }
        printf("最短距离为 %d\n",dist[v1]);
        printf("路径为 ");
        int temp = v1;
        while (temp != v)
        {
            printf("%c--", g->vertexes[temp-1]);
            temp = prev[temp];
        }
        printf("%c\n", g->vertexes[v-1]);
}
 void createGraph(Graph * g)
 {
     printf("请输入顶点数和边数\n");
     scanf("%d%d", &(g->numberOfVertex), &(g->numberOfEdge));
     printf("请输入所有的顶点\n");
     getchar();
     for (int i = 0; i < g->numberOfVertex; i++)
     {
         g->vertexes[i] = getchar();
         getchar();
     }
     for (int i = 0; i < g->numberOfVertex; i++)
     {
         for (int j = 0; j < g->numberOfVertex; j++)
         {
             g->edges[i][j] = MaxInt;
         }
     }
     printf("请输入两点及中间边的权值\n");
     for (int k = 0; k < g->numberOfEdge; k++)
     {
         int i, j, value;
         scanf("%d %d",&i, &j);
         scanf("%d", &(g->edges[i][j]));
         g->edges[j][i] = g->edges[i][j];
     }
     for (int i = 0; i < g->numberOfVertex; i++)
     {
         g->edges[i][i] = 0;
     }

 }

 int main()
 {
     Graph *g = (Graph*)(malloc(sizeof(Graph)));
     createGraph(g);
     while (1)
     {
         printf("求两点之间的最短路径\n");
         printf("请输入两点\n");
         int v1, v2;
         scanf("%d%d", &v1, &v2);
         dijkstra(g, v1, v2);          
     }
 }
