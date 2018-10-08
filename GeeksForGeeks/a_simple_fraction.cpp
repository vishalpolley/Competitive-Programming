/*
A Simple Fraction

Given a fraction. Convert it into a decimal. So simple :P

eg.
10/2 = 5
3/5 = 0.6

(The Question Begins Now)  :D
If the decimals are repeating recursively, then enclose them inside  ().

eg.
8/3 = 2.(6)

as 8/3 = 2.66666666.......  infinitly.


Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is an integer N denoting the numerator of fraction.
The second line of each test case is an integer D denoting the denominator of fraction.

Output:

Print decimal of that fraction in separate line for each test case.

Constraints:

1 ≤ T ≤ 100
1 ≤ N,D ≤ 2000

Example:

Input
2
4
2
8
3
Output
2
2.(6)
*/

#include <bits/stdc++.h>
using namespace std;

string simpleFraction(int numr, int denr)
{
    unordered_map<int, int> m;
    m.clear();
    string ans, fraction;
    int quotient, rem;
    quotient = floor(numr / denr);
    ans += to_string(quotient);
    rem = numr % denr;
    if(rem == 0)
        return ans;
    else
    {
        ans += '.';
        while(rem != 0 && m.find(rem) == m.end())
        {
            m[rem] = fraction.length();
            rem = rem * 10;
            quotient = rem / denr;
            fraction += to_string(quotient);
            rem = rem % denr;
        }
        if(m.find(rem) != m.end())
        {
            ans += fraction.substr(0, m[rem]);
            ans += '(' + fraction.substr(m[rem]) + ')';
        }
        else
            ans += fraction;
    }
    return ans;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, d; cin >> n >> d;
        cout << simpleFraction(n, d) << endl;
    }
}
