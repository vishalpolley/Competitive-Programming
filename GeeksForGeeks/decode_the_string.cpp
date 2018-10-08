#include <bits/stdc++.h>
using namespace std;

string decodeString(int &pos, string s)
{
    int num = 0;
    string word = "";
    for(; pos < s.size(); pos++)
    {
        char curr = s[pos];
        if(curr == '[')
        {
            string currStr = decodeString(++pos, s);
            for(; num > 0; num--) word += currStr;
        }
        else if(curr >= '0' && curr <= '9')
            num = num * 10 + (curr - '0');
        else if(curr == ']')
            return word;
        else
            word += curr;
    }
    return word;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int pos = 0;
        string s; cin >> s;
        cout << decodeString(pos, s) << endl;
    }
    return 0;
}
