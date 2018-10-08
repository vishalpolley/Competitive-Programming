#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
    while(1)
    {
        int n, m, s, posx, posy, cnt=0;
        char mov, pos;
        cin >> n >> m >> s;
        if(n==0 && m==0 && s==0)
        {
            break;
            return 0;
        }
        char** arr = new char*[n];
        for(int i=0; i<n; i++)
            arr[i] = new char[m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j]=='N' || arr[i][j]=='S' || arr[i][j]=='L' || arr[i][j]=='O')
                {
                    pos = arr[i][j];
                    posx = i; posy = j;
                }
            }
        for(int i=0; i<s; i++)
        {
            cin >> mov;
            if(mov=='D')
            {
                if(pos=='N')
                    pos = 'L';
                else if(pos=='S')
                    pos = 'O';
                else if(pos=='L')
                    pos = 'S';
                else if(pos=='O')
                    pos = 'N';
            }
            if(mov=='E')
            {
                if(pos=='N')
                    pos = 'O';
                else if(pos=='L')
                    pos = 'N';
                else if(pos=='S')
                    pos = 'L';
                else if(pos=='O')
                    pos = 'S';
            }
            if(mov=='F')
            {
                if(pos=='N' && posx!=0 && arr[posx-1][posy]!='#')
                {
                    posx -= 1;
                    if(arr[posx][posy]=='*')
                    {
                        cnt++;
                        arr[posx][posy] = '.';
                    }
                }
                if(pos=='L' && posy!=m-1 && arr[posx][posy+1]!='#')
                {
                    posy += 1;
                    if(arr[posx][posy]=='*')
                    {
                        cnt++;
                        arr[posx][posy] = '.';
                    }
                }
                if(pos=='S' && posx!=n-1 && arr[posx+1][posy]!='#')
                {
                    posx += 1;
                    if(arr[posx][posy]=='*')
                    {
                        cnt++;
                        arr[posx][posy] = '.';
                    }
                }
                if(pos=='O' && posy!=0 && arr[posx][posy-1]!='#')
                {
                    posy -= 1;
                    if(arr[posx][posy]=='*')
                    {
                        cnt++;
                        arr[posx][posy] = '.';
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
            delete [] arr[i];
        delete [] arr;
        cout << cnt << "\n";
    }
}
