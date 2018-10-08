#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 6;

int ans[maxn];
int ptr = 0;

void solve(int n, int mul)
{
    if(n == 1) {ans[ptr] = mul; return;}
    if(n == 2) {ans[ptr] = mul; ans[++ptr] = mul * 2; return;}
    if(n == 3) {ans[ptr] = mul; ans[++ptr] = mul; ans[++ptr] = mul * 3; return;}
    for(int i = 0; i < n; ++i) {if((i+1) & 1) ans[ptr++] = mul;}
    solve(n/2, mul * 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    solve(n, 1);
    for(int i = 0; i < n; ++i) cout << ans[i] << " ";
    return 0;
}
