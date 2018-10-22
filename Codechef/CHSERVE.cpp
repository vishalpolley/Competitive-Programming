#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    while(n--)
    {
        uint64_t p1, p2, k; cin >> p1 >> p2 >> k;
        cout << ((((p1 + p2) / k) % 2) ? "COOK" : "CHEF") << endl;
    }
    return 0;
}
