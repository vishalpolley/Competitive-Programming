#include <bits/stdc++.h>
#include <cmath>
#define ll long long int
#define mod 1000000007
using namespace std;

list <int> bits;

void bits_of_n(ll n)
{
    while(n)
    {
        bits.push_back(n % 2);
        n /= 2;
    }
}

ll modexp_lr(ll a, ll n)
{
    ll r = 1;
    list <int> :: iterator it;
    bits.reverse();
    for(it = bits.begin(); it != bits.end(); ++it)
    {
        r = r * r % mod;
        if(*it == 1)
            r = r * a % mod;
    }
    return r;
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a, b, n, exp_2;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        exp_2 = abs(a - b);
        if(exp_2 == 0)
            cout << (modexp_lr(a, n) + modexp_lr(b, n)) % mod;
        else
            cout << __gcd(modexp_lr(a, n) + modexp_lr(b, n), exp_2) % mod;
        cout << endl;
    }
    return 0;
}
