/*
B. Divisor Subtraction

You are given an integer number n. The following algorithm is applied to it:

if n=0, then end algorithm;
find the smallest prime divisor d of n;
subtract d from n and go to step 1.
Determine the number of subtrations the algorithm will make.

Input
The only line contains a single integer n (2≤n≤1010).

Output
Print a single integer — the number of subtractions the algorithm will make.

Examples
inputCopy
5
outputCopy
1
inputCopy
4
outputCopy
2
Note
In the first example 5 is the smallest prime divisor, thus it gets subtracted right away to make a 0.

In the second example 2 is the smallest prime divisor at both steps.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sprime(ll n) {
    for(ll i = 3; i <= sqrt(n); i+=2) {
        if(n%i == 0)
            return i;
    }
    return n;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, steps = 0; cin >> n;
    while(n) {
        if(n%2 == 0)
            steps += n/2, n = 0;
        else
            steps++, n -= sprime(n);
    }
    cout << steps;
    return 0;
}

