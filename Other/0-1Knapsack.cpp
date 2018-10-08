#include<bits/stdc++.h>
using namespace std;

int knapSack()
{
    int i, w;
    int K[n+1][W+1];
    for(int i: n)
        for(int w: W)
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1])
}

int main()
{

}
