#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
/************************************************************************/
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int level;
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
/************************************************************************/
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
int levelorder(struct node *t)
{
    queue<struct node *> Q;
    Q.push(t);
    int h = height(t);
    vector<int> HT[h + 1];
    HT[0].push_back(t->data);
    while (Q.size() != 0)
    {
        struct node *x;
        x = Q.front();
        Q.pop();
        if (x->left != NULL)
        {
            Q.push(x->left);
            x->left->level = x->level + 1;
            int i = x->left->level;
            HT[i].push_back(x->left->data);
        }
        if (x->right != NULL)
        {
            Q.push(x->right);
            x->right->level = x->level + 1;
            int i = x->right->level;
            HT[i].push_back(x->right->data);
        }
    }
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j < HT[i].size(); j++)
        {
            cout << HT[i][j] << " ";
        }
    }
    cout << "zigzag" << endl;
    for (int i = 0; i <= h; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < HT[i].size(); j++)
            {
                cout << HT[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = HT[i].size() - 1; j >= 0; j--)
            {
                cout << HT[i][j] << " ";
            }
            cout << endl;
        }
    }
}

/************************************************************************/
int main()
{
    struct node *root = NULL;
    createTree(&root);
    levelorder(root);
}