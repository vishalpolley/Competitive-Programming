#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int cnt = 0;
        int n, k, a; cin >> n >> k;
        while(n--)
        {
            cin >> a;
            if(a > 1)
                cnt++;
        }
        cout << ((k >= cnt) ? "YES" : "NO") << endl;
    }
    return 0;
}

