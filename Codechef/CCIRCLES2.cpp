/*
2 3
0 0 5
8 3 2
0
10
20
*/

#include <bits/stdc++.h>
using namespace std;

inline double euclideanDistance(int x1, int x2, int y1, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main() {
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    vector< vector<int>> v(n, vector<int>(3));
    for(int i = 0; i < n; ++i)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    int idx = 0;
    vector<double> x((n*(n-1))/2), y((n*(n-1))/2);
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            int x1 = v[i][0], y1 = v[i][1], r1 = v[i][2];
            int x2 = v[j][0], y2 = v[j][1], r2 = v[j][2];
            double d = euclideanDistance(x1, x2, y1, y2);
            double a, b;
            if(d > r1 + r2) {
                a = d - r1 - r2;
                b = d + r1 + r2;
            } else if(d < abs(r1 - r2)) {
                if(r1 > r2) a = r1 - (d + r2), b = 2 * r1 - a;
                else a = r2 - (d + r1), b = 2 * r2 - a;
            } else {
                a = 0;
                b = d + r1 + r2;
            }
            x[idx] = a;
            y[idx] = b;
            idx++;
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 0; i < q; ++i) {
        int k; cin >> k;
        int started = distance(x.begin(), upper_bound(x.begin(), x.end(), k));
        int ended = distance(y.begin(), lower_bound(y.begin(), y.end(), k));
        cout << started-ended << "\n";
    }
    return 0;
}

