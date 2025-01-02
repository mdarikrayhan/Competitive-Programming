// LUOGU_RID: 160012805
/**
 *    author: sunkuangzheng
 *    created: 24.05.2024 10:22:14
**/
#include<bits/stdc++.h>
#ifdef DEBUG_LOCAL
#include <mydebug/debug.h>
#endif
using ll = long long;
const int N = 3e5+5;
using namespace std;
int T,n,fa[N],x,top[N],siz[N],dfn[N],dep[N],son[N],tt,rt[N],t[N*4],ans,tg[N*4],tp,ti,pt,pi;
vector<int> g[N],gr[N];
pair<int,int> ts[N*40];
pair<int,char> tgs[N*40];
void dfs1(int u,int f){
    fa[u] = f,son[u] = 0,dep[u] = dep[f] + 1,siz[u] = 1;
    for(int v : g[u]) if(v != f) if(dfs1(v,u),siz[u] += siz[v],siz[v] > siz[son[u]]) son[u] = v; 
}void dfs2(int u,int tp){
    top[u] = tp,dfn[u] = ++tt; if(son[u]) dfs2(son[u],tp);
    for(int v : g[u]) if(v != fa[u] && v != son[u]) dfs2(v,v);
}void cg(int s,int x){
    ts[++tp] = {s,t[s]},t[s] = x;
    tgs[++pt] = {s,tg[s]},tg[s] = x;
}void pd(int s){if(tg[s] != -1) cg(s*2,tg[s]),cg(s*2+1,tg[s]),tgs[++pt] = {s,tg[s]},tg[s] = -1;}
void upd(int s,int l,int r,int ql,int qr,int k){
    if(ql <= l && r <= qr) return cg(s,k),void();
    int mid = (l + r) / 2; pd(s);
    if(ql <= mid) upd(s*2,l,mid,ql,qr,k);
    if(qr > mid) upd(s*2+1,mid+1,r,ql,qr,k);
    ts[++tp] = {s,t[s]},t[s] = t[s*2] + t[s*2+1];
}void upd(int u){ while(u) upd(1,1,n,dfn[top[u]],dfn[u],0),u = fa[top[u]];}
void dfs0(int u,int f){
    int ti = tp,pi = pt; upd(u),upd(1,1,n,dfn[u],dfn[u],1),ans = max(ans,t[1]);
    for(int v : gr[u]) dfs0(v,u);
    while(tp > ti){auto [x,y] = ts[tp --]; t[x] = y;}
    while(pt > pi){auto [x,y] = tgs[pt --]; tg[x] = y;}
}void los(){
    cin >> n,ans = 0;
    for(int i = 1;i <= n;i ++) g[i].clear(),gr[i].clear();
    tp = pt = tt = 0;
    for(int i = 1;i <= 4*n;i ++) t[i] = 0,tg[i] = -1;
    for(int i = 2;i <= n;i ++) cin >> x,gr[x].push_back(i);
    for(int i = 2;i <= n;i ++) cin >> fa[i],g[fa[i]].push_back(i);
    dfs1(1,0),dfs2(1,1),dfs0(1,0),cout << ans << "\n";
}int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(cin >> T;T --;) los();
}