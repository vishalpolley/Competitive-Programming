#include <iostream>
using namespace std;

int main()
{
    int* a = NULL;
    int n;
    cin >> n;
    a = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=1; i<n; i++)
    {
        if(abs(a[i]-a[i-1])>1)
        {
            cout << "NO";
            goto step;
        }
    }
    cout << "YES";
    step: delete [] a;
    a = NULL;
    return 0;
}
