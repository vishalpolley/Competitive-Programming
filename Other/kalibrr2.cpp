#include<bits/stdc++.h>
using namespace std;

int n, m;
int stringSearch(vector<vector <char> > &vec, int r, int c, string s)
{
    if(vec[r][c] != s[0])
        return 0;
    int l = s.length(), val = 0;
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int d = 0; d < 8; ++d)
    {
        int k;
        int rd = r + x[d];
        int cd = c + y[d];
        for(k = 1; k < l; ++k)
        {
            if(rd >= n || rd < 0 || cd >= m || cd < 0)
                break;
            if(vec[rd][cd] != s[k])
                break;
            rd += x[d];
            cd += y[d];
        }
        if(k == l)
            val++;
    }
    if(val)
        return val;
    return 0;
}

int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        char ch;
        cin >> n >> m;
        vector<vector<char> > vec;
        for(int x = 0; x < n; ++x)
        {
            vector<char> row;
            for(int y = 0; y < m; ++y)
            {
                cin >> ch;
                row.push_back(ch);
            }
            vec.push_back(row);
        }
        string s; cin >> s;
        int val = 0;
        for(int r = 0; r < n; ++r)
        {
            for(int c = 0; c < m; ++c)
            {
                if(stringSearch(vec, r, c, s) > 0)
                {
                    val += stringSearch(vec, r, c, s);
                }
            }
        }
        printf("Case %d: %d\n", i, val);
    }
}

