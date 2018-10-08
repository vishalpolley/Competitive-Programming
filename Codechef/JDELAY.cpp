#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    int t; cin >> t;
    while(t--)
    {
        int n, cnt = 0; cin >> n;
        while(n--)
        {
            int a, b; cin >> a >> b;
            if(b-a > 5) cnt++;
        }
        cout << cnt << endl;
    }
}
