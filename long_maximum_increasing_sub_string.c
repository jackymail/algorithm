/*给出一个数组，找出最少的元素，使得将其删除之后，剩下的元素是递增的。
 *删除最少的元素，保证剩下的元素是递增有序的，换一句话说就是找出最长的
 *的递增有序子序列。
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max(x,y) (x > y ? x:y)
#define MaxSize 20

typedef int ElementType;

typedef struct{
	ElementType Data[MaxSize];
        int Top;
}Stack;

Stack S;
Stack S_Reverse;

void Push(Stack *PtrS,ElementType item)
{
    if(PtrS->Top == MaxSize -1)
    {
	printf("the stack is full\n");
	return;
    }
    else 
    {
        ++PtrS->Top;
        printf("***push the items the index is %d,the item is %d***\n",PtrS->Top,item);
	PtrS->Data[PtrS->Top] = item;
        return;
    }
}

ElementType Pop(Stack *PtrS)
{
     if(PtrS->Top == -1)
     {
	printf("the Stack is empty");
     	return -1;
     }
     else
     {
        return (PtrS->Data[PtrS->Top--]);
     }
}



int get_lis_length(int A[],int length)
{
    int dp[10] = {0}; //dp[i]表示以i结尾的最长子序列的长度。
    int maxCount = 0;
    int i = 0;
    int j = 0;
    int temp = 0;

    S.Top = -1;
    S_Reverse.Top = -1;

    memset(S.Data,0,sizeof(S.Data));
    memset(S_Reverse.Data,0,sizeof(S_Reverse.Data));
   
    for(i=0;i<length;i++)
    {
        printf("the i is %d\n",i);
	dp[i] = 1;
        for(j=0;j<i;j++)
        {
            //printf("the A[%d] is %d,the A[%d] is %d\n",i,j,A[i],A[j]);
	    if(A[i] >= A[j])
            {		
               // printf("the  i = %d j = %d the A[i] is %d,the A[j] is %d\n",i,j,A[i],A[j]);
	        Push(&S,A[j]);    
    		//printf("the i: dp[%d] is %d , j: dp[%d]+1 is %d\n",i,dp[i],j,dp[j]+1);
                
                dp[i] = max(dp[i],dp[j]+1);
		if(maxCount < dp[i])
                {
                    printf("push %d to the stack",A[i]);
                    Push(&S,A[i]);
		    maxCount = dp[i];
                }
            //    printf("the dp[%d] is %d\n",i,dp[i]);
            }	
        }
    }
   
    for(i=0;i <maxCount-1;i++)
    {
	//printf("the %d dp[i] is %d\n",i,dp[i]);
    	printf("the S.top is %d\n",S.Top);
        temp = Pop(&S);
        printf("the temp value is %d\n",temp);
        Push(&S_Reverse,temp);
    }

    printf("the long sequence elements is :");
    
    for(i=0;i < maxCount;i++)
    {
	printf("%d  ",Pop(&S_Reverse));
    }
    printf("\n");
    return maxCount; 
}

int main(void)
{
   int A[10] = {0};
   int index = 0;
   int length = 10;

   for(index = 0; index <10;index++)
   {
	scanf("%d",&A[index]);
   }

   length = get_lis_length(A,length);      
   printf("the length is %d\n",length);
   return 0;
}
