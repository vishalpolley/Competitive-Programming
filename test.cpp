/*
2
8 3
1 2 2 1 3 3 2 1
5 3
1 1 2 2 3
*/

#include <bits/stdc++.h>
using namespace std;

const int SIZE = (1<<20);
long long sum[SIZE];

long long prefix(int l, int r) {
    if(l > r || r < 0)
        return 0;
    long long ret = sum[r];
    if(l > 0) ret -= sum[l-1];
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, k, val, pos; cin >> n >> k;
        set<int> s;
        int *arr = new int[n];
        for(int i=0; i<n; ++i)
            cin >> arr[i], s.insert(arr[i]);
        vector<int> vec[SIZE];
        for(int i=0; i<n; ++i)
            vec[arr[i]].push_back(i);
        long long ans=(1ll<<60);
        for(auto &v : vec) {
            if(k > v.size()) continue;
            sum[0]=v[0];
            sum[v.size()]=0;
            for(int i=1; i<v.size(); ++i)
                sum[i] = sum[i-1]+v[i];
            for(int j=0; j+k<=v.size(); ++j) {
                long long l = j, r = j+k-1;
                long long mid = l+(r-l)/2;
                long long left_cost = (mid-l)*v[mid] - ((mid-l)*(mid-l+1))/2 - prefix(l, mid-1);
                long long right_cost = prefix(mid+1, r) - ((r-mid)*(r-mid+1))/2 - (r-mid)*v[mid];
                ans = min(ans, left_cost+right_cost);
            }
        }
        cout << (ans == (1ll<<60) ? -1 : ans) << "\n";
        delete[] arr;
        arr = nullptr;
    }
    return 0;
}
