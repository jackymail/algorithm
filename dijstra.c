#include "stdio.h"

int main(void)
{
   int e[10][10];
   int dis[10];
   int book[10];
   int i;
   int j;
   int n;
   int m
   int t1;
   int t2;
   int t3;
   int u;
   int v;
   int min;
   int inf = 99999999;

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
	   e[i][j] = inf;
        }
      }
   }

   for(i=1;i<=m;i++)
   {
	dis[i] = e[1][i];
   }

   for(i=0;i<=n;i++)
   {
      book[i] = 0;
   } 
   book[1] = 1;
   
   for(i=1;i<=n-1;i++)
   {
       min = inf;
       for(j=1;j<=n;j++)
       {
	  if(book[j] == 0 && dis[j] < min)
          {
	     min = dis[j];
             u = j;
          }
       }
   }
   book[u] = 1;
   for(v=1;v<=n;v++)
   {
      if(e[u][v] <  inf)
      {
	if(dis[v] > dis[u]+e[u][v])
        {
	    dis[v] = dis[u]+e[u][v];
        }
      }
   }
}
