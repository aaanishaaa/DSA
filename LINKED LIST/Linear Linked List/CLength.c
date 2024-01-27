#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *START;

struct node *GetNode()
{
    struct node *P;
    P = (struct node *)malloc(sizeof(struct node));
    return P;
}

void Traverse()
{
    struct node *P;
    P = START;
    while (P != NULL)
    {
        printf("%d\t", P->info);
        P = P->next;
    }
}
struct node *linearSearch(int x)
{
    struct node *P;
    P = START;
    while (P)
    {
        if (P->info == x)
        {
            printf("\n%d found", x);
            return P;
        }
        P = P->next;
    }
    printf("element not found");
    return NULL;
}

void InsBeg(int x)
{
    struct node *P;
    P = GetNode();
    P->info = x;
    P->next = START;
    START = P;
}

void count()
{
    int c = 0;
    struct node *P;
    P = START;
    while (P != NULL)
    {
        c++;
        P = P->next;
    }
    printf("The count is %d\n", c);
}

int CDetection()
{
    struct node *P;
    struct node *Q;
    P = START;
    Q = START->next;
    while (Q && Q->next)
    {
        P = P->next;
        Q = Q->next;
        Q = Q->next;
        if (P == Q)
        {
            return 1;
        }
    }
    return 0;
}

int Clength()
{
    int c = 0;
    struct node *P;
    struct node *Q;
    int X;
    while (Q && Q->next)
    {
        P = P->next;
        Q = Q->next;
        Q = Q->next;
        if (P == Q)
        {
            Q = X;
            P = P->next;
            while (P!=0)
            {
                c++;
                P = P->next;
            }
        }
    }
    return c;
}
int main()
{
    START = NULL;
    struct node *P;
    struct node *Q;
    InsBeg(6);
    InsBeg(5);
    InsBeg(4);
    InsBeg(3);
    InsBeg(2);
    InsBeg(1);
    P = linearSearch(6);
    Q = linearSearch(3);
    P->next = Q;
    int x = Clength();
    printf("The length is %d",x);
}