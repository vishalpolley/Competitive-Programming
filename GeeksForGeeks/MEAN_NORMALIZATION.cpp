#include <bits/stdc++.h>
using namespace std;

int bn_search(vector <double> arr, int l, int r, double x)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid-1] <= x && arr[mid] >= x)
            return mid;
        if(arr[mid] > x)
            return bn_search(arr, l, mid-1, x);
        return bn_search(arr, mid+1, r, x);
    }
    return -1;
}

int main()
{
//    freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l_index = 0;
    double p, t, min_t = DBL_MAX;
    double* x_arr = NULL;
    vector <double> p_vec;
    cin >> n;
    x_arr = new double[n];
    for(int i=0; i<n; ++i)
    {
        double s = 0;
        cin >> m;
        for(int j=0; j<m; ++j)
        {
            cin >> p;
            s += p;
            p_vec.push_back(p);
        }
        x_arr[i] = s/m;
    }
    sort(x_arr, x_arr+n);
    sort(p_vec.begin(), p_vec.end());
    double* pre_arr = new double[p_vec.size()];
    pre_arr[0] = p_vec[0];
    for(int i=1; i<int(p_vec.size()); ++i)
        pre_arr[i] = pre_arr[i-1] + p_vec[i];
    for(int i=0; i<n; i++)
    {
        t = 0;
        l_index = bn_search(p_vec, l_index, p_vec.size(), x_arr[i]);
        t += (l_index * x_arr[i]) - pre_arr[l_index - 1];
        t += (pre_arr[int(p_vec.size()) - 1] - pre_arr[l_index - 1]) - ((int(p_vec.size()) - l_index) * x_arr[i]);
        if(t < min_t)
            min_t = t;
    }
    cout << fixed << setprecision(12) << min_t << endl;
    delete [] x_arr;
    delete [] pre_arr;
    x_arr = pre_arr = NULL;
    return 0;
}
