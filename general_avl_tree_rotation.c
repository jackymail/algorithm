#include "stdio.h"
#include "stdlib.h"

typedef struct AVLNode *Position;
typedef Position AVLTree;
#define int ElementType

struct AVLNode{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;	
};


int Max(int a,int b)
{
    return a > b ? a:b;
}

AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left),A->Height) + 1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleLeftRotation(A->Left);
    return SingleLeftRotation(A);
}

AVLTree Insert(AVLTree T,ElementType X)
{
    if(!T)
    {
	T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    }
    else if(X < T->Data)
    {
      T->Left = Insert(T->Left,X);
      if(GetHeight(T->Left)- GetHeight(T->Right) == 2)
      {
	if(X < T->Left->Data)
        {
	   T = SingleLeftRotation(T);
        }
        else
        {
	   T = DoubleLeftRightRotation(T);
        }
      }
    }
    else if(X > T->Data)
    {
	T->Right = Insert(T->Right,X);
        if(GetHeight(T->Left) - GetHeight(T->Right) == 2)
        {
	    if(X > T->Right->Data)
            {
		T = SingleLeftRotation(T);
            } 
            else
            {
		T = DoubleLeftRightRotation(T);
            }
        }
    }
    T->Heigh = Max(GetHeight(T->Left),GetHeight(T->Right) + 1);
    return T;
}





























