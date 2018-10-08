#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

map <int, int> vis;
vector <int> adj[101];
void dfs(int s, int length)
{
    vis[s] = length;
    for(int i=0; i<adj[s].size(); i++)
    {
        if(!vis[adj[s][i]])
        {
            dfs(adj[s][i], length+1);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, x, v;
    string s;

    while(1)
    {
        cin >> n;

        if (n == 0)
            break;

        getline(cin, s);

        while(getline(cin, s), s!="0")
        {
            for(int i=2; i<s.length()-2; i+=2)
            {
                adj[s[0]-'0'].push_back(s[i]-'0');
            }
        }

        cin >> x;
        for(int i=0; i<x; i++)
        {
            cin >> v;
            dfs(v, 1);
            cout << vis[1] << vis[2] << vis[3] << endl;
            cout << vis[adj[v].back()] << " ";
            for(int i=1; i<=n; i++)
            {
                if(!vis[i] || vis[i]<2)
                {
                    cout << i << " ";
                }
            }
            cout << "\n";
            vis.clear();
        }
        for(int i=0; i<101; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}
