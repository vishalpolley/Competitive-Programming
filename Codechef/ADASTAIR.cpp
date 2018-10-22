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
        int n, k, cnt = 0; cin >> n >> k;
        int h1, h2; h1 = 0;
        while(n--)
        {
            cin >> h2;
            if((h2-h1) > k)
                cnt += floor((h2-h1-1)/k);
            h1 = h2;
        }
        cout << cnt << endl;
    }
    return 0;
}
