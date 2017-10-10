/*容器盛水，给出n个非负整数，a1,a2...an.每个元素代码平面上的一个点（i,ai）.
 *然后将这些点（i,ai）和x坐标上的点（i,0）连成一条垂直与x轴的线段，找出两条线段，连同
 *x轴组成的容器所能容纳的水最多。
 */
#include "stdio.h"


#define min(x,y) (x>y ? y:x)
#define max(x,y) (x>y ? x:y)

int main(void)
{
  int A[5] = {0,1,3,3,2}; 
  int i = 0;
  int j = 4;
  int result = 0;
  int area = 0;
  printf("the j is %d\n",j); 
  while(i < j)
  {
     area = min(A[i],A[j]) * (j - i);
     printf("the area is %d\n",area);
     result = max(result,area);
     printf("the result is %d\n",result);
     if(A[i] <= A[j])
     {
	i++;
     }
     else
     {
	j--;
     }
  }
  printf("the result is %d",result);
  return 0;
}
