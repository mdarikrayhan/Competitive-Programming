// LUOGU_RID: 157511863
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <class Miaowu>
inline void in(Miaowu &x){
    char c;x=0;bool f=0;
    for(c=getchar();c<'0'||c>'9';c=getchar())f|=c=='-';
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
    x=f?-x:x;
}
const int N=1e3+5;
int n,m;
bool awa[N],qaq[N];
ll a[N],val[N],ans[N];
vector<int>g[N];
namespace Dinic{
    const ll inf=4e18;
    const int TN=2e3+5,TM=2e4+5;
    bool vis[TN];
    ll sum,dis[TN];
    int S,T,tot,head[TN],cur[TN],de[TN];
    struct Edge{int to,nxt;ll fl,cst;}e[TM];
    inline void clear(){
        sum=0,tot=1;
        memset(head,0,sizeof head); 
    }
    inline void addedge(int u,int v,ll fl,ll w){
        e[++tot]=Edge{v,head[u],fl,w},head[u]=tot;
        e[++tot]=Edge{u,head[v],0,-w},head[v]=tot;
    }
    inline bool spfa(){
        queue<int>Q;
        memset(dis,0x3f,sizeof dis);
        Q.push(S),dis[S]=0,vis[S]=1;
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            vis[u]=0;
            for(int i=head[u];i;i=e[i].nxt){
                int v=e[i].to;
                if(e[i].fl&&dis[v]>dis[u]+e[i].cst){
                    dis[v]=dis[u]+e[i].cst,de[v]=de[u]+1;
                    if(!vis[v])vis[v]=1,Q.push(v);
                }
            }
        }
        return dis[T]<inf;
    }
    inline ll dfs(int u,ll fl){
        if(u==T)return fl;
        ll res=0;
        for(int &i=cur[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].fl&&de[v]==de[u]+1&&dis[v]==dis[u]+e[i].cst){
                ll qwq=dfs(v,min(fl,e[i].fl));
                res+=qwq,fl-=qwq,e[i].fl-=qwq,e[i^1].fl+=qwq;
                sum+=qwq*e[i].cst;
                if(fl==0)break;
            }
        }
        return res;
    }
    inline pair<ll,ll> Flow(){
        ll flow=0;
        while(spfa()){
            memcpy(cur,head,sizeof cur);
            flow+=dfs(S,inf);
        }
        return make_pair(flow,sum);
    }
    inline void getcut(int u){
        if(awa[u])return;
        awa[u]=1;
        for(int i=head[u];i;i=e[i].nxt)
            if(e[i].fl)getcut(e[i].to);
    }
}
inline void solve(ll l,ll r,vector<int>vc){
    if(vc.size()==0)return;
    if(l==r){
        for(int x:vc)ans[x]=l;
        return;
    }
    ll mid=l+r>>1;
    for(int x:vc)val[x]=abs(a[x]-mid)-abs(a[x]-mid-1);
    Dinic::S=n+1,Dinic::T=n+2;
    Dinic::clear();
    for(int i=1;i<=n;i++)qaq[i]=0;
    for(int x:vc)qaq[x]=1;
    for(int x:vc){
        if(val[x]>=0){
            Dinic::addedge(n+1,x,val[x],0);
        }
        else{
            Dinic::addedge(x,n+2,-val[x],0);
        }
        for(int v:g[x]){
            if(qaq[v])Dinic::addedge(x,v,Dinic::inf,0);
        }
    }
    Dinic::Flow();
    memset(awa,0,sizeof awa);
    Dinic::getcut(n+1);
    vector<int>vc1,vc2;
    for(int i=1;i<=n;i++){
        if(!qaq[i])continue;
        if(val[i]>=0){
            if(!awa[i])vc1.push_back(i);
            else vc2.push_back(i);
        }
        else{
            if(awa[i])vc2.push_back(i);
            else vc1.push_back(i);
        }
    }
    solve(l,mid,vc1);
    solve(mid+1,r,vc2);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)in(a[i]);
    for(int i=1,u,v;i<=m;i++)in(u),in(v),g[u].push_back(v);
    vector<int>vc;
    for(int i=1;i<=n;i++)vc.push_back(i);
    solve(-1e15,1e15,vc);
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}