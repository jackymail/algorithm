#include "stdio.h"
#include "stdlib.h"
#define ElementType int
#define MAX_DATA  100000

#define TRUE 1
#define FALSE 0

typedef struct{
    ElementType *Elements;
    int size;
    int Capacity;
}HeapStruct;

HeapStruct *MaxHeap;

int IsHeapFull(MaxHeap H)
{
  if(NULL == MaxHeap)
  {
      return TRUE;
  }
  
  if(H->size == H->Capacity)
  {
      return TRUE;
  }
  else
  {
      return FALSE;
  }
}

MaxHeap create(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(HeapStruct));
    if(NULL == H)
    {
	return NULL;
    }
    H->Elements = (ElementType *)malloc((MaxSize+1) * sizeof(ElementType));
    H->size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MAX_DATA;
    return H;
}

void insert(MaxHeap H,ElementType item)
{
    int i = 0;
    if(IsHeapFull(H) != TRUE)
    {
	printf("the heap is full\n");
        return;
    }
    
    i = ++H->size; /*H->size 指向的是堆的最后一个元素的位置，所以i指向的是最后一个元素的后面。
*/
#if 1 //设置哨兵时
    for(;H->Elements[i/2] < item;i/=2)  /* i/2 表示父亲节点的位置,这句代码的意思是：如果插入的元素的值比父亲节点的大，则将父亲节点的值下移，即孩子节点位置（i）的值的值赋值成父亲节点i/2的值*/
#else  //没有设置哨兵
    for(;H->Elements[i/2]<item && i >1;i/=2)
#endif
    {
	H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item;
    return;
}

/*
 * 堆中删除元素 （最大堆）
 *
 */
ElementType DeleteMax(MaxHeap H)
{
    int parent = 0;
    int child = 0;
    ElementType MaxItem = 0;
    ElementType temp = 0;
    
    if(FALSE == IsEmpty(H))
    {
	printf("heap is empty\n");
      	return;
    }
 
    MaxItem = H->Elements[1]; //取出根节点的最大值,0的位置不存储堆栈中的值，存储的是哨兵的值。从1开始存储，又因为是最大堆，所以1是最大值。
    temp = H->Elements[H->size--]; // 取出堆中的最后一个元素
    
    for(parent = 1;parent*2<=H->size;parent=child) /*parent*2 是左孩子的位置，如果左孩子的位置大于了堆栈的size，说明这个节点已经没有孩子节点了。parent等于child的意思是等一次循环结束后，parent指向孩子节点中比较大的位置*/
  ｛
	child = parent * 2; //child 先指向左孩子。
        if((child != H->size) && (H->Elements[child] <  H->Elements[child+1]))//首先进行child的判断，如果child等于size说明没有右孩子节点，然后比较左右孩子节点的大小，如果右孩子比左孩子的值要大，则child的值++指向右孩子的位置，否则不用就不用动了。
        {
	    child++;
        }
        if(temp >= H->Element[child])  //说明待插入的元素比左右孩子节点都大，不用进行调整。
        {
	     break;
        }
        else
        {
	   H->Elements[parent] = H->Elements[child];//如果父亲节点的值比孩子节点的小，则把父亲节点的值赋值给孩子节点。
        }
	
   ｝
   H->Elements[parent] = temp;
   return MaxItem;  //返回最大值
}

void PercDown(MaxHeap H,int p)
{
    int parent = 0;
    int child  = 0;
    ElementType X = 0;

    X = H->Elements[p];
    for(parent=p,parent*2<=H->size;parent=child)
    {
	child = parent * 2;
        if(child != H->size && H->Elements[child] < H->Elements[child+1])
        {	 
		child++;
        }
        if(X >= H->Element[child])
        {
	    break;
        }
        else
        {
	   H->Elements[parent] = H->Elements[child];
        }
    }   
    H->Elements[parents] = X;
}

/*
 * 建立最大堆，思路是先把元素全部输入，先组成一个完全二叉树，然后从底部开始调整。
 *  H->size/2 的意思完全二叉树的最后一个节点的父亲节点
 */

void BuildHeap(MaxHeap H)
{
    int i  = 0;
    for(i=H->size/2;i>0;i--) /* 最后一个节点的父节点*/
    {
	PercDown(H,i);
    } 
    return;
}





















