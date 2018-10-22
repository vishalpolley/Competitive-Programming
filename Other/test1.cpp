#include <bits/stdc++.h>
using namespace std;

template<typename ForwardIterator,typename T>
ForwardIterator first_less_than(ForwardIterator first, ForwardIterator last, T value)
{
    auto it = lower_bound(first, last, value);
    return (it == first ? last : --it);
}

template<typename T>
void print(T t)
{
    for(const auto& ele : t)
        cout << ele << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {1, 3, 3, 5, 7};
    vector<int> u(5);
    auto it = first_less_than(v.begin(), v.end(), 7);
    cout << (it != v.end() ? to_string(*it) : "Not Found") << endl;
    rotate_copy(v.begin(), v.begin() + 2, v.end(), u.begin());
    print(u);
    print(v);
    return 0;
}
