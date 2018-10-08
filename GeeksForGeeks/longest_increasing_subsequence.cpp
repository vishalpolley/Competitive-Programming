#include <bits/stdc++.h>
using namespace std;

int longestIncreasing(int arr[], int n)
{
    int result = 0;
    int *l = new int[n];
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(arr[i] > arr[j])
                l[i] = max(l[i], l[j] + 1);
        }
        if(l[i] > result)
            result = l[i];
    }
    return result + 1;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int *arr = new int[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << longestIncreasing(arr, n) << endl;
    }
    return 0;
}
