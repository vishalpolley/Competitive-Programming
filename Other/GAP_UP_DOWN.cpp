#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, gap_up = 0, gap_down = 0;
    int* low = NULL;
    int* high = NULL;
    int* close = NULL;
    cin >> n;
    low = new int[n];
    high = new int[n];
    close = new int[n];
    for(int i=0; i<n; ++i)
        cin >> low[i];
    for(int i=0; i<n; ++i)
        cin >> high[i];
    for(int i=0; i<n; ++i)
        cin >> close[i];
    for(int i=1; i<n; ++i)
    {
        if(low[i] > close[i-1])
            gap_up++;
        if(high[i] < close[i-1])
            gap_down++;
    }
    cout << gap_up << ' ' << gap_down;
    delete [] low;
    delete [] high;
    delete [] close;
    low = high = close = NULL;
    return 0;
}
