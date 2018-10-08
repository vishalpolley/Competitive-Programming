#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    float phi;
    cin >> n;
    phi = n;
    if(n%2 == 0)
        phi*=(1.0 -(1.0 / 2.0));
    if(n%3 == 0)
        phi*=(1.0 -(1.0 / 3.0));
    if(n%5 == 0)
        phi*=(1.0 -(1.0 / 5.0));
    if(n%7 == 0)
        phi*=(1.0 -(1.0 / 7.0));
    if(n%11 == 0)
        phi*=(1.0 -(1.0 / 11.0));
    if(n%13 == 0)
        phi*=(1.0 -(1.0 / 13.0));
    cout << int(phi);
    return 0;
}
