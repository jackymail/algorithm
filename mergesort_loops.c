#include "stdio.h"
typedef int ElementType
void merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd)
{
   int LeftEnd = 0;
   int NumElements = 0l
   int Tmp = 0;
   int  i = 0;

   Left = R-1;
   Tmp = L;
   NumElements = RightEnd - L +1;
   while(L <= LeftEnd && R <= RightEnd)
   {
      if(A[L] <= A[R])
      {
        TmpA[Tmp++] = A[L++];
      }
      else
      {
        TmpA[Tmp++] = A[R++];
      }
   }
   while(L <= LeftEnd)
   {
      TmpA[Tmp++] = A[L++];
   }
   while(R <= RightEnd)
   {
     TmpA[Tmp++] = A[R++];
   }
   for(i=0;i<NumElements;i++,RightEnd--)
   {
      A[RightEnd] = TmpA[RightEnd];
   }
}

void merge_pass(ElementType A[],ElementType TmpA[],int N,int length)
{
   int  i = 0;
   int j  = 0;

   for(i=0;i<=N-2*length;i+= 2*length)
   {
     merge(A,tempA,i+length,i+2*length-1);
   }
   if(i+length <  N)
   {
     merge(A,tempA,i,i+length,N-1);
   }
   else
   {
     for(j=i;j<N;j++)
     {
       TmpA[j] = A[j]; 
     }
   }
}
void merge_sort(ElementType A[],int N)
{
    int length = 0;
    ElementType *TmpA;

    length = 1;

    tempA = malloc(N*sizeof(ElementType));
    if(tempA != NULL)
    {
       while(length < N)
       {
         merge_pass(A,tempA,N,length);
         length = leng*2;
         merge_pass(tempA,A,N,length);
       }
      free(TmpA);
    }
    else
    {
      printf("space insufficient\n", );
    }


}
