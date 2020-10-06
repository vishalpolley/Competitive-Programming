#include <iostream>
using namespace std;

int main()
{
    int* a = NULL;
    int n,i=0;
    cin >> n;
    a = new int[n];
   while(i<n)
   {
       cin>>a[i];
       i++;
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
