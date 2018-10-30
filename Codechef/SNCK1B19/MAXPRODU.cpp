#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
//    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int64_t ans = 1;
        int64_t n, k; cin >> n >> k;
        int64_t sum_k = (k * (k + 1)) / 2;
        int64_t sum_k1 = ((k+1) * (k+2)) / 2;
        if(sum_k > n)
            cout << -1;
        else if(sum_k <= n && (sum_k1 - 1) > n)
            cout << 0;
        else
        {
            int64_t v = (n - (sum_k1-1)) / k;
            int64_t r = (n - (sum_k1-1)) % k;
            int64_t *prod = new int64_t[k];
            for(int i = 0; i < k; ++i)
                prod[i] = i+2+v;
            for(int i = 0; i < r; ++i)
                prod[k-1-i] += 1;
            for(int i = 0; i < k; ++i)
            {
                int64_t val1 = ((prod[i] % MOD) * (prod[i]-1) % MOD) % MOD;
                int64_t val2 = ((ans % MOD) * (val1 % MOD)) % MOD;
                ans = val2;
            }
            cout << ans % MOD;
            delete prod;
        }
        cout << "\n";
    }
    return 0;
}

