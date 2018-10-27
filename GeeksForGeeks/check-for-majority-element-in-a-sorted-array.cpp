#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;
        if((mid == 0 || x > arr[mid-1]) && x == arr[mid])
            return mid;
        else if(x > arr[mid])
            return binarySearch(arr, mid+1, high, x);
        else
            return binarySearch(arr, low, mid-1, x);
    }
    return -1;
}

bool majorityElement(int arr[], int n, int x)
{
    int i = binarySearch(arr, 0, n-1, x);
    if(i == -1)
        return false;
    if((i + n/2) <= (n-1) && arr[i + n/2] == x)
        return true;
    else
        return false;
}

int main()
{
    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int *arr = new int[n];
//    vector<int> vec;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
//        vec.push_back(arr[i]);
    }
//    vec.resize(distance(vec.begin(), unique(vec.begin(), vec.end())));
    for(int i = 0; i < n; ++i)
        if(majorityElement(arr, n, arr[i])) {cout << arr[i] << endl; break;};
    delete arr;
    return 0;
}
