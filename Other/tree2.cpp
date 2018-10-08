#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void insert(struct node *root, int data)
{
    queue<struct node *> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left = newNode(data);
            break;
        }
        else
            q.push(temp->left);
        if(!temp->right)
        {
            temp->right = newNode(data);
            break;
        }
        else
            q.push(temp->right);
    }
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct node *root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    int data = 12;
    insert(root, data);
    cout << endl;
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    return 0;
}
