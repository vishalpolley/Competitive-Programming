#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int a, b, k; cin >> a >> b >> k;
        int v = b/k;
        v -= a/k;
        if(a % k == 0)
            v++;
        printf("Case %d: %d\n", i, v);
    }
}
