/*
3
2 1
9 3
11 13
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll digit_sum(ll n) {
    ll sum = 0LL;
    while(n) sum += n%10, n = n/10;
    return sum;
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        ll n, d; cin >> n >> d;
        queue< pair<ll, ll>> q;
        q.push({n, 0});
        map<ll, ll> m;
        int i = 0;
        while(i < 100000 && !q.empty()) {
            auto t = q.front(); q.pop();
            if(m.find(1) != m.end()) break;
            if(t.first < 10) {
                if(m.find(t.first) != m.end()) continue;
                else m[t.first] = t.second;
            } else {
                q.push({digit_sum(t.first), t.second+1});
            }
            q.push({t.first+d, t.second+1});
            i++;
        }
        cout << m.begin()->first << " " << m.begin()->second << "\n";
    }
    return 0;
}
