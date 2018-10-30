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
        int diff = INT_MAX, exp;
        int n, m, m1, k, l; cin >> n >> m1 >> k >> l;
        map<int, bool> time; m = m1;
        for(int i = 0; i < n; ++i)
        {
            int a; cin >> a;
            time.insert(make_pair(a, true));
        }
        int prev = 0;
        for(auto& i : time)
        {
            int t = i.first;
            if(t > k || m < 0)
                break;
            m -= (t/l-prev/l); m++;
            exp = (m-1)*l + (l-t%l);
            if(exp < diff)
                diff = exp;
            prev = t;
        }
        exp = (m1+n+1)*l - k;
        if(exp < diff)
            diff = exp;
        if(k > (m1+n)*l)
            diff = 0;
        cout << diff << endl;
    }
    return 0;
}

