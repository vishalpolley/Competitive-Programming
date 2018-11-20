/*
5
2 3 32 43 8
1 2
1 3
2 4
3 5
*/

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int number[MAX];
int treeOr[MAX];
bool visited[MAX];
vector<int> adj[MAX];

void dfs(int s) {
    visited[s] = true;
    for(auto& c : adj[s]) {
        if(visited[c]) continue;
        dfs(c);
        treeOr[s] |= number[c];
    }
    treeOr[s] |= number[s];
}

int main() {
    int ans = 0;
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes; cin >> nodes;
    for(int i = 0; i < nodes; ++i)
        cin >> number[i];
    vector<pair<int, int>> edges;
    for(int i = 1; i < nodes; ++i) {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto& p : edges) {

    }
    cout << ans << "\n";
    return 0;
}
