#include <iostream>
using namespace std;

int main()
{
    int t, n, m, lat, lon;
    while(1)
    {
        cin >> t;
        if(t==0)
            return 0;
        else
        {
            cin >> n >> m;
            for(int i=0; i<t; i++)
            {
                cin >> lat >> lon;
                if(lat==n || lon==m)
                    cout << "divisa" << "\n";
                else if(lat>n)
                {
                    if(lon>m)
                        cout << "NE" << "\n";
                    else
                        cout << "SE" << "\n";
                }
                else if(lat<n)
                {
                    if(lon>m)
                        cout << "NO" << "\n";
                    else
                        cout << "SO" << "\n";
                }
            }
        }
    }
}
