/*
Smallest multiple
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    ll ans = arr[0];
    for(int i = 1; i < n; ++i) {
        ans = (ans*arr[i]) / gcd(ans, arr[i]);
    }
    return ans;
}

int main() {
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << lcm(n) << endl;
    return 0;
}
