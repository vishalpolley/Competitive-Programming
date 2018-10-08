#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        sort(s.begin(), s.end());
        do
            cout << s << " ";
        while(next_permutation(s.begin(), s.end()));
        cout << "\n";
    }
    return 0;
}
