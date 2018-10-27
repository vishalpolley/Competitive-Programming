#include <bits/stdc++.h>
using namespace std;

int countPaths(int m, int n)
{
    if(m == 1 || n == 1)
        return 1;
    return countPaths(m-1, n) + countPaths(m, n-1);
}

int countPathsDP(int m, int n)
{
    int arr[m][n];
    for(int i = 0; i < m; ++i)
        arr[i][0] = 1;
    for(int i = 0; i < n; ++i)
        arr[0][i] = 1;
    for(int i = 1; i < m; ++i)
        for(int j = 1; j < n; ++j)
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
    return arr[m-1][n-1];
}

int countPathsDP2(int m, int n)
{
    int *arr = new int[n];
    arr[0] = 1;
    for(int i = 0; i < m; ++i)
        for(int j = 1; j < n; ++j)
            arr[j] += arr[j-1], cout << arr[j] << endl;
    return arr[n-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int m, n; cin >> m >> n;
        cout << countPathsDP(m, n) << endl;
    }
    return 0;
}
