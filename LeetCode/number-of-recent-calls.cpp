#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    static int cnt;
    RecentCounter() {
        cnt = 0;
    }

    int ping(int t) {
        if(t <= 3001)
            return ++cnt;
        else
            return cnt;
    }
};

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(t);
    return 0;
}

