#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, flag_b, flag_o, x;
    cin >> t;
    string tf, bf;
    while(t--)
    {
        flag_b = 2;
        flag_o = 1;
        cin >> tf >> bf;
        for(int i=0; i<3; i++)
        {
            if(tf[i] == 'b' || bf[i] == 'b')
            {
                flag_b --;
                continue;
            }
            if(tf[i] == 'o' || bf[i] == 'o')
            {
                flag_o --;
                continue;
            }
        }
        if(flag_b == 0 && flag_o == 0)
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
    return 0;
}
