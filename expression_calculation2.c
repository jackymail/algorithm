#include "stdio.h"
#include "stdlib.h"
#include <ctypes.h>
#include "stack_s.c"

#define TRUE 1
#define FALSE 0

Status int(char c,char op[])
{
    char *p = NULL;
    p = op;
    while(*p != '\0')
    {
	if(c == *p)
        {
	    return TRUE;
        }
        p++;
    }
    return FALSE;
}
char Precede(char a,char b)
{
    int i = 0;
    int j = 0;
    char pre[][7]={         
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='}};
    switch(a)
    {
	case '+':
            i=0;
            break;
        case '-':
            i=1;
            break;
        case '*':
            i=2;
            break;
        case '/':
            i=3;
            break;
        case '(':
            i=4;
            break;
        case ')'
            i=5;
            break;
        case '#':
            i=6;
            break;
    }
    switch(b)
    {
        case '+':
            j=0;
            break;
        case '-':
            j=1;
            break;
        case '*':
            j=2;
            break;
        case '/':
            j=3;
            break;
        case '(':
            j=4;
            break;
        case ')'
            j=5;
            break; 
        case '#':
            j=6;
            break;
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
	case '+':
        result = i+j;
        break;
        case '-':
         result = i-j;
         break;
        case '*':
          result = i * j;
          break;
        case '/':
           result = i/j;
           break;
    }
    return result;
}
int getNext(int *n)
{
  char c;
  *n = 0;
  while((c=getchar() == ''));
  if(!isdigit(c))
  {
	*n = c;
         return 1;
  }
  do{
    *n = *n*10+(c-'0');
    c = getchar();
    }while(isdigit(c));
   ungetc(c,stdin);
   return 0;
}

int EvaluationExpressions()
{
    int n;
    int flag;
    int c;
    char x;
    char theta;
    int a = 0;
    int b = 0;
    
    char OP[]="+-*/()#";
    SqStack OPTR;
    SqStack OPND;

    initStack(&OPTR);
    Push(&OPTR,'#');
    InitStack(&OPND);
    flag = getNext(&c);

    GetTop(OPTR,&x);
    while(c != '#' || x != '#')
    {
	if(flag == 0)
        {
	   push(&OPND,c);
           flag = getNext(&c);
        }
        else
        {
            GetTop(OPTR,&x);
            switch(Precede(x,c))
            {
	    case '<':
                push(&OPTR,c);
                flag = getNext(&c);
                break;
            case '=':
                pop(&OPTR,&x);
                flag = getNext(&c);
                break;
            case '>':
                pop(&OPTR,&theta);
                pop(&OPND,&b);
                pop(&OPND,&a);
                push(&OPND,Operate(a,theta,b));
                break;
            }
         }
         GetTop(OPTR,&x);
    }
    getTop(OPND,&c);
    return c;
}
int main()
{
    int c;
    printf("please input the expressions\n");
    c = EvaluationExpressions();
    printf("Result = %d\n",c);
    getch();
    return 0;
}






































