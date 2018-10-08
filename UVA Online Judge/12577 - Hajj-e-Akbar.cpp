#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i=1;
    string s;
    while(1)
    {
        cin >> s;
        if(s=="*")
            break;
        else
        {
            if(s=="Hajj")
                printf("Case %d: Hajj-e-Akbar\n", i);
            else
                printf("Case %d: Hajj-e-Asghar\n", i);
            i++;
        }
    }
    return 0;
}
