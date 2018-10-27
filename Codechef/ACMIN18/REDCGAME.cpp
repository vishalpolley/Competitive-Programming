#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float abs_(float x)
{
    if(x > 0)
    {
        return x;
    }

    else
    {
        return x * (-1);
    }
}

int main()
{
    //freopen("in.in", "r", stdin);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k, ans = 0;
        cin >> n >> k;

        vector <int> v;

        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;

            ans += x;

            v.push_back(x);
        }

        while(1)
        {
            sort(v.begin(), v.end());
            int avg = 0;
            int size = 0, st_ind = -1;

            for(int i = 0 ; i < n ; i++)
            {
                if(v[i] > k)
                {
                    if(st_ind == -1)
                    {
                        st_ind = i;
                    }

                    avg += v[i];
                    size++;
                }
            }

            if(size <= 1)
            {
                goto end;
            }



            avg = avg/size;
            int ind = -1;
            int chk = 999999;

            for(int i = st_ind ; i < n - 1 ; i++)
            {
                if(abs_(avg - v[i]) + abs_(avg - v[i + 1]) < chk)
                {
                    chk = abs_(avg - v[i]) + abs_(avg - v[i + 1]);
                    ind = i;
                }
            }

            int sub = v[ind] - k;
            v[ind] -= sub;
            v[ind + 1] -= sub;
            ans -= 2 * sub;
        }

        end:;

        cout << ans << endl;
    }
}
