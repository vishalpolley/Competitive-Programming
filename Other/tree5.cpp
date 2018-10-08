/* Print all leaf nodes of a Binary Tree from left to right */
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

void printLeafNodes(struct Node *node)
{
    if(node == NULL)
        return;
    if(node->left == NULL && node->right == NULL)
        cout << node->data << " ";
    if(node->left)
        printLeafNodes(node->left);
    if(node->right)
        printLeafNodes(node->right);
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);
    printLeafNodes(root);
    return 0;
}
