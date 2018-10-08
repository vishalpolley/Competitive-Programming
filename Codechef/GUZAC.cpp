#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    bool flag;
    long int n, k, x, c, d, l_val, cnt;
    long long int s;
    cin >> t;
    while(t--)
    {
        s = 0;
        flag = false;
        cin >> n >> k >> x;
        long int* p = new long int[k];
        for(int i=0; i<k; ++i)
            cin >> p[i];
        sort(p, p+k);
        cnt = n-k;
        if(cnt > 0)
        {
            c = (x+p[0])-(p[k-1]);
            if(c > 0)
            {
                c = min(c, cnt);
                s += (c*((x+p[0]-c+1)+(x+p[0])))/2;
                cnt-=c;
            }
            c = k-1;
            while(cnt != 0)
            {
                d = p[c]-p[c-1]-1;
                if(d > 0)
                {
                    d = min(d, cnt);
                    l_val = p[c]-d;
                    cnt-=d;
                    flag=true;
                }
                c--;
            }
            if(flag == true)
            {
                c++;
                s += ((p[k-1]-l_val+1)*(p[k-1]+l_val))/2;
                for(long int i=c-1; i>=0; --i)
                    s += p[i];
            }
        }
        if(flag == false)
        {
            for(long int i=k-1; i>=0; --i)
                s += p[i];
        }
        cout << s << endl;
        delete [] p;
        p = NULL;
    }
    return 0;
}
