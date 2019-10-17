#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string str)
{
    string ans;
    ans += str[0];
    int len = str.length(), j = 0;
    if(len < 2)
        return str;
    for(int i = 1; i < len; ++i)
    {
        if(ans[j] != str[i])
            j++, ans += str[i];
    }
    ans[++j] = '\0';
    return ans;
}

int main()
{
    //do not use comments unnecessarily
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int dee = 0, dum = 0;
        string s; cin >> s;
        for(int i = 0; i < n; ++i)
        {
            string nim; cin >> nim;
            nim = removeDuplicates(nim);
            for(int i = 0; i < nim.length(); ++i)
                ((nim[i] == '0') ? dee++ : dum++);
        }
        if(dee == dum)
            cout << s << endl;
        else
            cout << ((dee > dum) ? "Dum" : "Dee") << endl;
    }
    return 0;
}
