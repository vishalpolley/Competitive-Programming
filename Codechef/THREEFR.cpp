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
        int x, y, z; cin >> x >> y >> z;
        cout << ((x+y == z || y+z == x || z+x == y) ? "yes" : "no") << endl;
    }
    return 0;
}
