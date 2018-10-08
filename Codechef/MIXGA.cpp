#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, x;
    cin >> t;
    while(t--)
    {
        x = 0;
        char vanja = '+';
        cin >> n >> k;
        int* arr = new int[n];
        for(int i=0; i<n; ++i)
            cin >> arr[i];
        for(int i=0; i<n; ++i)
        {
            if(arr[i] == 0)
                continue;
            if((i+1)%2 == 1) // Vanja
            {
                if(x > 0)
                {
                    x++;
                    vanja = '+';
                }
                else if(x < 0)
                {
                    x--;
                    vanja = '-';
                }
                else if(x == 0)
                    x++;
            }
            else            // Miksi
            {
                if(x > 0)
                    x--;
                else if(x < 0)
                    x++;
                else if(x == 0)
                {
                    if(vanja == '-')
                        x++;
                    else if(vanja == '+')
                        x--;
                }
            }
        }
        if(abs(x) >= k)
            cout << 1;
        else
            cout << 2;
        cout << endl;
        delete [] arr;
        arr = NULL;
    }
    return 0;
}
