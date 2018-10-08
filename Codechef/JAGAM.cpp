#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, z1, z2; cin >> n >> z1 >> z2;
        vector<int> v(2 * n);
        for(int i=0; i<n; ++i)
            cin >> v[2 * i], v[2 * i + 1] = -v[2 * i];
    }
    return 0;
}
