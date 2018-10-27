/*
Permutations of a given string

Given a string, print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases.
Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG
Output:
ABC ACB BAC BCA CAB CBA
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA
*/
#include <bits/stdc++.h>
using namespace std;

void stringPermutations(vector<string> &ans, string str, int l, int r)
{
    if(l == r)
        ans.push_back(str);
    for(int i = l; i < r; ++i)
    {
        swap(str[l], str[i]);
        stringPermutations(ans, str, l+1, r);
        swap(str[l], str[i]); // Backtracking
    }
}

int main()
{
//    freopen("../in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        vector<string> vec;
        stringPermutations(vec, s, 0, s.length());
        sort(vec.begin(), vec.end());
        for(auto& i : vec)
            cout << i << " ";
/*        sort(s.begin(), s.end());
        do
            cout << s << " ";
        while(next_permutation(s.begin(), s.end()));
 */       cout << "\n";
    }
    return 0;
}
