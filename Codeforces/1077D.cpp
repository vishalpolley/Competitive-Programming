#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, val; cin >> n >> k;
    unordered_map<int, int> m, m1;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; ++i) {
        cin >> val;
        auto it = m.find(val);
        (it != m.end() ? it->second++ : m[val]=1);
    }
    for(auto& i : m)
        pq.push({i.second, i.first});
    pair<int, int> p;
    for(int i = 0; i < k; ++i) {
        cout << pq.top().second << " ";
        p = pq.top();
        pq.pop();
        m1[p.second]++;
        p.first = m[p.second]/(m1[p.second]+1);
        pq.push({p.first, p.second});
    }
    return 0;
}
