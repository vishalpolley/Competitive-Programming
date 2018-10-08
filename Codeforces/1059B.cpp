#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    bool flag = true;
    int n, m; cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> c;
            if(c == '#')
                arr[i][j] = 1;
            else if(c == '.')
                arr[i][j] = 0;
        }
    }
    for(int i = 1; i < n-1; ++i)
    {
        for(int j = 1; j < m-1; ++j)
        {
            if((arr[i-1][j-1] == 1 || arr[i-1][j-1] == 2) && (arr[i-1][j] == 1 || arr[i-1][j] == 2) && (arr[i-1][j+1] == 1 || arr[i-1][j+1] == 2)
               && (arr[i][j-1] == 1 || arr[i][j-1] == 2) && (arr[i][j+1] == 1 || arr[i][j+1] == 2)
               && (arr[i+1][j-1] == 1 || arr[i+1][j-1] == 2) && (arr[i+1][j] == 1 || arr[i+1][j] == 2) && (arr[i+1][j+1] == 1 || arr[i+1][j+1] == 2))
           {
                arr[i-1][j-1] = 2; arr[i-1][j] = 2; arr[i-1][j+1] = 2;
                arr[i][j-1] = 2; arr[i][j+1] = 2;
                arr[i+1][j-1] = 2; arr[i+1][j] = 2; arr[i+1][j+1] = 2;
           }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(arr[i][j] == 1)
            {
                flag = false;
                cout << "NO" << endl;
                break;
            }
        }
        if(!flag)
            break;
    }
    if(flag)
        cout << "YES" << endl;
    return 0;
}
