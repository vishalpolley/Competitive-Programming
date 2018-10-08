#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, n, out;
    long int a, b;
    cin >> q;
    for(int i=0; i<q; ++i)
    {
        long int unach_profit = 0;
        cin >> n;
        for(int j=0; j<n; ++j)
        {
            cin >> a >> b;
            if(a >= b + unach_profit)
            {
                out = 0;
                unach_profit = 0;
            }
            else
            {
                out = 1;
                unach_profit += b - a;
            }
        }
        cout << out << endl;
    }
    return 0;
}
