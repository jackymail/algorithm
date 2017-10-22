/*
 每次从边的集合中弹出一条最短边，检查是否是属于同一个并查集，如果属于则这条边不能使用
 如果不属于，则可以使用。 最短边通过最小堆实现。
*/




#include "stdio.h"
#include "stdlib.h"

#define MAXV 1000

typedef int DisjSet[MAXV+1];
typedef int Vertex;

struct EdgeType{
    Vertex V1;
    Vertex V2;
    int W;
};

DisjSet VSet;
struct EdgeType *ESet;

void Initialize(int N)
{
   while(N)
   {
      VSet[N--] = -1;
   }
   return;
}

Vertex Find(Vertex V)
{
    Vertex root,trail,lead;

    for(root=V;VSet[root]>0;root=VSet[root])
    {
	;
    }
    for(trail = V;trail != root;trail = lead)
    {
	lead = VSet[trail];
        VSet[trail] = root;
    }
    return root;
}

void SetUnion(Vertex Root1,Vertex Root2)
{
    if(VSet[Root2] < VSet[Root1])
    {
	VSet[Root2] += VSet[Root1];
        VSet[Root1] = Root2;
    }
    else
    {
	VSet[Root1] += VSet[Root2];
	VSet[Root1] = Root1;
    }
    return;
}

void MinHeap(int i ,int M)
{
    int child;
    struct EdgeType temp;

    temp = ESet[i];
    for(;((i<<1)+1) < M;i=child)
    {
        child = (i<<1)+1;
        if(child!=M-1 && ESet[child+1].W<ESet[child].W)
        {
	      child++;
        }
        if(temp.W > ESet[child].W)
        {
	     ESet[i] = ESet[child];
        }
        else
        {
	    break;
        }
    }
    ESet[i] = temp;
    return;
}

void InitializeESet(int M)
{
   int i = 0;
   for(i=M/2;i>=0;i--)
   {
      MinHeap(i,M);
   }
   return;
}

int GetEdge(int CurrentSize)
{
    struct EdgeType temp;
    temp = ESet[0];
    ESet[0] = ESet[CurrentSize-1];
    ESet[CurrentSize-1] = temp;
    MinHeap(0,CurrentSize-1);
    return CurrentSize-1;
}

int CheckCycle(Vertex V1,Vertex V2)
{
    Vertex Root1 = Find(V1);
    Vertex Root2 = Find(V2);

    if(Root1 == Root2)
    {
	return 0;
    }
    else
    {
	SetUnion(Root1,Root2);
        return 1;
    }
}

int Krustal(int N,int M)
{
   int EdgeN = 0;
   int Cost = 0;
   int NextEdge = M;

   InitializeESet(N);
   InitializeESet(M);

   while(EdgeN < N-1)
   {
	if(NextEdge <= 0)
        {
	    break;
        }
        NextEdge = GetEdge(NextEdge);
        if(CheckCycle(ESet[NextEdge].V1,ESet[NextEdge].V2))
        {
		Cost += ESet[NextEdge].W;
                EdgeN++;
        }
   }
   if(EdgeN < N-1)
   {
	Cost = -1;
   }
   return Cost;
}

int main()
{
   int N = 0;
   int M = 0;
   int i = 0;

   scanf("%d %d",&N,&M);
   if(M < N-1)
   {
      printf(" -1 \n");
   }
   else
   {
	ESet = malloc(sizeof(struct EdgeType)*M);
        for(i=0;i<M;i++)
        {
	   scanf("%d %d %d",&ESet[i].V1,&ESet[i].V2,&ESet[i].W);
        }
        printf("%d\n",Krustal(N,M));
   }
   return 0;
}
