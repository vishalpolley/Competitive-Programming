#include <iostream>
using namespace std;

int main()
{
    int i=0;
    string s;
    while(i<10)
    {
        cout << i << "\n" << flush;
        getline(cin, s);
        if(s=="cool" || s=="great!" || s=="don't think so" || s=="don't touch me" || s=="not bad")
        {
            cout << "normal";
            return 0;
        }
        if(s=="terrible" || s=="don't even" || s=="are you serious?" || s=="go die in a hole" || s=="worse" || s=="no way")
        {
            cout << "grumpy";
            return 0;
        }
        i++;
    }
}
