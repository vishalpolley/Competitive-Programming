#include <iostream>
#include <cstdio>
using namespace std;

char A[10000][10000];
char a[4][10000][10000];

int check(int N, int n, int slice)
{
    int cnt = 0;
    bool flag;
    for(int i=0; i<N-n+1; i++)
    {
        for(int j=0; j<N-n+1; j++)
        {
            flag = true;
            for(int x=0; x<n; x++)
            {
                for(int y=0; y<n; y++)
                {
                    if(A[x+i][y+j]!=a[slice][x][y])
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    int N, n;
    while(scanf("%d %d", &N, &n), N || n)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cin >> A[i][j];
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin >> a[0][i][j];
        }

        int arr[4] = {0};

        // Array Rotation
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                // 90 degrees rotation
                a[1][i][j] = a[0][n-1-j][i];
                // 180 degrees rotation
                a[2][i][j] = a[0][n-1-i][n-1-j];
                // 270 degrees rotation
                a[3][i][j] = a[0][j][n-1-i];
            }
        }

        for(int i=0; i<4; i++)
        {
            arr[i] = check(N, n, i);
        }
        printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
    }
    return 0;
}
