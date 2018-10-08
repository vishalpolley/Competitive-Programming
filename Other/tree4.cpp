/* Root to leaf path sum equal to a given number */
#include <bits/stdc++.h>
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

bool hasPathSum(struct Node *node, int sum, vector <int> &result)
{
    if(node == NULL)
        return false;
    if(node->left == NULL && node->right == NULL)
    {
        if(sum == node->data)
        {
            result.push_back(node->data);
            return true;
        }
        return false;
    }
    sum = sum - node->data;
    if (hasPathSum(node->left, sum, result) || hasPathSum(node->right, sum, result))
    {
        result.push_back(node->data);
        return true;
    }
    return false;
}

void inOrder(struct Node *node)
{
    if(node)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

int main()
{
    int sum = 21;
    vector <int> result;
    struct Node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    cout << hasPathSum(root, sum, result) << "\n";
    for(vector <int>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it)
        cout << *it << " ";
    return 0;
}
