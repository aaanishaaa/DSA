#include<stdio.h>
#include <string.h>
#include "intheader.h"
int prcd(char op1, char op2)
{
    if(op1=='(')
        return FALSE;
    else
    {
        if(op2=='(')
            return FALSE;
        else
        {
            if(op2==')')
                return TRUE;
            else
            {
                if (op1='^' || op1=='*' || op1=='/' || op1=='%')
                {
                    if (op2=='^')
                    {
                        return FALSE;
                    }
                    else
                        return TRUE;
                }
                else
                {
                    if(op2=='+' || op2=='-')
                    {
                        return TRUE;
                    }
                    else
                        return FALSE;
                }
            }
        }
    }
}
void InfixToPrefix(char infix[])
{
    struct stack S;
    initialize(&S);
    int i=0;
    char symb,x;
    char Postfix[1000];
    int j=0;
    while(infix[i]!='\0')
    {
        symb=infix[i];
        i++;
        if(symb>='a' && symb<='z')
        {
            Postfix[j]=symb;
            j++;
        }
        else
        {
            while(!isEmpty(&S) && prcd(Stacktop(&S),symb))
            {
                x=pop(&S);
                Postfix[j]=x;
                j++;
            }
            push(&S,symb);
        }
        while (!isEmpty(&S))
        {
            x=pop(&S);
            Postfix[j]=x;
            j++;
        }

    }
    Postfix[j]='\0';
    printf("%s",Postfix);
}
int main()
{
    char infix[1000]="a+b-c";
    InfixToPostfix(infix);
    return 0;
}

