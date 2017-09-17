#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct
{
 int number;
 int flag;
}Element;




int main(void)
{
  int index = 0;
  int delete_index = 0;
  int deviation = 0;
  int left_number = 10;
  Element element[10];
  
  memset(&element[0],0,sizeof(Element)*10);

  for(index=0;index<10;index++)
  {
     printf("please input the number %d\n",index);
     scanf("%d",&element[index].number);
     element[index].flag = 0;
  }

  for(index=0;index < 10;index++)
  {
     printf("the %d element is %d\n",index,element[index].number);
  }
  index  = 0;  //index 重新归0.
  while(1)
  {
    //printf("outside the index is %d\n",index);
    if(element[index].flag == 0) //遇到没有被删除过的数字 delete_index++;
    {
      ++delete_index;
    }
    if(delete_index == 3) //delete_index 碰到三次后（可以不连续），才做删除处理。
    {
      //  printf("the index is %d\n",index);
        left_number--;
        delete_index = 0;
	element[index].flag = 1;
        printf("delete number %d %d\n",index,element[index].number);
        if(left_number == 0)
        {
             printf("the left number is %d",left_number);
	     break;
        }
    }
    index++;
    index = index %10;  // 取模处理，index范围都被处理成0～9
  }   
  printf("the last element to be deleted is %d\n",index);
  return 0;
}
