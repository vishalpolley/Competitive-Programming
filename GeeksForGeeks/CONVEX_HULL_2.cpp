#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);
    return (val > 0) ? 1 : (val < 0) ? 2 : 0;
}

void findConvexHull(Point pts[], int n)
{
    set <pair <int, int> > result;
    int l = 0;
    for(int i = 0; i < n; ++i)
        if(pts[i].x < pts[l].x)
            l = i;
    int p = l, q;
    do
    {
        result.insert(make_pair(pts[p].x, pts[p].y));
        q = (p + 1) % n;
        for(int i = 0; i < n; ++i)
            if(orientation(pts[p], pts[i], pts[q]) == 2)
                q = i;
        p = q;
    } while(l != q);
    if(result.size() > 2)
        for(auto const &pts : result)
        {
            if(pts != *(result.rbegin()))
                cout << pts.first << ' ' << pts.second << ", ";
            else
                cout << pts.first << ' ' << pts.second;
        }
    else
        cout << -1;
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        Point *pts = new Point[n];
        for(int i = 0; i < n; ++i)
            cin >> pts[i].x >> pts[i].y;
        if(n < 3)
            cout << -1 << endl;
        else
            findConvexHull(pts, n);
        delete [] pts;
        pts = NULL;
    }
    return 0;
}

