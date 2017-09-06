#include "stdio.h"

struct node
{
   int x;
   int s;
};

int main()
{
   struct note queue[2501];
   int e[51][51] = {0};
   int book[51] = {0};
   int head = 0;
   int tail = 0;
   int i,j,n,m,a,b,cur,start,end,flag;
   scanf("%d %d %d %d",&n,&m,&start,&end);
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
		e[i][j] = 99999999;
           }
        }
   }
   for(i=1;i<=m;i++)
   {
	scanf("%d %d",&a,&b);
        e[a][b] = 1;
        e[b][a] = 1;
   }

   head  =1;
   tail  = 1;
   que[tail].x = start;
   que[tail].s = 0;
   tail++;
   book[start] = 1;
   
   while(head < tail)
   {
      cur = que[head].x;
      for(j=1;j<=n;j++)
      {
	if(e[cur][j] != 99999999 && book[j] == 0)
        {
	   que[tail].x = j;
           que[tail].s = que[head].s+1;
           tail++;
           book[j] = 1;
        }
        if(que[tail-1].x == end)
        {
	   flag = 1;
           break;
        }

      }  
      if(flag == 1)
      {
	break;
      }
      head++;
   }
   printf("%d",que[tail-1].s);
   getchar(); 
   getchar();
}
