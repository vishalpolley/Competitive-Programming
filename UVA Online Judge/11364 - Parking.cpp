#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int t, n, min_value, max_value, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        min_value = INT_MAX;
        max_value = INT_MIN;
        for(int i=0; i<n; i++)
        {
            cin >> x;
            min_value = min(min_value, x);
            max_value = max(max_value, x);
        }
        cout << (max_value-min_value)*2 << "\n";
    }
    return 0;
}
