#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(bool prime[])
{
    vector<int> vec;
    for(int p = 2; p * p <= 100; ++p)
    {
        if(prime[p])
        {
            for(int i = p * 2; i <= 100; i += p)
                prime[i] = false;
        }
    }
    for(int i = 2; i <= 100; ++i)
        if(prime[i]) vec.push_back(i);
    return vec;
}

int main()
{
//    freopen("../../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec;
    set<int> s, s1, ans;
    set<int>::iterator sit, sit1;
    vector<int>::iterator it1, it2;
    bool prime[100];
    memset(prime, true, sizeof(prime));
    vec = sieveOfEratosthenes(prime);
    for(it1 = vec.begin(); it1 != vec.end(); ++it1)
    {
        for(it2 = vec.begin(); it2 != vec.end(); ++it2)
        {
            if(*it1 == *it2)
                continue;
            int val = (*it1) * (*it2);
            if(val <= 200)
                s.insert(val);
        }
    }
    for(sit = s.begin(); sit != s.end(); ++sit)
    {
        for(sit1 = s.begin(); sit1 != s.end(); ++sit1)
        {
            int val = *sit + *sit1;
            if(val <= 200)
                s1.insert(val);
        }
    }
    for(int i = 1; i <= 200; ++i)
        if(s1.find(i) == s1.end())
            ans.insert(i);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(ans.find(n) == ans.end())
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}

