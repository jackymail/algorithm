#include "stdio.h"
#include "stdlib.h"

#if 0
status topological_sort(ALGraph G)
{
   FindDegree(G,indegree); //求个顶点的入度。
   InitStack(S);
   for(i=0;i<G->vernum;++i)
   {
	if(indegree[i] == 0)
        {
	   Push(S,i);
        }
   }
   count = 0;
   while(!stackempty(S))
   {
	Pop(S,i);
        printf(i,G.vertexces[i].data);
        ++count;
        for(p=G->vertexces[i].firsttarc;p;p=p->nextrc)
        {
	     k = p->adjvx;
             if(!(--indegree[k]))
             {
		PUSH(S,k);
             }
         }
   }
   if(count<G.vernum)
   {
	return ERROR;
   }
   return OK;
}
#else
bool  TopSort(LGraph Graph,Vertex TopOrder[])
{
    int Indegree[MaxVertexNum];
    int cnt;
    Vertex V;
    PtrToAjustVNode W;

    Queue Q = CreateQuue(Graph->Nv);

    /*Initialize indegree*/
    for(V=0;V<Graph->Nv;V++)
    {
      Indegree[V] = 0;
    }
    /* traverse the map,and get the indegree[]*/
    for(V=0;V<Graph->Nv;V++)
    {
        for(W=Graph->G[V];FirstEdge;W,W=W->Next)
        {
          Indegree[W->AdjV]++;
        }
    }

    for(V=0;V<Graph->Nv;V++)
    {
      if(Indegree[V] == 0)
      {
        AddQ(Q,V);
      }
    }

    cnt = 0;
    while(!IsEmptyQ(Q))
    {
        V = DeleteQ(Q);
        TopOrder[cnt++]= V;
        for(W=Graph->G[V].FirstEdge;W;W=W->Next)
        {
           if(--Indegree[W->AdjV] == 0)
           {
             AddQ(Q,W->AdjV);
           }
        }
    }

    if(cnt != Graph->Nv)
    {
      return false;
    }
    else
    {
      return true;
    }
}





















#endif
