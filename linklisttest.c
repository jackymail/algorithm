#include "stdio.h"
#include "stdlib.h"

typedef struct list
{
  int data;
  struct list *next;
}Linklist;


void createLinkList(Linklist **head)
{
   *head = NULL;
}

void insertLinkList(Linklist **head,int data)
{
  Linklist *node = NULL;
  Linklist *temp_head = NULL;
  Linklist *temp = NULL;
  
  temp_head = *head;
  
  if(head == NULL)
  {
     printf("the head is null\n");
  }
  else
  {
    printf("the head is %p",head);
  }
  node = (Linklist *)malloc(sizeof(Linklist));
  if(NULL == node)
  {
    printf("fail to malloc memory,return\n");
    return;
  }
  else
  {
    printf("successfully malloc memory,the node is %p\n",node);
    node->data = data;
    node->next = NULL;
  }
  if(temp_head == NULL)
  {
    printf("temp_head is NULL\n");
    *head = node;
    printf("the head is %p",head);
  }
  else
  {
    printf("temp head is not null\n");
    while(temp_head)
    {
      printf("temp_head is not NULL,goto the next one\n");
      temp = temp_head;
      temp_head = temp_head->next;
    }
    printf("insert a node\n");
    temp->next = node;
  }
  printf("the head is %p\n",head);
  return;  
}

Linklist* buildLinkList(Linklist *head)
{
  int data = 0;

  while(1)
  {
    scanf("%d",&data);
    if(data < 0)
    {
      printf("data is less than 0,break\n");
      break;
    }
    else
    {
      printf("the data is %d\n",data);
      insertLinkList(&head,data);
      printf("out the head is %p\n",head);
    }
  }
  if(NULL == head)
  {
     printf("head is null when quit\n");
  }
  else
  {
     printf("head is not null when quit\n");
  }
  return head;
}

Linklist* mergeLinkList(Linklist *head1,Linklist *head2,Linklist *head3)
{
  Linklist *h1;
  Linklist *h2;
  Linklist *h3 = NULL;
  
  Linklist *node;
  
  h1 = head1;
  h2 = head2;
  //h3 = head3;
  
  while(h1 != NULL && h2 != NULL)
  {
    node  = (Linklist *)malloc(sizeof(Linklist));
    if(node == NULL)
    {
      break;
    }
    if(h1->data < h2->data)
    {
	printf("h1 data is less than h2 data %d %d\n",h1->data,h2->data);
        node->data = h1->data;
        node->next = NULL;
        if(h3 == NULL)
        {
	  printf("h3 is null\n");
          h3 = node;
	  head3 = h3;
        }
        else
        {
	  printf("h3 is not null,insert new node the node data is %d\n",node->data);
          h3->next = node;  
          h3 = h3->next;
        }
        h1 = h1->next;
    }
    else
    {
	printf("h1 data is more than h2 data %d %d\n",h1->data,h2->data);
        node->data = h2->data;
        node->next = NULL;
        if(h3 == NULL)
        {
	  printf("h3 is null\n");
          h3 = node;
          head3 = h3;
        }
        else
        {
	  printf("h3 is not null,insert new node ,the node data is %d\n",node->data);
          h3->next = node;
          h3 = h3->next;
        }
        h2 = h2->next;   
    }
  }
 #if 1 
  while(h1 != NULL)
  {
    node = (Linklist *)malloc(sizeof(Linklist));
    if(node != NULL)
    {
      node->data = h1->data;
      node->next = NULL;
      h3->next = node;
      h3 = h3->next;
      h1 = h1->next;
    }
  }
  
  while(h2 != NULL)
  {
    node = (Linklist *)malloc(sizeof(Linklist));
    if(node != NULL)
    {
      node->data = h2->data;
      node->next = NULL;
      h3->next = node;
      h3 = h3->next;
      h2 = h2->next;
    }
  }
  #endif
  return head3;
}

void print(Linklist *p)
{
  printf("begin to print linklist\n");
  Linklist *t = NULL;
  t = p;
  if(NULL == p)
  {
    printf("begin to print data,pointer is null\n");
    return;
  }
  while(t!= NULL)
  {
    printf("%d ",t->data);
    t=t->next;
  }
  return;
}

int main(void)
{

  Linklist *head1 = NULL;
  Linklist *head2 = NULL;
  Linklist *head3 = NULL;
  Linklist *h1 = NULL;
  Linklist *h2 = NULL;
  Linklist *h3 = NULL;
  createLinkList(&head1);
  createLinkList(&head2);
  createLinkList(&head3);
   
  printf("input head1\n");
  h1 = buildLinkList(head1);
  //buildLinkList(head2);

  if(NULL == h1)
  {
      printf("head1 is null\n");
  }

  print(h1);
  printf("input head2\n");
  h2 = buildLinkList(head2);
  print(h2);   

  printf("begin to merge data\n");
  h3 = mergeLinkList(h1,h2,head3);
  
  print(h3);

  return 0;
}
