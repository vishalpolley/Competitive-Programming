/*
C. Meme Problem

Try guessing the statement from this picture:


You are given a non-negative integer d. You have to find two non-negative real numbers a and b such that a+b=d and a⋅b=d.

Input
The first line contains t (1≤t≤103) — the number of test cases.

Each test case contains one integer d (0≤d≤103).

Output
For each test print one line.

If there is an answer for the i-th test, print "Y", and then the numbers a and b.

If there is no answer for the i-th test, print "N".

Your answer will be considered correct if |(a+b)−a⋅b|≤10−6 and |(a+b)−d|≤10−6.

Example
inputCopy
7
69
0
1
4
5
999
1000
outputCopy
Y 67.985071301 1.014928699
Y 0.000000000 0.000000000
N
Y 2.000000000 2.000000000
Y 3.618033989 1.381966011
Y 997.998996990 1.001003010
Y 998.998997995 1.001002005
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        double d; cin >> d;
        double expr = d*d - 4*d;
        if(expr < 0)
            cout << "N";
        else {
            expr = sqrt(expr);
            if(expr > d)
                cout << "N";
            else {
                double expr1 = (d+expr)/2;
                double expr2 = (d-expr)/2;
                cout << fixed << setprecision(9) << "Y " << expr1 << " " << expr2;
            }
        }
        cout << "\n";
    }
    return 0;
}

