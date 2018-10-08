#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t, u, v, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> *adj;
        adj = new vector<int>[n];
        for(int i=0; i<n; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for(int i=1; i<n; i++)
        {
            cout << i << " --> ";
            for(int v : adj[i])
                cout << v << " ";
            cout << "\n";
        }
        delete[] adj;
    }
    return 0;
}
