// LUOGU_RID: 160538738
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=605;
int n,x,y,head[N],to[N],nxt[N],cnt,fa[N];
inline void add(int u,int v){to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;}
int dep[N],m,s[N],ct[N][2],cts[N];
vector<int> ps[N][2];
void dfs(int u)
{
    dep[u]=dep[fa[u]]+1,s[dep[u]]++,m=max(m,dep[u]);
    if(head[u]) ct[dep[u]][1]++,ps[dep[u]][1].push_back(u);
    else ct[dep[u]][0]++,ps[dep[u]][0].push_back(u);
    for(int i=head[u];i;i=nxt[i]) dfs(to[i]);
}
int tot,siz[M],val[M];bool f[M][N],ans[N];
inline void work1()
{
    for(int i=tot;i;i--)
    {
        if(x>=siz[i]*val[i]&&f[i-1][x-siz[i]*val[i]])
            x-=siz[i]*val[i],cts[val[i]]+=siz[i];
    }
    for(int i=1;i<=m;i++)
    {
        if(!cts[s[i]]) continue;
        for(int j=0;j<2;j++)
            for(auto k:ps[i][j])
                ans[k]=1;
        cts[s[i]]--;
    }
    cout<<m<<"\n";
    for(int i=1;i<=n;i++)
        cout<<(ans[i]?'a':'b');
    exit(0);
}
inline void work2()
{
    cout<<m+1<<"\n";
    for(int i=1;i<=m;i++)
    {
        int nw=0;int* x=&::y;
        if(::x>=y) nw=1,x=&::x;
        for(auto p:ps[i][1])
            ans[p]=nw;
        *x-=ct[i][1];
        if(*x>=ct[i][0])
        {
            for(auto p:ps[i][0])
                ans[p]=nw;
            *x-=ct[i][0];
        }
        else
        {
            for(int j=0;j<*x;j++)
                ans[ps[i][0][j]]=nw;
            for(int j=*x;j<ct[i][0];j++)
                ans[ps[i][0][j]]=(nw^1),(nw?y:(::x))--;
            *x=0;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<(ans[i]?'a':'b');
    exit(0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>x;y=n-x;    
    for(int i=2;i<=n;i++)
        cin>>fa[i],add(fa[i],i);
    dfs(1);
    for(int i=1;i<=m;i++)
        cts[s[i]]++;
    for(int i=1;i<=n;i++)
    {
        if(!cts[i]) continue;
        for(int j=1;j<=cts[i];j<<=1)
            cts[i]-=j,++tot,siz[tot]=j,val[tot]=i;
        if(cts[i]) ++tot,siz[tot]=cts[i],val[tot]=i;
        cts[i]=0;
    }f[0][0]=1;
    for(int i=1;i<=tot;i++)
    {
        int nw=siz[i]*val[i];
        for(int j=0;j<=n;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=nw&&f[i-1][j-nw])
                f[i][j]=1;
        }
    }
    if(f[tot][x]) work1();
    else work2();
    return 0;
}