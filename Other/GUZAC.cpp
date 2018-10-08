#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long int n, k, x, cnt;
    long long int s;
    vector <long int> vec;
    cin >> t;
    while(t--)
    {
        s = 0;
        cnt = 0;
        cin >> n >> k >> x;
        long int* p = new long int[n];
        memset(p, 0, sizeof(p));
        for(int i=0; i<n; i++)
            cout << p[i] << endl;
        for(int i=0; i<k; ++i)
            cin >> p[i];
        sort(p, p+k);
        for(long int i=p[0]; i<=x+p[0]; ++i)
        {
            if(i == p[cnt])
            {
                cnt++;
                s+=p[cnt];
                continue;
            }
            else
                vec.push_back(i);
        }
        cnt = k;
        for(vector <long int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
        {
            while(cnt < n)
            {
                s+=*it;
                cnt++;
            }
        }
        cout << s << endl;
        delete [] p;
        p = NULL;
    }
    return 0;
}
