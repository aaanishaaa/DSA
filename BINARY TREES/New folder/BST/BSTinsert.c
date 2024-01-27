#include<stdio.h>
#include<stdlib.h>

/********************************/

struct node{
    int data;
    struct node* left;
    struct node* right;
};

/********************************/
struct node *makenode(int k){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=k;
    p->left=NULL;
    p->right=NULL;
    return p;
}

/********************************/
struct node* BSTinsert(struct node* T,int key){
    if(T==NULL){
        T=makenode(key);
    }
    else{
        if(key<T->data){
            T->left=BSTinsert(T->left,key);
        }
        else{
            T->right=BSTinsert(T->right,key);
        }
    }
    return T;
}

/********************************/
void inorder(struct node *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}
void minele(struct node *T){
    while(T->left!=NULL){
        T=T->left;
    }
    printf("\nThe min element is %d",T->data);
} 
void maxele(struct node *T){
    while(T->right!=NULL){
        T=T->right;
    }
    printf("\nThe max element is %d",T->data);
}
void BSTsearch(struct node* T,int key){
    if(T!=NULL){
        if(T->data==key){
            printf("Element found");
            return;
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
    printf("element not found");
    }
}
/*****************************/
int main(){
    struct node* T=NULL;
    struct node* x;
    T=BSTinsert(T,100);
    T=BSTinsert(T,50);
    T=BSTinsert(T,150);
    T=BSTinsert(T,20);
    T=BSTinsert(T,70);
    T=BSTinsert(T,120);
    T=BSTinsert(T,170);
    inorder(T);
    minele(T);
    maxele(T);
    printf("\n");
    BSTsearch(T,50);
}