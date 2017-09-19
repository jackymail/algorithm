/**
 *根据一个二叉搜索树的前序遍历，获得这颗二叉搜索树的后序遍历，
 思路，根据二叉搜索树的特点：二叉搜索树的中序遍历的结果是一个递增的序列，
 所以将前序遍历的结果排序后，就可以得到中序遍历。根据前序遍历和中序遍历就可以创建
 一颗二叉树。前序遍历第一个节点的值就是后序遍历的第一个节点。 接着可以扫描前序序列
 ，比根节点小的元素一定是在左子树上，比根节点大的树一定是在右子树上。然后在递归的对这两个子树进行处理。就可以获得后序遍历的元素。
 */


#include "stdio.h"
#include "stdlib.h"

#define MAXN 128


void get_post_order(int Pre[],int Post[],int N,int length)
{
   int index = 0;
   int pre_left[MAXN] = {0};
   int pre_right[MAXN] = {0};
   int split_point = 0;
   int sub_left = 0;
   int sub_right = 0;

   if(length < 1)
   {
      return;	
   }  
   
   split_point = Pre[0];
   Post[N-1] = split_point;
    
   printf("the split point is %d\n",split_point);
   
   for(index = 1;index < length;index++)
   {
        printf("the index %d is %d\n",index,Pre[index]);
	if(Pre[index] < split_point)
        {
           printf("less than 7\n");
	   pre_left[sub_left++] = Pre[index];	   
        }
        else
        {
           printf("greater than 7\n");
	   pre_right[sub_right++] = Pre[index];
        }
   }
   printf("the sub_left is %d,the sub_right is %d\n",sub_left,sub_right);
#if 0    //对称
   get_post_order(pre_left,Post,N-1,sub_left);
   get_post_order(pre_right,Post,N-1-sub_left,sub_right);
#else    //给对称
   get_post_order(pre_left,Post,N-1-sub_right,sub_left);
   get_post_order(pre_right,Post,N-1,sub_right);
#endif 
  return;
}


int main(void)
{
   int N = 0;
   int index = 0;
   int Pre[MAXN] = {0};
   int Post[MAXN] = {0};
   printf("please enter the value of N:\n");
   scanf("%d",&N);
   
   for(index = 0;index < N;index++)
   {
	scanf("%d",&Pre[index]);
   }      
    
   get_post_order(Pre,Post,N,N);

   for(index = 0;index < N;index++)
   {
	printf("%d ",Post[index]);
   }
}





