/*
3 3 2
2 4 3
1 3
1 2
2 3
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first)
        return a.second > b.second;
    else
        return a.first > b.first;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes, edges, k; cin >> nodes >> edges >> k;
    vector<int> adj[nodes+1];
    int val[nodes+1];
    for(int i = 1; i <= nodes; ++i)
        cin >> val[i];
    for(int i = 0; i < edges; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= nodes; ++i) {
        vector<pair<int, int>> p;
        for(auto& a : adj[i])
            p.push_back({val[a], a});
        sort(p.begin(), p.end(), comp);
        cout << ((p.size() >= k) ? p[k-1].second : -1) << "\n";
    }
    return 0;
}

