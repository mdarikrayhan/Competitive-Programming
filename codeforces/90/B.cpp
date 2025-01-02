#include  <bits/stdc++.h>
using namespace std;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void solve()
{
    short n,m;
    cin >> n >>m ;
    string arr[n],arr2[n];

    for(short i=0; i<n; ++i)
    {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    string word ="";

    for(short i=0; i<n; ++i)
    {
        for(short j=0; j<m; ++j)
        {
            bool flag1=0,flag2=0;
            for(short r=0; r<m; ++r)
            {
                if(j == r )
                {
                    continue;
                }
                if(arr[i][j] == arr[i][r])
                {
                    arr[i][r] = '.';
                    flag1 =1;
                }
            }
            if(flag1)
                arr[i][j]='.';

            for(short c=0; c<n; ++c)
            {
                if(i == c )
                {
                    continue;
                }
                if(arr2[i][j] == arr2[c][j])
                {
                    arr2[c][j] = '.';
                    flag2 =1;
                }
            }
            if(flag2)
                arr[i][j]='.';

            if(arr[i][j] == arr2[i][j] && arr[i][j] !='.')
                word += arr[i][j];
        }
    }
    cout << word << endl;
}


int main()
{
    fastIO();
    fastIO();

    int t=1;
    //cin >> t;
    while(t--)solve();


    return 0;
}