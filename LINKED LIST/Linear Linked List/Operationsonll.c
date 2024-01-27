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

void Traverse(struct node *list)
{
    struct node *P;
    P = list;
    while (P != NULL)
    {
        printf("%d\t", P->info);
        P = P->next;
    }
}

void InsBeg(struct node **list,int x)
{
    struct node *P;
    P = GetNode();
    P->info = x;
    P->next = *list;
    *list = P;
}

void count(struct node **list)
{
    int c = 0;
    struct node *P;
    P = *list;
    while (P != NULL)
    {
        c++;
        P = P->next;
    }
    printf("The count is %d\n", c);
}
void InsAft(struct node **list,int y, int x)
{
    struct node *temp;
    struct node *P;
    temp = *list;
    while (temp != NULL)
    {
        if (temp->info == y)
            break;
        else
            temp = temp->next;
    }
    P = GetNode();
    P->info = x;
    P->next = temp->next;
    temp->next = P;
}
void InsEnd(struct node **list,int x)
{
    struct node *P;
    struct node *Q;
    P = *list;
    while (P->next != NULL)
    {
        P = P->next;
    }
    Q = GetNode();
    Q->info = x;
    Q->next = NULL;
    P->next = Q;
}
// void counteo(struct node **list)
// {
//     struct node *P;
//     P = *list;
//     int ce = 0, co = 0;
//     while (P != NULL)
//     {
//         if (P->info % 2 == 0)
//         {
//             ce++;
//         }
//         else
//         {
//             co++;
//         }
//         P = P->next;
//     }
//     printf("Even nodes are %d\n", ce);
//     printf("Odd nodes are %d\n", co);
// }
int DelBeg(struct node **list){
    struct node *P;
    int x;
    P= *list;
    *list= (*list) ->next;
    x=P->info;
    free(P);
    return x;
}
void Reverse(struct node** list){
    struct node *P = NULL;
    struct node *C = *list;
    struct node *N = (*list)->next;
    while (C) {
        C->next = P;
        P = C;
        C = N;
        if (N) {
            N = N->next;
        }
    }
    *list = P;
}
void Merge(struct node **list1, struct node **list2){
    struct node *P = *list1;
    struct node *Q = *list2; 
    struct node *list3 = NULL; 

    while (P != NULL && Q != NULL) {
        if (P->info < Q->info) {
            InsBeg(&list3, P->info);
            P = P->next;
        } else {
            InsBeg(&list3, Q->info);
            Q = Q->next;
        }
    }
    while (P != NULL) {
        InsBeg(&list3, P->info);
        P = P->next;
    }
    while (Q != NULL) {
        InsBeg(&list3, Q->info);
        Q = Q->next;
    }

    Reverse(&list3);
    Traverse(list3);
}
int DelEnd(struct node **list){
    struct node *P;
    struct node *Q;
    P=*list;
    Q=NULL;
    int x;
    while(P->next!=NULL){
        Q=P;
        P=P->next;
    }
    Q->next=NULL;
    x=P->info;
    free(P);
    return x;
}
void Union(struct node **list1, struct node **list2){
    struct node *P = *list1;
    struct node *Q = *list2; 
    struct node *list3 = NULL; 

    while (P != NULL && Q != NULL) {
        if (P->info < Q->info) {
            InsBeg(&list3, P->info);
            P = P->next;
        } else if(Q->info<P->info)
        {
            InsBeg(&list3, Q->info);
            Q = Q->next;
        }
        else{
            InsBeg(&list3, P->info);
            P = P->next;
            Q=Q->next;
        }
    }
    while (P != NULL) {
        InsBeg(&list3, P->info);
        P = P->next;
    }
    while (Q != NULL) {
        InsBeg(&list3, Q->info);
        Q = Q->next;
    }

    Reverse(&list3);
    Traverse(list3);
}
void Intersection(struct node **list1, struct node **list2){
    struct node *P = *list1;
    struct node *Q = *list2; 
    struct node *list3 = NULL; 

    while (P != NULL && Q != NULL) {
        if (P->info < Q->info) {
            // InsBeg(&list3, P->info);
            P = P->next;
        } else if(Q->info<P->info)
        {
            // InsBeg(&list3, Q->info);
            Q = Q->next;
        }
        else{
            InsBeg(&list3, P->info);
            P = P->next;
            Q=Q->next;
        }
    }
    Reverse(&list3);
    Traverse(list3);
}
void S1S2(struct node **list1, struct node **list2){
    struct node *P = *list1;
    struct node *Q = *list2; 
    struct node *list3 = NULL; 

    while (P != NULL && Q != NULL) {
        if (P->info < Q->info) {
            InsBeg(&list3, P->info);
            P = P->next;
        } else if(Q->info<P->info)
        {
            // InsBeg(&list3, Q->info);
            Q = Q->next;
        }
        else{
            // InsBeg(&list3, P->info);
            P = P->next;
            Q=Q->next;
        }
    }
    while (P != NULL) {
        InsBeg(&list3, P->info);
        P = P->next;
    }
    Reverse(&list3);
    Traverse(list3);
}
void S2S1(struct node **list1, struct node **list2){
    struct node *P = *list1;
    struct node *Q = *list2; 
    struct node *list3 = NULL; 

    while (P != NULL && Q != NULL) {
        if (P->info < Q->info) {
            // InsBeg(&list3, P->info);
            P = P->next;
        } else if(Q->info<P->info)
        {
            InsBeg(&list3, Q->info);
            Q = Q->next;
        }
        else{
            // InsBeg(&list3, P->info);
            P = P->next;
            Q=Q->next;
        }
    }
    while (Q != NULL) {
        InsBeg(&list3, Q->info);
        Q = Q->next;
    }
    Reverse(&list3);
    Traverse(list3);
}
void SymmerticDiff(struct node **list1, struct node **list2){
    struct node *P = *list1;
    struct node *Q = *list2; 
    struct node *list3 = NULL; 

    while (P != NULL && Q != NULL) {
        if (P->info < Q->info) {
            InsBeg(&list3, P->info);
            P = P->next;
        } else if(P->info > Q->info){
            InsBeg(&list3, Q->info);
            Q = Q->next;
        }
        else{
            // InsBeg(&list3, P->info);
            P = P->next;
            Q = Q->next;
        }
    }
    while (P != NULL) {
        InsBeg(&list3, P->info);
        P = P->next;
    }
    while (Q != NULL) {
        InsBeg(&list3, Q->info);
        Q = Q->next;
    }

    Reverse(&list3);
    Traverse(list3);
}
int main()
{
    struct node *START1;
    struct node *START2;
    struct node *START3;
    START1 = NULL;
    START2 = NULL;
    int x;
    InsBeg(&START1, 500);
    InsBeg(&START1, 400);
    InsBeg(&START1, 300);
    InsBeg(&START1, 200);
    InsBeg(&START1, 100);
    Traverse(START1);
     printf("\n\n");
    InsBeg(&START2, 800);
    InsBeg(&START2, 300);
    InsBeg(&START2, 100);
    Traverse(START2);
    printf("\n\n");
    Merge(&START1,&START2);
    printf("\n\n");
    Union(&START1,&START2);
    printf("\n\n");
    Intersection(&START1,&START2);
    printf("\n\n");
    S1S2(&START1,&START2);
    printf("\n\n");
    S2S1(&START1,&START2);
    printf("\n\n");
    SymmerticDiff(&START1,&START2);
    return 0;
}