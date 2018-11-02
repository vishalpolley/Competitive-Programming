/*
Special Pythagorean triplet
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <bits/stdc++.h>
using namespace std;

void pythagoreanTriplet(int n) {
    for(int a = 1; a < n/3; ++a) {
        for(int b = a+1; b < n/2; ++b) {
            int c = n-a-b;
            if(c*c == a*a+b*b) {
                cout << a << " " << b << " " << c << " ";
                cout << a*b*c << endl;
                break;
            }
        }
    }
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    pythagoreanTriplet(n);
    return 0;
}
