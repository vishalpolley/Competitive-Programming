#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, d;
    string s;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(s=="78" || s=="1" || s=="4")
            cout << "+";
        else if(*(s.end()-2)=='3' && *(s.end()-1)=='5')
            cout << "-";
        else if(s[0]=='9' && *(s.end()-1)=='4')
            cout << "*";
        else
            cout << "?";
        cout << "\n";
    }
    return 0;
}
