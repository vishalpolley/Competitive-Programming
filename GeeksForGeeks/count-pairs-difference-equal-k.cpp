#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int k; cin >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    int l = 0, r = 0, d, cnt = 0;
    while(r < n)
    {
        d = arr[r] - arr[l];
        if(k == d)
            cnt++, l++, r++;
        else if(k > d)
            r++;
        else
            l++;
    }
    cout << cnt << endl;
    return 0;
}
