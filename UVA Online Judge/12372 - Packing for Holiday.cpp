#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t, l, w, h, i=1;
    cin >> t;
    while(t--)
    {
        cin >> l >> w >> h;
        if(l>20 || w>20 || h>20)
            printf("Case %d: bad\n", i);
        else
            printf("Case %d: good\n", i);
        i++;
    }
    return 0;
}
