/*
Sum of all substrings of a number

Given a integer represented as a string, we need to get the sum of all possible sub-strings of this string.

Examples:

Input  : N = “1234”
Output : 1670
Sum = 1 + 2 + 3 + 4 + 12 + 23 +
       34 + 123 + 234 + 1234
    = 1670

Input  : N = “421”
Output : 491
Sum = 4 + 2 + 1 + 42 + 21 + 421
    = 491


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print the required result.

Constraints:
1<=T<=200
1<=N<=10^5+6

Example:
Input:
2
1234
421
Output:
1670
491
*/

#include <bits/stdc++.h>
using namespace std;

/*
int sumSubstring(string n)
{
    int result = 0;
    int *digitSum = new int[n.length()];
    digitSum[0] = n[0] - '0';
    result = digitSum[0];
    for(int i = 1; i < n.length(); ++i)
    {
        digitSum[i] = (i + 1) * (n[i] - '0') + 10 * digitSum[i-1];
        result += digitSum[i];
    }
    delete digitSum;
    return result;
}
*/

int sumSubstring(string n)
{
    int result = 0;
    int mul = 1;
    for(int i = n.length(); i > 0; --i)
    {
        result += (n[i-1] - '0') * i * mul;
        mul = mul * 10 + 1;
    }
    return result;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << sumSubstring(to_string(n)) << endl;
    }
    return 0;
}
