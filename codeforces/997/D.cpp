// LUOGU_RID: 159990869
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 4005
#define mod 998244353
#define int ll
using namespace std;
int re()
{
    int x=0;
    #ifndef ONLINE_JUDGE
    scanf("%d",&x);
    return x;
    #endif
    bool t=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
        t=ch=='-'?0:t,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?x:-x;
}
int m;
void update(int *f,int *g)
{
    for(int i=0;i<=m;i++)
        f[i]=0;
    f[0]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=i;j++)
            f[i]=(f[i]+f[i-j]*g[j])%mod;
}
int n,n1,n2,ans;
int f[maxn][80],g[maxn][80],h1[80],h2[80];
vector<int>e[maxn];
void upd(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    if(x<0)x+=mod;
}
int ksm(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=ret*x%mod;
        x=x*x%mod,y>>=1;
    }
    return ret;
}
namespace ZH
{
    int jc[maxn],inv[maxn];
    void zh_init()
    {
        jc[0]=1;
        for(int i=1;i<=n;i++)
            jc[i]=jc[i-1]*i%mod;
        inv[n]=ksm(jc[n],mod-2);
        for(int i=n;i;i--)
            inv[i-1]=inv[i]*i%mod;
    }
    int A(int x,int y)
    {
        if(x<y)return 0;
        return jc[x]*inv[x-y]%mod;
    }
    int C(int x,int y)
    {
        return A(x,y)*inv[y]%mod;
    }
}
using namespace ZH;
void dfs(int pos,int fa)
{
    for(int v:e[pos])
    {
        if(v==fa)continue;
        dfs(v,pos);
        for(int i=1;i<=m;i++)
            upd(g[pos][i],f[v][i-1]);
    }
    update(f[pos],g[pos]);
}
void rdfs(int pos,int fa)
{
    for(int i=1;i<=m;i++)
        upd(g[pos][i],f[fa][i-1]);
    update(f[pos],g[pos]);
    for(int i=0;i<=m;i++)
        upd(h1[i],f[pos][i]);
    for(int v:e[pos])
    {
        if(v==fa)continue;
        for(int i=1;i<=m;i++)
            upd(g[pos][i],-f[v][i-1]);
        update(f[pos],g[pos]);
        rdfs(v,pos);
        for(int i=1;i<=m;i++)
            upd(g[pos][i],f[v][i-1]);
    }
    for(int i=1;i<=m;i++)
        upd(g[pos][i],-f[fa][i-1]);
    update(f[pos],g[pos]);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n1=re(),n2=re(),m=re();
    if(m&1)return puts("0"),0;
    n=m;
    zh_init();
    m>>=1;
    n=n1;
    for(int i=1;i<n;i++)
    {
        int u=re(),v=re();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    rdfs(1,0);
    memcpy(h2,h1,sizeof h1);
    mclear(h1);
    mclear(g);
    for(int i=1;i<=n;i++)
        e[i].clear();
    n=n2;
    for(int i=1;i<n;i++)
    {
        int u=re(),v=re();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    rdfs(1,0);
    for(int i=0;i<=m;i++)
        ans=(ans+h1[i]*h2[m-i]%mod*C(m<<1,i<<1))%mod;
    printf("%lld",ans);
    return 0;
}