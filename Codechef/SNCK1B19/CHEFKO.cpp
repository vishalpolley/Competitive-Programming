

#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, k;
         cin >> n >> k;
        pair<int, int> p[n];
        for(int i = 0; i < n; ++i)
            cin >> p[i].first >> p[i].second;
        sort(p, p+n);
        int ans = 0;
        multiset<int> s;
        for(int i = 0; i < n; ++i) {
            s.insert(p[i].second);
            if(s.size() > k)
                s.erase(s.begin());
            if(s.size() == k)
                ans = max(ans, *s.begin() - p[i].first);
        }
        cout << ans << "\n";
    }
    return 0;
}

