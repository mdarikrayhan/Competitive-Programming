#include "bits/stdc++.h"
#ifdef DEBUG
#include "PrettyDebug.hpp"
#else
#define debug(...) [](){}()
#define debuga(...) [](){}()
#endif
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
#define fi first
#define se second
using namespace std; typedef long long ll; using pii = pair<int,int>;
// Oracle takes a vector of elements and returns whether it's independent
// Returns the minimum cost, and a vector of the result
template<class ValT,class Or1,class Or2>
pair<ValT,vector<int>> MincostMatroidIntersect(int n,vector<ValT> cost,Or1& Oracle1,Or2& Oracle2){
    vector<int> vis(n);
    while(true){
        vector<vector<int>> to(n);
        vector<int> qwq; For(i,0,n-1) if(vis[i]) qwq.push_back(i);
        For(u,0,n-1) if(vis[u]){
            qwq.erase(find(qwq.begin(),qwq.end(),u));
            Oracle1.prepare(qwq); Oracle2.prepare(qwq);
            For(v,0,n-1) if(!vis[v]){
                if(Oracle1.predict(v)) to[u].push_back(v);
                if(Oracle2.predict(v)) to[v].push_back(u);
            }
            qwq.push_back(u);
        }
        vector<int> X1(n),X2(n),inq(n),lst(n,-1); queue<int> q; vector<pair<ValT,int>> dis(n,make_pair(numeric_limits<ValT>::max(),0));
        Oracle1.prepare(qwq); Oracle2.prepare(qwq);
        For(u,0,n-1) if(!vis[u]){
            if(Oracle1.predict(u)) X1[u]=1,q.push(u),inq[u]=1,dis[u]=make_pair(cost[u],0);
            if(Oracle2.predict(u)) X2[u]=1;
        }
        while(q.size()){
            int u=q.front(); q.pop(); inq[u]=0;
            for(int v:to[u]){
                auto e=make_pair(dis[u].first+(vis[v]?-cost[v]:cost[v]),dis[u].second+1);
                if(dis[v]>e) { dis[v]=e; lst[v]=u; if(!inq[v]) inq[v]=1,q.push(v); }
            }
        }
        auto mn=make_pair(numeric_limits<ValT>::max(),0); int O=-1;
        For(u,0,n-1) if(X2[u]&&dis[u]<mn) mn=dis[u],O=u;
        if(O==-1) break;
        while(O!=-1) vis[O]^=1,O=lst[O];
    }
    ValT total=0; vector<int> ans; For(i,0,n-1) if(vis[i]) ans.push_back(i),total+=cost[i];
    return make_pair(total,ans);
}
constexpr int N=55,M=505;
class DSU{
    int n,fa[N];
public:
    void init(int _n) { n=_n; iota(fa+1,fa+1+n,1); }
    // int getfa(int x) { return x==fa[x]?x:fa[x]=getfa(fa[x]); }
    int getfa(int x) { while(x!=fa[x]) x=fa[x]=fa[fa[x]];; return x; }
    bool merge(int x,int y) { x=getfa(x),y=getfa(y); fa[y]=x; return x!=y; }
}O;
int n,K,d[N],G[N][N],a[M],b[M],cnt,ta[N],tb[N],tcnt,ans,deg[N];
void dfs(int X,int Y){
    if(X==K){
        O.init(K); For(i,1,tcnt) if(!O.merge(ta[i],tb[i])) return;
        For(i,1,K) deg[i]=0;; For(i,1,tcnt) if(++deg[ta[i]]>d[ta[i]]||++deg[tb[i]]>d[tb[i]]) return;
        vector<int> cost(cnt); For(i,0,cnt-1) cost[i]=G[a[i]][b[i]];
        struct{
            void prepare(const vector<int>& A){
                O.init(n); For(i,1,tcnt) O.merge(ta[i],tb[i]);
                for(int e:A) assert(O.merge(a[e],b[e]));
            }
            bool predict(int e){
                return O.getfa(a[e])!=O.getfa(b[e]);
            }
        }Oracle1;
        struct{
            void prepare(const vector<int>& A){
                For(i,1,K) deg[i]=0;
                For(i,1,tcnt) deg[ta[i]]++,deg[tb[i]]++;
                for(int e:A) deg[a[e]]++,deg[b[e]]++;
            }
            bool predict(int e){
                return deg[a[e]]!=d[a[e]]&&deg[b[e]]!=d[b[e]];
            }
        }Oracle2;
        auto [res,vec]=MincostMatroidIntersect(cnt,cost,Oracle1,Oracle2);
        For(i,1,tcnt) res+=G[ta[i]][tb[i]];
        if(vec.size()+tcnt==n-1u) ans=min(ans,res);
        return;
    }
    if(Y==K) dfs(X+1,X+2); else dfs(X,Y+1);
    tcnt++; ta[tcnt]=X; tb[tcnt]=Y;
    if(Y==K) dfs(X+1,X+2); else dfs(X,Y+1);
    tcnt--;
}
signed main(){
    // Fin("data.in");
    atexit([](){cerr<<"Time = "<<clock()<<" ms"<<endl;});
    cin>>n>>K; For(i,1,K) cin>>d[i];; For(i,1,n) For(j,i+1,n) cin>>G[i][j];
    For(i,K+1,n) d[i]=1e9;
    O.init(n); vector<pii> vec; For(i,K+1,n) For(j,i+1,n) vec.emplace_back(i,j);
    sort(vec.begin(),vec.end(),[&](pii A,pii B){return G[A.fi][A.se]<G[B.fi][B.se];});
    for(auto [x,y]:vec) if(O.merge(x,y)) a[cnt]=x,b[cnt]=y,cnt++;
    For(i,1,K) For(j,K+1,n) a[cnt]=i,b[cnt]=j,cnt++;
    ans=1e9; dfs(1,2); cout<<ans<<'\n';
    return 0;
}

// CONTINUE, NON-STOPPING, FOR CHARLIEY
// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING

// Started Coding On: May 09 Thu, 15 : 37 : 35