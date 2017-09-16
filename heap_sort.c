#include "stdio.h"
#include "stdlib.h"

#define MAXM 5
typedef int ElementType;



void Ajust(ElementType A[],int start,int M)
{
    int parent = 0;
    int child = 0;
    int temp = 0;

    temp = A[start];
    
    for(parent=start; (parent*2+1) < M;parent=child) 
    {
	child = parent*2+1;
        if(child != (M-1) && A[child] > A[child+1])
        {
	    child++;
        }
        if(temp >  A[child]) 
        {
	   A[parent] = A[child];
        }
        else
        {
	   break;
        }
        
    }  
    A[parent] = temp;
    return;
}
int main()
{
  int N = 0;
  int M = 0;
  int i = 0;
  ElementType A[MAXM] = {0};
  ElementType temp = 0;

  scanf("%d %d",&N,&M);
  
  //if(N > MAXM)
  {
     for(i=0;i<M;i++)
     {
        printf("please input %d data\n",i);
	scanf("%d",&A[i]);
     }
     for(i=(M-1) >> 1;i>=0;i--)
     {
	Ajust(A,i,M);
     }
     for(i=M;i<N;i++)
     {
        printf("please input %d data\n",i);
        scanf("%d",&temp);
        if(temp > A[0])
        {
          A[0] = temp;
          Ajust(A,0,M);
        }
     }

     for(i=M-1;i>0;i--)
     {
	temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        Ajust(A,0,i);
     }     
  }
 // else
  {
    //use insertion sort\n;

  }
  
  if(N<M)
  {
     M = N;
  }
  printf("the sorted array is \n");
  for(i=0;i<M;i++)
  {  
    printf("%d ",A[i]);
  }
  printf("\n");

  return 0;
}




