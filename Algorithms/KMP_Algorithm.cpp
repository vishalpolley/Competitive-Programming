#include <bits/stdc++.h>
using namespace std;

void prefixTable(int P[], string str1)
{
    P[0] = 0;
    int i = 1, j = 0;
    int m = str1.length();
    while(m > i)
    {
        if(str1[i] == str1[j])
            P[i] = j+1, i++, j++;
        else if(j > 0)
            j = P[j-1];
        else
            P[i] = 0, i++;
    }
}

int KMP(string str1, string str2)
{
    int i = 0, j = 0;
    int m = str1.length();
    int n = str2.length();
    int *P = new int[m];
    prefixTable(P, str1);
    while(n > i)
    {
        if(str2[i] == str1[j])
        {
            if(j == m-1)
                return i-j;
            else
                i++, j++;
        }
        else if(j > 0)
            j = P[j-1];
        else
            i++;
    }
    delete P;
    return -1;
}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string str1, str2; cin >> str1 >> str2;
        cout << KMP(str1, str2) << endl;
    }
    return 0;
}
