/*
Multiples of 3 and 5
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sum = 0; cin >> n;
    for(int i = 1; i < n; ++i) {
        if((i%3) == 0 && (i%5) == 0) sum += i;
        else if((i%5) == 0) sum += i;
        else if((i%3) == 0) sum += i;
    }
    cout << sum << "\n";
    return 0;
}
