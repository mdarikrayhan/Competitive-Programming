#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> pi;

typedef long long ll;

namespace flow{
    const int N=4e5+5, M=6e5+5, inf=1e9;
    struct edge{
        int v, w, nxt;
    };
    int n,S,T;
    edge E[M*2]; int bg[N], tot=2;
    int dis[N], cur[N];
    void link(int u,int v,int w){
        E[tot]={v, w, bg[u]}; bg[u]=tot++;
        E[tot]={u, 0, bg[v]}; bg[v]=tot++;
    }
    bool bfs(){
        rep(i,1,n){
            dis[i]=-1, cur[i]=bg[i];
        }
        queue<int> Q;
        dis[S]=0, Q.push(S);
        while(!Q.empty()){
            int u=Q.front(); Q.pop();
            for(int id=bg[u]; id; id=E[id].nxt){
                int v=E[id].v, w=E[id].w;
                if(w && dis[v]==-1){
                    dis[v]=dis[u]+1;
                    Q.push(v);
                }
            }
        }
        return dis[T]!=-1;
    }
    int dfs(int u,int rst){
        if(u==T){
            return rst;
        }
        int pre=rst;
        for(int &id=cur[u]; id; id=E[id].nxt){
            int v=E[id].v, w=E[id].w;
            if(w && dis[v]==dis[u]+1){
                int f=dfs(v, min(rst, w));
                E[id].w-=f, E[id^1].w+=f, rst-=f;
                if(!rst){
                    break;
                }
            }
        }
        return pre-rst;
    }
    int dinic(){
        int res=0;
        while(bfs()){
            res+=dfs(S, inf);
        }
        return res;
    }
    bool vis0[N], vis1[N];
    void getvis(){
        queue<int> Q0, Q1;
        Q0.push(S), Q1.push(T);
        vis0[S]=1, vis1[T]=1;
        while(!Q0.empty()){
            int u=Q0.front(); Q0.pop();
            for(int id=bg[u]; id; id=E[id].nxt){
                int v=E[id].v, w=E[id].w;
                if(w!=0 && !vis0[v]){
                    vis0[v]=1;
                    Q0.push(v);
                }
            }
        }
        while(!Q1.empty()){
            int u=Q1.front(); Q1.pop();
            for(int id=bg[u]; id; id=E[id].nxt){
                int v=E[id].v, w=E[id].w;
                if(w==0 && !vis1[v]){
                    vis1[v]=1;
                    Q1.push(v);
                }
            }
        }
    }
    int reduce(int id){
        int u=E[id*2+1].v, v=E[id*2].v;
        if(vis0[v]){
            return -v;
        }
        else{
            return u;
        }
    }
}

signed main(){
    #ifndef ONLINE_JUDGE
    assert(freopen(".in","r",stdin));
    // assert(freopen(".out","w",stdout));
    #endif

    int n1,n2,m,q; cin>>n1>>n2>>m>>q;
    flow::n=n1+n2+2, flow::S=n1+n2+1, flow::T=n1+n2+2;
    rep(i,1,m){
        int u,v; cin>>u>>v;
        flow::link(u, v+n1, 1);
    }
    rep(i,1,n1){
        flow::link(flow::S, i, 1);
    }
    rep(i,1,n2){
        flow::link(n1+i, flow::T, 1);
    }
    int get=flow::dinic();
    flow::getvis();
    vi match;
    rep(i,1,n1){
        for(int id=flow::bg[i]; id; id=flow::E[id].nxt){
            int v=flow::E[id].v, w=flow::E[id].w;
            if(v>=n1+1 && v<=n1+n2 && w==0){
                match.pb(id/2);
            }
        }
    }
    ll sum=0;
    for(int x:match){
        sum+= x;
    }
    rep(i,1,q){
        int op; cin>>op;
        if(op==1){
            int id=match.back();
            match.pop_back();
            sum-= id;
            int ver=flow::reduce(id);
            if(ver<0){
                ver+=n1;
            }
            cout<<1<<'\n';
            cout<<ver<<'\n';
            cout<<sum<<'\n';
        }
        else{
            cout<<match.size()<<'\n';
            for(int x:match){
                cout<<x<<' ';
            }
            cout<<endl;
        }
    }
}