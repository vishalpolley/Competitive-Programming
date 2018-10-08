#include <bits/stdc++.h>
using namespace std;

int bn_search(float arr[], int l, int r, int k)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid-1] <= k && arr[mid] >= k)
            return mid;
        if(arr[mid] > k)
            return bn_search(arr, l, mid-1, k);
        return bn_search(arr, mid+1, r, k);
    }
    return -1;
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num, n, q, k, index;
    cin >> n;
    int* pre_sum = new int[n];
    float* avg_sum = new float[n];
    for(int i=0; i<n; ++i)
    {
        cin >> num;
        if(i==0)
            pre_sum[0] = num;
        else
            pre_sum[i] = pre_sum[i-1] + num;
    }
    sort(pre_sum, pre_sum+n);
    for(int i=0; i<n; ++i)
        avg_sum[i] = float(pre_sum[i])/(i+1);
    cin >> q;
    while(q--)
    {
        cin >> k;
        index = bn_search(avg_sum, 0, n, k);
        if(index == -1)
            cout << n << endl;
        else
            cout << index << endl;
    }
    delete [] pre_sum;
    delete [] avg_sum;
    pre_sum = NULL;
    avg_sum = NULL;
    return 0;
}
