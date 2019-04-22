#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> m;
        for(int i = 0; i < n; ++i) {
            int c; cin >> c;
            if(m.find(c) != m.end())
                m[c]++;
            else
                m.insert(make_pair(c, 1));
        }
        int z = 0;
        int s = m.size();
        int *candies = new int[s];
        int *cnt = new int[s];
        for(auto &i : m) {
            candies[z] = i.first;
            cnt[z] = i.second;
            z++;
        }
        for(int i = 0; i < s; ++i)
            cout << candies[i] << " " << cnt[i] << endl;
        int x; cin >> x;
        int dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= s; ++i) {
            for(int j = 0; j <= x; ++j) {
                int r = min(cnt[i], j/candies[i]);
                for(int k = 0; k <= r; ++k)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-candies[i]*k])%MOD;
            }
        }
        cout << (if(dp[s][x] > 0) ? "YES" : "NO") << endl;
        delete candies;
        delete cnt;
        candies = NULL;
        cnt = NULL;
    }
    return 0;
}
