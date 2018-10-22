/*
Longest common prefix

Given two string str1 and str2(of lower case alphabets) of same length. Find the longest prefix of str1 which is common in str2 as well. Print the index at which the longest common prefix of str1 is found in str2 and the longest common prefix with spaces in between.

NOTE: If there is no common prefix then print "-1".

INPUT: First line of the input is T denoting the number of test cases. Each test case takes two strings as input.

OUTPUT: Print the index from where the longest common prefix of str1 is found in str2 and the longest common prefix with a space in between.

CONSTRAINTS:
1<=T<=100
1<=Length of strings<10000

Examples:
INPUT:
2
geeks
dgeek
practicegeeks
coderpractice

OUTPUT:
1 geek
5 practice
*/

#include <bits/stdc++.h>
using namespace std;

void prefixArray(int P[], string str1)
{
    P[0] = 0;
    int i = 1, j = 0;
    int m = str1.length();
    while(m > i)
    {
        if(str1[i] == str1[j])
            P[i] = j+1, i++, j++;
        else if(j > 0)
            j = P[j-1];
        else
            P[i] = 0, i++;
    }
}

int KMP(string str1, string str2)
{
    int i = 0, j = 0, len = 0, pos = 0;
    int m = str1.length(); // Pattern
    int n = str2.length(); // Text
    int *P = new int[m];
    prefixArray(P, str1);
    while(n > i)
    {
        if(str2[i] == str1[j])
        {
            if(j == m-1)
            {
                len = m;
                pos = i-j;
                break;
            }
            else
                i++, j++;
        }
        else if(j > 0)
            j = P[j-1];
        else
            i++;
        if(j > len)
            len = j, pos = i-j;
    }
    if(len)
        cout << pos << " " << str1.substr(0, len);
    else
        cout << -1;
    delete P;
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
        KMP(str1, str2);
        cout << "\n";
    }
    return 0;
}
