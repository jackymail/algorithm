#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int Bool
typedef struct node *Node;
struct node{
   char *name;
   Bool isMulu;
   Node File;
   Node Mulu;
   Node Brother;
}Head;

void Print(Node,int);
void Read();
Node New(char *);
Node InsertMulu(Node,char*);
Node InsertFile(Node,char*);

int main()
{
   int n = 0;
   int i = 0;
   scanf("%d",&n);
   Head.Name = (char*)malloc(sizeof(char)*5);
   strcpy(Head.Name,"root");
   Head.File = NULL;
   Head.Mulu = NULL;
   Head.Brother = NULL;
   Head.isMulu = 1;

   for(i=0;i<n;i++)
   {
      getchar();
      Read();
   }
   Print(&Head,0);
   return 0;
}
void Read()
{
    char FileName[261];
    Node temp = &Head;
    scanf("%s",FileName);


    char words[261];
    int j = 0;
    int L = 0;
    int i = 0;
    
    for(i=0;i<strlen(FileName);i++)
    {
	if(FileName[i] == '\\')
        {
	    for(j=L;j<i;j++)
            {
		words[j-L] = FileName[j];
            }
            words[j-L] = '\0';
            temp->Mulu = InsertMulu(temp->Mulu,words);
            temp = temp->Mulu;
            L = i+1;
        }
    }
    if(L < strlen(Filename))
    {
        for(j=L;j<=strlen(FileName);j++)
        {
	   words[j-L] = FileName[j];
        }
	temp->File = InsertFile(temp->File,words);
    }
}
Node InsertMulu(Node H,char *k)
{
    if(!H || strcmp(H->Name,K) > 0)
    {
	Node temp = new(K);
        temp->Brother = H;
        return temp;
    }
    if(strcmp(H->Name,K) == 0)
    {
	return H;
    }
    H->Brother = InsertMulu(H->Brother,K);
    return H;
}

Node InsertFile(Node H,char *K)
{
   if(!H || strcmp(H->Name,K) > 0)
   {
	Node temp = New(K);
        temp->isMulu = 0;
        temp->Brother = H;
        return temp;
   }
   H->Brother = InsertFile(H->Brother,K);
}

Node New(char *K)
{
   Node temp = (Node)malloc(sizeof(struct node));
   temp->Name = (char *)malloc(sizeof(char*)strlen(K)+1);
   strcpy(temp->Name,K);
   temp->Brother = NULL;
   temp->File = NULL;
   temp->Mulu = NULL;
   temp->isMulu = 1;
   return temp;
}
void Print(Node H,int space)
{
   int i = 0;
   if(H)
   {
      for(i=0;i<space,i++)
      {
	  printf("%s\n",H->Name);
      }  
      if(H->isMulu == 1)
      {
	Print(H->Mulu,space+2);
      }
      Print(H->File,space+2);
      Print(H->Brother,space);


   }
}











