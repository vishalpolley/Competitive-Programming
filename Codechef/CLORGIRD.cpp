#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        char obs;
        bool flag = true;
        int n, m; cin >> n >> m;
        int grid[n][m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> obs, grid[i][j] = (obs == '.') ? 0 : 2;
        for(int i = 0; i < n-1; ++i)
        {
            for(int j = 0; j < m-1; ++j)
            {
                if(grid[i][j] == 2 || grid[i+1][j] == 2 || grid[i][j+1] == 2 || grid[i+1][j+1] == 2)
                    continue;
                else
                    grid[i][j] = 1, grid[i+1][j] = 1, grid[i][j+1] = 1, grid[i+1][j+1] = 1;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        cout << ((flag) ? "YES" : "NO") << endl;
    }
    return 0;
}

