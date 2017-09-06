#include "stdio.h"

int min = 99999999;
int book[101];
int n = 0;
int e[101][101];

void dfs(int cur,int dis)
{
  int j = 0;
  
  if(dis > min)
  {
     return;
  }

  if(cur == n)
  {
     if(dis<min)
     {
	min = dis;
     }

  }

  for(j=1;j<=n;j++)
  {
    if(e[cur][j] != 99999999 && book[j] == 0)
    {
	book[j] = 1;
        dfs(j,dis+e[cur][j]);
        book[j] = 0;
    }
  }
  return;
}

int main()
{
   int i = 0;
   int j = 0;
   int m = 0;
   int a = 0;
   int b = 0;
   int c =0;
     
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
	scanf("%d %d %d",&a,&b,&c);
        e[a][b] = c;
   }

   book[1] =1;
   dfs(1,0);
   printf("%d",min);
   getchar();
   getchar();
   return 0;
}
