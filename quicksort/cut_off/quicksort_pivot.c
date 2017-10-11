#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "time.h"

#define ElementType int
#define MAX_SIZE 1000000
#define CUT_OFF 100
#define FILE_NAME "rand_data.txt"

void insertion_sort(int A[],int N)
{
    int p = 0;
    int Tmp = 0;
    int i = 0;

    for(p=1;p<N;p++)
    {
	Tmp = A[p];
        for(i=p;i>0&&A[i-1]>Tmp;i--)
        {
	    A[i] = A[i-1];
        }
        A[i] = Tmp;
    }
    return;
}



void swap_data(int *p,int *q)
{
  printf("the swap data is %d %d\n",*p,*q);
  int a = 0;
  int b = 0;
  if(NULL == p || NULL == q)
  {
      return;
  }

  a = *p;
  b = *q;
  printf("the a and b before switch is %d %d\n",a,b);
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  *p = a;
  *q = b;
  printf("the a and b after switch is %d %d\n",*p,*q);
  return;
}

int choose_pivot(int A[],int left,int right)
{
   int center = (left+right)/2;
   if(A[left] > A[center])
   {
        swap_data(&A[left],&A[center]);
   }
   if(A[left] > A[right])
   {
        swap_data(&A[left],&A[right]);
   }
   if(A[center] > A[right])
   {
        swap_data(&A[center],&A[right]);
   }

   //printf("the left element is %d\n",A[left]);
   //printf("the middle element is %d\n",A[center]);
   //printf("the right element is %d\n",A[right]);

   swap_data(&A[center],&A[right-1]);
   printf("calculate the pivot is %d\n",A[right-1]);
   return A[right-1];
}


void quick_sort(int A[],int start,int end)
{
    int i = 0;
    int j = 0;
    int pivot = 0;
    int temp  = 0;

    if(start >= end)
    {
        printf("i is bigger than j\n");
	return;
    }

    pivot = choose_pivot(A,start,end);
  
    i = start;
    j = end-1;

    printf("outside %s====%d,the i is %d,the j is %d\n",__FUNCTION__,__LINE__,i,j);

    //if(i >= j)
    //{
//	return;
  //  }
    if((end - start) >= CUT_OFF)
    {
    while(1)
    {
        printf("inside %s====%d,the i is %d,the j is %d\n",__FUNCTION__,__LINE__,i,j);
        while(1)
        {
          ++i;
          if(i <= end && i >0)
          {
            if(A[i] < pivot)
            {
	//	i++;
            }
            else
            {
		break;
            }
          }
          else
          {
	      break;
          }
        }
        while(1)
        {
           --j;
           if(j <= MAX_SIZE-1 && j > 0)
           {
           	if(A[j] > pivot)
          	{
		    ;
           	}
           	else
           	{
	     	    break;
           	}
           }
           else
           {
		break;
           }
        } 
       

        if(i < j)
        {
            swap_data(&A[i],&A[j]);
        }
        else
        {
           break;
        }
    }
   
    printf("the i is %d,the end-1 is %d\n",i,end-1);
    if(i < end-1)
    {
	swap_data(&A[i],&A[end-1]);
    }
    quick_sort(A,start,i-1);
    quick_sort(A,i+1,end);
    }
    else
    {
        printf("using cut off\n");
	insertion_sort(A+start,end-start+1);
    }
    return;
}

int main(void)
{
   int A[MAX_SIZE] = {0};
   int index  = 0;
   int fd  = -1;
   int temp = 0;
   int start_time = 0;
   int end_time = 0;
   int time_spent = 0;
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
   start_time = clock();
   quick_sort(A,0,MAX_SIZE-1);
   end_time = clock();
   time_spent = (end_time-start_time)/CLOCKS_PER_SEC;
   printf("the time spent on sorting the array is %d\n",time_spent);
   printf("the sorted array is:\n");
   #if 0
   for(index = 0;index < MAX_SIZE;index++)
   {
	printf("%d\n",A[index]);
   }
   #endif
   close(fd);
   return 0;
}
