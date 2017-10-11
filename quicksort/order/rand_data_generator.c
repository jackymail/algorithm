/*
 * 产生随机数,随机数的范围是 0 ~ (x-1),因为进行的是模运算。
 */
#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_VALUE 100000
#define FILE_NAME "rand_data.txt"
#define FILE_NAME_ORDER "order_data.txt"
#define FILE_NAME_REPEAT_DATA "repeat_data.txt"
#define Random(x) (rand()%x)

void generate_order_data()
{
   int index = 0;
   int fd = -1;
   
   fd = open(FILE_NAME_ORDER,O_RDWR|O_CREAT,0777);
   if(fd < 0)
   {
      printf("fail to open the file descriptor");
      return;
   }
 
   for(index = 1;index <= MAX_VALUE;index++)
   {
	write(fd,&index,4);

   }
   
   close(fd);   
   return;
}

void generate_repeat_data()
{
   int index;
   int fd = -1;
   int value = 0;

   fd = open(FILE_NAME_REPEAT_DATA,O_RDWR|O_CREAT,0777);
   if(fd < 0)
   {
      printf("fail to open the file descriptor");
      return;
   }
   
   value = 4;
   for(index = 0;index< MAX_VALUE/4;index++)
   {
	write(fd,&value,4);
   }
   value = 3;
   for(index=MAX_VALUE/4;index < MAX_VALUE/2;index++)
   {
	write(fd,&value,4);
   }
   value = 2;
   for(index=MAX_VALUE/2;index<(MAX_VALUE/4*3);index++)
   {
	write(fd,&value,4);

   }
   value = 1;
   for(index=(MAX_VALUE/4*3);index<MAX_VALUE;index++)
   {
	write(fd,&value,4);
   }
   close(fd);
   return;
}

int main(void)
{
   int i = 0;
   int dis = 0;
   int temp;
   int fd = -1;
   int write_byte = 0;

   fd = open(FILE_NAME,O_RDWR|O_CREAT,0777);
   if(fd < 0)
   {
      printf("fail to open the file descriptor");
      return -1;
   }
 
   
   for(i=0;i<MAX_VALUE;i++)
   {
      temp = Random(MAX_VALUE);
      printf("%d\n",temp);
      write_byte = write(fd,&temp,4);
      printf("the write_byte is %d\n",write_byte);
   }
   
   close(fd);  
   
   generate_order_data();
   generate_repeat_data();
    
   return 0;
}




