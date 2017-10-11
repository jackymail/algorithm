#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int ElementType;
#define TRUE 1
#define FALSE 0

struct SNode{
   ElementType Data;
   struct SNode *Next;
};

typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;

Stack Create()
{
    Stack S;

    S=(Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(Stack S)
{
    if(S->Next == NULL)
    {
	return TRUE;
    }
    else
    {
	return FALSE;
    }
}

void Push(Stack S,ElementType X)
{
    printf("the S->Next is %x\n",S->Next);
    printf("push %d to the stack\n",X);
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    //S = S->Next;
    return;
}


ElementType Pop(Stack S)
{
    PtrToSNode FirstCell;
    ElementType TopElem;

    if(IsEmpty(S))
    {
	printf("stack empty\n");
        return -1;
    }
    else
    {
	FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}
int main(void)
{
   Stack S = Create();
   int index  = 0;

   Push(S,1);
   Push(S,2);
   Push(S,3);
   printf("begin to pop element\n");
   
   for(index= 0;index < 3;index++)
   {
      printf("pop the value %d\n",Pop(S));
   }

   return 0;
}






