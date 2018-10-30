#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << ((n == 2010 || n == 2015 || n == 2016 || n == 2017 || n == 2019) ? "HOSTED" : "NOT HOSTED" ) << endl;
    }
    return 0;
}

