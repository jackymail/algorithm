#include "stdio.h"

#define MaxSize 100

typedef struct{
  int N;
  int A;
  int B;
  int C;
}ElementType;


ElementType ERROR;

typedef struct{
   ElementType Data[MaxSize];
   int Top;
}Stack;

void Push(Stack *PtrS,ElementType item)
{
     if(PtrS->Top == MaxSize-1)
     {
        printf("stack full");
        return;
     }
     else
     {
	PtrS->Data[++(PtrS->Top)] = item;
        return;
     }
}
ElementType Pop(Stack *PtrS)
{
    if(PtrS->Top == -1)
    {
	printf("stack empty\n");
        return ERROR;
    }
    else
    {
	PtrS->Top--;
        return (PtrS->Data[PtrS->Top+1]);
    }
}

void Hanoi(n)
{
     ElementType P,toPush;
     Stack S;
     
     P.N = n;
     P.A = 'a';
     P.B = 'b';
     P.C = 'c';
     S.Top = -1;

    Push(&S,P);
    while(S.Top != -1)
    {
       P = Pop(&S);
       if(P.N == 1)
       {
	  printf("%c -> %c\n",P.A,P.C);
       }
       else
       {
	  toPush.N = P.N -1;
          toPush.A = P.B;
          toPush.B = P.A;
          toPush.C = P.C;
          Push(&S,toPush);
          toPush.N = 1;
          toPush.A = P.A;
          toPush.B = P.B;
          toPush.C = P.C;
          Push(&S,toPush);
          toPush.N = P.N -1;
          toPush.A = P.A;
          toPush.B = P.C;
          toPush.C = P.B;
          Push(&S,toPush);
       }
    } 
}
int main()
{
    int n;
    ERROR.N = -1;
    
    scanf("%d",&n);
    Hanoi(n);
    return 0;
}









