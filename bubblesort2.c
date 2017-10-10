#include "stdio.h"
#include "stdlib.h"

#define MAXIMUN_ELEMENT 100

void insertion_sort(int A[],length)
{
    int p = 0;
    int Tmp = 0;
    int i = 0;
    
    for(p=1;p<N;p++)
    {
	Tmp = A[p];
        for(i = p;i>0&&A[i-1]>Tmp)
        {
	   A[i] = A[i-1];
        }
        A[i] = Tmp;
    }
    return;
}

int main(void)
{
   int index = 0;

   int A[MAXIMUN_ELEMENT] = {0};
   
   for(index=0;index<MAXIMUN_ELEMENT;i++)
   {
	scanf("%d",&A[index]);
   }
   selection_sort(A,MAXIMUN_ELEMENT);
   
   for(index=0;index<MAXIMUN_ELEMENT;index++)
   {
      printf("%d\n",A[index]);
   }

   return 0;
}
