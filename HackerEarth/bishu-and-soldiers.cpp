#include <bits/stdc++.h>
using namespace std;

void _swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int _partition(vector<int> arr, int _start, int _end) {
    int pivot = _end;
    int pIndex = _start;
    for(int i = _start; i < _end-1; ++i) {
        if(arr[i] <= pivot) {
            _swap(&arr[i], &arr[pIndex]);
            pIndex = pIndex+1;
        }
    }
    _swap(&arr[pIndex], &arr[_end]);
    return pIndex;
}

void _sort(vector<int> arr, int _start, int _end) {
    if(_start < _end) {
        int pIndex = _partition(arr, _start, _end);
        _sort(arr, _start, pIndex-1);
        _sort(arr, pIndex+1, _end);
    }
}

int binarySearch(vector<int> arr, int _start, int _end, int p) {s
    if(_start <= _end) {
        int mid = _start+(_end-_start)/2;
        if(arr[mid] == p)
            return mid;
        else if(arr[mid] > p)
            return binarySearch(arr, _start, mid-1, p);
        else
            return binarySearch(arr, mid+1, _end, p);
    }
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> sum(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    _sort(arr, 0, n);
    sum[0] = arr[0];
    for(int i = 1; i < n; ++i)
        sum[i] = sum[i-1]+arr[i];
    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        int p; cin >> p;
        int idx = binarySearch(arr, 0, n, p);
        cout << idx << " " << sum[idx] << "\n";
    }
    return 0;
}

