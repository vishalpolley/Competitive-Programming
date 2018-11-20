/*
Summation of primes
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <bits/stdc++.h>
using namespace std;

long long sieveOfEratosthenes(int n) {
    long long ans = 0;
    vector<bool> prime(n+1, true);
    for(int i = 2; i <= sqrt(n); ++i) {
        if(prime[i]) {
            for(int j = i*2; j <= n; j+=i)
                prime[j] = false;
        }
    }
    for(int i = 2; i <= n; ++i)
        if(prime[i]) ans += i;
    return ans;
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << sieveOfEratosthenes(n) << "\n";
    return 0;
}

