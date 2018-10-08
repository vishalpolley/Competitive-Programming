#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
    int top;
public:
    int arr[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if(top >= (MAX - 1))
        return false;
    else
    {
        arr[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if(top < 0)
        return 0;
    else
    {
        int x = arr[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop();
    return 0;
}
