/*
Arya's Long String

Arya has a string, S, of uppercase English letters. She writes down the string S on a paper K times.
She wants to calculate the occurence of a specific letter in the first N characters of the final string.

Input:

First line of input contains a single integer T denoting the number of test cases.
The first line of each test case contains a string S.
The second line contains 2 space-separated integers K and N, and an uppercase English letter C whose occurence needs to be counted.

Output:

For each test case, print the required answer in a new line.


Constraints:

1 <= T <= 150
1 <= |S| <= 500
1 <= K <= 10^5
1 <= N <= |S|*K


Example:

Input :
2
ABA
3 7 B
BHD
4 6 E
Output :
2
0

Explaination :
Case 1 : Final string - ABAABAABA
Case 2 : Final string - BHDBHDBHDBHD

Example 2 :
Input :
1
MMM
2 4 M
Output :
4

Explaination :
Case 1 : Final string - MMMMMM
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int ans = 0;
        string str; cin >> str;
        int len = str.length();
        int *char_hash = new int[26];
        for(int i = 0; i < 26; ++i)
            char_hash[i] = 0;
        int k, n; cin >> k >> n;
        for(int i = 0; i < len; ++i)
            char_hash[str[i] - 65]++;
        char c; cin >> c;
        if(char_hash[c - 65])
        {
            if(!n)
                ans = 0;
            else
            {
                ans = char_hash[c - 65] * (n / len);
                for(int i = 0; i < (n % len); ++i)
                    if(str[i] == c) ans++;
            }
        }
        cout << ans << endl;
        delete char_hash;
    }
    return 0;
}
