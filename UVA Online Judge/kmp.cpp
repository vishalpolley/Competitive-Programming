#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 100010

char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

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
    strcpy(T, "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN");
    strcpy(P, "SEVENTY SEVEN");
    n = (int)strlen(T);
    m = (int)strlen(P);
    printf("T = '%s'\n", T);
    printf("P = '%s'\n", P);
    printf("KMP\n");
    kmpPreprocess();
    kmpSearch();
    return 0;
}
