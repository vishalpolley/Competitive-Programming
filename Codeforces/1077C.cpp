/*
C. Good Array

Let's call an array good if there is an element in the array that equals to the sum of all other elements. For example, the array a=[1,3,3,7] is good because there is the element a4=7 which equals to the sum 1+3+3.

You are given an array a consisting of n integers. Your task is to print all indices j of this array such that after removing the j-th element from the array it will be good (let's call such indices nice).

For example, if a=[8,3,5,2], the nice indices are 1 and 4:

if you remove a1, the array will look like [3,5,2] and it is good;
if you remove a4, the array will look like [8,3,5] and it is good.
You have to consider all removals independently, i. e. remove the element, check if the resulting array is good, and return the element into the array.

Input
The first line of the input contains one integer n (2≤n≤2⋅105) — the number of elements in the array a.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤106) — elements of the array a.

Output
In the first line print one integer k — the number of indices j of the array a such that after removing the j-th element from the array it will be good (i.e. print the number of the nice indices).

In the second line print k distinct integers j1,j2,…,jk in any order — nice indices of the array a.

If there are no such indices in the array a, just print 0 in the first line and leave the second line empty or do not print it at all.

Examples
inputCopy
5
2 5 1 2 2
outputCopy
3
4 1 5
inputCopy
4
8 3 5 2
outputCopy
2
1 4
inputCopy
5
2 1 2 4 3
outputCopy
0

Note
In the first example you can remove any element with the value 2 so the array will look like [5,1,2,2]. The sum of this array is 10 and there is an element equals to the sum of remaining elements (5=1+2+2).

In the second example you can remove 8 so the array will look like [3,5,2]. The sum of this array is 10 and there is an element equals to the sum of remaining elements (5=3+2). You can also remove 2 so the array will look like [8,3,5]. The sum of this array is 16 and there is an element equals to the sum of remaining elements (8=3+5).

In the third example you cannot make the given array good by removing exactly one element.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int val, ans=0;
    int64_t s, sum=0;
    vector<int> v;
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; ++i)
        cin >> val, arr.push_back({val, i+1}), sum += val;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n-1; ++i) {
        s = sum;
        s -= arr[i].first;
        s -= arr[n-1].first;
        if(s == arr[n-1].first)
            ans++, v.push_back(arr[i].second);
    }
    sum-=arr[n-1].first;
    sum-=arr[n-2].first;
    if(sum == arr[n-2].first)
        ans++, v.push_back(arr[n-1].second);
    cout << ans << "\n";
    for(auto& i : v)
        cout << i << " ";
    return 0;
}

