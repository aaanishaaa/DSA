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
struct node*  linearSearch(int x){
   struct node *P;
   P = START;
    while (P != NULL)
    {
        if(P->info == x){
            printf("\n %d found",x);
            return P;
        }
        P=P->next;
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

void count(){
    int c=0;
    struct node* P;
    P=START;
    while(P!=NULL){
        c++;
        P=P->next;
    }
    printf("The count is %d\n",c);
}

void InsEnd(int x)
{
    struct node *P;
    struct node *Q;
    P = START;
    while (P->next != NULL)
    {
        P = P->next;
    }
    Q = GetNode();
    Q->info = x;
    Q->next = NULL;
    P->next = Q;
}
int reverse(){
    struct node *P;
    struct node *C;
    struct node *N;
    P=NULL;
    C=START;
    N=C->next;
    while(C!=NULL){
        C->next=P;
        P=C;
        C=N;
        if(N!=NULL){
            N=N->next;
        }
    }
START=P;
}

int main()
{
    START = NULL;
    InsBeg(1);
    InsBeg(2);
    InsBeg(3);
    InsBeg(4);
    InsBeg(5);
    InsEnd(7);
    Traverse();
    printf("\n");
    linearSearch(2);
    printf("\n");
    reverse();
    printf("\n");
    Traverse();
}