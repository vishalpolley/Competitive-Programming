/*
Remainder with 7

Given a number as string(n) , your task is to complete the function remainderWith7 which returns an integer which denotes the remainder of the number when its divided by 7.

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow . Each test case contains a number represented as string.

Output:
For each test case in a new line print the remainder when the number is divided by 7.

Constraints:
1<=T<=100
1<=length of n <=300

Example(To be used only for expected output):
Input:
2
5
8
Output:
5
1

*/

#include <bits/stdc++.h>
using namespace std;

int remainderWith7(string n)
{
    int d, rem;
    while(n.length())
    {
        d = n[0] - '0';
        if(d < 7 && n.length() == 1)
        {
            rem = d;
            break;
        }
        if(d >= 7)
        {
            rem = d - 7;
            n.erase(0, 1);
            if(rem != 0)
                n = to_string(rem) + n;
        }
        else
        {
            rem = 10 * d + (n[1] - '0');
            rem -= 7 * (rem / 7);
            n.erase(0, 2);
            if(rem != 0)
                n = to_string(rem) + n;
        }
    }
    return rem;
}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        cout << remainderWith7(s) << endl;
    }
    return 0;
}
