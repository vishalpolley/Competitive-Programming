#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
};

void leftViewFun(struct Node *node, int level, int *max_level)
{
    if(node == NULL)
        return;
    if(*max_level < level)
    {
        cout << node->data << " ";
        *max_level = level;
    }
    leftViewFun(node->left, level+1, max_level);
    leftViewFun(node->right, level+1, max_level);
}

int main()
{
    int max_level = 0;
    struct Node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    leftViewFun(root,  1, &max_level);
    return 0;
}
