/*
Largest palindrome product
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int a) {
    int n = 0, t = a;
    while(t > 0)
        n *= 10, n += t % 10, t /= 10;
    return (n == a);
}

int solve() {
    int num, ans = 0;
    for(int i = 990; i > 99; i-=11) {
        for(int j = 999; j > 99; --j) {
            num = i*j;
            if(ans < num && isPalindrome(num)) {
                ans = num; break;
            } else if(ans > num)
                break;
        }
    }
    return ans;
}

int main() {
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 3;
    cout << solve() << endl;
    return 0;
}

