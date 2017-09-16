/*
 * 产生随机数,随机数的范围是 0 ~ (x-1),因为进行的是模运算。
 */
#include "stdio.h"
#include "stdlib.h"

#define Random(x) (rand()%x)

int main(void)
{
   int i = 0;
   int dis = 0;
   
   for(i=0;i<100;i++)
   {
      printf("%d\n",Random(100));
   }
  
   return 0;
}




