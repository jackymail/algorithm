#include "stdio.h"
#include "stdlib.h"
int sum_calculation(int *data,int number)
{
  int index_i = 0;
  int index_j = 0;
  int sum = 0;
  int maximum_sum = 0;
  if(NULL == data)
  {
//    printf("the data is null\n");
    return -1;
  }
  
  for(index_i = 0;index_i < number;index_i++)
  {
    sum = 0;
    for(index_j = index_i; index_j < number;index_j++)
    {
        sum = sum + *(data+index_j); 
        if(sum > maximum_sum)
        {
          maximum_sum = sum;
        }
    }

  }
  return maximum_sum;
}


int main(void)
{
  int number = 0;
  int index  = 0;
  int *data = NULL;
  int maximum_sum = 0;
  
  scanf("%d",&number);
  
  data = (int*)malloc(number*sizeof(int));
  
  for(index = 0;index < number;index++)
  {
    printf("please input the %d number",index);
    scanf("%d",(data+index));
  }
  
  for(index = 0; index < number;index++)
  {
    printf("the input number are as follow %d\n",*(data+index));
  }

  maximum_sum = sum_calculation(data,number);
  printf("the maximum_sum is %d",maximum_sum);
  
  free(data);
  return 0;
}
