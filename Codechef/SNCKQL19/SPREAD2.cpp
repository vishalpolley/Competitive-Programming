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
        uint64_t c, ans = 1;
        int n; cin >> n;
        int *a = new int[n];
        uint64_t *b = new uint64_t[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        b[0] = a[0];
        for(int i = 1; i < n; ++i)
            b[i] = b[i-1] + a[i];
        c = b[0];
        while(n-1 > c)
            c += b[c], ans++;
        delete a;
        delete b;
        cout << ans << endl;
    }
    return 0;
}
