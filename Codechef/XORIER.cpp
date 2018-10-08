#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        uint64_t *hash_arr = new uint64_t[MAX];
        memset(hash_arr, 0, sizeof(hash_arr));
        uint64_t a, n, cnt = 1, odd_cnt = 0, even_cnt = 0, p1 = 0, p2 = 0, ans; cin >> n;
        vector <uint64_t> odd, even;
        for(uint64_t i = 0; i < n; ++i)
            cin >> a, hash_arr[a]++, (a % 2) ? odd.push_back(a) : even.push_back(a);
        odd_cnt = (odd.size() * (odd.size() - 1)) / 2;
        even_cnt = (even.size() * (even.size() - 1)) / 2;
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        odd.erase(unique(odd.begin(), odd.end()), odd.end());
        even.erase(unique(even.begin(), even.end()), even.end());
        if(odd.size() > 0)
        {
            for(uint64_t i = 1; i < uint64_t(odd.size()); ++i)
            {
                if((odd[i] ^ odd[i - 1]) == 2)
                    p1 += (hash_arr[odd[i]] * hash_arr[odd[i - 1]]);
                p1 += ((hash_arr[odd[i]]) * (hash_arr[odd[i]] - 1)) / 2;
            }
            p1 += ((hash_arr[odd[0]]) * (hash_arr[odd[0]] - 1)) / 2;
        }
        if(even.size() > 0)
        {
            for(uint64_t i = 1; i < uint64_t(even.size()); ++i)
            {
                if((even[i] ^ even[i - 1]) == 2)
                    p2 += (hash_arr[even[i]] * hash_arr[even[i - 1]]);
                p2 += ((hash_arr[even[i]]) * (hash_arr[even[i]] - 1)) / 2;
            }
            p2 += ((hash_arr[even[0]]) * (hash_arr[even[0]] - 1)) / 2;
        }
        ans = ((odd_cnt + even_cnt) - (p1 + p2));
        cout << ans << endl;
    }
    return 0;
}
