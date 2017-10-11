#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define TRUE 1
#define FALSE 0

typedef int ElementType;

struct Node{
   ElementType Data;
   struct Node *Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode Position;

struct QNode{
   Position front;
   Position rear;
   int MaxSize;
};

typedef struct QNode *Queue;

Queue create_queue()
{
   Queue q = (Queue)malloc(sizeof(Queue));
   if(NULL == q)
   {
      return NULL;
   }
   q->front = NULL;
   q->rear = NULL;
   q->MaxSize = 10;
   return q;
}

int IsEmpty(Queue Q)
{
    if(NULL == Q->front)
    {
	return TRUE;
    }
    else
    {
	return FALSE;
    }
}

ElementType DeleteQ(Queue Q)
{
   Position frontCell;
   ElementType frontElement;

   if(IsEmpty(Q))
   {
      printf("queue empty");
      return -1;
   }
   else
   {
	frontCell = Q->front;
        if(Q->front == Q->Rear)
        {
	     Q->front = Q->rear = NULL;
        }
        else
        {
	     Q->front = Q->front->Next;
        }
        frontElement = frontCell->Data;
        free(frontCell);
        return frontElement;
   }
}
void enqueue(Queue Q,int element)
{ 
   Position 


}

int main(void)
{
   Queue q ;
   
   q = create_queue();

   

}

























