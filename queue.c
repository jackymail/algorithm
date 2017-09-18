/*
 *循环队列的实现，A和b队列的第一个元素都是不用的，数据从第二个位置开始存储。（下标为1的位置）
 *判断队列慢的方法为  rear＋1 是否等于front，如果等于就说明已经满了。判断队列为空的的方法为rear 指针是否等于 front指针
 *
 */


#include "stdio.h"
#include "string.h"
#define MaxQSize 1000
#define ERROR -1

typedef struct{
  int Customer[MaxQSize];
  int rear;
  int front;
}Queue;

void InitialQ(Queue *PtrQ)
{
   if(NULL == PtrQ)
   {
      return;
   }
   memset(PtrQ,0,sizeof(Queue));
   PtrQ->rear = PtrQ->front = 0;
}

int IsemptyQ(Queue *PtrQ)
{
   return PtrQ->front == PtrQ->rear;
}

void AddQ(Queue *PtrQ,int Item)
{
   if((PtrQ->rear+1) % MaxQSize == PtrQ->front)
   {
	printf("the queue is full");
        return;
   }
   PtrQ->rear = (PtrQ->rear+1) % MaxQSize;
   PtrQ->Customer[PtrQ->rear] = Item;
   return;
}

int DeleteQ(Queue *PtrQ)
{
   if(PtrQ->front == PtrQ->rear)
   {
	printf("the queue is empty");
        return -1;
   }
   else
   {
	PtrQ->front = (PtrQ->front+1) % MaxQSize;
        return PtrQ->Customer[PtrQ->front];
   }
}
int main(void)
{
   int N = 0;
   int i = 0;
   int cur = 0;
   int flag = 0;
   Queue A,B;

   InitialQ(&A);
   InitialQ(&B);

   scanf("%d",&N);
   
   for(i=0;i<N;i++)
   {
      scanf("%d",&cur);
      if(cur%2)
      {
	AddQ(&A,cur);
      }
      else
      {
	AddQ(&B,cur);
      }
   }
   
   printf("the first element of Queue A is %d\n",A.Customer[0]);
   printf("the first element of Queue B is %d\n",B.Customer[0]);
    
   flag = 0;
   while(!IsemptyQ(&A) && !IsemptyQ(&B))
   {
       if(!flag)
       {
	  printf("%d",DeleteQ(&A));
          flag = 1;
       }
       else
       {
	  printf(" %d",DeleteQ(&A));
       }
       if(!IsemptyQ(&A))
       {
	   printf(" %d",DeleteQ(&A));
       }
       printf(" %d",DeleteQ(&B));
   }
   while(!IsemptyQ(&A))
   {
      if(!flag)
      {
	 printf("%d",DeleteQ(&A));
         flag = 1;
      }
      else
      {
	 printf(" %d",DeleteQ(&A));
      }
   }
     
   while(!IsemptyQ(&B))
   {
      if(!flag)
      {
	printf("%d",DeleteQ(&B));
        flag = 1;
      }
      else
      {
	printf(" %d",DeleteQ(&B));
      }
   }
   printf(" \n");
   return 0;
}





























