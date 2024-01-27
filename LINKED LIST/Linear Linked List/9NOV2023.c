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

void FreeNode(struct node* P){
    free(P);
}

void Traverse()
{
    struct node *P;
    P = START;
    while (P != NULL)
    {
        printf("%d\t\n", P->info);
        P = P->next;
    }
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

void DelBeg(){
    int x;
    if(START==NULL){
        printf("VOID DELETION");
    }
    else{
        struct node* P;
        P=START;
        START=START->next;
        x=P->info;
        FreeNode(P);
    }
    printf("Deleted Node is %d\n",x);
}

void DelEnd(){
 int y;
if(START==NULL)
{
    printf("Void Deletion");
}
else {
    struct node* P;
    struct node* Q;
    P=START;
    Q=NULL;
    while(P->next!=NULL){
        Q=P;
        P=P->next;
    }
    if(Q!=NULL){
        Q->next=NULL;
    }
    else{
        START=NULL;
        }
        y=P->info;
        FreeNode(P);
    
    }
    printf("The Deleted end node is %d\n",y);
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
    DelBeg();
    Traverse();
    DelEnd();
    Traverse();
}