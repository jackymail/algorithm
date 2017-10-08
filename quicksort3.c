#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ElementType int
#define MAX_SIZE 1000000
#define FILE_NAME "rand_data.txt"

void quick_sort(int A[],int start,int end)
{
    int i = 0;
    int j = 0;
    int pivot = 0;
    int temp  = 0;   
    
    pivot = A[start];
    i = start;
    j = end;
    
    printf("outside %s====%d,the i is %d,the j is %d\n",__FUNCTION__,__LINE__,i,j);
 
        
    if(i > j)
    {
	return;
    }
    
    while(i != j)
    {
        printf("inside %s====%d,the i is %d,the j is %d\n",__FUNCTION__,__LINE__,i,j);
	while(A[j] >= pivot && i < j)
        {
	     j--;
        }

        while(A[i] <= pivot && i < j)
        {
	     i++;
        }
        
        if(i < j)
        {
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
   
     printf("***the i is %d  the j is %d***\n",i,j); 
     A[start] = A[i];
     A[i] = pivot;
    

    quick_sort(A,start,i-1);
    quick_sort(A,i+1,end);
    return ;
}

int main(void)
{
   int A[MAX_SIZE] = {0};
   int index  = 0;
   int fd  = -1;
   int temp = 0;
   printf("please intput %d digits\n",MAX_SIZE);
   
   fd = open(FILE_NAME,O_RDWR,0777);
   if(fd < 0)
   {
      printf("fail to open the file\n");
      return -1;
   }     


   for(index = 0;index < MAX_SIZE;index++)
   {  
        read(fd,&temp,4);
        printf("the temp is %d\n",temp); 
	A[index] = temp;
   }
   
   printf("\n\n\n\nthe index is %d\n\n\n\n\n",index);
     
   quick_sort(A,0,MAX_SIZE-1);

   printf("the sorted array is:\n");
   for(index = 0;index < MAX_SIZE;index++)
   {
	printf("%d ",A[index]);
   }
   close(fd);
   return 0;
}


