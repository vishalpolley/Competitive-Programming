#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, d = 26; cin >> n;
        uint64_t x = 0, y = 0, z = 0;
        int mul = floor((n-1)/d) + 1;
        int seq1 = 26 + (mul - 1) * d;
        int seq2 = 10 + (mul - 1) * d;
        int seq3 = 2 + (mul - 1) * d;
        if(n <= seq1 && n > seq2) z = pow(2, mul-1);
        else if(n <= seq2 && n > seq3) y = pow(2, mul-1);
        else if(n <= seq3) x = pow(2, mul-1);
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}
