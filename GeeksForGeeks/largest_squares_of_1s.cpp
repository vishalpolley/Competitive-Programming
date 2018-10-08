#include <bits/stdc++.h>
using namespace std;

int largestSquare(vector<vector<int>> &c, int n, int m)
{
    int s[n+1][m+1], result = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(i == 0 || j == 0)
                s[i][j] = c[i][j];
            else if(c[i][j] > 0)
                s[i][j] = 1 + min(s[i][j-1], min(s[i-1][j], s[i-1][j-1]));
            else
                s[i][j] = 0;
            if(s[i][j] > result)
                result = s[i][j];
        }
    }
    return result;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, m, val; cin >> n >> m;
        vector<vector<int>> c;
        for(int i = 0; i < n; ++i)
        {
            vector<int> row;
            for(int j = 0; j < m; ++j)
                cin >> val, row.push_back(val);
            c.push_back(row);
        }
        cout << largestSquare(c, n, m) << endl;
    }
    return 0;
}
