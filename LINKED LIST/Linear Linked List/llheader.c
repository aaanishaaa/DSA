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

// void count(struct node **list)
// {
//     int c = 0;
//     struct node *P;
//     P = *list;
//     while (P != NULL)
//     {
//         c++;
//         P = P->next;
//     }
//     printf("The count is %d\n", c);
// }
// void InsAft(struct node **list,int y, int x)
// {
//     struct node *temp;
//     struct node *P;
//     temp = *list;
//     while (temp != NULL)
//     {
//         if (temp->info == y)
//             break;
//         else
//             temp = temp->next;
//     }
//     P = GetNode();
//     P->info = x;
//     P->next = temp->next;
//     temp->next = P;
// }
// void InsEnd(struct node **list,int x)
// {
//     struct node *P;
//     struct node *Q;
//     P = *list;
//     while (P->next != NULL)
//     {
//         P = P->next;
//     }
//     Q = GetNode();
//     Q->info = x;
//     Q->next = NULL;
//     P->next = Q;
// }
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
int main()
{
    struct node *START;
    START = NULL;
    int x;
    InsBeg(&START, 100);
    InsBeg(&START, 200);
    InsBeg(&START, 300);
    InsBeg(&START, 400);
    InsBeg(&START, 500);
    DelBeg(&START);
    DelEnd(&START);
    Traverse(START);
    return 0;
}