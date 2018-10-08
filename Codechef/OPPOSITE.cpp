#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        bool flag = true;
        int64 *arr = new int64[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        if(n % 2 == 1)
            flag = false;
        else
        {
            for(int i = 0; i < n/2; ++i)
            {
                int64 x = arr[i];
                int64 y = arr[n/2 + i];
                if(x == y)
                {
                    if(x < 0 && y < 0)
                        arr[i] = 1, arr[n/2 + i] = 1;
                }
                else
                {
                    if(x > 0 && y > 0)
                    {
                        flag = false;
                        break;
                    }
                    else if(x > 0)
                        arr[n/2 + i] = x;
                    else
                        arr[i] = y;
                }
            }
        }
        if(flag)
        {
            cout << "YES" << endl;
            for(int i = 0; i < n; ++i)
                cout << arr[i] << " ";
        }
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}
