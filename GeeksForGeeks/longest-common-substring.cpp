/*
Longest Common Substring

Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.

Input : X = "zxabcdezy", y = "yzabcdezx"
Output : 6
The longest common substring is "abcdez" and is of
length 6.


Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string X and Y respectively
The next two lines contains the 2 string X and Y.


Output:
For each test case print the length of longest  common substring of the two strings .


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100


Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1
*/
#include <bits/stdc++.h>
using namespace std;

int commonSubstring(int x, string str1, int y, string str2)
{
    int m = 0;
    int dp[x+1][y+1];
    for(int i = 0; i < x; ++i) dp[i][0] = 0;
    for(int i = 0; i < y; ++i) dp[0][i] = 0;
    for(int i = 1; i <= x; ++i)
    {
        for(int j = 1; j <= y; ++j)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0;
            if(dp[i][j] > m)
                m = dp[i][j];
        }
    }
    return m;
}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int x, y; cin >> x >> y;
        string str1, str2; cin >> str1 >> str2;
        cout << commonSubstring(x, str1, y, str2) << endl;
    }
    return 0;
}
