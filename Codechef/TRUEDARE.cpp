#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        bool flag = true;
        int tr, val; cin >> tr;
        vector<int> vecTr(tr);
        for(int i = 0; i < tr; ++i)
            cin >> val, vecTr.push_back(val);
        sort(vecTr.begin(), vecTr.end());
        int td; cin >> td;
        vector<int> vecTd(td);
        for(int i = 0; i < td; ++i)
            cin >> val, vecTd.push_back(val);
        sort(vecTd.begin(), vecTd.end());
        int ts; cin >> ts;
        for(int i = 0; i < ts; ++i) {
            cin >> val;
            if(flag) {
                if(!binary_search(vecTr.begin(), vecTr.end(), val))
                    flag = false;
            }
        }
        int ds; cin >> ds;
        for(int i = 0; i < ds; ++i) {
            cin >> val;
            if(flag) {
                if(!binary_search(vecTd.begin(), vecTd.end(), val))
                    flag = false;
            }
        }
        cout << (!flag ? "no" : "yes") << "\n";
    }
    return 0;
}

