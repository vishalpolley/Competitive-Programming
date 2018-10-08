#include <bits/stdc++.h>
using namespace std;
typedef uint64_t int64;

int binarySearch(vector<int64> &L, vector<int64> &R, int l, int r, int64 p)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        if(p >= L[mid] && p < R[mid])
            return 0;
        else if(p >= R[mid] && p < L[mid + 1])
            return L[mid + 1] - p;
        if(p < L[mid])
            return binarySearch(L, R, l, mid - 1, p);
        return binarySearch(L, R, mid + 1, r, p);
    }
    return -1;
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<int64> L, R;
        for(int i = 0; i < n; ++i)
        {
            int64 l, r; cin >> l >> r;
            L.push_back(l);
            R.push_back(r);
        }
        sort(L.begin(), L.end());
        sort(R.begin(), R.end());
        while(m--)
        {
            int64 p; cin >> p;
            if(p < L[0])
                cout << L[0] - p;
            else if(p >= R[n-1])
                cout << -1;
            else
                cout << binarySearch(L, R, 0, n - 1, p);
            cout << "\n";
        }
    }
    return 0;
}
