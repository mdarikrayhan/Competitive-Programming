#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 100005
#define mod 1000000007
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
struct Linear_basis
{
    int a[5];
    Linear_basis()
    {
        mclear(a);
    }
    int operator [] (const int x)
    {
        return a[x];
    }
    void to_typical()
    {
        for(int i=0;i<5;i++)
            for(int j=i+1;j<5;j++)
                if(a[j]>>i&1)
                    a[j]^=a[i];
    }
    int get()
    {
        to_typical();
        int ret=0;
        for(int i=0;i<5;i++)
            ret=ret<<i+1|a[i];
        return ret;
    }
    void ins(int x)
    {
        while(x)
        {
            int y=__lg(x);
            if(!a[y])
                a[y]=x;
            x^=a[y];
        }
    }
    bool fi(int x)
    {
        while(x)
        {
            int y=__lg(x);
            if(!a[y])
                return 0;
            x^=a[y];
        }
        return 1;
    }
    bool add(Linear_basis& t)
    {
        for(int i=0;i<5;i++)
        {
            if(!t[i])continue;
            if(fi(t[i]))
                return 0;
            ins(t[i]);
        }
        return 1;
    }
}a;
struct Edge
{
    int v,w;
};
int n,m,ans,idx;
int can[maxn],vis[maxn],d[maxn],id[maxn],f[maxn],bac[maxn],b[maxn];
vector<Edge>e[maxn];
int newp(int x)
{
    if(!id[x])
        id[x]=++idx,b[idx]=x;
    return id[x];
}
void upd(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    if(x<0)x+=mod;
}
bool dfs(int pos,int fa,int now)
{
    if(~vis[pos])
    {
        if(a.fi(now^vis[pos]))
            return 1;
        a.ins(now^vis[pos]);
        return 0;
    }
    vis[pos]=now;
    for(auto i:e[pos])
    {
        int v=i.v,w=i.w;
        if(v==fa||d[v]>d[pos])continue;
        if(!d[v])
            d[v]=d[pos]+1;
        if(dfs(v,pos,now^i.w))
            return 1;
    }
    return 0;
}
signed main()
{
    n=re(),m=re();
    for(int i=1;i<=m;i++)
    {
        int u=re(),v=re(),w=re();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    memset(can,-1,sizeof can);
    memset(vis,-1,sizeof vis);
    for(auto i:e[1])
    {
        int v=i.v,w=i.w;
        can[v]=w;
    }
    d[1]=1e9;
    f[1]=1;
    idx=1;
    id[0]=1;
    for(int u=1;u<=n;u++)
    {
        if(can[u]==-1)continue;
        int v=0,w=0;
        for(auto i:e[u])
        {
            if(~can[i.v])
            {
                v=i.v,w=i.w^can[v]^can[u];
                can[v]=-1;
                break;
            }
        }
        mclear(a.a);
        d[u]=1;
        if(dfs(u,1,0))continue;
        for(int i=1;i<=idx;i++)
            bac[i]=f[i];
        int old=idx;
        if(!v)
        {
            for(int i=1;i<=old;i++)
            {
                Linear_basis now;
                for(int j=4,x=b[i];~j;x>>=j+1,j--)
                    now.a[j]=x&(1<<j+1)-1;
                if(now.add(a))
                {
                    int x=newp(now.get());
                    upd(f[x],bac[i]);
                }
            }
        }
        else
        {
            for(int i=1;i<=old;i++)
            {
                Linear_basis now;
                for(int j=4,x=b[i];~j;x>>=j+1,j--)
                    now.a[j]=x&(1<<j+1)-1;
                if(now.add(a))
                {
                    int x=newp(now.get());
                    upd(f[x],bac[i]*2%mod);
                }
            }
            if(!a.fi(w))
            {
                a.ins(w);
                for(int i=1;i<=old;i++)
                {
                    Linear_basis now;
                    for(int j=4,x=b[i];~j;x>>=j+1,j--)
                        now.a[j]=x&(1<<j+1)-1;
                    if(now.add(a))
                    {
                        int x=newp(now.get());
                        upd(f[x],bac[i]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=idx;i++)
        upd(ans,f[i]);
    printf("%d",ans);
    return 0;
}
			 				 	 			  	  	     	 		 	