#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    int n, k, l, s;
    map <char, double> cm;
    map <char, double>::iterator it;
    string line;
    double m, t;
    char c;
    cin >> n;
    while(n--)
    {
        t=0;
        cin >> k;
        while(k--)
        {
            cin >> c >> m;
            cm[c]=m;
        }
        cin >> l;
        cin.ignore();
        for(int i=0; i<l; i++)
        {
            getline(cin, line);
            s = line.size();
            for(int j=0; j<s; j++)
            {
                it = cm.find(line[j]);
                if(it != cm.end())
                    t += it->second;
            }
        }
        t /=100;
        printf("%0.2lf$\n", t);
        cm.clear();
    }
    return 0;
}
