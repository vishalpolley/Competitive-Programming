#include <bits/stdc++.h>
using namespace std;

void printPattern(int n, int v, bool flag)
{
    if(v == n) return;
    if(v <= 0) flag = false;
    if(flag) {cout << v-5 << " "; printPattern(n, v-5, flag);}
    else {cout << v+5 << " "; printPattern(n, v+5, flag);}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        bool flag = true;
        int n; cin >> n;
        cout << n << " " << n-5 << " ";
        printPattern(n, n-5, flag);
        cout << endl;
    }
    return 0;
}
