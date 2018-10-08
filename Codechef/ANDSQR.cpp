#include<bits/stdc++.h>
using namespace std;

int squareCheck(int n)
{
    double sqroot = sqrt(n);
    if((sqroot - floor(sqroot)) == 0)
        return 1;
    return 0;
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        uint64_t a, ans;
        int n, q, l, r, cnt; cin >> n >> q;
        int *arr = new int[n];
        for(int i = 0; i < n; ++i)
            cin >> a, arr[i] = squareCheck(a);
        for(int j = 0; j < q; ++j)
        {
            cnt = 0;
            cin >> l >> r;
            ans = ((r - l + 1) * (r - l + 2)) / 2;
            for(int i = l-1; i < r; ++i)
            {
                if(arr[i] == 0)
                    cnt++;
                else
                    ans -= (cnt * (cnt + 1)) / 2, cnt = 0;
            }
            ans -= (cnt * (cnt + 1)) / 2;
            cout << ans << endl;
        }
        delete [] arr;
        arr = NULL;
    }
    return 0;
}
