/*
3
3 1
1 1 1
3
3 1
1 2 4
7
1 1
1
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        bool flag = false;
        int n, m, x; cin >> n >> m;
        vector<int> A, B;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            if(x) A.push_back(x);
        }
        for(int i = 0; i < m; ++i) {
            cin >> x;
            if(x) B.push_back(x);
        }
        n = A.size();
        m = B.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if(n == m) {
            flag = true;
            for(int i = 0; i < n; ++i) {
                if(A[i] != B[i]) {
                    flag = false;
                    break;
                }
            }
        }
        cout << ((!flag) ? "Alice" : "Bob") << "\n";
    }
    return 0;
}
