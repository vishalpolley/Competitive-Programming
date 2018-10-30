#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int diff = INT_MAX, exp;
        int n, m, k, l; cin >> n >> m >> k >> l;
        int *arr = new int[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] > k)
                break;
            exp = (m+i+1)*l - arr[i];
            if(exp < diff)
                diff = exp;
        }
        exp = (m+n+1)*l - k;
        if(exp < diff)
            diff = exp;
        if(k > (m+n)*l)
            diff = 0;
        cout << diff << endl;
        delete arr;
    }
    return 0;
}
