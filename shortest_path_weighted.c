#include "stdio.h"
#include "stdlib.h"

Vertex FindMinDist(MGraph Graph,int dist[],int collected[])
{
   Vertex MinV;
   Vertex V;
   int MinDist = INFINITY;
 
   for(V=0;V<Graph->Nv;V++)
   {
	if(collected[V] == false && dist[V]<MinDist)
        {
	    MinDist = dist[V];
            MinV = V;
        }
   }
   if(MinDist < INFINITY)
   {
	return MinV;
   }
   else
   {	
	return ERROR;
   }
}
bool Dijstra(MGraph Graph,int dist[],int path[],Vertex S)
{
    int collected[MaxVertexNum];
    Vertex V,W;
    
    for(V=0;V<Graph->Nv;V++)
    {
	dist[V] = Graph->G[S][V];
        if(dist[V] < INFINITY)
        {
	    path[V] = S;
        }
        else
        {
	    path[V] = -1;
        }
        collected[V] = false;
    }
    dist[S] =0;
    collected[S] =true;

    while(1)
    {
      V = FinMinDist(Graph,dist,collected);
      if(V == ERROR)
      {
	  break;
      }
      collected[V] = true;
      for(W=0;W<Graph->Nv;W++)
      {
	  if(collected[W]==false && Graph->G[V][W]<INFINITY)
          {
	      if(Graph->G[V][W] < 0)
              {
		 return false;
              } 
              if(dist[V]+Graph->[V][W] < dist[W])
              {
		  dist[W] = dist[V] + Graph->G[V][w];
                  path[W] = V;
              }
          }
      }
    }
    return true;
}

