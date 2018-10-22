#include <bits/stdc++.h>
using namespace std;

int reservoir_cnt(int h[], int l, int r)
{
    if(l == r) return 1;
    int m = distance(h, max_element(h+l, h+r+1));
    if(m == l || m == r) return 1;
    return min(reservoir_cnt(h, l, m-1), reservoir_cnt(h, m+1, r)) + 1;
}

int main()
{
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int *h = new int[n];
        for(int i = 0; i < n; ++i)
            cin >> h[i];
        cout << reservoir_cnt(h, 0, n-1) << endl;
        delete h;
    }
    return 0;
}
