#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float i;
    string csv;
    bool flag=false;
    vector<float> m, n, slope;
    vector<pair<float, float>> pts;
    while(getline(cin, csv)) {
        stringstream ss(csv);
        while(ss >> i) {
            if(!flag) m.push_back(i);
            else n.push_back(i);
            if(ss.peek() == ',' || ss.peek() == ' ')
                ss.ignore();
        }
        flag=true;
    }
    for(int i=0; i < m.size(); ++i) {
        pts.push_back({m[i], n[i]});
    }
    sort(pts.begin(), pts.end());
    for(int i=0; i<pts.size()-1; ++i) {
        float m = (pts[i+1].second-pts[i].second)/(pts[i+1].first-pts[i].first);
        slope.push_back(m);
    }
    for(int i=0; i<slope.size()-1; ++i) {
        cout << slope[i+1]-slope[i] << endl;
    }
    return 0;
}
