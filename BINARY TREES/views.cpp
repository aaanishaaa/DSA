#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<stdlib.h>
using namespace std;
/************************************************************************/
/************************************************************************/
struct node{
int data;
struct node *left;
struct node *right;
int level;
int hd;
};
/************************************************************************/
struct node *Makenode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
// void preorder(struct node *t)
// {
//     if (t != NULL)
//     {
//         printf("%d ", t->data);
//         preorder(t->left);
//         preorder(t->right);
//     }
// }
// void inorder(struct node *t)
// {
//     if (t != NULL)
//     {
//         inorder(t->left);
//         printf("%d ", t->data);
//         inorder(t->right);
//     }
// }
// void postorder(struct node *t)
// {
//     if (t != NULL)
//     {
//         postorder(t->left);
//         postorder(t->right);
//         printf("%d ", t->data);
//     }
// }
void createTree(struct node **root)
{
    int x, choice;
    struct node *p, *q;
    if (*root == NULL)
    {
        printf("Enter the data of root node");
        scanf("%d", &x);
        p = Makenode(x);
        *root = p;
        createTree(&(*root));
    }
    else
    {
        printf("Whether the left of %d exist?(1/0)", (*root)->data);
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the data of left node");
            scanf("%d", &x);
            p = Makenode(x);
            (*root)->left = p;
            createTree(&(p));
        }

        printf("Whether the right of %d exist?(1/0)", (*root)->data);
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the data of right node");
            scanf("%d", &x);
            p = Makenode(x);
            (*root)->right = p;
            createTree(&(p));
        }
    }
}
/************************************************************************/
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
/************************************************************************/
int height(struct node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        if (t->left == NULL && t->right == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + max(height(t->left), height(t->right));
        }
    }
}
/***************************************************************************/
int levelorder(struct node *t){
    queue<struct node *>Q;
    Q.push(t);
    while(Q.size()!=0){
        struct node *x;
        x=Q.front();
        Q.pop();
        cout<<x->data<<" ";
        if(x->left!=NULL){
            Q.push(x->left);
        }
        if(x->right!=NULL){
            Q.push(x->right);
        }
    }
}
/************************************************************************/
void lrview(struct node *t){
    queue<struct node*>Q;
    int h=height(t);
    vector<int>HT[2*h+1];
    Q.push(t);
    t->level=0;
    HT[t->level].push_back(t->data);
    while(Q.size()!=0){
        struct node *x;
        x=Q.front();
        Q.pop();
        if(x->left!=NULL){
            x->left->level=x->level+1;
            Q.push(x->left);
            HT[x->left->level].push_back(x->left->data);
        }
            if(x->right!=NULL){
            x->right->level=x->level+1;
            Q.push(x->right);
            HT[->right->level].push_back(x->right->data);
        }
    }
}
cout<<endl<<"Left view of the tree:=>";
for(int i=0;i<=h;i++){
    cout<<HT[i][0]<<" ";
}

cout<<endl<<"Right view of the tree is :=>";
for(int i=0;i<=h;i++){
    int x;
    x=HT[i].size();
    cout<<HT[i][x-1]<<" ";
}

/************************************************************************/
int main(){
    struct node *root=NULL;
    createTree(&root);
    levelorder(root);
    lrview(root);
}