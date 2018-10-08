#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double hh, mm, h, hr, d, t, c, n;
    cin >> hh >> mm;
    cin >> h >> d >> c >> n;
    double buns1, buns2, cost1, cost2=INT_MAX;
    buns1 = ceil(h/n);
    cost1 = c*buns1;
    if(hh<20)
    {
        hh = abs(20-hh);
        if(mm!=00)
            t = hh*60 + abs(60-mm);
        else
            t = hh*60;
        buns2 = ceil((h+d*t)/n);
        cost2 = 0.8*c*buns2;
    }
    cout << fixed << setprecision(4) << (cost1<cost2 ? cost1 : cost2);
    return 0;
}
