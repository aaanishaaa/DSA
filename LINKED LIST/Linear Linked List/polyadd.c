#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
    int exp;
    struct node *next;
};

struct node *Getnode(){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->next=NULL;
    return p;
}

void InsBeg(struct node **START,int c, int e)
{
    struct node *p;
    p=Getnode();
    p->coef=c;
    p->exp=e;
    p->next=(*START);
    (*START)=p;
}

void Traverse(struct node *START)
{
    struct node *p;
    p=START;
    while(p!=NULL){
        printf("%dx^%d + ",p->coef,p->exp);
        p=p->next;
    }
}
struct node *AddPoly(struct node *Poly1, struct node *Poly2) {
    struct node *Poly3 = NULL;
    struct node *p = Poly1;
    struct node *q = Poly2;

    while (p != NULL && q != NULL) {
        if (p->exp == q->exp) {
            InsBeg(&Poly3, p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        } else if (p->exp > q->exp) {
            InsBeg(&Poly3, p->coef, p->exp);
            p = p->next;
        } else {
            InsBeg(&Poly3, q->coef, q->exp);
            q = q->next;
        }
    }

    while (p != NULL) {
        InsBeg(&Poly3, p->coef, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        InsBeg(&Poly3, q->coef, q->exp);
        q = q->next;
    }

    return Poly3;
}
struct node *SubPoly(struct node *Poly1, struct node *Poly2)
{
    struct node *Poly3 = NULL;
    struct node *p = Poly1;
    while (p != NULL)
    {
        p->coef = -1 * p->coef;
        p = p->next;
    }
    Poly3 = AddPoly(Poly1, Poly2);
    return Poly3;
}
struct node *MulPoly(struct node *Poly1, struct node *Poly2)
{
    struct node *Poly3 = NULL;
    struct node *p = Poly1;
    struct node *q;
    int N = Poly1->exp + Poly2->exp;
    int *DAT, x, i;
    DAT = (int *)calloc(N + 1, sizeof(int));
    while (p != NULL)
    {
        q = Poly2;
        while (q != NULL)
        {
            x = p->exp + q->exp;
            DAT[x]++;
            q = q->next;
        }
        p = p->next;
    }
    for (i = 0; i <= N; i++)
    {
        if (DAT[i] != 0)
            InsBeg(&Poly3, DAT[i], i);
    }
    return Poly3;
}

int main(){
    struct node *Poly1=NULL;
    struct node *Poly2=NULL;
    struct node *Poly3;
    InsBeg(&Poly1,9,1);
    InsBeg(&Poly1,8,2);
    InsBeg(&Poly1,3,3);
    InsBeg(&Poly1,7,4);
    Traverse(Poly1);
    printf("\n\n\n");
    InsBeg(&Poly2,4,1);
    InsBeg(&Poly2,5,2);
    InsBeg(&Poly2,8,3);
    InsBeg(&Poly2,2,4);
    Traverse(Poly2);
    printf("\n\n\n");
    Poly3=AddPoly(Poly1,Poly2);
    Traverse(Poly3);
    printf("\n\n\n");
    Poly3=SubPoly(Poly1,Poly2);
    Traverse(Poly3);
    printf("\n\n\n");
    Poly3=MulPoly(Poly1,Poly2);
    Traverse(Poly3);
    return 0;
}
