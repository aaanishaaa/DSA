#include<stdlib.h>
#include<stdio.h>
struct node{
    int info;
    struct node* prev;
    struct node* next;
};

/**************************/

struct node* Getnode(){
    struct node* P;
    P=(struct node*) malloc(sizeof(struct node));
    P->next=NULL;
    P->prev=NULL;
    return P;
}

/**************************/

void freenode(struct node* temp){
    free(temp);
}
/**************************/
void InsBeg(struct node **dSTART,int x){
    struct node* P;
    P=Getnode();
    P->info=x;
    P->next=(*dSTART);
    if((*dSTART)!=NULL){
        (*dSTART)->prev=P;
    }
    (*dSTART)=P;
}
/**************************/
void Traverse(struct node *dSTART){
    struct node *P=dSTART;
    while(P!=NULL){
        printf("%d  ",P->info);
        P=P->next;
    }
    printf("\n");
}
/**************************/
void InsAft(struct node **dSTART,struct node **P,int x){
    struct node* R;
    struct node* Q=(*P)->next;
    R=Getnode();
    R->info=x;
    (*P)->next=R;
    R->prev=(*P);
    R->next=Q;
    if(Q!=NULL){
        Q->prev=R;
    }
}
/**************************/
struct node *linearSearch(struct node **dSTART,int x)
{
    struct node *P;
    P = (*dSTART);
    while (P)
    {
        if (P->info == x)
        {
            printf("\n%d found\n", x);
            return P;
        }
        P = P->next;
    }
    printf("element not found");
    return NULL;
}
/**************************/
void InsEnd(struct node **dSTART,int x){
    struct node *P;
    struct node *Q;
    P=Getnode();
    P->info=x;
    P->next=NULL;
    if((*dSTART)!=NULL){
        Q=(*dSTART);
    while(Q->next!=NULL){
        Q=Q->next;
    }
    Q->next=P;
    P->prev=Q;
    }
    else{
        P->prev=NULL;
        (*dSTART)=P;
    }

}
/**************************/
void InsBef(struct node **dSTART,struct node **P,int x){
    struct node *Q;
    struct node *N;

    N=Getnode();
    N->info=x;

    Q=(*P)->prev;
    N->next=(*P);
    (*P)->prev=N;
    N->prev=Q;
    if(Q!=NULL){
        Q->next=N;
    }
    else
    (*dSTART)=N;
}
/************DELETIONS**************/

void DelBeg(struct node **dSTART){
    struct node *P;
    int x;
    P=(*dSTART);
    (*dSTART)=(*dSTART)->next;
    if(dSTART!=NULL){
        (*dSTART)->prev=NULL;
    }
    x=P->info;
    freenode(P);
    printf("THE DELETED NODE IS %d\n",x);
    }

/**************************/
void DelEnd(struct node **dSTART){
    struct node *P;
    struct node *Q;
    int x;
    P=(*dSTART);
    while(P->next!=NULL){
        P=P->next;
    }
    Q=P->prev;
    if(Q!=NULL){
        Q->next=NULL;
    }
    else{
        (*dSTART)->next=NULL;
    }
    x=P->info;
    freenode(P);
    printf("THE DELETED NODE IS %d\n",x);
}
/**************************/
void DelAft(struct node **dSTART,struct node **P){
if((*P)!=NULL && (*P)->next){
    struct node *Q=(*P)->next;
    (*P)->next=Q->next;
    if(Q->next){
        Q->next->prev=(*P);
    }
    freenode(Q);
}
else{
    printf("Void Deletion");
    exit(1);
}
}
/**************************/
int DelBef(struct node **dSTART,struct node **P){
    struct node *Q;
    if((*P)!=NULL && (*P)->prev){
        Q=(*P)->prev;
        (*P)->prev=Q->prev;
        if(Q->prev!=NULL){
            Q->prev->next=(*P);
        }
        else{
            (*P)=Q;
        }
        freenode(Q);
    }
    else{
        printf("VOID DELETION");
    }
}
/**************************/
int main(){
    struct node* dSTART;
    dSTART=NULL;
    InsBeg(&dSTART,600);
    InsBeg(&dSTART,500);
    InsBeg(&dSTART,400);
    InsBeg(&dSTART,200);
    InsBeg(&dSTART,100);
    struct node* x=linearSearch(&dSTART,400);
    InsAft(&dSTART,&x,300);
    InsEnd(&dSTART,1000);
    InsBef(&dSTART,&x,700);
    Traverse(dSTART);
    DelBeg(&dSTART);
    DelEnd(&dSTART);
    Traverse(dSTART);
    DelAft(&dSTART,&x);
    Traverse(dSTART);
    DelBef(&dSTART,&x);
    Traverse(dSTART);
}