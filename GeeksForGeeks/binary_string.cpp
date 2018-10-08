/*
Binary String

Given a binary string, count number of substrings that start and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.


Input:

The first line of input contains an integer T denoting the number of test cases.
Each test case consist of an integer 'n' denoting the string length and next line is followed by a binary string .


Output:

Print the number of substring starting and ending with 1 in a separate line.

Constraints:

1 ≤ T ≤ 40
1 ≤ |s| ≤ 1000


Example:

Input:
1
4
1111
Output:
6
*/

#include <bits/stdc++.h>
using namespace std;

int binaryString(string str)
{
    int cnt = 0;
    for(auto c : str)
    {
        if(c == '1')
            cnt++;
    }
    return (cnt * (cnt - 1)) / 2;
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
        string str; cin >> str;
        cout << binaryString(str) << endl;
    }
    return 0;
}
