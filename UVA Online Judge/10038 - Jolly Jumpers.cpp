#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 30005

bool b[MAX];

int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    int n, curr;
    while(scanf("%d", &n)!=EOF)
    {
        scanf("%d", &curr);
        memset(b, 0, sizeof(b));
        int v, pre;
        bool chk = 1;
        pre = curr;
        for(int i=1; i<n; i++)
        {
            scanf("%d", &curr);
            v = abs(curr-pre);
            if(v<=0 || v>n-1)
                chk = 0;
            else if(b[v]==1)
                chk = 0;
            b[v] = 1;
            pre = curr;
        }
        if(chk)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
