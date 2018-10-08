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

void swap(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

struct Node **first;
struct Node **second;

void pairWiseSwap(struct Node **node, int &cnt)
{
    if(*node == NULL)
        return;
    if((*node)->left == NULL && (*node)->right == NULL)
    {
        second = node;
        cnt++;
        if((cnt % 2) == 0)
            swap(first, second);
        else
            first = second;
    }
    if((*node)->left)
        pairWiseSwap(&(*node)->left, cnt);
    if((*node)->right)
        pairWiseSwap(&(*node)->right, cnt);
}

void printInOrder(struct Node *node)
{
    if(node)
    {
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }
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
    cout << "Inorder traversal before swap:\n";
    printInOrder(root);
    cout << "\n";
    int c = 0;
    pairWiseSwap(&root, c);
    cout << "Inorder traversal after swap:\n";
    printInOrder(root);
    cout << "\n";
    return 0;
}
