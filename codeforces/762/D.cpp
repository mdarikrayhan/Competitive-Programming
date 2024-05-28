#include<bits/stdc++.h>
#define LL long long 
#ifdef ONLINE_JUDGE
#define N 500005
#else 
#define N 101
#endif
using namespace std;

LL n,m,k;
LL a[N][4];
LL f[N][4];

int main()
{
    #ifdef ONLINE_JUDGE
    #else
    freopen("F://2_1_code//C//in.txt","r",stdin);
    //freopen("F://2_1_code//C//out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin>>n;
    for(int j=1;j<=3;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][j];
        }
    }

    LL ret=a[1][1]+a[1][2]+a[1][3];
    f[1][1]=a[1][1];    
    f[1][2]=a[1][2]+f[1][1];
    f[1][3]=a[1][3]+f[1][2];

    for(int i=2;i<=n;i++)
    {
        f[i][1]=max({f[i-1][1]  ,   f[i-1][2]+a[i][2]  ,  f[i-1][3]+a[i][2]+a[i][3]})+a[i][1];
        f[i][2]=max({f[i-1][1]+a[i][1]  ,  f[i-1][2]  ,  f[i-1][3]+a[i][3]})+a[i][2];
        f[i][3]=max({f[i-1][1]+a[i][1]+a[i][2]  ,  f[i-1][2]+a[i][2]  ,  f[i-1][3]})+a[i][3];

        ret+=a[i][1]+a[i][2]+a[i][3];
        ret-=a[i-2][1]+a[i-2][2]+a[i-2][3];

        f[i][1]=max(f[i][1],f[i-2][3]+ret);
        f[i][3]=max(f[i][3],f[i-2][1]+ret);
        // return 
    }
    cout<<f[n][3]<<endl;

    // for(int j=1;j<=3;j++)
    // {
    //     for(int i=1;i<=n;i++)
    //     {
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"Hello World"<<endl;
    return 0;
}
