 /*
 *
 *题目描述：给出一个整数数组nums，重新排列nums使得
 *nums[0] < num[1] > num[2] < num[3] > ...
 *example nums=[1,5,1,1,6,4].一个可能的答案是:［1,4,1,5,1,6］
 *数据保证必定有解
 */
#include <iostream>
#include <algorithm>
using namespace std;

#if 0 // solution 1
void swap(int *x,int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sortInWave(int arr[],int n)
{
    int i = 0;
    sort(arr,arr+n);
    for(i=0;i<n-1;i+=2)
    {
      swap(&arr[i],&arr[i+1]);
    }
}

int main()
{
   int arr[] = {10,90,49,2,1,5,23};
   int n = sizeof(arr)/sizeof(arr[0]);
   int i = 0;
   sortInWave(arr,n);

   for(i=0;i<n;i++)
   {
     cout << arr[i] << " ";
   }
   return 0;
}
#else
void swap(int *x,int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sortInWave(int arr[],int n)
{
   int i = 0;
   for(i=0;i<n;i+=2)
   {
      if(i > 0 && arr[i-1] > arr[i])
      {
        swap(&arr[i],&arr[i-1]);
      }。
      if(i<n-1 && arr[i] < arr[i+1])
      {
        swap(&arr[i],&arr[i+1]);
      }
   }
}
int main()
{
    int arr[0] = {10,90,49,2,1,5,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr,n);
    for(i=0;i<n;i++)
    {
      cout << arr[i] << "";
    }
    return 0;
}

#endif
