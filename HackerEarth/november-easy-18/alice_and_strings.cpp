#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b; cin >> a >> b;
    bool flag = false;
    int len1, len2, diff, c = -26;
    len1 = a.length();
    len2 = b.length();
    if(len1 == len2) {
        flag = true;
        for(int i = len1-1; i >= 0; --i) {
            diff = b[i] - a[i];
            if(diff >= c)
                c = diff;
            else {
                flag = false;
                break;
            }
        }
    }
    cout << ((flag) ? "YES" : "NO");
    return 0;
}
