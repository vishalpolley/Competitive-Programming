#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x = ((((((n*567)/9)+7492)*235)/47)-498);
        cout << abs((x/10)%10) << "\n";
    }
    return 0;
}
