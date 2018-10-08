#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    int n, b;
    while(scanf("%d", &n)!=EOF)
    {
        b = 0;
        for(int i=0; i<4; i++)
            b = ((b << 8) | ((n >> 8*i)&255));
        printf("%d converts to %d\n", n, b);
    }
    return 0;
}
