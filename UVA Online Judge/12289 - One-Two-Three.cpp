#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(s.length()==5)
            cout << "3\n";
        else if((s[0]=='t' && s[1]=='w') || (s[0]=='t' && s[2]=='o') || (s[1]=='w' && s[2]=='o'))
            cout << "2\n";
        else
            cout << "1\n";
    }
    return 0;
}
