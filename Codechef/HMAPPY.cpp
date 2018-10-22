#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[n];
    uint64_t m; cin >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < n; ++i) c[i] = a[i] * b[i];
    sort(c, c+n, greater<int>());
    cout << *max_element(c, c+n);
    delete a;
    delete b;
    return 0;
}
