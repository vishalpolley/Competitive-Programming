#include <cstdio>
using namespace std;

int ls[100005], rs[100005];

int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    int s, b, l, r;
    while(scanf("%d %d", &s, &b), s || b)
    {
        for(int i=1; i<=s; i++)
        {
            ls[i] = i-1;
            rs[i] = i+1;
        }
        ls[1]=-1;
        rs[s]=-1;
        for(int i=0; i<b; i++)
        {
            scanf("%d %d", &l, &r);
            ls[rs[r]] = ls[l];
            if(ls[l]!=-1)
                printf("%d ", ls[l]);
            else
                printf("* ");
            rs[ls[l]] = rs[r];
            if(rs[r]!=-1)
                printf("%d\n", rs[r]);
            else
                printf("*\n");
        }
        printf("-\n");
    }
    return 0;
}
