/*
Longest Palindrome in a String

Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[ i . . . . j ] where 0 ≤ i ≤ j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:

The first line of input consists number of the test cases. The following T lines consist of a string each.


Output:

In each separate line print the longest palindrome of the string given in the respective test case.


Constraints:

1 ≤T≤ 100
1 ≤ Str Length≤ 104

Example:

Input:
1
aaaabbaa

Output:

aabbaa
*/

#include <bits/stdc++.h>
using namespace std;

/*
// DP Solution
// Time Complexity - O(n*2)
// Space Complexity - O(n*2)
string longestPalindrome(string str)
{
    string ans;
    int max_len = 0;
    int len = str.length();
    bool dp[len][len];
    // Initializing dp table
    for(int i = 0; i < len; ++i)
        for(int j = 0; j < len; ++j)
            dp[i][j] = false;
    // Substrings of length 1 and 2
    for(int i = 0; i < len; ++i)
    {
        dp[i][i] = true;
        if(dp[i][i] && max_len < 1)
            max_len = 1, ans = str.substr(i, 1);
        if(str[i] == str[i+1] && i+1 < len)
        {
            dp[i][i+1] = true;
            if(max_len < 2)
                max_len = 2, ans = str.substr(i, 2);
        }
    }
    // Substrings of length > 2
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; j < len-i-2; ++j)
        {
            if(str[j] == str[i+j+2] && dp[j+1][i+j+1] == true)
            {
                dp[j][i+j+2] = true;
                if(i+3 > max_len)
                    max_len = i+3, ans = str.substr(j, i+3);
            }
        }
    }
    return ans;
}
*/

string longestPalindrome(string str)
{
    int h, l;
    int i1 = 0, i2 = 0;
    string ans;
    int len = str.length();
    for(int i = 0; i < len; ++i)
    {
        // Length of string is Even
        l = i;
        h = i+1;
        while(l >= 0 && h < len && str[l] == str[h])
            l--, h++;
        if(h-l-2 > i2-i1)
            i1 = l+1, i2 = h-1;
        // Length of string is Odd
        l = i-1;
        h = i+1;
        while(l >= 0 && h < len && str[l] == str[h])
            l--, h++;
        if(h-l-2 > i2-i1)
            i1 = l+1, i2 = h-1;
    }
    return str.substr(i1, i2-i1+1);
}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}
