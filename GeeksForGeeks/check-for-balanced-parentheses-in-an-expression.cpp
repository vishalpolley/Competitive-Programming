#include<bits/stdc++.h>
using namespace std;

bool balancedParantheses(string expr)
{
    char x;
    stack <char> stk;
    for(int i = 0; i <= expr.length(); ++i)
    {
        if(expr[i] == '{' || expr[i] == '[' || expr[i] == '(')
        {
            stk.push(expr[i]);
            continue;
        }
        if(expr.empty())
            return false;
        switch(expr[i])
        {
        case '}':
            x = stk.top();
            stk.pop();
            if(x == '[' || x == '(')
                return false;
            break;
        case ']':
            x = stk.top();
            stk.pop();
            if(x == '{' || x == '(')
                return false;
            break;
        case ')':
            x = stk.top();
            stk.pop();
            if(x == '[' || x == '{')
                return false;
            break;
        }
    }
    return stk.empty();
}

int main()
{
    string expr; cin >> expr;
    cout << ((balancedParantheses(expr)) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
