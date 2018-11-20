/*
Gaitonde and his Seven Accomplices

Back in Bombay in 1992, Gaitonde's terror was spreading as his men take out rival gang members by the dozen. Now, Gaitonde targeted 7 areas where he wanted his rule. He makes a team of 7 accomplices for the same.
Every day at 5 pm, Gaitonde used to communicate with his accomplices and asked them about the progress they have made. Gaitonde had given a "code" to all his accomplices for communication.
Delighted by his accomplices progress, he prepares dinner for them; seven chairs, seven plates, seven forks and seven knives for seven hungry gangsters.
On the day of dinner, nine gangsters came, instead of seven (nobody knows how or why), each of them claiming to be one of Gaitonde's seven accomplices.
Luckily, each accomplice had a "code" (which Gaitonde had given them). This "code" is a positive integer less than 100. Gaitonde, a famous mathematician, realised long ago that the sum of numbers on the "code" of his seven accomplices was exactly 100. You are manager of Gaitonde and he has shared this information with you. Now, you have to decide which of the seven gangsters are legit.
Write a program which determines which gangsters are legit, i.e. pick seven of nine numbers that add to 100.
Input Format:
There are 9 lines of input. Each contains an integer between 1 and 99 (inclusive). All of the numbers will be distinct.
Note: The test data will be such that the solution is unique.
Constraints:
Time Limit: 1 second
Output Format:
Your program must produce exactly seven lines of output – the "codes" of Gaitonde's seven gangsters. Output the numbers in any order.
Sample Test Cases:
Sample Input 1:
7
8
10
13
15
19
20
23
25
Sample Output 1:
7
8
10
13
19
20
23
Explanation:
Out of the given 9 value, only these 7 values sum up to form 100.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int s) {
    for(int i = 0; i < 8; ++i) {
        for(int j = 1; j < 9; ++j) {
            if((s-arr[i]-arr[j]) == 100) {
                for(int k = 0; k < 9; ++k) {
                     if(arr[k] == arr[i] || arr[k] == arr[j]) continue;
                     else cout << arr[k] << "\n";
                }
                return;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../../in.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[9], sum = 0;
    for(int i = 0; i < 9; ++i) cin >> arr[i], sum += arr[i];
    solve(arr, sum);
    return 0;
}

