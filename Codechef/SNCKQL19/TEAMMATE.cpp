#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    uint64_t *fact = new uint64_t[100005];
    fact[0] = 1, fact[1] = 1;
    for(int i = 2; i < 1e5; ++i)
        fact[i] = ((fact[i-1] % MOD) * (i % MOD)) % MOD;
    while(t--)
    {
        uint64_t val = 1;
        int n; cin >> n;
        int *s = new int[n];
        map<int, int, greater<int>> _hash;
        map<int, int, greater<int>>::iterator it;
        for(int i = 0; i < n; ++i)
        {
            cin >> s[i];
            if(_hash.find(s[i]) == _hash.end())
                _hash.insert(make_pair(s[i], 1));
            else
                _hash[s[i]]++;
        }
        for(it = _hash.begin(); it != _hash.end(); ++it)
        {
            int cnt = 0;
            int value = it->second;
            while(value > 1)
            {
                val = ((val % MOD) * ((((value % MOD) * (value - 1) % MOD) / 2) % MOD)) % MOD;
                value -= 2;
                cnt++;
            }
            val = (val / fact[cnt]) % MOD;
            if(value == 1)
            {
                int value2 = (++it)->second; --it;
                if(value2 > 0)
                    val = ((val % MOD) * (value2 % MOD)) % MOD;
                (++it)->second--; --it;
            }
        }
        cout << val % MOD << endl;
        delete s;
    }
    return 0;
}
