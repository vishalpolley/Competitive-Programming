#include <bits/stdc++.h>
using namespace std;

int palindromicSubstring(string str)
{

}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        cout << palindromicSubstring(str) << endl;
    }
    return 0;
}
