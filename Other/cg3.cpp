#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while(q--)
    {
        int val = INT_MIN, y;
        int x, l, r; cin >> x >> l >> r;
        int l_b = pow(2, (int)log2(r));
        int u_b = r;
        if(l_b < l)
            l_b = l;
        for(int i = l_b; i <= u_b; ++i)
        {
            if((x ^ i) > val)
                val = x ^ i;
        }
        cout << val << endl;
    }
    return 0;
}
