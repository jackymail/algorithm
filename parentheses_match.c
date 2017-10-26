#include "stdio.h"
#include "stdlib.h"
#define STACKINCREAMENT 10
#define STACK_INIT_SIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int status;
typedef char SElemtype;
typedef struct{
    SElemtype *base;
    SElemtype *top;
    status stacksizse;
}sqstack;

status init(sqstack *s)
{
     if(NULL == s)
     {
	s->base = (SElemtype*)malloc(STACK_INIT_SIZE*sizeof(SElemtype));
        if(!s->base)
        {
	   printf("fail to allocate the memory\n");
           return;
        }
     }
     s->top = s->base;
     s->stacksizse = STACK_INIT_SIZE;
     return OK;
}
status Gettop(sqstack *s,SElemtype *e)
{
    if(s->top == s->base)
    {
	return ERROR;
    }
    *e = *(s->top-1);
    return OK;
}
status push(sqstack *s,SElemtype e)
{
   if(s->top - s->base >= s->stacksizse)
   {
	s->base = (SElemtype*)realloc(s->base,(s->stacksizse+STACKINCREAMENT)*sizeof(SElemtype));
        if(!s->base)
        {
	    return;
        }
      s->top = s->base + stacksizse;
      s->stacksizse += STACKINCREAMENT;
   }
   *s->top++ = e;
   return OK;
}

status pop(sqstack *s,SElemtype *e)
{
     if(s->top == s->base)
     {
	return ERROR;
     }
     *e = *--s->top;
     return OK;
}

status stackempty(sqstack *s)
{
    if(s->top == s->base)
    {
	return OK;
    }
    else
    {
	return ERROR;
    }
}

status clearstack(sqstack *s)
{
    if(s->top == s->base)
    {
	return ERROR;
    }
    s->top = s->base;
    return OK;
}
status parenthesis_match(sqstack *s,char *str)
{
    int i = 0;
    int flag = 0;
    SElemtype e;
    while(str[i] != '\0')
    {
        switch(str[i])
        {
	   case '(':
               push(s,str[i]);
               break;
           case '[':
               push(s,str[i]);
               break;
           case ')':
                {
		   pop(s,&e);
                   if(e != '(')
                   {
			flag = 1;
                   }
                }
                break;
            case ']':
                {
		   pop(s,&e);
                   if(e != '[')
                   {
			flag = 1;
                   }
                }
                break;
            default:
                break;
        }
        if(flag)
        {
	   break;
        }
        i++;
    }
    if(!flag && stackempty(s))
    {
	printf("mathed\n");
    }
    else 
    { 
        printf("mis matched\n");
    }
    return OK;
}
int main()
{
    char str[100];
    char enter;
    sqstack s;
    init(&s);
    printf("please input string\n");
    scanf("%s",str);
    scanf("%c",&enter);
    parenthesis_match(&s,str);
    return 0;
}



































