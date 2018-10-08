#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, v, a, b, cnt=1;
    while(1)
    {
        a=0; b=0;
        cin >> n;
        if(n==0)
            break;
        else
        {
            for(int i=0; i<n; i++)
            {
                cin >> v;
                if(v==0)
                    b++;
                else
                    a++;
            }
            printf("Case %d: %d\n", cnt, a-b);
            cnt++;
        }
    }
    return 0;
}
