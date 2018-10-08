#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n, x, y;
    string s;
    map<int, int> coord;
    map<int, int>::iterator it;
    while(scanf("%d", &n), n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> s >> x >> y;
            coord.insert(pair <int, int> (x, y));
        }
        for(it=coord.begin(); it!=coord.end(); it++)
        {
            d = sqrt(pow(abs(it1->first-it2->first), 2)+pow(abs(it1->second-it2->second), 2));
            cout << d << endl;
        }
        coord.clear();
    }
    return 0;
}
