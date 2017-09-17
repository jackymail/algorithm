#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

struct AVLNode{
  ElementType Data;
  struct AVLNode *Left;
  struct AVLNode *Right;
  int Height;
};

typedef struct AVLNode *Position;
typedef Position AVLTree;

int max (int a,int b)
{
   return a > b ? a :b;
}
/*
 *获取树的高度
 */
int GetHeight(AVLTree A)
{
    if(NULL == A)
    {
	return -1;
    }
    return A->Height;
}


/*
 *单左旋转 A必须有一个左子节点
 */
AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = NULL;
    if(NULL == A)
    {
        printf("%s,%d A is NULL\n",__FUNCTION__,__LINE__);
	return NULL;
    }
    
    B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    
    A->Height = max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
    B->Height = max(GetHeight(B->Left),A->Height) + 1;
    return B;
}
/*
 * 单右旋转
 */
AVLTree SingleRightRotation(AVLTree A)
{
     AVLTree B = NULL;
     if(NULL == A)
     {
        printf("%s,%d A is NULL\n",__FUNCTION__,__LINE__);
	return NULL;
     }

     B = A->Right;
     A->Right = B->Left;
     B->Left = A;
 
     A->Height = max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
     B->Height = max(GetHeight(B->Right),A->Height) + 1;
     return B;
}
/*
 *双左右旋转 A必须有一个左子节点B,B必须有一个右子节点C
 */
AVLTree DoubleLeftRightRotation(AVLTree A)
{
   A->Left = SingleRightRotation(A->Left);

   return SingleLeftRotation(A);


}

/*
 *双右左旋转 A节点必须有一个右子节点A,B节点必须有一个左子节点C
 */
AVLTree DoubleRightLeftRotation(AVLTree A)
{
   A->Right = SingleLeftRotation(A->Right);
   return SingleRightRotation(A);
}
/*
 *节点插入二叉树
 */
AVLTree insert(AVLTree T,ElementType X)
{
    if(NULL == T)
    {
	T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    }
    else if(X < T->Data)
    {
	T->Left = insert(T->Left,X);
        if((GetHeight(T->Left) - GetHeight(T->Right)) == 2)
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
	T->Right = insert(T->Right,X);
        if((GetHeight(T->Left) - GetHeight(T->Right)) == -2)
        {
           if(X > T->Right->Data)
           {
		T = SingleRightRotation(T);
           }
           else
           {
		T = DoubleRightLeftRotation(T);
           }
		
        }
    }
     //else X == T->Data 相等就不插入了。
 
    T->Height = max(GetHeight(T->Left),GetHeight(T->Right)) + 1;
    return T;
}

int main(void)
{
   int number = 0;
   int value = 0;
   AVLTree root = NULL;

   scanf("%d",&number);
   while(number--)
   {
      scanf("%d",&value);
      root = insert(root,value);
   }
   printf("the root value is %d\n",root->Data);
   printf("the height is %d\n",root->Height);
   return 0;
}













