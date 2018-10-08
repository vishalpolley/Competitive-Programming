#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	int n = 8, x;
	int p = pow(n, n);
	int a, lb, ub;
	vector <int> arr;
    vector<int> v;
	for(int i = 0; i < p; ++i)
        cin >> x, arr.push_back(x);
	sort(arr.begin(), arr.end());
    for(int i = 0; i < p; ++i)
        v.push_back(arr[i]);
	a=0;
	while(1)
	{
		if(a==v.size())
			break;
		lb=lower_bound(v.begin(),v.end(),v[a])-v.begin();
		ub=upper_bound(v.begin(),v.end(),v[a])-v.begin();
		cout<<v[a]<<" occurs "<<(ub-lb)<<" times.\n";
		a=ub;
	}
}

