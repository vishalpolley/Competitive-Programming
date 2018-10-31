/*
5 3
1 2 3 4 5
1 2 3 4 5
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    ll m; cin >> m;
    priority_queue< pair< ll, int>> q;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        q.push(make_pair(a[i]*b[i], b[i]));
    }
    for(ll i = 0; i < m; ++i) {
        ll k = q.top().first;
        ll v = q.top().second;
        q.pop();
        q.push(make_pair(k-v, v));
    }
    cout << q.top().first;
    return 0;
}
