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
int main()
{
    struct node *root = NULL;
    createTree(&root);
    preorder(root);
    printf("\n\n");
    inorder(root);
    printf("\n\n");
    postorder(root);
}
