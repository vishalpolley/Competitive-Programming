/*
Convert to Roman No

Given an integer n your task is to complete the function convertToRoman which prints the corresponding roman number of n .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a single integer n.

Output:
For each test case in a new line output will be the roman number representation of n.

Constraints:
1<=T<=100
1<=n<4000

Example:
Input
2
5
3
Output
V
III
*/

void convertToRoman(int n)
{
    string ans;
    string R[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    while(n > 0)
    {
        if(n / 1000)
            ans += 'M', n -= 1000;
        else if(n / 900)
            ans += "CM", n -= 900;
        else if(n / 500)
            ans += 'D', n -= 500;
        else if(n / 400)
            ans += "CD", n -= 400;
        else if(n / 100)
            ans += 'C', n -= 100;
        else if(n / 90)
            ans += "XC", n -= 90;
        else if(n / 50)
            ans += 'L', n -= 50;
        else if(n / 40)
            ans += "XL", n -= 40;
        else if(n / 10)
            ans += 'X', n -= 10;
        else
            ans += R[n-1], n = 0;
    }
    cout << ans;
}
