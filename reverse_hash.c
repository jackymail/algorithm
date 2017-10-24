#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXN 1000

struct TableRecord{
    int TableSize;
    int T[MAXN];
};

typedef struct TableRecord *Table;

struct GraphRecord{
  int NumVert;
  int M[MAXN][MAXN];
};

typedef struct GraphRecord *Graph;

struct HeapRecord{
   int Index;
   int Num;
};

typedef struct HeapRecord *HeapNode;

struct HeapStruct{
   int HeapSize;
   HeapNode Elements;
};

typedef struct HeapStruct *MinHeap;

void InsertHeap(HeapNode X,MinHeap Q);
HeapNode DeleteMin(MinHeap Q);

Table Read(int N)
{
   int i = 0;
   Table HT = (Table)malloc(sizeof(struct TableRecord));
   HT->TableSize = N;
   
   for(i=0;i<N;i++)
   {
	scanf("%d",&HT->T[i]);
   }
   return HT;
}

Graph ConstructG(Table HT,int N)
{
   int i = 0;
   int j = 0;
   Graph G = (Graph)malloc(sizeof(struct GraphRecord));

   for(i=0;i<HT->TableSize;i++)
   {
      for(j=0;j<HT->TableSize;j++)
      {
	G->M[i][j] = 0;
      }
   }

   for(i=0;i<HT->TableSize;i++)
   {
      if(!(HT->T[i] < 0)){
	j = HT->T[i]%HT->TableSize;
        while(i != j)
        {
	   G->M[j][i] = 1;
           j = (j+1)%HT->TableSize;
        }
      }
   }

   G->NumVert = HT->TableSize;
   return G;
}

void InsertHeap(HeapNode X,MinHeap Q)
{
    int i = 0;
    for(i=++Q->HeapSize;Q->Elements[i/2].Num;i/=2)
    {
	Q->Elements[i].Num = Q->Elements[i/2].Num;
        Q->Elements[i].Index = Q->Elements[i/2].Index;
    }
    Q->Elements[i].Num = X->Num;
    Q->Elements[i].Index = X->Index;
}
HeapNode Delete_Min(MinHeap Q)
{
    int i = 0;
    int child = 0;

    HeapNode MinT = (HeapNode)malloc(sizeof(struct HeapRecord));
    HeapNode LastT = (HeapNode)malloc(sizeof(struct HeapRecord));

    MinT->Num = Q->Elements[1].Num;
    MinT->Index = Q->Elements[1].Index;
    LastT->Num = Q->Elements[Q->HeapSize].Num;
    LastT->Index = Q->Elements[Q->HeapSize--].Index;


    for(i=1;i*2<=Q->HeapSize;i=child)
    {
	child = i*2;
        if(child!=Q->HeapSize && Q->Elements[child+1].Num < Q->Elements[child].Num)
        {
	   child++;
        }
	if(LastT->Num > Q->Elements[child].Num)
        {
	    Q->Elements[i].Num = Q->Elements[child].Num;
            Q->Elements[i].Index = Q->Elements[child].Index;
        }
        else
        {
	    break;
        }
    }
    Q->Elements[i].Num = LastT->Num;
    Q->Elements[i].Index = LastT->Index;

    return MinT;
}

void Top_Sort(Graph G,Table HT,int N)
{
   MinHeap Q = (MinHeap)malloc(sizeof(struct HeapStruct));
   HeapNode Tmp = (HeapNode)malloc(sizeof(struct HeapRecord));
   int i = 0;
   int j = 0;
   int InDegree[MAXN];
   int flag = 0;

   Q->Elements = (HeapNode)malloc((G->NumVert+1) * sizeof(struct HeapRecord));
   Q->HeapSize = 0;
   Q->Elements[0].Num = -1;

   for(i=0;i<G->NumVert;i++)
   {
	InDegree[i] = 0;
        if(!(HT->T[i] <0))
        {
	   for(j=0;j<G->NumVert;j++)
           {
		InDegree[i] += G->M[j][i];
           }
           if(!InDegree[i])
           {
		Tmp->Index = i;
                Tmp->Num = HT->T[i];
                InsertHeap(Tmp,Q);
           }
        }
   }

   while(Q->HeapSize)
   {
	Tmp = Delete_Min(Q);
        if(flag)
        {
	  printf(" %d",Tmp->Num);
        }
        else
        {
	  printf("%d",Tmp->Num);
        }
        i = Tmp->Index;
        for(j=0;j<G->NumVert;j++)
        {
	    if(G->M[i][j])
            {
		InDegree[j]--;
                if(!InDegree[j])
                {
		   Tmp->Index = j;
                   InsertHeap(Tmp,Q);
                }
            }
        }
   }
   printf(" \n");
}

int main()
{
  Graph G;
  Table  HT;
  int N;

  scanf("%d",&N);
  HT = Read(N);
  G = ConstructG(HT,N);
  Top_Sort(G,HT,N);  
  return 0;
}































































