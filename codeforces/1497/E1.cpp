#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//#define int long long
using namespace std;
typedef long long LL;
const int N=200010,M=10000005,K=22;
int primes[M],minp[M],cnt;
int w[N],f[K][N],buc[M],g[K][N];
void init(int n)
{
    for (int i=2;i<=n;i++)
    {
        if (!minp[i]) primes[++cnt]=minp[i]=i;
        for (int j=1;i*primes[j]<=n;j++)
        {
            minp[i*primes[j]]=primes[j];
            if (minp[i]==primes[j]) break;
        }
    }
}
void solve()
{  
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>w[i];
        int t=1;
        while (w[i]>1)
        {
            int p=minp[w[i]],cnt=0;
            while (w[i]%p==0) w[i]/=p,cnt++;
            if (cnt&1) t*=p;
        }
        w[i]=t;
    }
    for (int i=0;i<=k;i++)
    {
        for (int j=1;j<=n;j++) buc[w[j]]=0;
        for (int j=1,p=1,cnt=0;j<=n;j++)
        {
            buc[w[j]]++;
            if (buc[w[j]]>1) cnt++;
            while (cnt>i)
            {
                if (buc[w[p]]>1) cnt--;
                buc[w[p]]--;
                p++;
            }
            g[i][j]=p;
        }
    }
    for (int x=0;x<=k;x++)
    {
        for (int i=1;i<=n;i++) f[x][i]=1e9;
        for (int i=1;i<=n;i++)
            for (int y=0;y<=x;y++)
            {
                int d=x-y;
                f[x][i]=min(f[x][i],f[y][g[d][i]-1]+1);
            }
    }
    int ans=1e9;
    for (int i=0;i<=k;i++) ans=min(ans,f[i][n]);
    for (int i=1;i<=n;i++) buc[w[i]]=0;
    cout<<ans<<"\n";
}
signed main()
{
    init(M-1);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}