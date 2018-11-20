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
        string str; cin >> str;
        int len = str.length(), cntg = 0, cntr = 0;
        for(int i = 0; i < len; ++i) {
            if(str[i] == str[(i+1)%len] && str[i] == 'G')
                cntg++;
            else if(str[i] == str[(i+1)%len] && str[i] == 'R')
                cntr++;
        }
        if((cntg == 1 && cntr == 1) || (cntg == 0 && cntr == 0))
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }
    return 0;
}

