/**
 *给出两个数组 A和B,两个数组的大小分别为m和n，其中m<n.现要求将(n-m)个0插入A
 *使得A*B的值最小，求其最小乘积。
 *一个数组dp记录A和B不同位置组合的最小乘积，dp[i][j] 代表A[0...i]与B[0...j]
 组合的最小乘积，但i ＝ 0，j ＝0时，只有一种组合，无法插入0，即A[0]*B[0];
 当i=0时，j可以0到n-m.也就是n-m个0，加上B[j]本身与A[0]进行组合。
 当i>0时，因为我们只能网较短的数组A插入0，所以我们要么累加A[i]*B[j]+dp[i-1][j-1].
 要么累加0*B[j]+dp[i][j],取两者较小值。
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MIN(X,Y) (X>Y ? X:Y)


int minimum_mul(int A[],int a_length,int B[],int b_length)
{
  int m = a_length;
  int n = b_length;
  int dp[m][n];
  int i = 0;
  int j = 0;
  memset(&dp[0][0],0,m*n*sizeof(int));
 
  for(i=0;i<m;i++)
  {
     for(j=i;j<(i + (n-m) +1);j++)
     {
	if(j > i)
        {
	    if(i > 0)
            {
		dp[i][j] = MIN(A[i]*B[j]+dp[i-1][j-1],dp[i][j-1]);	
            }
            else
            {
		dp[i][j] = MIN(A[i]*B[j],dp[i-1][j-1]);
            }
        }
        else
        {
	   if(i == 0)
           {
		dp[i][j] = A[i] * B[j];	
           }
           else
           {
                dp[i][j] = A[i]*B[j] + dp[i-1][j-1];
           }
        }

     }
  }  

  return dp[m-1][n-1];
}

int main(void)
{
   int A[] = {1,3};
   int B[] = {1,2,3,4};
   int mini_mul = 0;

   mini_mul = minimum_mul(A,2,B,4);
   printf("the minimum_mul is %d\n",mini_mul);

   return 0;
}









