#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string str1, string str2, string str3)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int len = str3.length();
    int dp1[len1+1][len+1];
    for(int i = 0; i <= len; ++i) dp1[0][i] = 0;
    for(int i = 0; i <= len1; ++i) dp1[i][0] = 0;
    for(int i = 1; i <= len1; ++i)
    {
        for(int j = 1; j <= len; ++j)
        {
            if(str1[i-1] == str3[j-1])
                dp1[i][j] = 1 + dp1[i-1][j-1];
            else
                dp1[i][j] = max(dp1[i-1][j], max(dp1[i-1][j-1], dp1[i][j-1]));
        }
    }
    int dp2[len2+1][len+1];
    for(int i = 0; i <= len; ++i) dp2[0][i] = 0;
    for(int i = 0; i <= len2; ++i) dp2[i][0] = 0;
    for(int i = 1; i <= len2; ++i)
    {
        for(int j = 1; j <= len; ++j)
        {
            if(str2[i-1] == str3[j-1])
                dp2[i][j] = 1 + dp2[i-1][j-1];
            else
                dp2[i][j] = max(dp2[i-1][j], max(dp2[i-1][j-1], dp2[i][j-1]));
        }
    }
    if(dp1[len1][len] == len1 && dp2[len2][len] == len2 && len1 + len2 == len)
    {
        string str = str1 + str2;
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        transform(str3.begin(), str3.end(), str3.begin(), ::toupper);
        int *hash1 = new int[26];
        int *hash2 = new int[26];
        for(int i = 0; i < 26; ++i) hash1[i] = 0;
        for(int i = 0; i < 26; ++i) hash2[i] = 0;
        for(int i = 0; i < str.length(); ++i)
            hash1[str[i] - 65]++;
        for(int i = 0; i < str3.length(); ++i)
            hash2[str3[i] - 65]++;
        for(int i = 0; i < 26; ++i)
            if(hash1[i] != hash2[i])
                return false;
        return true;
    }
    return false;
}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str1, str2, str3; cin >> str1 >> str2 >> str3;
        cout << isInterleave(str1, str2, str3) << endl;
    }
}
