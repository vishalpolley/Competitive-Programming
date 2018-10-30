#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int cnt = 0;
        int n, val; cin >> n;
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
        {
            cin >> val;
            if(m.find(val) == m.end())
                m.insert(make_pair(val, 1));
            else
                m[val]++;
        }
        for(auto& p : m)
        {
            int key = p.first;
            int value = p.second;
            for(int i = value; i >= 1; --i)
            {
                if(m.find(i) == m.end())
                    continue;
                if(m[i] >= key)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

