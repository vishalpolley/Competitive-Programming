#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, m, x, y, k, p; cin >> n >> m >> x >> y;
        bool flag = false;
        if(n == 2 && m == 2)
            cout << "Chefirnemo";
        else
        {
            if(n > 1 && m > 1)
            {
                k = x * ((n - 2) / x); p = y * ((m - 2) / y);
                if((k + 2) == n && (p + 2) == m) cout << "Chefirnemo", flag = true;
            }
            k = x * ((n - 1) / x); p = y * ((m - 1) / y);
            if((k + 1) == n && (p + 1) == m) cout << "Chefirnemo", flag = true;
            if(!flag) cout << "Pofik";
        }
        cout << "\n";
    }
    return 0;
}
