/*
Ternary Search

https://www.hackerearth.com/practice/algorithms/searching/ternary-search/tutorial/
*/

#include <bits/stdc++.h>
using namespace std;

bool ternarySearch(int arr[], int l, int r, int x)
{
    if(r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if(arr[mid1] == x)
            return 1;
        if(arr[mid2] == x)
            return 1;
        if(x < mid1)
            return ternarySearch(arr, l, mid1-1, x);
        else if(x > mid2)
            return ternarySearch(arr, mid2+1, r, x);
        else
            return ternarySearch(arr, mid1+1, mid2-1, x);
    }
    return 0;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int x; cin >> x;
    cout << (ternarySearch(arr, 0, n-1, x) ? "FOUND" : "NOT FOUND") << endl;
    delete arr;
    return 0;
}
