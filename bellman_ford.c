#include "stdio.h"

int main(void)
{
    int dis[10] = {0};
    int i = 0;
    int k = 0;
    int n = 0;
    int m = 0;
    int u[10] ={0};
    int v[10] ={0};
    int w[10] ={0};
    int inf=99999999;

    scanf("%d %d",&n,&m);

    for(i=1;i<=m;i++)
    {
      scanf("%d %d %d",&u[i],&v[i],&w[i]);
    }
    for(i=1;i<=n;i++)
    {
        dis[i] = inf;
    }
    dis[1] = 0;
    for(k=1;k<=n-1;k++)
    {
        for(i=1;i<=m;i++)
        {
            if(dis[v[i]] > dis[u[i]] + w[i])
            {
                dis[v[i]] = dis[u[i]] + w[i];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
      printf("%d ",dis[i]);
    }
    getchar();
    getchar();
    return 0;
}
