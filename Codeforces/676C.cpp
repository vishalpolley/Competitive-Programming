/*
C. Vasya and String

High school student Vasya got a string of length n as a birthday present. This string consists of letters 'a' and 'b' only.
Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters.

Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?

Input
The first line of the input contains two integers n and k (1 ≤ n ≤ 100 000, 0 ≤ k ≤ n) —
the length of the string and the maximum number of characters to change.

The second line contains the string, consisting of letters 'a' and 'b' only.

Output
Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.
Examples
input
4 2
abba
output
4
input
8 1
aabaabaa
output
5
Note
In the first sample, Vasya can obtain both strings "aaaa" and "bbbb".

In the second sample, the optimal answer is obtained with the string "aaaaabaa" or with the string "aabaaaaa".
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(string str, int k, int l) {
    int dp[2] = {0, 0};
    for(int i = 0; i < l; ++i)
        dp[str[i]-'a']++;
    if(k >= min(dp[0], dp[1])) return 1;
    for(int i = 0; i+l < (int)str.size(); ++i) {
        dp[str[i]-'a']--;
        dp[str[i+l] - 'a']++;
        if(k >= min(dp[0], dp[1])) return 1;
    }
    return 0;
}

int main() {
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, c = 0; cin >> n >> k;
    string str; cin >> str;
    int l = 1, r = n;
    int mid, ans = 0;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(solve(str, k, mid))
            ans = max(ans, mid), l = mid+1;
        else r = mid-1;
    }
    cout << ans << "\n";
    return 0;
}
