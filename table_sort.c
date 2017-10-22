/*
 * -1表示最后页，-2表示未排序 
 *
 */

#include "stdio.h"
#include "string.h"

#define MaxP 1000
#define MaxL 100
#define MaxC 81


struct PageType {
 int next;
 char cont[MaxP][MaxL];
}Page[MaxP];

void ReadPages(int Pn,int Ln)
{
   int i = 0;
   int j = 0;

   for(i=0;i<Pn;i++)
   {
      for(j=0;j<Ln;j++)
      {
	gets(Page[i].cont[j]);
        Page[i].next = -2;
      }
   }
}

int SortPages(int Pn,int Ln)
{
     int head = 0;
     int tail = 0;
     int i = 0;

     head = tail = 0;
     Page[0].next = -1;
     if(Pn == 1)
     {
	return 0;
     }
     i = 1;
     while(i != tail)
     {
        printf("from i to tail,the i is %d,the tail is %d\n",i,tail);
        //printf("aaa the Page[i].next is %d\n",Page[i].next);
        //printf("aaa the lastline is %s,the first line is %s\n",Page[tail].cont[Ln-1],Page[i].cont[0]);
	if((Page[i].next == -2) && !strcmp(Page[tail].cont[Ln-1],Page[i].cont[0]))
        {
             printf("kkk tail head equal ,change the next item to %d\n",i);
             Page[tail].next = i;
             tail = i;
             Page[tail].next = -1;
        }
        i = (i+1)%Pn;
     }

     for(i=0;i<Pn;i++)
     {
        printf("the page[%d].next is %d",i,Page[i].next);
     }
     i = 1;
     while(i != head)
     {
	printf("from i to head,the i is %d,the head is %d\n",i,head);
	//printf("bbb the Page[i].next is %d\n",Page[i].next);
        //printf("bbb the lastline is %s,the first line is  %s\n",Page[i].cont[Ln-1],Page[head].cont[0]);
        if((Page[i].next == -2) && (!strcmp(Page[i].cont[Ln-1],Page[head].cont[0])))
        {
           printf("kkk tail head equal,check the next to %d\n",head);
	   Page[i].next = head;
           head = i;
        }
        i = (i+1)%Pn;
     }
     return head;
}
void Output(int head,int Ln)
{
   int i = 0;
   int j = 0;
   for(j=0;j<Ln;j++)
   {
	printf("%s \n",Page[head].cont[j]);
   } 
   for(i=Page[head].next;i!=-1;i=Page[i].next)
   {
	for(j=1;j<Ln;j++)
        {
           printf("%s \n",Page[i].cont[j]);
        }
   }
}

int main()
{
   int Pn;
   int Ln;
   scanf("%d %d\n",&Pn,&Ln);
   ReadPages(Pn,Ln);
   printf("the result is as follow\n");
   Output(SortPages(Pn,Ln),Ln); 
   return 0;
}


















