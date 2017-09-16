#include "stdio.h"
#include "stdlib.h"

#define MAXN 50

struct TreeNode{
  char Data;
  struct TreeNode *Left;
  struct TreeNode *Right;
};

typedef struct TreeNode *BinTree;


BinTree CreateBinTree(char *Pre,char *In,int len)
{
    BinTree T;
    int i = 0;
    
    if(len == 0)
    {
       return NULL;
    }

    T = malloc(sizeof(struct TreeNode));
    T->Data = Pre[0];
    for(i=0;i<len;i++)
    {
	if(Pre[0] == In[i])
        {
	    break;	
        }
    }
    T->Left =  CreateBinTree(Pre+1,In,i);
    T->Right = CreateBinTree(Pre+i+1,In+i+1,len-i-1);
    return T;
}



int Height(BinTree T)
{
   int THeight = 0;
   int LHeight = 0;
   int RHeight = 0;

   if(!T)
   {
     THeight = 0;
   }
   else
   {
       LHeight = Height(T->Left);
       RHeight = Height(T->Right);
       THeight = (LHeight > RHeight) ? LHeight : RHeight;
       THeight++;
   } 
   return THeight;
}


int main(void)
{
   int N = 0;
   char Pre[MAXN+1]={0};
   char In[MAXN+1]={0};
   
   BinTree T = NULL;
   scanf("%d",&N);
   scanf("%s\n%s",Pre,In);
   
   T = CreateBinTree(Pre,In,N);
   printf("%d\n",Height(T));  
   return 0;
}




