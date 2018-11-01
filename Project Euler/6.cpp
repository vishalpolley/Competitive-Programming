/*
Sum square difference
Problem 6
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll sum1 = (n*(n+1)*(2*n+1))/6;
    ll sum2 = (n*(n+1))/2;
    cout << (ll)pow(sum2, 2) - sum1 << "\n";
    return 0;
}

