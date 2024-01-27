#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};
/*********************************/
struct headnode{
    int c;
    int max;
    int min;
    struct node *next;
};
/*********************************/
struct node *GetNode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
/*********************************/
struct node *headnode(){
    struct headnode *mhead;
    mhead = (struct headnode *)malloc(sizeof(struct headnode));
    mhead->c=0;
    mhead->max=__WINT_MIN__;
    mhead->min=__INT_MAX__;
}
/*********************************/
void createll(struct node **head){
    struct node *p;
    p=GetNode();
    p->info=0;
    p->next=NULL;
    (*head)=p;
}
/*********************************/
void traverse(struct node **head){
    struct node *p;
    int max=-1,min=32000;
    p=(*head)->next;
    while(p!=NULL){
        printf("%d-->",p->info);
        p=p->next;
    }
    while(max>(*head)->info){
        p=(*head)->next;
        max==p->info;
        p=p->next;
    }
        while(min<(*head)->info){
        p=(*head)->next;
        max==p->info;
        p=p->next;
        }
printf("Maximum is %d\n",max);
printf("Minimum is %d\n",min);
}
/*********************************/
int InsBeg(struct node **head,int x){
    struct node *p;
    struct node *q;
    q=(*head)->next;
    p=GetNode();
    p->info=x;
    (*head)->next=p;
    p->next=q;
    (*head)->info=(*head)->info+1;
    return 0;
}
/*********************************/
int main(){
    struct node *head;
    struct node *mhead;
    createll(&head);
    InsBeg(&head,100);
    InsBeg(&head,200);
    InsBeg(&head,300);
    InsBeg(&head,400);
    InsBeg(&head,500);
    traverse(&head);
    printf("\nThe no. of nodes are %d",head->info);

}
