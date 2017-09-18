/**
 * 操作数组
 *
 **/

#include "stdio.h"

#define MaxSize 10

typedef int ElementType;

typedef struct{
    ElementType Data[MaxSize];
    int Top;
}Stack;

void Push(Stack *PtrS,ElementType item)
{
   if(PtrS->Top == MaxSize -1)
   {
        printf("stack is full");
        return;
   }
   else
   {	
	PtrS->Data[++(PtrS->Top)] = item;
        return;
   }
}

ElementType Pop(Stack *PtrS)
{
    if(PtrS->Top == -1)
    {
	printf("stack is empty\n");
        return -1;
    }
    else
    {
	PtrS->Top--;
        return (PtrS->Data[PtrS->Top+1]);
    }

}
int main(void)
{
   int index = 0;
   int temp = 0;
   Stack S;
   
   S.Top = -1;
   
   for(index = 0;index<MaxSize;index++)
   {
	scanf("%d",&temp);
        Push(&S,temp);
   }
 
   for(index = 0;index<MaxSize;index++)
   {
	temp = Pop(&S);
        printf("the temp data is %d\n",temp);
   }

   return 0;
}





