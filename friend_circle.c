#include "stdio.h"

#define MAXN 30000

typedef int DisjSet[MAXN+1];
typedef int SetType;
typedef int ElementType;




void Initialization(DisjSet S,int N)
{
    int i = 0;
    for(i=N;i>0;i--)
    {
	S[i] = -1;
    }
    return;
}  
int setUnion(DisjSet S,SetType Root1,SetType Root2)
{
    if(S[Root2] < S[Root1])
    {
	S[Root2] += S[Root1];
        S[Root1] = Root2;
        return Root2;
    }
    else
    {
	S[Root1] += S[Root2];
        S[Root2] = Root1;
        return Root1;
    }

}
SetType Find(ElementType X,DisjSet S)
{
    if(S[X] <= 0)
    {
        printf("find root ,the root is %d\n",X);
	return X;
    }
    else
    {
	//return 
        S[X] = Find(S[X],S);
        printf("the root is %d\n",S[X]);
        return S[X];
    }
}



void Input_connection(DisjSet S)
{
   ElementType u = 0;
   ElementType v = 0;
   SetType Root1 = 0;
   SetType Root2 = 0;
   int m = 0;
   int i = 0;

   scanf("%d %d",&m,&u);
   
   Root1 = Find(u,S);
   for(i=1;i<m;i++)
   {
	scanf("%d",&v);
        Root2 = Find(v,S);
        printf("the Root1 is %d,the Root2 is %d\n",Root1,Root2);

        if(Root1 != Root2)
        {
	   Root1 = setUnion(S,Root1,Root2);
        }
   }
}


void check_friends(DisjSet S,int N)
{
   int i = 0;
   int max = 1;
   
   for(i=1;i<=N;i++)
   {	
      if(S[i] < 0 && max < -S[i])
      {
	 max = -S[i];
      }
   }
   printf("%d\n",max);
}


int main(void)
{
    DisjSet S;
    int N = 0;
    int M = 0;
    int i = 0;

    scanf("%d %d\n",&N,&M);
    Initialization(S,N);
    for(i=0;i<M;i++)
    {
	Input_connection(S);
    }
    
    check_friends(S,N);
   
    return 0;
}
















