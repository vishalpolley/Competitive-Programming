#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        bool flag = true;
        int n; cin >> n;
        int64_t *a = new int64_t[n];
        int64_t *b = new int64_t[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];
        int c = 0;
        if(n >= 3)
        {
            while(c+3 <= n)
            {
                if(a[c] < b[c])
                {
                    int mul = b[c] - a[c];
                    a[c] += mul;
                    a[c+1] += mul*2;
                    a[c+2] += mul*3;
                }
                if(a[c+1] > b[c+1] || a[c+2] > b[c+2])
                {
                    flag = false;
                    break;
                }
                c++;
            }
            if(a[c] != b[c] || a[c+1] != b[c+1])
                flag = false;
        }
        else
        {
            if(n == 2 && (b[1]-a[1]) != 2*(b[0]-a[0]))
                flag = false;
        }
        delete a;
        delete b;
        cout << ((flag) ? "TAK" : "NIE") << endl;
    }
    return 0;
}
