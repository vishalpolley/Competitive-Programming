/*
10001st prime
Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n) {
    int cnt = 0;
    vector<bool> prime(n+1, true);
    for(int i = 2; i <= sqrt(n); ++i) {
        if(prime[i]) {
            for(int j = i*2; j <= n; j+=i)
                prime[j] = false;
        }
    }
    for(int i = 2; i <= n; ++i) {
        if(prime[i]) cnt++;
        if(cnt == 10001 && prime[i])
            cout << i << endl;
    }
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}

