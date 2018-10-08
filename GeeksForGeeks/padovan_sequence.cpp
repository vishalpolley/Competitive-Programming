/*
Padovan Sequence

A Padovan Sequence is a sequence which is represented by the following recurrence
P(n) = P(n-2) + P(n-3)
P(0) = P(1) = P(2) = 1
Now given a number N your task is to find the Nth no in this sequence.

Note: Since the output could be very long take mod 1000000007


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer N.

Output:
For each test case in a new line print the nth no of the Padovan sequence.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
12
4
Output:
21
2
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    int *padovan = new int[101];
    padovan[0] = 1; padovan[1] = 1; padovan[2] = 1;
    for(int i = 3; i <= 100; ++i)
        padovan[i] = (padovan[i-2] % MOD + padovan[i-3] % MOD) % MOD;
    while(t--)
    {
        int n; cin >> n;
        cout << padovan[n] << endl;
    }
    delete padovan;
    return 0;
}
