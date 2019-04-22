#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, ans = 0; cin >> n;
        int x, y;
        multimap<int, int> m;
        for(int i=0; i<n; ++i) {
            cin >> x >> y;
            m.insert({x, y});
        }
        auto it = m.begin();
        int left=it->first, right=it->second;
        for(auto &i : m) {
            x = i.first;
            y = i.second;
            if(x > right) { // Disjoint Condition
                ans += abs(right-left+1);
                left = x;
                right = y;
            }
            else if(x >= left && x <= right && y > right)
                right = y;
        }
        ans += abs(right-left+1);
        cout << ans << "\n";
    }
    return 0;
}

