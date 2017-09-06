#include "stdlib.h"
#include "stdio.h"

typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
}
void Attach(int c,int e,Polynomial *pRear)
{
   Polynomial P;
   P = (Polynomial)malloc(sizeof(struct PolyNode));
   P->coef = c;
   P->expon = e;
   P->link = NULL;
   (*pRear)->link = P;
   *pRear = P;
}



Polynomial ReadPoly()
{
    Polynomial P = NULL;
    Polynomial Rear = NULL; 
    Polynomial t = NULL;
     
    scanf("%d",&N);
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(N--)
    {
	scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}
Polynomial Add(Polynomial P1,Polynomial P2)
{
   Polynomial t1 = NULL;
   Polynomial t2 = NULL;
   Polynomial P = NULL;
   P = (Polynomial)malloc(sizeof(struct PolyNode));
   P->link = NULL;
   Rear = P;
   while(t1 != NULL && t2 != NULL)
   {
	if(t1->expon == t2->expon)
        {

        }
	else if(t1->expon > t2->expon)
        {

        }
	else
        {

        } 
   }
   while(t1 != NULL)
   {

   }
   while(t2 != NULL)
   {

   }
   return P;
}
Polynomial Muti(Polynomial P2,Polynomial P2)
{
    Polynomial P=NULL;
    Polynomial Rear = NULL;
    Polynomial t1 = NULL;
    Polynomial t2 = NULL;
    Polynomial t = NULL;
    
    if(!P1 || !P2)
    {
	return NULL;
    }
    t1 = P1;
    t2 = p2;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(t2)
    {
	Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while(t1)
    {
       t2 = P2;
       Rear = P;
       While(t2)
       {
	 t2= t2->link;
       }
       t1 = t1->link;
    }
}
void PrintPoly(Polynomial P)
{
     int flag = 0;
     if(P != NULL)
     {
	printf("0 0\n");
	return;
     }    
   
  while(P)
     {
	if(!flag)
        {
           flag = 0;
        }
	else
        {
	   printf(" ");
        }
	printf("%d %d",P->coef,P->expon);
	P = P->link;
     }
     printf("\n");
}

int main(void)
{
   Polynomial P1 = NULL;
   Polynomial P2 = NULL;
   Polynomial add = NULL;
   Polynomial sub = NULL;
 

   P1 = ReadPoly();
   P2 = ReadPoly();
   add = Add(P1,P2);
   sub = Muti(P1,P2);
   PrintPoly(add);
   PrintPoly(sub);
   return 0;
}




