#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--)
    {
        int n, k, c; cin >> n >> k;
        uint64_t *arr = new uint64_t[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n, greater<uint64_t>());
        c = k-1;
        while(arr[c] == arr[k-1] && c < n)
            c++;
        cout << c << endl;
        delete arr;
    }
    return 0;
}
