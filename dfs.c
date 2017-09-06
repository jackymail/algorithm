#include "stdio.h"
int book[101] = {0};
int sum = 0;
int n = 0;
int e[101][101] = {0};


void dfs(int cur)
{
   int i =0;
   printf("%d ",cur);
   sum++;
   
   if(sum == n)
   {
      return;
   }
   
   for(i=1;i<=n;i++)
   {
     if(e[cur][i] == 1 && book[i] == 0)
     {
	book[i] = 1;
        dfs(i);
     }

   }
   return;
}
int main()
{
   int i=0;
   int j=0;
   int m = 0;
   int a =0;
   int b =0;

   scanf("%d %d",&n,&m);
   for(i=1;i<=n;i++)
   {
     for(j=1;i<=n;j++)
     {
	if(i==j)
        {
	    e[i][j] = 0;
        }
        else
	{
	    e[i][j] = -1;
        }
     }
   }
   for(i=1;i<=m;i++)
   {
       scanf("%d %d",&a,&b);
       e[a][b] = 1;
       e[b][a] = 1;
   }
   
   book[1] =1;
   dfs(1);
   getchar();
   getchar();
   return 0;
}








