#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *GetNode()
{
    struct node *P;
    P = (struct node *)malloc(sizeof(struct node));
    return P;
}

void Traverse(struct node *chain)
{
    struct node *P;
    P = (chain);
    while (P != NULL)
    {
        printf("\t%d\t", P->info);
        P = P->next;
    }
}

void InsBeg(struct node **chain,int x)
{
    struct node *P;
    P = GetNode();
    P->info = x;
    P->next = (*chain);
    (*chain) = P;
}

int main(){
    struct node*chain [10]={NULL};
    for(int i=1;i<=100;i++){
        int k=i%10;
        InsBeg(&chain[k],i);
    }
    for(int i=0;i<10;i++){
        printf("\n Chain is %d =>",i);
        Traverse(chain[i]);
    }
}