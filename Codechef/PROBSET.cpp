#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m;
    string x, y;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> n >> m;
        for(int i=0; i<n; ++i)
        {
            bool flag = false;
            cin >> x >> y;
            for(int j=0; j<m; ++j)
            {
                if(y[j] == '0')
                {
                    flag = true;
                    break;
                }
            }
            if(x == "correct")
            {
                if(!flag)
                {
                    if(s != "INVALID" && s != "WEAK")
                        s = "FINE";
                }
                else
                    s = "INVALID";
            }
            if(x == "wrong")
            {
                if(!flag)
                {
                    if(s != "INVALID")
                        s = "WEAK";
                }
                else
                {
                    if(s != "INVALID" && s != "WEAK")
                        s = "FINE";
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
