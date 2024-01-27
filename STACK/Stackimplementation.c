#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 1000
#define TRUE 1
#define FALSE 0

struct stack
{
    int item[STACKSIZE];
    int top;
};

struct stack s; // Declare the stack structure

void INITIALIZE(struct stack *s)
{
    s->top = -1;
}

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

int isempty(struct stack *s)
{
    if (s->top == -1)
        return TRUE;
    else
        return FALSE;
}

void main()
{
    int x;
    INITIALIZE(&s); // Pass the address of the stack structure
    push(&s, 3);
    push(&s, 7);
    x = pop(&s);

    printf("\nPushed value is: %d", 3);
    printf("\nPushed value is: %d", 7);
    printf("\nPopped value is: %d", x);

}
