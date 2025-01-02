#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using ll=long long;
using pil=pair<int,ll>;
const int N=1E5+10;
const ll inf=1E18;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int head[N],nex[N],to[N],w[N],n,m,s;
ll dis[N];
namespace dij1
{
    struct cmp{bool operator()(pil &x,pil &y){return x.se>y.se;}};
    priority_queue<pil,vector<pil>,cmp>q;
    void ins(int x,ll d){if(cmin(dis[x],d))q.emplace(x,d);}
    void work()
    {
        for(int i=1;i<=n;++i)dis[i]=inf;
        ins(1,0);
        while(!q.empty())
        {
            auto [x,d]=q.top();
            q.pop();
            if(d^dis[x])continue;
            for(int i=head[x];i;i=nex[i])ins(to[i],d+w[i]);
        }
        for(int i=1;i<=n;++i)if(dis[i]==inf)dis[i]=-1;
    }
}
namespace dij2
{
    int h[N];
    vector<int>q[N];
    void ins(int x,int t){if(cmin(h[x],t))q[t].eb(x);}
    void work(int c)
    {
        for(int i=1;i<=n;++i)h[i]=c+1;
        ins(1,0);
        for(int i=0;i<=c;++i)while(!q[i].empty())
        {
            int x=q[i].back();
            q[i].pop_back();
            if(i^h[x])continue;
            for(int j=head[x];j;j=nex[j])ins(to[j],dis[x]+i+w[j]-dis[to[j]]);
        }
        for(int i=1;i<=n;++i)if(~dis[i])dis[i]+=h[i];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=1,u,v;i<=m;++i)
    {
        cin>>u>>v>>w[i];
        nex[i]=head[u];
        head[u]=i;
        to[i]=v;
    }
    dij1::work();
    while(s--)
    {
        if(read()&1)cout<<dis[read()]<<'\n';
        else
        {
            int c=read();
            for(int i=c;i--;++w[read()]);
            dij2::work(min(c,n-1));
        }
    }
    return 0;
}
