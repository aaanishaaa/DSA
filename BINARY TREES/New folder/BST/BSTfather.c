#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
    struct node* father;
};
/**********************************************/
struct node *makenode(int k){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=k;
    p->left=NULL;
    p->right=NULL;
    p->father=NULL;
    return p;
}
/**********************************************/
struct node* BSTinsert(struct node* T, int key){
    struct node *P,*Q,*R;
    R=makenode(key);
    P=T;
    Q=NULL;
    if(T==NULL){
        T=R;
    }
    else{
        while(P!=NULL){
            Q=P;
            if(key<P->data){
                P=P->left;
            }
            else{
                P=P->right;
            }
        }
        if(key<Q->data){
            Q->left=R;
        }
        else{
            Q->right=R;
        }
    }
    R->father=Q;
    return T;
}
/**********************************************/
void inorder(struct node *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}
/**********************************************/
struct node* BSTsearch(struct node* T,int key){
    if(T!=NULL){
        if(T->data==key){
            return T;
        }
        else{
            if(key<T->data){
                BSTsearch(T->left,key);
            }
            else{
                BSTsearch(T->right,key);
            }
        }
    }
    else{
    return NULL;
    }
}
/**********************************************/
struct node* BSTminimum(struct node* T){
    while(T->left!=NULL){
        T=T->left;
    }
    return T;
}
/**********************************************/
struct node* BSTmaximum(struct node* T){
    while(T->right!=NULL){
        T=T->right;
    }
    return T;
}
/**********************************************/
struct node* BSTSuccesor(struct node* P){
    struct node* Q;
    if(P->right!=NULL){
        Q=BSTminimum(P->right);
        return Q;
    }
    else{
        Q=P->father;
        while(Q!=NULL && Q->right==P){
            P=Q;
            Q=Q->father;
        }
        return Q;
    }
}
/**********************************************/
struct node* BSTPredecessor(struct node* P){
    struct node* Q;
    if(P->left!=NULL){
        Q=BSTmaximum(P->left);
        return Q;
    }
    else{
        Q=P->father;
        while(Q!=NULL && Q->left==P){
            P=Q;
            Q=Q->father;
        }
        return Q;
    }
}
/**********************************************/
int main(){
    struct node* T=NULL;
    struct node* P,*Q;
    T=BSTinsert(T,6);
    T=BSTinsert(T,5);
    T=BSTinsert(T,4);
    T=BSTinsert(T,9);
    T=BSTinsert(T,14);
    T=BSTinsert(T,16);
    T=BSTinsert(T,12);
    T=BSTinsert(T,10);
    T=BSTinsert(T,11);
    T=BSTinsert(T,15);
    T=BSTinsert(T,2);
    T=BSTinsert(T,1);
    T=BSTinsert(T,3);
    T=BSTinsert(T,8);
    T=BSTinsert(T,7);
    T=BSTinsert(T,13);

    inorder(T);

    printf("\n");

    P=BSTsearch(T,8);
    printf("The element %d found at %u",P->data,P);
    printf("\n");

    Q=BSTsearch(T,9);
    printf("\n");

    P=BSTSuccesor(Q);
    printf("The succesor of %d is %d", Q->data,P->data);

    printf("\n");
    P=BSTPredecessor(Q);
    printf("The predecessor of %d is %d", Q->data,P->data);
    printf("\n");
}