/*
Bishu and his Girlfriend

There are N countries {1,2,3,4....N} and N-1 roads(i.e depicting a tree)

Bishu lives in the Country 1 so this can be considered as the root of the tree.

Now there are Q girls who lives in various countries (not equal to 1) .

All of them want to propose Bishu.But Bishu has some condition.

He will accept the proposal of the girl who lives at minimum distance from his country.

Now the distance between two countries is the number of roads between them.

If two or more girls are at the same minimum distance then he will accept the proposal of the girl who lives in a country with minimum id.

No two girls are at same country.

Input: First line consists of N,i.e number of countries Next N-1 lines follow the type u v which denotes there is a road between u and v.
Next line consists of Q Next Q lines consists of x where the girls live.

Output: Print the id of the country of the girl who will be accepted.

Help Him!!!!!

contraints: 2<=N<=1000 1<=u,v<=N 1<=Q<=(N-1)

6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int length[], int s, int l) {
    length[s] = l;
    for(int i = 0; i < adj[s].size(); ++i)
        if(!length[adj[s][i]]) dfs(adj, length, adj[s][i], l+1);
}

int main() {
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len = INT_MAX, ans;
    int nodes, edges; cin >> nodes;
    edges = nodes-1;
    vector<int> adj[nodes+1];
    int length[nodes+1] = {0};
    for(int i = 0; i < edges; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, length, 1, 1);
    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        int x; cin >> x;
        if(length[x] == len && ans > x)
            ans = x;
        if(length[x] < len)
            len = length[x], ans = x;
    }
    cout << ans << endl;
    return 0;
}

