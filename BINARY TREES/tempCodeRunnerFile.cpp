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