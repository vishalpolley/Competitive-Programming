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
        int n, m, k, l, ans; cin >> n >> m >> k >> l;
        vector<int> a(n+1);
        for(int i = 0; i < n; ++i) cin >> a[i];
        a[n] = k;
        sort(a.begin(), a.end());
        ans = (m+1)*l-1;
        for(int i = 0; i <= n; ++i)
            ans = min((m+i+1)*l - a[i], ans);
        cout << ans << "\n";
    }
    return 0;
}
