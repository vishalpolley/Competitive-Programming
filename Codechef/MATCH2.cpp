#include <bits/stdc++.h>
using namespace std;
typedef uint64_t int64;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int p = 0;
        int n, q; cin >> n >> q;
        int64 *a = new int64[n];
        int64 *b = new int64[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];
        for(int i = 0; i < n; ++i)
            if(a[i] == b[i]) p++;
        while(q--)
        {
            int x, y; cin >> x >> y;
            int64 z; cin >> z;
            int l = x ^ p;
            int r = y ^ p;
            int64 c = z ^ p;
            for(int i = l - 1; i < r; ++i)
                a[i] = c;
            p = 0;
            for(int i = 0; i < n; ++i)
                if(a[i] == b[i]) p++;
            cout << p << endl;
        }
    }
    return 0;
}
