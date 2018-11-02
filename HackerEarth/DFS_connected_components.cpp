/*
How to find connected components using DFS?

A graph is said to be disconnected if it is not connected, i.e. if two nodes exist in the graph such that there is no edge in between those nodes.
In an undirected graph, a connected component is a set of vertices in a graph that are linked to each other by paths.

Consider the example given in the diagram. Graph G is a disconnected graph and has the following 3 connected components.

First connected component is 1 -> 2 -> 3 as they are linked to each other
Second connected component 4 -> 5
Third connected component is vertex 6
In DFS, if we start from a start node it will mark all the nodes connected to the start node as visited.
Therefore, if we choose any node in a connected component and run DFS on that node it will mark the whole connected component as visited.

6
4
1 2
2 3
1 3
4 5
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], bool visited[], int s) {
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i) {
        if(!visited[adj[s][i]]) {
            dfs(adj, visited, adj[s][i]);
        }
    }
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes, edges, cnt = 0; cin >> nodes >> edges;
    vector<int> adj[nodes+1];
    bool visited[nodes+1] = {false};
    for(int i = 0; i < edges; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= nodes; ++i) {
        if(!visited[i])
            dfs(adj, visited, i), cnt++;
    }
    cout << cnt << endl;
    return 0;
}

