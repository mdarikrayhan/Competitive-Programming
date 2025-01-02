// LUOGU_RID: 159722830
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int inf=1e9+7;
int n;
int s,t;
int dd[N];
int cc[N];
int fir[N],nex[3*N],to[3*N],w[3*N],cnt=1;
int lst[N],ttp[N],in[N];
vector<int>g[N],f[N];
vector<pair<int,int> >eg;
int id=0;
void insert(int u,int v,int c)
{
    nex[++cnt]=fir[u];
    fir[u]=cnt;
    to[cnt]=v;
    w[cnt]=c;
}
void add(int x,int y,int z)
{
    insert(x,y,z);
    insert(y,x,0);
}
bool bfs()
{
    memset(dd,-1,sizeof(dd));
    dd[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=fir[u];i;i=nex[i])
        {
            int v=to[i];
            if(w[i]&&dd[v]==-1)
            {
                dd[v]=dd[u]+1;
                q.push(v);
            }
        }
    }
    if(dd[t]!=-1)return 1;
    return 0;
}
int dinic(int u,int fl)
{
    int res=fl;
    if(u==t)return fl;
    for(int i=fir[u];i&&res;i=nex[i])
    {
        int v=to[i],c=w[i];
        if(c&&dd[v]==dd[u]+1)
        {
            int tp=min(min(res,c),dinic(v,min(res,c)));
            if(tp==0)
            {
                dd[v]=-1;
            }
            res-=tp;
            w[i]-=tp;
            w[i^1]+=tp;
        }
    }
    return fl-res;
}
void dfs(int u)
{

    for(int i=0;i<f[u].size();i++)
    {
        int v=f[u][i];
        if(cc[v]==0)dfs(v);
        cc[u]=cc[v];
    }
    if(cc[u]==0)
    {
        cc[u]=++id;
        lst[id]=u;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        eg.push_back({x,y});
        add(x,y+n,1);
    }
    s=0;
    t=2*n+1;
    for(int i=1;i<=n;i++)
    {
        add(s,i,1);
        add(i+n,t,1);

    }
    int ans=0;
    while(bfs())
    {
        int flow;
        while(flow=dinic(s,inf))ans+=flow;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=fir[i];j;j=nex[j])
        {
            int v=to[j];
            if(w[j]==0&&v>n&&v<t)
            {
                f[i].push_back(v-n);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(cc[i]==0)
        {
            dfs(i);
            ttp[cc[i]]=i;
        }
        
    }
    for(int i=0;i<eg.size();i++)
    {
        if(cc[eg[i].first]!=cc[eg[i].second])
        {
            in[cc[eg[i].second]]++;
            g[cc[eg[i].first]].push_back(cc[eg[i].second]);
        }
    }
    queue<int>q;
    for(int i=1;i<=id;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    
    }
    vector<int>a;
    while(!q.empty())
    {
        int u=q.front();
        a.push_back(u);
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            in[v]--;
            if(in[v]==0)q.push(v);
        }
    }
    cout<<(int)(a.size())-1<<'\n';
    for(int i=1;i<a.size();i++)
    {
        cout<<lst[a[i-1]]<<' '<<ttp[a[i]]<<'\n';
    }
}