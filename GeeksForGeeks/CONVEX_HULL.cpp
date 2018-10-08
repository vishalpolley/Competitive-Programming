#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

int distance(Point a, Point b, Point c)
{
    int x1 = a.x - b.x;
    int y1 = a.y - b.y;
    int x2 = a.x - c.x;
    int y2 = a.y - c.y;
    int val1 = ((x1 * x1) + (y1 * y1));
    int val2 = ((x2 * x2) + (y2 * y2));
    return (val1 > val2) ? 1 : (val1 < val2) ? -1 : 0;
}

int crossProduct(Point a, Point b, Point c)
{
    int x1 = a.x - b.x;
    int y1 = a.y - b.y;
    int x2 = a.x - c.x;
    int y2 = a.y - c.y;
    int val = (x1 * y2) - (x2 * y1);
    return (val > 0) ? 1 : (val < 0) ? -1 : 0;
}

void findConvexHull(Point pts[], int n)
{
    Point start = pts[0];
    for(int i = 1; i < n; ++i)
    {
        if(pts[i].x < start.x)
            start = pts[i];
    }
    Point current = start;
    set <pair <int, int> > result;
    list <Point> collinearPoint;
    result.insert(make_pair(start.x, start.y));
    if(n == 3)
    {
        if(!crossProduct(pts[0], pts[1], pts[2]))
        {
            cout << -1 << endl;
            return;
        }
    }
    while(true)
    {
        Point nextTarget = pts[0];
        for(int i = 1; i < n; ++i)
        {
            if(pts[i].x == current.x && pts[i].y == current.y)
                continue;
            int val = crossProduct(current, nextTarget, pts[i]);
            if(val > 0)
            {
                nextTarget = pts[i];
                collinearPoint.clear();
            }
            else if(val == 0)
            {
                if(distance(current, nextTarget, pts[i]) < 0)
                {
                    collinearPoint.push_back(nextTarget);
                    nextTarget = pts[i];
                }
                else
                    collinearPoint.push_back(pts[i]);
            }
        }
        for(auto const &val : collinearPoint)
            result.insert(make_pair(val.x, val.y));
        if(nextTarget.x == start.x && nextTarget.y == start.y)
            break;
        result.insert(make_pair(nextTarget.x, nextTarget.y));
        current = nextTarget;
    }
    if(result.size() > 2)
    {
        for(auto const &ptr : result)
        {
            if(ptr == *(result.rbegin()))
                cout << ptr.first << ' ' << ptr.second;
            else
                cout << ptr.first << ' ' << ptr.second << ", ";
        }
    }
    else
        cout << -1;
    cout << "\n";
}

int main()
{
    freopen("in.in", "r", stdin);
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
