#include "stdio.h"
#include "stdlib.h"

#define CUT_OFF 1
#define MAX_NUMBER 10

int swap(int *p,int *q)
{
  int a = 0;
  int b = 0;
  if(NULL == p || NULL == q)
  {
      return -1;
  }
  
  a = *p;
  b = *q;
//  printf("the a and b before switch is %d %d\n",a,b);  
#if 0
  a = a+b;
  b = a-b;
  a = a-b;
#else
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
#endif
  *p = a;
  *q = b;
  //printf("the a and b after switch is %d %d\n",*p,*q);
  return 0;
}
void printarray(int A[])
{
  int index = 0;
  printf("the array after median3 is as follow\n");
  for(index=0;index<MAX_NUMBER;index++)
  {
     printf("%d\n",A[index]);
  }
  return;
}


int median3(int A[],int left,int right)
{
   int center = (left+right)/2;
   if(A[left] > A[center])
   {
	swap(&A[left],&A[center]);
   }
   if(A[left] > A[right])
   {
	swap(&A[left],&A[right]);
   }
   if(A[center] > A[right])
   {
	swap(&A[center],&A[right]);
   }

   //printf("the left element is %d\n",A[left]);
   //printf("the middle element is %d\n",A[center]);
   //printf("the right element is %d\n",A[right]);
  
   swap(&A[center],&A[right-1]);
   printf("calculate the pivot is %d\n",A[right-1]);
   return A[right-1];
}
// merger sort implementation

// bubble sort implementation
void insertion_sort(int A[],int N)
{
  int p = 0;
  int Tmp = 0;
  int i = 0;

  for(p=1;p<N;p++)
  {
     Tmp = A[p];
     for(i = p;i>0&&A[i-1]>Tmp;i--)
     {
	A[i] = A[i-1];
     }
     A[i] = Tmp;
  }
  return;
}
int quick_sort(int A[],int left,int right)
{
   int pivot = 0;
   int l = 0;
   int r = 0;
   if(left >= right)
   {
      printf("exceed limit,break\n");
      return 0;
   }
   if((right-left) >= CUT_OFF)
   {
      pivot = median3(A,left,right);
      printarray(A);
      l = left;
      r = right -1;
      printf("the l is %d,the r is %d\n",l,r);
      while(1)
      {
	while(A[++l] < pivot);
        while(A[--r] > pivot);
        if(l < r)
        {
	   printf("normal switch  A[%d] is smaller than A[%d],%d %d\n",l,r,A[l],A[r]);
	   swap(&A[l],&A[r]);
    //       printf("swap data\n");
        }
	else
        {
      //     printf("break\n");
	   break;
        }
      }
  
      printf("ajust switch A[%d] is smaller than A[%d],%d %d\n",l,(right-1),A[l],A[right-1]);
      if(l<right-1)
      {
      	swap(&A[l],&A[right-1]);
      }
      printf("left side quick sort %d %d\n",left,l-1);
      quick_sort(A,left,l-1);
      printf("right side quick sort %d %d\n",l+1,right);
      quick_sort(A,l+1,right);
   }
   else
   {
     printf("using insertion sort\n");
     insertion_sort(A+left,right-left+1);
   }
   return 0;
}

int main(void)
{
   int index = 0;
   int array[MAX_NUMBER+1] = {0};
   
   for(index = 0;index<MAX_NUMBER;index++)
   {
      #if 0
      //printf("please input the number\n");
      scanf("%d",&array[index]);
      #else
      array[index] = rand()/MAX_NUMBER;
      #endif
   }   

   //printf("the array before sorted is\n");
   
   for(index =0;index < MAX_NUMBER;index++)
   {
      printf("%d\n",array[index]);
   }
   printf("\n");
   quick_sort(array,0,MAX_NUMBER-1);
   
   //printf("the sorted array is as follow\n");
   for(index =0;index < MAX_NUMBER;index++)
   {
      printf("%d\n",array[index]);
   }
   return 0;
}
