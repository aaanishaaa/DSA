#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

struct stack
{
    int item[STACKSIZE];
    int top;
};

struct stack s1; // Declare the stack structure
struct stack s2;
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
int main(){
    int x,min;
    INITIALIZE(&s1);
    INITIALIZE(&s2);
    push(&s1,7);
    push(&s1,4);
    push(&s1,9);
    push(&s1,2);
    push(&s1,8);
    min=stacktop(&s1);
    while(!isempty(&s1)){
        x=pop(&s1);
        if(x<min){
            min=x;
        }
        push(&s2,x);
    }
    while(!isempty(&s2)){
        x=pop(&s2);
        push(&s1,x);
    }
    printf("%d",min);
}