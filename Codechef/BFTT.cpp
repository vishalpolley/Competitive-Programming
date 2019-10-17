#include <bits/stdc++.h>
using namespace std;

long int count_3(long int n)
{
    long int cnt = 0;
    while(n != 0)
    {
        if(n%10 == 3)
            cnt++;
        n/=10;
    }
    return cnt;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long int n, cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt = 0;
        for(int i=1; i<=1000, cnt < 3; ++i)
        {
            n++;
            cnt = count_3(n);
        }
        cout << n << endl;
    }
    return 0;
}
