#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
/************************************/
struct node *Makenode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
/*************************************/
void preorder(struct node *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(struct node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}
void postorder(struct node *t)
{
    if (t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}
/*************************************/
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
/*************************************/
int countnode(struct node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countnode(t->left) + countnode(t->right);
    }
}
/*************************************/
int countn0(struct node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        if (t->right == NULL && t->left == NULL)
        {
            return 1;
        }
        else
        {
            return countn0(t->left) + countn0(t->right);
        }
    }
}
/*************************************/
int countn1(struct node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        if (t->right == NULL && t->left == NULL)
        {
            return 0;
        }
        else
        {
            if (t->right != NULL && t->left != NULL)
            {
                return countn1(t->left) + countn1(t->right);
            }
            else
            {
                return countn1(t->left) + countn1(t->right) + 1;
            }
        }
    }
}
/*************************************/
int countn2(struct node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        if (t->right == NULL && t->left == NULL)
        {
            return 0;
        }
        else
        {
            if (t->right != NULL && t->left != NULL)
            {
                return countn2(t->left) + countn2(t->right) + 1;
            }
            else
            {
                return countn2(t->left) + countn2(t->right);
            }
        }
    }
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
/*************************************/
int height(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL &&t->right==NULL){
            return 0;
        }
        else{
            return 1+max(height(t->left),height(t->right));
        }
    }
}
/*************************************/
int main()
{
    struct node *root = NULL;
    createTree(&root);
    preorder(root);
    printf("\n\n");
    inorder(root);
    printf("\n\n");
    postorder(root);
    printf("\n\n");
    int c = countnode(root);
    printf("The Count is %d\n", c);
    int c0 = countn0(root);
    printf("The No child count is %d\n", c0);
    int c1 = countn1(root);
    printf("The One child count is %d\n", c1);
    int c2 = countn2(root);
    printf("The two child count is %d\n", c2);
    int h = height(root);
    printf("The height is %d\n", h);
}
