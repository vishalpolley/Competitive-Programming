#include <iostream>
using namespace std;

int main()
{
    int t, k, m=0;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(s=="donate")
        {
            cin >> k;
            m += k;
        }
        else
            cout << m << "\n";
    }
    return 0;
}
