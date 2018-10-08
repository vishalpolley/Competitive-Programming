#include <bits/stdc++.h>
using namespace std;
#define M 200

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        bitset <M> bs(s);
        cout << ((bs.to_ullong() % 3 == 0) ? 1 : 0) << endl;
    }
    return 0;
}
