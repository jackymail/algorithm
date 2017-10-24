#include "stdio.h"
#include "stdlib.h"

#define MAXN  50

typedef struct TreeNode *BinTree;

struct TreeNode{
  char Data;
  BinTree Left;
  BinTree Right;
};

BinTree CreateBinTree(char *Pre,char *In;int Len)
{
    BinTree T;
    int i = 0;
    if(Len <= 0)
    {
	return NULL;
    }  
    T = malloc(sizeof(struct TreeNode));
    T->Data = Pre[0];
    for(i=0;i<Len;i++)
    {
	if(Pre[0] == In[i])
        break;
    }
    
    T->Left =  CreateBinTree(Pre+1,In,i);
    T->Right = CreateBinTree(Pre+i+1,In+i+1,Len-i-1);
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
        RHeigh = Height(T->Right);
        THeight = (LHeight > RHeight) ? LHeight:RHeight;
        Theight++;
    }
    return THeight;
}

int main()
{
  int N = 0;
  char Pre[MAXN+1];
  char In[MAXN+1];
  BinTree T = NULL;

  scanf("%d",&N);
  scanf("%s\n%s",Pre,In);

  T = CreateBinTree(Pre,In,N);
  printf("%d\n",Height(T));
  return 0;
}






