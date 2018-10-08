/*
Reverse words in a given string

Given a String of length N reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. Each case contains a string
containing spaces and characters.


Output:
For each test case, output a single line containing the reversed String.

Constraints:
1<=T<=20
1<=Lenght of String<=2000


Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/

#include <bits/stdc++.h>
using namespace std;

void reverseWords(string str)
{
    string t;
    stack<string> s;
    for(auto c : str)
    {
        if(c != '.')
            t += c;
        else
        {
            s.push(t);
            s.push(".");
            t = "";
        }
    }
    if(!t.empty())
        s.push(t);
    while(!s.empty())
        cout << s.top(), s.pop();
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        reverseWords(str);
        cout << "\n";
    }
}
