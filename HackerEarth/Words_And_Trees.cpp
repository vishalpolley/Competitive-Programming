/*
8 3
o v s l v p d i
1 3
8 3
4 8
6 1
5 3
7 6
2 3
7 ifwrxl
4 eyljywnm
3 llvse
*/

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

char letter[MAX];
bool visited[MAX];
vector<int> adj[MAX];
int subtree[MAX][26];

void dfs(int s) {
    visited[s] = true;
    for(auto& c : adj[s]) {
        if(visited[c]) continue;
        if(!visited[c])
            dfs(c);
        for(int i = 0; i < 26; ++i)
            subtree[s][i] += subtree[c][i];
    }
    subtree[s][letter[s]-'a']++;
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> letter[i];
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 0; i < q; ++i) {
        int ans = 0;
        int x; cin >> x;
        string s; cin >> s;
        vector<int> hash_arr(26);
        for(auto& c : s)
            hash_arr[c-'a']++;
        for(int i = 0; i < 26; ++i)
            ans += max(0, hash_arr[i]-subtree[x][i]);
        cout << ans << "\n";
    }
    return 0;
}
