#include "stdio.h"
#define MAX_NUM 10

void quicksort(int a[],int left,int right)
{
    int i = 0;
    int j = 0;
    int t = 0;
    int temp = 0;

    printf("the left is %d,the right is %d\n",left,right);

    if(left > right)
    {
	return;
    }

    temp = a[left];
    i = left;
    j = right;
    while(i!=j)
    {
        #if 0
	while(a[j] >= temp && i<j)
        {
	   j--;
        }
	while(a[i] <= temp && i <j)
        {
	   i++;
        }
        #else
	while(a[i] <= temp && i<j)
        {
	   i++;
        }
        while(a[j] >= temp && i<j)
        {
	   j--;
        }
        #endif
        if(i<j)
        {
	   t = a[i];
           a[i] = a[j];
	   a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;
    
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
    return;
}
int main(void)
{
  int i = 0;
  int j = 0;
  int n = 0;
  int array[MAX_NUM] = {0};
 
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     scanf("%d",&array[i]);
  }
  quicksort(array,0,n-1);

  for(i=0;i<=n;i++)
  {
    printf("%d ",array[i]);
  }
  getchar();
  getchar();
  return 0;
}



