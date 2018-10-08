#include <iostream>
using namespace std;

int main()
{
    int a, b, c, t, i=1;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        if((c>a && a>b) || (b>a && a>c))
            cout << "Case " << i << ": " << a << "\n";
        else if((a>b && b>c) || (c>b && b>a))
            cout << "Case " << i << ": " << b << "\n";
        else if((a>c && c>b) || (b>c && c>a))
            cout << "Case " << i << ": " << c << "\n";
        i++;
    }
    return 0;
}
