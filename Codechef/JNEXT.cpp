#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    int* N = NULL;
    cin >> t;
    while(t--)
    {
        int index_1 = -1, index_2, temp = INT_MIN;
        cin >> n;
        N = new int[n];
        for(int i=0; i<n; ++i)
            cin >> N[i];
        for(int i=n-1; i>=0; --i)
        {
            if(N[i-1] >= N[i])
                continue;
            else
            {
                index_1 = i-1;
                break;
            }
        }
        if(index_1 == -1)
        {
            cout << -1 << endl;
            continue;
        }
        int diff_1, diff_2 = INT_MAX;
        for(int i=index_1+1; i<n; i++)
        {
            diff_1 = N[i] - N[index_1];
            if(diff_1 > 0 && diff_1 < diff_2)
            {
                diff_2 = diff_1;
                index_2 = i;
            }
        }
        temp = N[index_1];
        N[index_1] = N[index_2];
        N[index_2] = temp;
        sort(N+index_1+1, N+n);
        for(int i=0; i<n; ++i)
            cout << N[i];
        cout << endl;
        delete [] N;
        N = NULL;
    }
    return 0;
}
