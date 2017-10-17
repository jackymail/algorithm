#include "stdio.h"
#include "stdlib.h"
#define ERRORMin 99999
#define ERRORMax -99999

typedef struct node *Node;
struct node{
  int K1;
  int Max_K1,Min_K1;
  int K2;
  int Left;
  int Right;
}*Dacare;

int n;
int Root();
int DLR(int);
int LDR(int);

int main()
{
   int i = 0;
   scanf("%d",&n);
   Decare = (Node)malloc(sizeof(struct node)*n);
   for(i=0;i<n;i++)
   {
	scanf("%d",&Decare[i].K1);
        scanf("%d",&Decare[i].K2);
        scanf("%d",&Decare[i].Left);
        scanf("%d",&Decare[i].Right);
	Decare[i].Min_K1 = ERRORMin;
        Decare[i].Max_K1 = ERRORMax;
   }
   int head = Root();
   int Result = DLR(head);
   if(Result)
   {
	Result = LRD(head);
   }
   if(Result)
   {
       printf("YES\n");
   }
   else
   {
       printf("NO\n");
   }
   return 0;
}
int Root(){
   int *temp = (int*)malloc(sizeof(int)*n);
   int i = 0;
   for(i=0;i<n;i++)
   {
	temp[i] = 0 ;
   }
   for(i=0;i<n;i++)
   {
	temp[Decare[i].Left] = 1;
        temp[Decare[i].Right] = 1;
   }
   for(i=0;i<n;i++)
   {
      if(!temp[i])
      {
         return i;
      }
   }
   return -1;
}
int DLR(int K)   //k2 minnum heap
{
    if(K == -1)
    {
	return 1;
    }
    if(Decare[K].Left != -1)
    {
	if(Decare[Decare[K].Left].K2 < Decare[K].K2)
        {
	    return 0;
        }
    }
    if(Decare[K].Right != -1)
    {
        if(Decare[Decare[K].Right].K2 < Decare[K].K2)
        {
	    return 0;
        }
    }
    if(DLR(Decare[K].Left == 0))
    {
	return 0;
    }
    if(DLR(Decare[K].Right) == 0)
    {
	return 0;
    }
    return 1;
}

int LDR(int K)   //K1 binary search tree
{
     if(K == -1)
     {
	return 1;
     }
     if(LDR(Decare[K].Left) == 0)
     {
	return 0;
     }
     if(Decare[K].Left == -1)
     {
	Decare[K].Max_K1 = Decare[K].K1;
     }
     else
     {
	Decare[K].Max_K1 = Decare[Decare[K].Right].Max_K1;
     }
     int temp=K;
     if(Decare[temp].Left != -1)
     if(Decare[temp.K1] < Decare[Decare[temp].Left].Max_K1)
     {
	return 0;
     }
     if(Decare[temp].Right != -1)
     {
     }
     if(Decare[temp].K1 > Decare[Decare[temp].Right].Min_K1)
     {
       return 0;
     }
     return 1;
}   










