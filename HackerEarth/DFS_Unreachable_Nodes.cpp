/*
Unreachable Nodes
You have been given a graph consisting of N nodes and M edges. The nodes in this graph are enumerated from 1 to N .
The graph can consist of self-loops as well as multiple edges. This graph consists of a special node called the head node.
You need to consider this and the entry point of this graph. You need to find and print the number of nodes that are unreachable from this head node.

Input Format

The first line consists of a 2 integers N and M denoting the number of nodes and edges in this graph.
The next M lines consist of 2 integers a and b denoting an undirected edge between node a and b.
The next line consists of a single integer x denoting the index of the head node.

*Output Format *:

You need to print a single integer denoting the number of nodes that are unreachable from the given head node.

10 10
8 1
8 3
7 4
7 5
2 6
10 7
2 8
10 9
2 10
5 10
2
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], bool visited[], int s) {
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
        if(!visited[adj[s][i]]) dfs(adj, visited, adj[s][i]);
}

int main() {
//    freopen("../in.in", "r", stdin);
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
    int x; cin >> x;
    dfs(adj, visited, x);
    for(int i = 1; i <= nodes; ++i)
        if(!visited[i]) cnt++;
    cout << cnt << endl;
    return 0;
}

