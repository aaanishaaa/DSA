#include<stdio.h>
#include <stdlib.h>
#define STACKSIZE 1000
#define TRUE
#define FALSE

struct stack{
int item[STACKSIZE];
int top;
};

struct stack s;

/***************************/
void initialize(struct stack *s)
{
    s->top = -1;
}
/**************************/
void push(struct stack *s, int x)
{
    if (s->top == STACKSIZE - 1)
    {
        printf("\nStack overflows\n");
        exit(1);
    }
    else
    {
        s->top++;
        s->item[s->top] = x;
    }
}
/*************************/
int pop(struct stack *s)
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
        s->top--;
        return x;
    }
}
/*************************/
int stacktop(struct stack *s)
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
/***************************/
int isempty(struct stack *s)
{
    if (s->top == -1)
        return TRUE;
    else
        return FALSE;
}

void main()
{
    int x,a,b,c;
    initialize(&s);
    printf("\n enter the number to pushed");
    scanf("%d",&a);
    printf("\n enter the number to push");
    scanf("%d",&b);
    printf("\n enter the number to push");
    scanf("%d",&c);
    push(&s, a);
    push(&s, b);
    push(&s, c);
    x = pop(&s);

    printf("\nPushed value is: %d", a);
    printf("\nPushed value is: %d", b);
     printf("\nPushed value is: %d", c);
    printf("\nPopped value is: %d", x);

}
