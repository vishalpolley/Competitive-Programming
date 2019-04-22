#include <bits/stdc++.h>
using namespace std;

/*
5
2 5 1 3 4
*/

void removeConsecutiveDuplicates(char *input) {
    int i=0;
    while(input[i+1] != '\0') {
        if(input[i] == input[i+1]) {
            int j=i;
            while(input[j+1] != '\0')
                input[j] = input[j+1], j++;
            input[j] = '\0';
        }
        else
            i++;
    }
}


int main() {
    freopen("../in.in", "r", stdin);
    int n; cin >> n;
    char arr[n];
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    removeConsecutiveDuplicates(arr);
    return 0;
}
