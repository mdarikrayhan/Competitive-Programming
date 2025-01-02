#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 2005
#define int ll
using namespace std;
int re()
{
    int x=0;
    bool t=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
        t=ch=='-'?0:t,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?x:-x;
}
int n,mod;
int f[maxn][maxn],g[maxn],ans[maxn],lef[maxn],rig[maxn];
vector<int>e[maxn];
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
void upd(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    if(x<0)x+=mod;
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
    }
    int sum=0;
    for(int i=1;i<n;i++)
    {
        int ss=1,cnt=0;
        for(int v:e[pos])
        {
            if(v==fa)continue;
            ss=ss*f[v][i]%mod;
            cnt++;
            lef[cnt]=rig[cnt]=f[v][i];
        }
        lef[0]=rig[cnt+1]=1;
        for(int i=1;i<=cnt;i++)
            lef[i]=lef[i-1]*lef[i]%mod;
        for(int i=cnt;i;i--)
            rig[i]=rig[i+1]*rig[i]%mod;
        upd(sum,ss);
        f[pos][i]=-(cnt-1)*sum%mod;
        cnt=0;
        for(int v:e[pos])
        {
            if(v==fa)continue;
            cnt++;
            g[v]=(g[v]+lef[cnt-1]*rig[cnt+1])%mod;
            f[pos][i]=(f[pos][i]+f[v][i]*g[v])%mod;
        }
    }
}
signed main()
{
    n=re(),mod=re();
    zh_init();
    for(int i=1;i<n;i++)
    {
        int u=re(),v=re();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=0;i<n;i++)
        ans[i]=1;
    for(int v:e[1])
    {
        dfs(v,1);
        for(int i=0;i<n;i++)
            ans[i]=ans[i]*f[v][i]%mod;
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<i;j++)
            ans[i]=(ans[i]-C(i,j)*ans[j])%mod;
    for(int i=1;i<n;i++)
    {
        upd(ans[i],0);
        printf("%lld ",ans[i]);
    }
    return 0;
}
  			   		 		 	  		   		   	  	