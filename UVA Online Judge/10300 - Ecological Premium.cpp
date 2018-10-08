#include <iostream>
using namespace std;

int main()
{
    int n, s, a, e, f;
    long long cnt;
    cin >> n;
    while(n--)
    {
        cnt=0;
        cin >> f;
        for(int i=0; i<f; i++)
        {
            cin >> s >> a >> e;
            cnt += s*e;
        }
        cout << cnt << "\n";
    }
    return 0;
}

