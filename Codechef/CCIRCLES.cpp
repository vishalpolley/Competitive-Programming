#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x;
    double y;
    double r;
};

struct range
{
    double s;
    double e;
};

int binarySearch(vector<pair<double, char> > vecpair, int l, int r, int x)
{
    if(l > r)
        return -1;
    if(x >= vecpair[r].first)
        return r;
    int mid = l + (r - l) / 2;
    if(vecpair[mid].first == x)
        return mid;
    if(mid > 0 && vecpair[mid-1].first <= x && x < vecpair[mid].first)
        return mid-1;
    if(x < vecpair[mid].first)
        return binarySearch(vecpair, l, mid-1, x);
    return binarySearch(vecpair, mid+1, r, x);
}

void rangeCalculation(point p1, point p2, range &bound)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    double dst = sqrt(x*x + y*y);
    double r1 = p1.r;
    double r2 = p2.r;
    double m1, m2;
    if(r1 > r2)
        swap(r1, r2);
    m1 = dst - (r1 + r2);
    m2 = dst + (r1 + r2);
    if(dst == 0) // Concentric Circles
    {
        bound.s = r2 - r1;
        bound.e = 2*r1 + m1;
    }
    if(dst > r1+r2) // Outer Cirlces
    {
        bound.s = m1;
        bound.e = m2;
    }
    if(r2 > dst + r1) // Containing Cirlces
    {
        bound.s = r2 - (dst + r1);
        bound.e = 2*r2 - m1;
    }
    if(dst >= r2-r1 && dst <= r1+r2) // Intersecting Circles
    {
        bound.s = 0;
        bound.e = m2;
    }
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, t; cin >> n >> q;
    point pt[n];
    t = (n*(n-1))/2; // Number of Ranges
    range bound[t];
    for(int i = 0; i < n; ++i)
        cin >> pt[i].x >> pt[i].y >> pt[i].r;
    t = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j)
            rangeCalculation(pt[i], pt[j], bound[t++]);
    vector<pair<double, char> > vecpair; // Range Pairs
    for(int i = 0; i < t; ++i)
    {
        vecpair.push_back(make_pair(bound[i].s, 's'));
        vecpair.push_back(make_pair(bound[i].e, 'e'));
    }
    sort(vecpair.begin(), vecpair.end());
    int *prefixSum = new int[2*t];
    int c = 0;
    for(const auto& p : vecpair) // Prefix Sum Array
    {
        if(!c)
        {
            prefixSum[c] = ((p.second == 's') ? 1 : -1);
            c++;
            continue;
        }
        if(p.second == 's')
            prefixSum[c] = prefixSum[c-1] + 1;
        else
            prefixSum[c] = prefixSum[c-1] - 1;
        c++;
    }
    while(q--)
    {
        int cnt = 0;
        double k; cin >> k;
        int idx = binarySearch(vecpair, 0, 2*t-1, k);
        cout << ((idx != -1) ? prefixSum[idx] : 0) << endl;
    }
    delete prefixSum;
    return 0;
}
