/*
Recursively remove all adjacent duplicates

Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should not have any adjacent duplicates.


Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac
*/

#include <bits/stdc++.h>
using namespace std;

void removeAdjacent(char* str, int len)
{
    int k = 0;
    for(int i = 1; i < len; ++i)
    {
        if(str[i-1] != str[i])
            str[k++] = str[i-1];
        else
            while(str[i-1] == str[i])
                i++;
    }
    if(str[len-2] != str[len-1])
        str[k++] = str[len-1];
    str[k] = '\0';
    if(len > k)
        removeAdjacent(str, k);
}

int main()
{
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        char cstr[str.size()+1];
        str.copy(cstr, str.size()+1);
        cstr[str.size()] = '\0';
        removeAdjacent(cstr, strlen(cstr));
        cout << cstr << endl;
    }
    return 0;
}
