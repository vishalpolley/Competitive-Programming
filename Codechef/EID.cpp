#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, d;
    cin >> t;
    while(t--)
    {
        cin >> n;
        d = INT_MAX;
        long int *arr = new long int[n];
        for(int i=0; i<n; ++i)
            cin >> arr[i];
        sort(arr, arr+n);
        for(int i=0; i<n-1; ++i)
        {
            arr[i] = abs(arr[i+1] - arr[i]);
            if(d>arr[i])
                d = arr[i];
        }
        cout << d << endl;
        delete [] arr;
        arr = NULL;
    }
    return 0;
}
