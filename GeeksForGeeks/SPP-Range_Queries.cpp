#include <bits/stdc++.h>
using namespace std;

void rangeQueries(int64_t l, int64_t r)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int q; cin >> q;
        while(q--)
        {
            int64_t l, r; cin >> l >> r;
            rangeQueries(l, r);
            cout << "\n";
        }
    }
    return 0;
}
