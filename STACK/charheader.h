#define STACKSIZE 1000

struct stack
{
    char item[STACKSIZE];
    char top;
};

// Initialize the stack by setting top to -1
void initialize(struct stack *S)
{
    S->top = -1;
}

int isEmpty(struct stack *S)
{
    return (S->top == -1);
}

void push(struct stack *S, char k)
{
    if (S->top == STACKSIZE - 1)
    {
        printf("Stack Overflow: Cannot push %c\n", k);
        exit(1);
    }
    else
    {
        S->top++;
        S->item[S->top] = k;
    }
}

char pop(struct stack *S)
{
    if (isEmpty(S))
    {
        printf("Stack Underflow: Cannot pop\n");
        exit(1);
    }
    else
    {
        char x = S->item[S->top];
        S->top--;
        return
