#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
};

int main()
{
    freopen("in.in", " r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    point pt[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> pt[i].x >> pt[i].y;
        (pt[i].y >= 0) ? p++ : n++;
    }
    if(p > 0 && n > 0) {cout << -1 << endl; return 0;}
    return 0;
}
