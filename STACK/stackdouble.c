#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
#define TRUE
#define FALSE

struct stack
{
    int item[STACKSIZE];
    int top;
};
struct stack top1;
struct stack top2;
int stacktop1(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\nStack underflows\n");
        exit(1);
    }
    else
    {
        int x;
        x = s->item[s->top];
        return x;
    }
}
int stacktop2(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\nStack underflows\n");
        exit(1);
    }
    else
    {
        int x;
        x = s->item[s->top];
        return x;
    }
}

int arr[STACKSIZE];

void initialise1(){
    stacktop1==-1;
}

int isempty1(struct stack *s)
{
    if (s->top1 == -1)
        return TRUE;
    else
        return FALSE;
}
