// LUOGU_RID: 158223797
/**
 *    author: sunkuangzheng
 *    created: 06.05.2024 17:55:11
**/
#include<bits/stdc++.h>
#ifdef DEBUG_LOCAL
#include <mydebug/debug.h>
#endif
using ll = long long;
const int N = 5e5+5;
using namespace std;
int T,n,m,u,v,dfn[N],ta[N],tot,fa[N][20],dep[N],siz[N]; vector<int> g[N];
int op(int a,int b){return (dfn[a] < dfn[b] ? a : b);}
template <class S,S (*op)(S,S)> struct stb{
    S st[20][N];
    void init(S *h){
        for(int i = 1;i <= n;i ++) st[0][i] = h[i];
        for(int j = 1;j <= __lg(n);j ++) for(int i = 1;i + (1 << j) - 1 <= n;i ++)
            st[j][i] = op(st[j-1][i],st[j-1][i+(1<<j-1)]);
    }S qry(int l,int r){
        int k = __lg(r - l + 1);
        return op(st[k][l],st[k][r-(1<<k)+1]);
    }
};stb<int,op> st;
struct S{int u,v;}tb[N];
int lca(int u,int v){
    if(u == v) return u;
    if((u = dfn[u]) > (v = dfn[v])) swap(u,v);
    return st.qry(u+1,v);
}int dis(int u,int v){return dep[u] + dep[v] - 2 * dep[lca(u,v)];}
S op(S a,S b){
    if(!a.u) return b; if(!b.u) return a;
    vector<int> acc = {a.u,a.v,b.u,b.v}; int mx = -1; S ans = {0,0};
    for(int i : acc) for(int j : acc) if(int x = dis(i,j); x > mx) mx = x,ans = {i,j};
    return ans;
}stb<S,op> ts;
void dfs(int u,int f){
    ta[dfn[u] = ++tot] = fa[u][0] = f,dep[u] = dep[f] + 1,tb[dfn[u]] = {u,u},siz[u] = 1;
    for(int i = 1;i <= 18;i ++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(int v : g[u]) if(v != f) dfs(v,u),siz[u] += siz[v];
}int kfa(int u,int k){for(int i = 18;i >= 0;i --) if((k >> i) & 1) u = fa[u][i];return u;}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i ++) cin >> u >> v,g[u].push_back(v),g[v].push_back(u);
    dfs(1,0),st.init(ta),ts.init(tb),cin >> m;
    while(m --){
        cin >> u >> v; int d = lca(u,v),x = dis(u,v),ans = 0;
        if(dep[u] < dep[v]) swap(u,v);
        int k = kfa(u,(x - 1) >> 1);
        auto qry = [&](int u,int l,int r){
            if(l > r || r < 1 || l > n) return 0;
            auto [x,y] = ts.qry(l,r);
            return max(dis(u,x),dis(u,y));
        };  cout << max(qry(u,dfn[k],dfn[k]+siz[k]-1),max(qry(v,1,dfn[k]-1),qry(v,dfn[k]+siz[k],n))) << "\n";

    }
}