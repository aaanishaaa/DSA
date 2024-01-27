#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void FreeNode(struct node* P){
    free(P);
}

/*************************************************/

struct node *GetNode()
{
    struct node *P;
    P = (struct node *)malloc(sizeof(struct node));
    return P;
}

/*************************************************/

int InsBeg(struct node **CSTART,int x){
    struct node *P;
    P=GetNode();
    P->info=x;
    if((*CSTART)!=NULL){
        P->next=(*CSTART)->next;
        (*CSTART)->next=P;
    }
    else{
        P->next=P;
        (*CSTART)=P;
    }
    return 0;
}
/*************************************************/
void InsEnd(struct node **CSTART,int x)
{
    struct node *P;
    struct node *temp;
    P=GetNode();
    P->info=x;
    if(*CSTART!=NULL){
        temp=(*CSTART)->next;
        (*CSTART)->next=P;
        P->next=temp;
        (*CSTART)=P;
    }
    else{
        P->next=P;
        (*CSTART)=P;
    }
}

/*************************************************/

void Traverse(struct node *CSTART){
    struct node *P;
    P=(CSTART)->next;
    while(P!=(CSTART)){
        printf("%d-->",P->info);
        P=P->next; 
    }
     printf("%d",P->info);
}

/*************************************************/

void InsAft(struct node **CSTART,int aft,int x){
    struct node *P=*CSTART;
    struct node *Q;
    while(P->info!=aft){
        P=P->next;
    }
    Q=GetNode();
    Q->info=x;
    Q->next=P->next;
    P->next=Q;
}

/***************DELETIONS****************************/

void DelBeg(struct node **CSTART){
    int x;  
    struct node *P=(*CSTART)->next;
    struct node *Q=P->next;
    if((*CSTART)==NULL){
        printf("Void");
        exit (1);
    }
    else{
    (*CSTART)->next=Q;
    if((*CSTART)->next=(*CSTART)){
        (*CSTART)=NULL;
    }
    else{
        x=P->info;
        FreeNode(P);
    }
    }
    printf("\nDELETED NODE IS %d",x);
}

/*************************************************/
int main(){
    struct node *CSTART=NULL;
    InsBeg(&CSTART,10);
    InsBeg(&CSTART,20);
    InsBeg(&CSTART,30);
    InsBeg(&CSTART,40);
    InsBeg(&CSTART,50);
    InsAft(&CSTART,30,25);
    InsEnd(&CSTART,5);
    Traverse(CSTART);
    DelBeg(&CSTART);
    Traverse(CSTART);
}
