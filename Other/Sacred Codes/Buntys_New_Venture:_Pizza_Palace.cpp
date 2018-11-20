/*
Bunty's New Venture: Pizza Palace

Everyone’s favorite character Bunty has opened a new pizza place, named Pizza Palace, the best in town. Bunty is trying to make the best pizza possible, but at the same time he doesn’t want to have a small selection of pizzas. He makes his pizzas out of N ingredients marked with numbers from 1 to N. All that would be simple if he could mix any ingredient with every ingredient on the pizza, but unfortunately, that is not the case. Sometimes some ingredients cannot mix and that creates additional complications for our pizza master.
There are M pairs of ingredients that cannot be on the same pizza at the same time. Given these restrictions, Bunty wants to know how many different pizzas he can make. Help him answer this question. Two pizzas are considered different if there is an ingredient of index i that is on one pizza, but not on the other.
Input Format:
The first line of input contains two integers N and M (1 <= N <= 20, 1 <= M <= 400), where N denote the number of ingredients and M denote the number of pair of ingredients which cannot be mixed. In each of the following M lines, it contains two different numbers a and  b, they represent the banning of mixing ingredients marked with a and b. (1 <= a, b <= N). All pairs of ingredients are not necessarily distinct, some pair could occur multiple times.
Constraints:
Time Limit: 1 second
Output Format:
Output contains only one line. The first and only line of output must contain the number of different pizzas given the restrictions in the task.
Sample Test Cases:
Sample Input 1:
3 2
1 2
2 3
Sample Output 1:
5
Explanation:
Bunty can make pizzas consisting of the following ingredients: None, {1}, {1,3} {2}, {3}. Notice that a pizza can be made without ingredients.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cnt = 1; cin >> n >> m;
    bool arr[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            arr[n][m] = true;
    for(int i = 0; i < m; ++i) {
        int i1, i2; cin >> i1 >> i2;
        i1 = i1-1, i2 = i2-1;
        arr[i1][i2] = false;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(arr[i][j]) cnt = cnt+1;
        }
    }
    cout << cnt;
    return 0;
}

