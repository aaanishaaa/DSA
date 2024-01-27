#define STACKSIZE 1000
#define TRUE 1
#define FALSE 0
// **************************************************
struct stack
{
    int item[STACKSIZE];
    int top;
};
// ******************************************************
void initialize(struct stack *S)
{
    S->top=-1;
}
// **********************************************************
int isEmpty(struct stack *S)
{
    if(S->top==-1)
        return TRUE;
    else
        return FALSE;

}
// *********************************************************
void push(struct stack *S,int k)
{
    if(S->top==STACKSIZE-1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
        S->top++;
        S->item[S->top]=k;
    }
}
// **************************************************************
int pop(struct stack *S)
{
    if(isEmpty(S))
    {
        printf("stack underflow");
        exit(1);
    }
    else
    {
        int x=S->item[S->top];
        S->top--;
        return x;
    }
}
// ***************************************************************
int Stacktop(struct stack *S){
    int x;
    x= S->item[S->top];
    return x;
}
