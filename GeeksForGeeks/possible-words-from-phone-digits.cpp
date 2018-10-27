/*
Possible words from Phone digits

Given a keypad as shown in diagram, and an N digit number. List all words which are possible by pressing these numbers.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input.
The first line of each test case is N, N is the number of digits. The second line of each test case contains D[i], N number of digits.

Output:
Print all possible words from phone digits with single space.

Constraints:
1 <= T <= 10
1 <= N <= 10
2 <=  D[i] <= 9

Example:
Input:
1
3
2 3 4

Output:
adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi
*/

#include <bits/stdc++.h>
using namespace std;

const string digit_arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void permute(int number[], int idx, int n, char str[])
{
    if(idx == n)
    {
        cout << str << " ";
        return;
    }
    for(int i = 0; i < digit_arr[number[idx]].length(); ++i)
    {
        str[idx] = digit_arr[number[idx]][i];
        permute(number, idx+1, n, str);
    }
}

int main()
{
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int *number = new int[n];
        for(int i = 0; i < n; ++i)
            cin >> number[i];
        char str[n+1];
        str[n] = '\0';
        permute(number, 0, n, str);
        cout << "\n";
        delete number;
    }
    return 0;
}
