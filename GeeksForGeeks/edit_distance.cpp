#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

/*
int editDistance(string a, int m, string b, int n)
{
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    if(a[m-1] == b[n-1])
        return editDistance(a, m-1, b, n-1);
    return 1 + min(editDistance(a, m, b, n-1),      // Insert
                   editDistance(a, m-1, b, n),      // Remove
                   editDistance(a, m-1, b, n-1));   // Replace
}
*/

int editDistance(string a, int m, string b, int n)
{
    int dp[m+1][n+1];
    for(int i = 0; i <= m; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1],
                                   dp[i-1][j],
                                   dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int m, n; cin >> m >> n;
        string a, b; cin >> a >> b;
        cout << editDistance(a, m, b, n) << endl;
    }
    return 0;
}
