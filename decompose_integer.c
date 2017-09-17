#include "stdio.h"
#include "string.h"

#define MAXN 30
#define MAXString 1024

int Count;

void Search(int remainder,int start, char *sterms);


int main()
{
   char sterms[MAXString] = "";
   int N;
  
   Count = 0;

   scanf("%d",&N);
   sprintf(sterms,"%d=",N);
   Search(N,1,sterms);
   if(Count % 4 != 0)
   {
      printf("\n");
   }
   return 0;
}
void Search(int remainder,int start,char *sterms)
{
   int i = 0;
   char temps[MAXString] = {0};
   
   if(sterms == NULL)
   {
     printf("the sterms is null\n");
     return;
   }
   
   strcpy(temps,sterms);
   for(i=start; i<=remainder; i++)
   {
	if(remainder - i >= i)
        {
	   sprintf(temps+strlen(sterms),"%d + ",i);
           Search(remainder-i,i,temps);
        }
        else if(remainder - i == 0)
        {
     	   sprintf(temps+strlen(sterms),"%d",i);
           Count++;
           if((Count % 4) != 1)
           {
		printf(";");
           }
           printf("%s",temps);
           if(Count % 4 == 0)
           {
	      printf("\n");
           }
        }
   }
}











