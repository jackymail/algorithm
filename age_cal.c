#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cal_age_number(int *buffer,int number,int *age)
{
  int index_i = 0;
  int index_j = 0;
  if(NULL == buffer || number < 0 || age == NULL)
  {
    return -1;
  }
  for(index_i = 0; index_i<number;index_i++)
  {
    for(index_j = 0;index_j<50;index_j++)
    {
        if(*(buffer+index_i) == index_j)
        {
          *(age+index_j) += 1;
        }
    }
    
  }
  return 0;
}

int main(void)
{
  int number = 0;
  int index = 0;
  int *buffer = NULL;
  int age[50+1] = {0};
  
  printf("please input the value of number:");
  scanf("%d",&number);

  memset(age,-1,sizeof(age));  
  if(number > 0)
  {
    buffer = (int *)malloc(number*sizeof(int));
    if(NULL==buffer)
    {
      printf("fail to allocate memory\n");
      return -1;
    }
  }
  else
  {
      return -1;
  }
  for(index = 0;index <number;index++)
  {
    scanf("%d ",(buffer+index));
  }
  cal_age_number(buffer,number,age);
  for(index = 0;index < number;index++)
  {
    if(age[index] > 0)
    {
    printf("%d:%d\n",index,age[index]);
    }
  }
  free(buffer);
  return 0;
}
