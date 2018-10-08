#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    uint64_t L, a; cin >> L >> a;
    if(!a)
    {
        cout << 0 << endl;
        return 0;
    }
    int b = 0, p = 0;
    while(n--)
    {
        int t, l; cin >> t >> l;
        b += (t-p) / a;
        p = t+l;
    }
    if(p < L)
        b += (L-p) / a;
    cout << b << endl;
    return 0;
}
