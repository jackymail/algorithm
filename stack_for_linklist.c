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
	return FALSE;
    }
    else
    {
	return TRUE;
    }
}

int Push(Stack S,ElementType X)
{
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
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
        return TopItem;
    }
}







