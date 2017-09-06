#include "stdio.h"
int main(void)
{
   int  i = 0;
   int j = 0;
   int n = 0;
   int m = 0;
   int a = 0;
   int b = 0;
   int cur = 0;
   int book[101] = {0};
   int e[101][101];


   scanf("%d %d",&n,&m);
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
	if(i==j)
        {
          e[i][j] = 0;
        }
	else
        {
	   e[i][j] = 999999999;
        }
     }
   }

   for(i=1;i<=m;i++)
   {
	scanf("%d %d",&a,&b);
        e[a][b] = 1;
        e[b][a] = 1;
   }
  
   head =1;
   tail =1;

   que[tail] = 1;
   tail++:
   book[1] = 1;
   while(head < tail && tail <=n)
   {
	cur = que[head];
        for(i=1;i<=n;i++)
        {
	   if(e[cur][i] == 1 && book[i] == 0)
           {
		que[tail] = i;
                tail++;
                book[i] = 1;
           }
          
           if(tail > n)
           {
		break;
           }

        }
	head++;
   }
   for(i=1;i<=tail;i++)
   {
      printf("%d ",que[i]);
   }

   getchar();
   getchar();
   return 0;
}
