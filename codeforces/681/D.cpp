// LUOGU_RID: 159869218
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int>g[maxn];
int p[maxn][25],a[maxn];
int dep[maxn],f[maxn][25];
bool pd;
bool rt[maxn],vis[maxn];
vector<int>ans;
void dfs0(int u,int fa)
{
    dep[u]=dep[fa]+1;
    int i;
    p[u][0]=a[u];
    f[u][0]=fa;
    for(i=1;i<20;i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(i=1;i<20;i++)
    {
        int o=p[f[u][i-1]][i-1];
        if(o!=p[u][i-1])
        {
            p[u][i]=0;
        }
        else
        {
            p[u][i]=p[u][i-1];
        }
    }
    for(i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)
        {
            continue;
        }
        dfs0(v,u);
    }
}
bool ask(int u,int d)
{
    int i;
    for(i=19;i>=0;i--)
    {
        if(d>=(1<<i))
        {
            d-=(1<<i);
            if(p[u][i]!=a[u])
            {
                return 0;
            }
            u=f[u][i];
        }
    }
    return 1;
}
void go(int u,int fa,int val)
{
    if(!ask(u,dep[u]-dep[a[u]]))
    {
        pd=1;
        return;
    }
    int i;
    for(i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)
        {
            continue;
        }
        go(v,u,val);
    }
    if(vis[u])
    {
        ans.push_back(u);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        rt[v]=1;
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[a[i]]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(!rt[i])
        {
            dfs0(i,0);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!rt[i])
        {
            go(i,0,0);
        }
    }
    if(pd)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
