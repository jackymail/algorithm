#include "stdio.h"
#include "stdlib.h"

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
void Msort(ElementType A[],ElementType TmpA[],int l,int RightEnd)
{
    int Center;
    if(L <RightEnd)
    {
      Center = (L + RightEnd)/2;
      Msort(A,TmpA,L,Center);
      Msort(A,TmpA,Center+1,RightEnd);
      Msort(A,TmpA,L,Center+1,RightEnd);
    }
}
void MergeSort(ElementType A[],int N)
{
    ElementType *TmpA;
    TmpA =(ElementType *)malloc(N * sizeof(ElementType));

    if(TmpA != NULL)
    {
      Msort(A,TmpA,0,N-1);
      free(TmpA);
    }
    else
    {
      printf("space insufficient\n");
    }

}
