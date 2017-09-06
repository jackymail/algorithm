#include "stdio.h"
#include "stdlib.h"

struct node
{
    int Data;
    struct node *Next;
};
typedef struct node *LinkListNode;

typedef struct list
{
    LinkListNode head;
    LinkListNode tail;
    int totalnumber;
}*List;


List CreateLinkList()
{
    List list;
    LinkListNode Lnode;
    list = malloc(sizeof(List));
    Lnode = (LinkListNode)malloc(sizeof(struct node));
    if(Lnode != NULL)
    {
        Lnode->Data = 0;
        Lnode->Next = NULL;
        list->head = Lnode;
        list->tail = Lnode;
        list->totalnumber = 0;
    }
    return list;
}

int AppendLinkListNode(List L,int value)
{
    LinkListNode Lnode;
    if(NULL == L)
    {
        return -1;
    }
    Lnode = (LinkListNode)malloc(sizeof(struct node));
    if(Lnode != NULL)
    {
        Lnode->Data = value;
        Lnode->Next = NULL;
    }
    L->tail->Next = Lnode;
    
    L->tail = L->tail->Next;
    L->totalnumber++;
    return 0;
}



int main(void)
{
    int N;
    int index;
    int value = 0;
    List LinkList = NULL;
    LinkListNode p = NULL;
    LinkListNode q = NULL;
    
    
    scanf("%d",&N);
    LinkList =  CreateLinkList();
    
    if(LinkList == NULL)
    {
        // printf("link list is null\n");
        return 0;
    }
    else
    {
        //printf("the link is not null\n");
    }
    
    while(1)
    {
        //printf("the value is %d\n",value);
        scanf("%d",&value);
        // printf("the value is %d\n",value);
        if(0 >= value)
        {
            break;
        }
        else
        {
            //printf("the value is %d\n",value);
            AppendLinkListNode(LinkList,value);
        }
    }
    // printf("out of the loop\n");
    p = LinkList->head;
    q = LinkList->head;
    if(N > LinkList->totalnumber)
    {
        printf("NULL");
    }
    while(--N && q != NULL)
    {
        q = q->Next;
    }
    
#if 1 
    while(q!=NULL)
    {
        q = q->Next;
        p = p->Next;
        
    }
    //p = p->Next;
#endif
    if(p!=NULL)
    {
        printf("%d",p->Data);
    }
    //#endif
    return 0;
}
