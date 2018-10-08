#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 100010

char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;

void kmpPreprocess()
{
    int i = 0, j = -1; b[0] = -1;
    while(i < m)
    {
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch()
{
    int i = 0, j = -1;
    while(i < n)
    {
        while(j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if(j == m)
        {
            printf("P is found at index %d in T\n", i - j);
            j = b[j];
        }
    }
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int len;
    char s[1000005];
    while(scanf("%s", &s) == 1)
    {
        len = strlen(s);
        if(!strcmp(s, ".")) break;
        strcpy(T, s);
        printf("%s\n", T);
    }
    return 0;
}
