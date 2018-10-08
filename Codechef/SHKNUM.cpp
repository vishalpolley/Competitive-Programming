#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    int t, n, x, y, a, b1, b2, o1, o2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x = log2(n);
        a = pow(2, x);
        if(n > a)
        {
            y = log2(n-a);
            b1 = pow(2, y);
            b2 = pow(2, y+1);
            o1 = abs(n-(a+b1));
            o2 = abs(n-(a+b2));
            if(o1 < o2)
                cout << o1;
            else
                cout << o2;
        }
        else
            cout << 1;
        cout << endl;
    }
    return 0;
}
