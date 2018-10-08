#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    int arr[n][n];
    memset(arr, -1, sizeof(arr[0][0]) * n * n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 | i==n-1 | j==0 | j==n-1)
                arr[i][j] = 1;

            if(i==(n-1)/2 | j==(n-1)/2)
                arr[i][j] += 1;

            if(i==j)
                arr[i][j] += 1;

            if(i+j==n-1)
                arr[i][j] += 1;
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cout << arr[i][j] << ' ';
    return 0;
}
