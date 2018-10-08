#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x;
    double y;
    double r;
};

inline double euclideanDistance(point p1, point p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    double d = sqrt(x*x + y*y);
    return d;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    point pt[n];
    double d[n][n];
    for(int i = 0; i < n; ++i)
        cin >> pt[i].x >> pt[i].y >> pt[i].r;
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j)
            d[i][j] = euclideanDistance(pt[i], pt[j]);
    while(q--)
    {
        int cnt = 0;
        double k; cin >> k;
        double m1, m2;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                double dst = d[i][j];
                double r1 = pt[i].r;
                double r2 = pt[j].r;
                if(r1 > r2)
                    swap(r1, r2);
                m1 = dst - (r1 + r2);
                m2 = dst + (r1 + r2);
                if(dst == 0) // Concentric Circles
                {
                    m1 = r2 - r1;
                    m2 = 2*r1 + m1;
                    if(k >= m1 && k <= m2)
                        cnt++;
                }
                if(dst > r1+r2 && k >= m1 && k <= m2) // Outer Cirlces
                    cnt++;
                if(r2 > dst + r1) // Containing Cirlces
                {
                    m1 = r2 - (dst + r1);
                    m2 = 2*r2 - m1;
                    if(k >= m1 && k <= m2)
                        cnt++;
                }
                if(dst >= r2-r1 && dst <= r1+r2 && k >= 0 && k <= m2) // Intersecting Circles
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
