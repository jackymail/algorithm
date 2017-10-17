#include "stdio.h"
#include "stdlib.h"

#define SIX 6
#define MaxVertexNum 1000

typedef unsigned long VertexType;

typedef struct node{
    VertexType Adjv;
    struct node *Next;
}EdgeNode;

typedef struct Vnode{
  char visited;
  double Percent;
  EdgeNode *FirstEdge;
}VertexNode;

typedef VertexNode AdjList[MaxVertexNum];

typedef struct {
   AdjList adjlist;
   unsigned long int n,e;
}ALGraph;

typedef struct Element {
  VertexType v;
  int Layer;
}QElementType;

typedef struct Node {
  QElementType Data;
  struct Node *Next;
}QNode;

typedef struct{
  QNode *rear;
  QNode *front;
}LinkQueue;

void Initialize(LinkQueue *PtrQ)
{
    PtrQ->rear = PtrQ->front = NULL;
}

int IsEmptyQ(LinkQueue *PtrQ)
{
    return PtrQ->front == NULL;
}

void AddQ(LinkQueue *PtrQ,QElementType item)
{
  QNode *cell = (QNode *)malloc(sizeof(QNode));
  cell->Data = item;
  cell->Next = NULL;

  if(IsEmptyQ(PtrQ))
  {
    PtrQ->front = PtrQ->rear = cell;
  }
  else
  {
    PtrQ->rear->Next = cell;
    PtrQ->rear = cell;
  }
}

QElementType DeleteQ(LinkQueue *PtrQ)
{
    QNode *frontCell;
    QElementType  FrontElem;

    if(PtrQ->front == NULL)
    {
       printf("queue empty\n");
       exit(0);
    }
    frontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear)
    {
       PtrQ->front = PtrQ->rear = NULL;
    }
    else
    {
       PtrQ->front = PtrQ->front->Next;
    }
    FrontElem = frontCell->Data;
    free(frontCell);
    return FrontElem;
}

void DestroyQueue(LinkQueue Q)
{
    QNode *cell;
    while(cell = Q.front)
    {
      Q.front = Q.front->Next;
      free(cell);
    }
}

void CreateALGraph(ALGraph *G)
{
    unsigned long int i,j,k;
    EdgeNode *edge;

    scanf("%ld %ld", &(G->n),&(G->e));
    for(i=0;i<G->n;i++)
    {
      G->adjlist[i].visited = 0;
      G->adjlist[i].Percent = 0.0;
      G->adjlist[i].FirstEdge = NULL;
    }
    for(k=0;k<G->e;k++)
    {
        scanf("%ld %ld",&i,&j);
        edge = (EdgeNode *)malloc(sizeof(EdgeNode));
        edge->Adjv = j-1;
        edge->Next = G->adjlist[i-1].FirstEdge;
        G->adjlist[i-1].FirstEdge = edge;
        edge->Adjv = i - 1;
        edge->Next = G->adjlist[j-1].FirstEdge;
        G->adjlist[j-1].FirstEdge = edge;
    }
}

void six_degree_bfs(ALGraph *G,VertexType Start)
{
  QElementType qe;
  LinkQueue Q;
  VertexType v;
  EdgeNode *edge;
  unsigned long int visitCount = 1;
  Initialize(&Q);
  G->adjlist[Start].visited = 1;
  qe.v = Start;
  qe.Layer = 0;
  AddQ(&Q,qe);
  while (!IsEmptyQ(&Q)) {
    qe = DeleteQ(&Q);
    v = qe.v;
    for(edge = G->adjlist[v].FirstEdge;edge;edge = edge->Next)
    {
        G->adjlist[edge->Adjv].visited = 1;
        visitCount++;
        if(++qe.Layer < SIX)
        {
          qe.v = edge->Adjv;
          AddQ(&Q,qe);
        }
        qe.Layer--;
    }
  }
  DestroyQueue(Q);
  G->adjlist[Start].Percent = 100.0 * (double)visitCount /(double)G->n;
}

int main()
{
  VertexType i = 0;
  VertexType j = 0;
  ALGraph *G = malloc(sizeof(ALGraph));  
  CreateALGraph(G);

  for(i=0;i<G->n;i++)
  {
    six_degree_bfs(G,i);
    printf("%ld:%.2f%%\n",i+1,G->adjlist[i].Percent);
    for(j=0;j<G->n;j++)
    {
      G->adjlist[j].visited = 0;
    }
  }
  return 0;
}
