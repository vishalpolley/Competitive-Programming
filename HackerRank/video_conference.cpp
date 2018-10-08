/*
Video Conference
https://www.hackerrank.com/contests/hourrank-30/challenges/video-conference
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> videoConference(vector<string> names)
{
    vector<string> ans;
    unordered_set<string> s;
    unordered_map<string, int> m;
    for(const auto& name : names)
    {
        auto it = m.find(name);
        if(it != m.end())
        {
            it->second++;
            ans.push_back(name + ' ' + to_string(it->second));
        }
        else
        {
            m[name] = 1;
            string t;
            bool inserted = false;
            for(auto c : name)
            {
                t += c;
                auto p = s.insert(t);
                if(!inserted && p.second)
                {
                    ans.push_back(t);
                    inserted = true;
                }
            }
            if(!inserted) ans.push_back(name);
        }
    }
    return ans;
}

int main()
{
    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name;
    int t; cin >> t;
    vector<string> names;
    while(t--)
        cin >> name, names.push_back(name);
    for(const auto& i : videoConference(names))
        cout << i << endl;
    return 0;
}
