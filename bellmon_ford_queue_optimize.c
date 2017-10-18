/**
 *First[u[i]] 表示以u[i]为第一个顶点的最后一条边的边号。
 *next[i] 表示第i条边的前面一条边。
 ＊*＊＊＊＊
 bellmon算法和和dijstra算法的一个主要区别个人觉得是bellon是按照edge进行松弛的，
 dijstra是按照按照vertex进行松弛的。
 这个程序中包含了，数组实现邻接表的方法。  
 */

#include "stdio.h"
int main(void)
{
   int n = 0;
   int m = 0;
   int i = 0;
   int j = 0;
   int k = 0;
   int u[8] = {0};
   int v[8] = {0};
   int w[8] = {0};

   int first[6] = {0};
   int next[8] = {0};
   int dis[6] = {0};
   int book[6] = {0};
   int que[101] = {0};
   int head = 1;
   int tail = 1;
   int inf = 99999999;
   printf("please enter n and m\n");
   scanf("%d %d",&n,&m);
   for(i=1;i<=n;i++)
   {
     dis[i] = inf;
   }
   dis[1] = 0;
   for(i=1;i<=n;i++)
   {
     book[i] = 0;
   }
   for(i=1;i<=n;i++)
   {
     first[i] = -1;
   }
   for(i=1;i<=m;i++)
   {
      //printf("please enter u[i],v[i] and w[i]\n");
      scanf("%d %d %d",&u[i],&v[i],&w[i]);
      next[i] = first[u[i]];
      first[u[i]] = i;
//      printf("the next[%d] is %d\n",i,next[i]);
//      printf("the first[%d] is %d", u[i],first[u[i]]);
   }
   
   for(i=1;i<=m;i++)
   {
	printf("the next[%d] is %d\n",i,next[i]);
   }
   for(i=1;i<6;i++)
   {
	printf("the first[%d] is %d\n",i,first[i]);
   }

  
   que[tail] =  1;
   tail++;
   book[1] = 1;
   while(head < tail)
   {
      printf("the head is %d,the tail is %d\n",head,tail);
      printf("in the while loop\n");
      k = first[que[head]];
      while (k != -1)
      {
          printf("the k is %d\n",k);
          if(dis[v[k]] >  dis[u[k]] + w[k])
          {
              dis[v[k]] = dis[u[k]] + w[k];
              if(book[v[k]] == 0)
              {
                que[tail] = v[k];
                tail++;
                book[v[k]] = 1;
              }

          }
          k = next[k];
      }
      book[que[head]] = 0;
      head++;
   }
   for(i=1;i<=n;i++)
   {
     printf("%d ",dis[i]);
   }
   getchar();
   getchar();
   return 0;
}
