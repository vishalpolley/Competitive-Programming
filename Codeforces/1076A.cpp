/*
A. Minimizing the String

You are given a string s consisting of n lowercase Latin letters.

You have to remove at most one (i.e. zero or one) character of this string in such a way that the string you obtain will be lexicographically smallest among all strings that can be obtained using this operation.

String s=s1s2…sn is lexicographically smaller than string t=t1t2…tm if n<m and s1=t1,s2=t2,…,sn=tn or there exists a number p such that p≤min(n,m) and s1=t1,s2=t2,…,sp−1=tp−1 and sp<tp.

For example, "aaa" is smaller than "aaaa", "abb" is smaller than "abc", "pqr" is smaller than "z".

Input
The first line of the input contains one integer n (2≤n≤2⋅105) — the length of s.

The second line of the input contains exactly n lowercase Latin letters — the string s.

Output
Print one string — the smallest possible lexicographically string that can be obtained by removing at most one character from the string s.

Examples
inputCopy
3
aaa
outputCopy
aa
inputCopy
5
abcda
outputCopy
abca
Note
In the first example you can remove any character of s to obtain the string "aa".

In the second example "abca" < "abcd" < "abcda" < "abda" < "acda" < "bcda".
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag = false;
    int n, m; cin >> n;
    string str; cin >> str;
    for(int i = 1; i < n; ++i) {
        if(str[i-1] > str[i]) {
            m = i-1; flag = true; break;
        }
    }
    if(str[n-1] > str[m] && !flag)
        m = n-1, flag = true;
    if(flag)
        cout << str.substr(0, m)+str.substr(m+1, n);
    else
        cout << str.substr(0, n-1);
    return 0;
}
