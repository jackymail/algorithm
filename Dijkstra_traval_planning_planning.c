#include <stdio.h>
#include <stdlib.h>

#define MAXV 500
#define INFINITE 100000000


typedef struct
{
  int dist[MAXV][MAXV];  //表示两点之间的距离
  int cost[MAXV][MAXV];  //两点之间需要的费用
  int visited[MAXV];     //某点是否已经被访问过
  int mindist[MAXV];     //从源点到该点之间的距离
  int mincost[MAXV];     //从源点到该点的最小费用
  int VertexN;           //顶点数
  int EdgeN;             //边数
}Graph;


void initialize_graph(Graph *G)
{
     int i = 0;
     int j = 0;

     if(NULL == G)
     {
	printf("the graph is null\n");
        return;
     }

     for(i=0;i<MAXV;i++)
     {
	for(j=0;j<MAXV;j++)
        {
	    G->dist[i][j] = INFINITE;
            G->cost[i][j] = INFINITE;
        }
        G->visited[i] = 0;
        G->mindist[i] = 0;
        G->mincost[i] = 0;
     }

     G->VertexN = 0;
     G->EdgeN = 0;
     return;
}

void read_graph(Graph *G,int *start,int *end)
{
   int i = 0;
   int V1 = 0;
   int V2 = 0;
    
   if(NULL == G || NULL == start || NULL == end)
   {
      printf("data error\n");
      return;  
   } 
   
   scanf("%d %d %d %d",&G->VertexN,&G->EdgeN,start,end);

   for(i=0;i< G->EdgeN;i++)
   {
     scanf("%d %d",&V1,&V2);
     scanf("%d %d",&G->dist[V2][V2],&G->cost[V1][V2]);
     G->dist[V2][V1] = G->dist[V1][V2]; //无向图，V1到V2的距离和V2到V1的距离是一的。
     G->cost[V2][V1] = G->cost[V1][V2];
   }
}

void Dijstra(Graph *G,int start)
{
   int w = 0;
   int v = 0;
   int min_vertex = 0;
   int min_dis = 0;
   int min_cost = 0;
   
   if(NULL == G)
   {
      printf("the graph pointer is null\n");
      return;
   }
   if(start < 0 || start >= MAXV)
   {
      printf("the start point is out of range\n");
      return;
   }
   G->visited[start] = 1;

   G->mindist[start] = G->mincost[start] = 0;

   for(v = 0; v< G->VertexN;v++)
   {
	G->mindist[v] = G->dist[start][v];
        G->mincost[v] = G->cost[start][v];
   }     

   for(w=1;w<G->VertexN;w++)
   {
      min_dis = INFINITE;
      for(v=0;v<G->VertexN;v++)
      {
          if((G->visited[v] != 1) && (G->mindist[v] <= min_dis))	 
          {
	      min_dis = G->mindist[v];
              min_vertex = v;
          }
      }
     
      if(min_dis <  INFINITE)
      {
      	G->visited[min_vertex] = 1;
      }
      else
      {
	break;
      }
      for(v=0;v<G->VertexN;v++)
      {
          if(G->visited[v] != 1)
          {
	  	if(G->dist[min_vertex][v] + min_dis < G->dist[start][v])
          	{
       	      		G->mindist[v] = G->dist[min_vertex][v] + min_dis;
              		G->mincost[v] = G->mincost[min_vertex] + G->cost[min_vertex][v];

          	}
          	else if((G->mindist[min_vertex]+G->dist[min_vertex][v] == G->mindist
[v]) && (G->mincost[min_vertex]+G->cost[min_vertex][v] < G->mincost[v]))
          	{
	      		G->mincost[v] = G->mincost[min_vertex] + G->cost[min_vertex][v];	
          	}
          }
      }

   }
   return;
}


int main(void)
{
   int start_point = 0;
   int end_point = 0;
    
   Graph *G = NULL;


   G = (Graph*)malloc(sizeof(Graph));
   if(NULL == G)
   {
      return 0;
   }   

   initialize_graph(G);

   read_graph(G,&start_point,&end_point);

   Dijstra(G,start_point);
   
   printf("%d %d\n",G->mindist[end_point],G->mincost[end_point]);

   return 0;
}

