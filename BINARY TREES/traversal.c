#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
/************************************/
struct node *Makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
    }
void preorder(struct node *t){
    if(t!=NULL){
        printf("%d",t->data);
        preorder(t->left);
        preorder(t->right);
    }
    
}
void inorder(struct node *t){
    if(t!=NULL){
        inorder(t->left);
        printf("%d",t->data);
        inorder(t->right);
    }
    
}
void postorder(struct node *t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d",t->data);
    }
    
}
/*************************************/
int main(){
    struct node *root=NULL;
    root=Makenode(1);
    root->left=Makenode(2);
    root->right=Makenode(5);
    root->left->left=Makenode(3);
    root->left->right=Makenode(4);
    root->right->right=Makenode(6);
    preorder(root);
    printf("\n\n");
    inorder(root);
    printf("\n\n");
    postorder(root);
}