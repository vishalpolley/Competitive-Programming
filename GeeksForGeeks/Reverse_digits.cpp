#include <bits/stdc++.h>
using namespace std;

void reverseDigit(uint64_t n)
{
    if(n == 0)
        return;
    else {cout << n%10; reverseDigit(n/10);}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        uint64_t n; cin >> n;
        while(!(n % 10))
            n /= 10;
        reverseDigit(n);
        cout << "\n";
    }
    return 0;
}
