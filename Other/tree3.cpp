/* Invert the Binary Tree */
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
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
};

void mirror(struct Node *node)
{
    if(node == NULL)
        return;
    else
    {
        struct Node *temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void mirror2(struct Node *node)
{
    if(node == NULL)
        return;
    queue <struct Node *> q;
    q.push(node);
    while(!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();
        swap(temp->left, temp->right);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void inorder(struct Node *node)
{
    if(node)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    inorder(root);
    cout << "\n";
    mirror(root);
    inorder(root);
    return 0;
}
