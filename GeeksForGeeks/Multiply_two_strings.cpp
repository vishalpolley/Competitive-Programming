/*
Multiply two strings

Given two numbers as stings s1 and s2 your task is to multiply them. You are required to complete the function multiplyStrings which takes two strings s1 and s2 as its only argument and returns their product as strings.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow . Each test case contains two strings s1 and s2 .

Output:
For each test case in a new line the output will be a string denoting the product of the two strings s1 and s2.

Constraints:
1 <= T <= 100
1 <= length of s1 and s2 <= 103

Example(To be used only for expected output) :
Input:
2
33 2
11 23
Output:
66
253
*/

#include <bits/stdc++.h>
using namespace std;

string multiplyStrings(string str1, string str2)
{
    int c, carry;
    string ans;
    bool sign = false;
    if(str1[0] == '-' && str2[0] == '-')
        str1.erase(0, 1), str2.erase(0, 1);
    else if(str1[0] == '-')
        str1.erase(0, 1), sign = true;
    else if(str2[0] == '-')
        str2.erase(0, 1), sign = true;
    if(str2.length() > str1.length())
        swap(str1, str2);
    int len1 = str1.length();
    int len2 = str2.length();
    int len = 2 * len1 + 1;
    int *prod = new int[len];
    for(int i = 0; i < len; ++i) prod[i] = 0;
    for(int i = len2-1; i >= 0; --i)
    {
        c = len2-1-i, carry = 0;
        for(int j = len1-1; j >= 0; --j)
        {
            int a = str2[i] - '0';
            int b = str1[j] - '0';
            int x = prod[len-c-1] + (a * b) + carry;
            if(x >= 10)
            {
                prod[len-c-1] = x % 10;
                carry = x / 10;
            }
            else
            {
                prod[len-c-1] = x;
                carry = 0;
            }
            c++;
        }
        if(carry != 0)
            prod[len-c-1] += carry, c++;
    }
    c = len-c;
    while(prod[c] == 0)
        c++;
    for(int i = c; i < len; ++i)
        ans = ans + to_string(prod[i]);
    if(ans.empty())
        ans = '0';
    if(sign && ans != "0")
        ans = '-' + ans;
    delete prod;
    return ans;
}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str1, str2; cin >> str1 >> str2;
        cout << multiplyStrings(str1, str2) << endl;
    }
    return 0;
}
