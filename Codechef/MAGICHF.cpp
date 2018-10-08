#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, x, s; cin >> n >> x >> s;
        while(s--)
        {
            int a, b; cin >> a >> b;
            if(x == a) x = b;
            else if(x == b) x = a;
        }
        cout << x << endl;
    }
    return 0;
}
