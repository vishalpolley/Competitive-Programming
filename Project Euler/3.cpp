/*
Largest prime factor
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void prime_factors(ll n) {
    ll ans = 0LL;
    while(n % 2 == 0)
        n /= 2, ans = 2;
    for(ll i = 3; i <= sqrt(n); i += 2) {
        while(n % i == 0)
            n /= i, ans = max(ans, i);
    }
    if(n > 2)
        ans = max(ans, n);
    cout << ans << "\n";
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    prime_factors(n);
    return 0;
}

