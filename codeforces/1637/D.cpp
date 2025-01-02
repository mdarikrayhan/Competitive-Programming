// LUOGU_RID: 159908619
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110,M=10010,INF=1e9,inf=1e18;
int a[N],b[N],f[N][M];
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++) cin>>a[i],ans+=(n-1)*a[i]*a[i];
    for (int i=1;i<=n;i++) cin>>b[i],ans+=(n-1)*b[i]*b[i];
    for (int i=1;i<=n;i++)
        for (int j=0;j<=10000;j++)
            f[i][j]=inf;
    f[0][0]=0;
    for (int i=1,s=0;i<=n;i++)
    {
        s+=a[i]+b[i];
        for (int sa=1;sa<=10000;sa++)
        {
            int sb=s-sa;
            if (sb>=1&&sb<=10000)
            {
                if (sa>=a[i]&&sb>=b[i])
                    f[i][sa]=min(f[i][sa],f[i-1][sa-a[i]]+(sa-a[i])*a[i]+
                        (sb-b[i])*b[i]);
                if (sa>=b[i]&&sb>=a[i])
                    f[i][sa]=min(f[i][sa],f[i-1][sa-b[i]]+(sa-b[i])*b[i]+
                        (sb-a[i])*a[i]);
            }
        }
    }
    int t=inf;
    for (int i=1;i<=10000;i++) t=min(t,f[n][i]);
    cout<<ans+2*t<<"\n";
}   
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}