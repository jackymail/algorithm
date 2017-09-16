#include "stdio.h"
#include "stdlib.h"

#define ARRAY_NUMBER 10

void insertion_sort(int array[],int number)
{
   int i = 0;
   int j = 0;
   int temp = 0;
   
   for(i=1;i<number;i++)
   {
      temp = array[i];
      for(j=i;j>0 && (temp > array[j-1]);j--)
      {
	    array[j] = array[j-1];
      }
      array[j] = temp;
   }
   return;    
}


int main(void)
{
   int index = 0;
   int array[ARRAY_NUMBER] = {0};

   for(index = 0;index < ARRAY_NUMBER;index++)
   {
	scanf("%d",&array[index]);
   }

  
   insertion_sort(array,ARRAY_NUMBER);

   printf("the sorted array is : \n");
   for(index = 0;index < ARRAY_NUMBER;index++)
   {
       printf("%d\n",array[index]);  
   }
   return 0;
}
