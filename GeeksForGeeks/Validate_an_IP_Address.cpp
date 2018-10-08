/*
Validate an IP Address

Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in
dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 .
The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 0 to 255 and
any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string ip
as its only argument .

Input:
The first line of each test case contains an integer T denoting the number of test case . Then T test cases follow .
Each test case takes a string ip.

Output:
For each test case output will be 1 if the string is a valid ip address else 0.

Constraints:
1<=T<=100
1<=length of string <=50

Example(To be used only for expected output) :
Input
4
222.111.111.111
5555..555
0000.0000.0000.0000
1.2.3.04

Output
1
0
0
0
*/

#include <bits/stdc++.h>
using namespace std;

bool validateIP(string str)
{
    string t;
    int cnt = 0;
    for(auto c : str)
    {
        if((c < 48 || c > 57) && c != 46)
            return 0;
        if(c != '.')
            t += c;
        else
        {
            if(t.empty())
                return 0;
            if(t.length() > 3 || t.length() == 0)
                return false;
            if(stoi(t) < 0 || stoi(t) > 255)
                return false;
            if(t.length() != to_string(stoi(t)).length())
                return false;
            t = "";
            cnt++;
        }
    }
    if(cnt == 3 && !t.empty())
    {
        if(t.length() > 3 || t.length() == 0)
                return false;
        if(t.length() != to_string(stoi(t)).length())
                return false;
        if(stoi(t) >= 0 && stoi(t) <= 255)
            return true;
    }
    return false;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        cout << validateIP(str) << endl;
    }
    return 0;
}
