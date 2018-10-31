/*
5 3
1 2 3 4 5
1 2 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll balloons_required(vector<ll>& a, vector<ll>& b, ll candies) {
    ll c = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(b[i] == 0) continue;
        c += max(a[i]-candies/b[i], 0LL);
    }
    return c;
}

int main() {
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll m, l = 0LL, r = 0LL; cin >> m;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < n; ++i) r = max(r, a[i]*b[i]);
    while(l < r) {
        ll mid = (l+r)/2;
        ll balloons = balloons_required(a, b, mid);
        if(balloons <= m) r = mid;
        else l = mid+1;
    }
    cout << l << "\n";
    return 0;
}

