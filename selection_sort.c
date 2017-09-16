/*
 *选择排序的基本思路：第一次选定一个元素，接着遍历剩下的n-1个元素
 *找出比第一元素小的最小元素和第一个元素交换。
 *按照同样的方法接着对剩下的N-1个元素进行排序。 
 *
 *
 */
#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 10

void swap(int *data1,int *data2)
{
    if(NULL == data1 || NULL == data2)
    {
	printf("the data is NULL");
        return;
    }
    *data1 = *data1 ^ *data2;
    *data2 = *data1 ^ *data2;
    *data1 = *data1 ^ *data2;
}

int main(void)
{
   int array[ARRAY_SIZE] = {0};
   int i = 0;
   int j = 0;
   int swap_index = 0;
   int min_val = 0;
   int b_need_swap = 0;

   for(i=0;i<ARRAY_SIZE;i++)
   {
     scanf("%d",&array[i]);
   }


  
   for(i=0;i<ARRAY_SIZE-1;i++)
   {
      min_val = array[i];
      for(j=i+1;j<ARRAY_SIZE;j++)
      {
	if(min_val > array[j])
        {
           b_need_swap =1;
	   swap_index = j;
           min_val = array[j];
        }
      }
      if(b_need_swap == 1)
      {
      	swap(&array[i],&array[swap_index]);
      	b_need_swap =0;
      }
   }
   printf("the result of selection sort is:\n");
   for(i=0;i<ARRAY_SIZE;i++)
   {
     printf("%d ",array[i]);
   }
   printf("\n");
   return 0;
}









