#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if(n <= 7)
    {
        switch(n)
        {
            case 1:
                cout << "1";
                break;
            case 2:
                cout << "1 2";
                break;
            case 3:
                cout << "2 3 1";
                break;
            case 4:
                cout << "2 1 4 3";
                break;
            case 5:
                cout << "2 3 1 5 4";
                break;
            case 6:
                cout << "2 3 1 5 6 4";
                break;
            case 7:
                cout << "2 3 1 5 6 7 4";
                break;
        }
    }
    else
    {
        cout << "2 3 1 5 6 7 ";
        int i=8;
        while(i<=n){
            i++;
        cout << "4";
        }
    }
    cout << "\n" << n << ' ';
    for(int i = 1; i < n; ++i)
        cout << i << ' ';
    return 0;
}
