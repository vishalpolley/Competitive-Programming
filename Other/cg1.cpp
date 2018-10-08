#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        bool flag = false;
        int min_x = INT_MAX, max_x = INT_MIN;
        int min_y = INT_MAX, max_y = INT_MIN;
        int d_x, d_y, x_1, x_2, y_1, y_2, mid_x, mid_y;
        Point *pts = new Point[5];
        for(int i = 0; i < 5; ++i)
            cin >> pts[i].x >> pts[i].y;
        for(int i = 0; i < 5; ++i)
        {
            if(pts[i].x < min_x)
                min_x = pts[i].x, x_1 = i;
            if(pts[i].x > max_x)
                max_x = pts[i].x, x_2 = i;
            if(pts[i].y < min_y)
                min_y = pts[i].y, y_1 = i;
            if(pts[i].y > max_y)
                max_y = pts[i].y, y_2 = i;
        }
        d_x = abs(max_x - min_x);
        d_y = abs(max_y - min_y);
        if(d_x == 2 && d_y == 2)
        {
            mid_x = max_x - min_x;
            mid_y = max_y - min_y;
            for(int i = 0; i < 5; ++i)
                if((mid_x == pts[i].x && pts[i].y == pts[x_1].y) && (mid_y == pts[i].y && pts[i].x == pts[y_1].x)) flag = true;
                else if((mid_x == pts[i].x && pts[i].y == pts[y_1].y) && (mid_y == pts[i].y && pts[i].x == pts[x_1].x)) flag = true;
            if(flag)
                cout << "Yes";
        }
        else
            cout << "No";
        cout << "\n";
        delete [] pts;
        pts = NULL;
    }
    return 0;
}
