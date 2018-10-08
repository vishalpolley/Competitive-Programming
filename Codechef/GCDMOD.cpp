#include <bits/stdc++.h>
#include <cmath>
#define ll long long int
#define mod 1000000007
using namespace std;

list <int> digits;

void digits_of_n(ll n, int b)
{
    while(n)
    {
        digits.push_back(n % b);
        n /= b;
    }
}

ll modexp_lr_k_ary(ll a, ll n, int k = 5)
{
    int base = 2 << (k - 1);
    int table[base] = {1};
    list <int> :: iterator it;
    digits_of_n(n, base);
    for(int i = 1; i < base; ++i)
        table[i] = table[i-1] * a % mod;
    ll r = 1;
    digits.reverse();
    for(it = digits.begin(); it != digits.end(); ++it)
    {
        for(int i = 0; i < k; ++i)
            r = r * r % mod;
        if(*it)
            r = r * table[*it] % mod;
    }
    digits.clear();
    return r;
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a, b, n, exp;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        exp = abs(a - b);
        if(exp == 0)
            cout << (modexp_lr_k_ary(a, n) + modexp_lr_k_ary(b, n)) % mod;
        else
            cout << __gcd(modexp_lr_k_ary(a, n) + modexp_lr_k_ary(b, n), exp) % mod;
        cout << endl;
    }
    return 0;
}
