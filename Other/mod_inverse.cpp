#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i = 1; i < 100; ++i)
    {
        if((7*i) % 26 == 1)
        {
            cout << i << endl;
            break;
        }
    }
}
