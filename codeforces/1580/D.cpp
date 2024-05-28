// LUOGU_RID: 160524169
#include<bits/stdc++.h>
using namespace std;
const int N=4e3+5;
typedef long long LL;
int n,m,top,stk[N],a[N];
int l[N],r[N],siz[N];
void build()
{
    for (int i=1;i<=n;i++)
    {
        int k=top;
        while (k&&a[stk[k]]>a[i]) k--;
        if (k) r[stk[k]]=i;
        if (k<top) l[i]=stk[k+1];
        stk[top=++k]=i;
    }
}
LL f[N][N],g[N];
void dfs (int u) 
{
	f[u][1]=1ll*(m-1)*a[u],siz[u]=1;
    if (l[u])
    {
        dfs(l[u]);
        for (int i=1;i<=siz[u];i++) g[i]=f[u][i];
        for (int i=0;i<=siz[u];i++)
            for (int j=0;j<=siz[l[u]];j++)
            {
                f[u][i+j]=max(f[u][i+j],g[i]+f[l[u]][j]-1ll*i*j*a[u]*2);
            }
        siz[u]+=siz[l[u]];
    }
    if (r[u])
    {
        dfs(r[u]);
        for (int i=1;i<=siz[u];i++) g[i]=f[u][i];
        for (int i=0;i<=siz[u];i++)
            for (int j=0;j<=siz[r[u]];j++)
            {
                f[u][i+j]=max(f[u][i+j],g[i]+f[r[u]][j]-1ll*i*j*a[u]*2);
            }
        siz[u]+=siz[r[u]];
    }

}
void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build();
    dfs(stk[1]);
    cout<<f[stk[1]][m];
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T=1;
  // cin>>T;
    while (T--) solve();
    return 0;
}