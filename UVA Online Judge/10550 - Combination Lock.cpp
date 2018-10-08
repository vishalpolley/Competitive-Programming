#include <iostream>
using namespace std;

int main()
{
    int d, c1, c2, c3, cnt;
    while(1)
    {
        cnt=1080;
        cin >> d >> c1 >> c2 >> c3;
        if(d==0 && c1==0 && c2==0 && c3==0)
            return 0;
        else
        {
            if((c1-d)>0)
                cnt += (40-(c1-d))*9;
            else
                cnt += (d-c1)*9;
            d=c1;
            if((c2-d)>0)
                cnt += (c2-d)*9;
            else
                cnt += (40-(d-c2))*9;
            d=c2;
            if((c3-d)>0)
                cnt += (40-(c3-d))*9;
            else
                cnt += (d-c3)*9;
            cout << cnt << "\n";
        }
    }
}
