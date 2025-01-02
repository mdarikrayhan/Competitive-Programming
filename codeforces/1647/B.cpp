#include <iostream>
using namespace std;
const int N=107;
char map[N][N];
int main(void)
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>map[i][j];
            }
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m-1;j++)
                if(map[i][j]+map[i+1][j]+map[i][j+1]+map[i+1][j+1]==48+3*49)
                    goto f;
        cout<<"YES\n";
        continue;
        f:;
        cout<<"NO\n";
    }
    return 0;
}