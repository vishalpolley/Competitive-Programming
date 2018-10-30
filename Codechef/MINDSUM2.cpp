/*
3
2 1
9 3
11 13
Digital Root Method - https://en.wikipedia.org/wiki/Digital_root
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline pair<int, int> digital_root(ll n) {
    pair<int, int> val;
    val.first = n-9*floor((n-1)/9);
    val.second = 0;
    string num = to_string(n);
    while(num.length() > 1) {
        int temp = 0;
        for(int i = 0; i < num.length(); ++i)
            temp += n%10, n = n/10;
        n = temp; num = to_string(n);
        val.second++;
    }
    return val;
}

int main()
{
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        ll n, d; cin >> n >> d;
        int ans = n, steps = 0;
        pair<int, int> ds;
        for(int i = 0; i < 10; ++i) {
            ds = digital_root(n+d*i);
            if(ds.first < ans)
                ans = ds.first, steps = i+ds.second;
        }
        cout << ans << " " << steps << endl;
    }
    return 0;
}

