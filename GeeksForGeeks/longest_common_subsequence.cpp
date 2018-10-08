#include <bits/stdc++.h>
using namespace std;

/*
int longestCommonSubs(string x, int i, int m, string y, int j, int n)
{
    if(i == m || j == n)
        return 0;
    if(x[i] == y[j])
        return 1 + longestCommonSubs(x, i+1, m, y, j+1, n);
    else
        return max(longestCommonSubs(x, i+1, m, y, j, n), longestCommonSubs(x, i, m, y, j+1, n));
}
*/

int longestCommonSubs(string x, int m, string y, int n)
{
    int LCS[m+1][n+1];
    // Initilaizing LCS array
    for(int i = 0; i <= m; ++i)
        LCS[i][0] = 0;
    for(int i = 1; i <= n; ++i)
        LCS[0][i] = 0;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(x[i-1] == y[j-1])
                LCS[i][j] = 1 + LCS[i-1][j-1];
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    return LCS[m][n];
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int m, n; cin >> m >> n;
        string x, y; cin >> x >> y;
        cout << longestCommonSubs(x, m, y, n) << endl;
    }
    return 0;
}
