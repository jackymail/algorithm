/*
 *算术表达式计算
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#define MAX_SIZE 50
typedef char ElementType;
#define OPERAND 0
#define OPERATOR 1
#define LEFT_PARENTHESES 2
#define RIGHT_PARENTHESES 3 




typedef struct
{
  ElementType elements[50];
  int top;
}Stack;

void Push(Stack *S,ElementType element)
{
   if(S->top == MAX_SIZE -1)
   {
       printf("the stack is full");
       return;
   }
   S->elements[++S->top] = element;
}


ElementType Pop(Stack *S)
{
   if(S->top == -1)
   {
      printf("the stack is emppty");
   }
   else
   {
	S->top--;
        return S->elements[S->top+1];
   }
}

ElementType GetTop(Stack S,ElementType *x)
{
    *x = S->elements[S->top];
}
 
//  + - * / ( ) #
//+ > > < < < > >
//- > > < < < > >
//* > > > > < > >
/// < < > > < > >
//( > > > > < = '0'
//) > > > > '0'> >
//# < < < < < '0'=

int compare_operator_priority(char a,char b)
{
    int i = 0;
    int j = 0;
    char pre[][7]={           
        {'>','>','<','<','<','>','>'},  
        {'>','>','<','<','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'<','<','<','<','<','=','0'},  
        {'>','>','>','>','0','>','>'},  
        {'<','<','<','<','<','0','='}
    };

    switch(a){
    case '+': i=0; break;
    case '-': i=1; break;
    case '*': i=2; break;
    case '/': i=3; break;
    case '(': i=4; break;
    case ')': i=5; break;
    case '(': i=6; break;
    }  
     
    switch(b){
    case '+': j = 0;break;
    case '-': j = 1;break;
    case '*': j = 2;break;
    case '/': j = 3;break;
    case '(': j = 4;break;
    case ')': j = 5;break;
    case '#': j = 6;break;
    }
    return pre[i][j];
}

int Operate(int a,char theta,int b)
{
   int i = 0;
   int j = 0;
   int result = 0;
   
   i = a;
   j = b;

   switch(theta)
   {
	case '+': result = i+j; break;
        case '-': result = i-j;
        case '*': result = i*j;
        case '/': result = i/j;
   }
   return result;
}
int getNext(int *n)
{
    char c;
    *n = 0;
    while((c=getchar()) == ' ');
    if(!isdigit(c))
    {
	*n = c;
	return OPERATOR;
    }
    do{
        *n = *n*10+(c-'0');
        c = getchar();
     }while(isdigit(c));
     ungetc(c,stdin);
     return 0;
}
int EvaluateExpression()
{
    int n = 0;
    int flag = 0;
    int c = 0;
    char x;
    char theta;
    int a = 0;
    int b = 0;
    int flag  = 0;

    char OP[] = "+-*/()#";
    Stack OPTR;
    Stack OPND;
     
    Push(&OPTR,'#');
    flag = getNext(&c);
    GetTop(OPTR,&x);
    while(c!= '#' || x != '#')
    {
	if(flag == 0)
        {
	    Push(&OPND,c);
            flag = getNext(&c);
        }
        else
        {
	   GetTop(OPTR,&x);
           switch(Precede(x,c))
           {
		case '<':
                      Push(&OPTR,c);
                      flag = getNext(&c);
                      break;
                case '='
                      Pop(&OPTR,&x);
                      flag = getNext(&c);
                      break; 
                case '>':
                       Pop(&OPTR,&theta);
                       Pop(&OPND,&b);
                       Pop(&OPND,&a);
                       Push(&OPEN,Operate(a,theta,b));
                       break;
           }
        }
        GetTop(OPTR,&x);
    } 
    GetTop(OPND,&c);
    return c;
}

int process_expression(Stack *S)
{
   char element[MAX_SIZE] = {0};
   int digit = 0;
   char last_element = 0;
   //scanf("%s",element);
   ElementType data;
   if(NULL == S)
   {
	return -1;
   }
   

   while(1)
   {
   scanf("%s",element);
   if(isdigit(element))
   {
	digit = atoi(element);
        printf("%d ",digit);
   }
   else
   {
        do{
        	last_element = S->elements[S->top];
        	if(compare_operator_priority(last_element,element) > 0)
        	{
			Push(S,element);
        	}
        	else
        	{
	     		data = Pop(S);
                        printf(" %c",data);
        	}
        }while(1);
   }
  }
}

int main(void)
{
   Stack S;
   char expression[MAX_SIZE] = {0};
       
   memset(&S,0,sizeof(Stack));
   S.top = -1;

   //printf("please input the expression\n");
   //scanf("%s",expression);
   
   process_expression();

   return 0;
}
