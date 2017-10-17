#include "stdio.h"
#include "stdlib.h"

#define MAXV 1000
typedef struct{
   int visited[MAXV];
   int Edges[MAXV][MAXV];
   int VertexN;
   int EdgeN;
}Graph;

void InitializeG(Graph *G)
{
    int i=0;
    int j=0;
    for(i=0;i<MAXV;i++)
    {
	for(j=0;j<MAXV;j++)
        {
	   G->Edges[i][j] = 0;
        }
       G->visited[i] = 0;
    }
  G->VertexN = G->EdgeN = 0;
}
void ReadG(Graph *G)
{
    int i = 0;
    int V1 = 0;
    int V2 = 0;
    
    scanf("%d %d",&G->VertexN,&G->EdgeN);
    for(i=0;i<G->EdgeN;i++)
    {
	scanf("%d %d",&V1,&V2);
        G->Edges[V1-1][V2-1] = G->Edges[V2-1][V1-1] =1;
    }
    return;
}
void DFS(Graph *G,int V)
{
   int W = 0;
   G->visited[V] = 1;
   
   for(W=0;W<G->VertexN;W++)
   {
	if(G->Edges[V][W] && !G->visited[W])
        {
		DFS(G,W);
        }
   }
   return;
}

int CheckG(Graph *G)
{
    int r = 0;
    int i = 0;
    int j = 0;
    
    for(i=0;i<G->VertexN;i++)
    {
	r = 0;
        for(j=0;j<G->VertexN;j++)
        {
	    r += G->Edges[i][j];
        }
        if(r%2)
        {
	   return 0;
        }
    }
    return 1;
}

int main(void)
{
   int i = 0;
   Graph *G = malloc(sizeof(Graph));
   InitializeG(G);
   ReadG(G);
   printf("first time, the result of CheckG() is %d\n",CheckG(G));
   DFS(G,0);
   for(i=0;i<G->VertexN;i++)
   {
       if(!G->visited[i])
       {
	  break;
       }
   }
   if(i<G->VertexN)
   {
	printf("0\n");
   } 
   else
   {
	printf("%d \n",CheckG(G));
   }
   return 0;
}















