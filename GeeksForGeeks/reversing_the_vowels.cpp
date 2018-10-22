/*
Reversing the vowels

Given a string, reverse only the vowels present in it and print the resulting string.

Input: First line of the input file contains an integer T denoting the number of test cases. Then T test cases follow. Each test case has a single line containing a string.

Output: Corresponding to each test case, output the string with vowels reversed.

Example:
Input:
4
geeksforgeeks
practice
wannacry
ransomware

Output:
geeksforgeeks
prectica
wannacry
rensamwora
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
        string str; cin >> str;
        int len = str.length();
        int i = 0, j = len - 1;
        int pos1 = -1, pos2 = -1;
        while(i < j && i != j)
        {
            if((str[i] == 97 || str[i] == 101 || str[i] == 105
                || str[i] == 111 || str[i] == 117) && (str[j] == 97
                || str[j] == 101 || str[j] == 105
                || str[j] == 111 || str[j] == 117))
                pos1 = i, pos2 = j;
            else if(str[i] == 97 || str[i] == 101 || str[i] == 105
                || str[i] == 111 || str[i] == 117)
                pos1 = i, j--;
            else if(str[j] == 97 || str[j] == 101 || str[j] == 105
                || str[j] == 111 || str[j] == 117)
                pos2 = j, i++;
            else
                i++, j--;
            if(pos1 != -1 && pos2 != -1)
            {
                cout << pos1 << " " << pos2 << endl;
                swap(str[pos1], str[pos2]), i++, j--, pos1 = -1, pos2 = -1;
            }
        }
        cout << str << endl;
    }
    return 0;
}
