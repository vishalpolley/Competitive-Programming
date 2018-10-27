#include <iostream>
#include <cstring>
#include <tr1/unordered_map>

using namespace std;

int main()
{
//    freopen("in.in", "r", stdin);

    int t;
    cin >> t;

    while(t--)
    {
        tr1 :: unordered_map <int, int> ar;

        string s;
        cin >> s;

        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {
                int left = i - s[i] + '0';
                int right = i + s[i] - '0';

                //cout << left << " " << right << endl;

                for(int j = left ; j < i ; j++)
                {
                    ar[j]++;
                }

                for(int  j = i ; j <= right ; j++)
                {
                    ar[j]++;
                }
            }
        }

        int ch = 1;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(ar[i] > 1)
            {
                ch = 0;
            }
            //cout << ar[i] << " ";
        }

        if(ch)
        {
            cout << "safe" << endl;
        }

        else
        {
            cout << "unsafe" << endl;
        }
        //cout << endl;
    }
}
