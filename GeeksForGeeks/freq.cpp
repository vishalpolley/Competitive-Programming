#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int arr[8];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            for(int k = 1; k <= n; ++k)
            {
                for(int l = 1; l <= n; ++l)
                {
                    for(int m = 1; m <= n; ++m)
                    {
                        for(int o = 1; o <= n; ++o)
                        {
                            for(int p = 1; p <= n; ++p)
                            {
                                for(int q = 1; q <= n; ++q)
                                {
                                    for(int z = 1; z <= n; ++z)
                                        arr[z] = z;
                                    swap(arr[1], arr[i]);
                                    swap(arr[2], arr[j]);
                                    swap(arr[3], arr[k]);
                                    swap(arr[4], arr[l]);
                                    swap(arr[5], arr[l]);
                                    swap(arr[6], arr[l]);
                                    swap(arr[7], arr[l]);
                                    swap(arr[8], arr[l]);
            //                        cout << i << ' ' << j << ' ' << k << ' ' << l << " the permutation is: " << arr[1] << ' ' << arr[2] << ' ' << arr[3] << ' ' << arr[4] << endl;
            //                        cout << arr[1] << ' ' << arr[2] << ' ' << arr[3] << endl;
                                    string s = to_string(arr[1]) + to_string(arr[2]) + to_string(arr[3]) + to_string(arr[4]) + to_string(arr[5]) + to_string(arr[6]) + to_string(arr[7]) + to_string(arr[8]);
                                    cout << s << " ";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
