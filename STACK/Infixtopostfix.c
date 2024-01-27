#include <stdio.h>
#include <stdlib.h>
#include "charheader.h"

int prcd(char op1, char op2)
{
    if (op1 == '(' || op2 == '(')
        return FALSE;
    if (op2 == ')')
        return TRUE;
    if ((op1 == '^' && (op2 == '*' || op2 == '/' || op2 == '%')) ||
    ((op1 == '*' || op1 == '/' || op1 == '%') && (op2 == '+' || op2 == '-')))
        return FALSE;

    return TRUE;
}

int isOperand(char c)
{
    return (c >= 'a' && c <= 'z');
}

void InfixToPostfix(char infix[])
{
    int i = 0;
    char symb, x;
    char Postfix[1000];
    int j = 0;
    struct stack S;
    initialize(&S);

    while (infix[i] != '\0')
    {
        symb = infix[i];
        i++;

        if (isOperand(symb))
        {
            Postfix[j] = symb;
            j++;
        }
        else
        {
            while (!isEmpty(&S) && prcd(stacktop(&S), symb))
            {
                x = pop(&S);
                Postfix[j] = x;
                j++;
            }
            push(&S, symb);
        }
    }

    while (!isEmpty(&S))
    {
        x = pop(&S);
        Postfix[j] = x;
        j++;
    }

    Postfix[j] = '\0';
    printf("%s\n", Postfix);
}

int main()
{
    char infix[1000] = "a+b*c-d/e";
    InfixToPostfix(infix);
    return 0;
}
