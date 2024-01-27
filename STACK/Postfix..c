#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACKSIZE 1000
#define TRUE 1
#define FALSE 0

struct stack
{
    int item[STACKSIZE];
    int top;
};

struct stack s;

void initialize(struct stack *s)
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

int peek(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\nStack is empty\n");
        exit(1);
    }
    else
    {
        return s->item[s->top];
    }
}

int isOperand(char c)
{
    return (c >= '0' && c <= '9');
}

int eval(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return a % b;
    case '^':
        return (int)pow(a, b);
    default:
        return 0;
    }
}

int posteval(char postfix[])
{
    struct stack S;
    initialize(&S);
    int i = 0;
    while (postfix[i] != '\0')
    {
        char symbol = postfix[i];
        if (isOperand(symbol))
        {
            push(&S, symbol - '0');
        }
        else
        {
            int a = pop(&S);
            int b = pop(&S);
            int val = eval(b, a, symbol);
            push(&S, val);
        }
        i++;
    }
    return peek(&S);
}

int main()
{
    char exp[30];
    int ans;
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    ans = posteval(exp);
    printf("Answer is -> %d\n", ans);
    return 0;
}

