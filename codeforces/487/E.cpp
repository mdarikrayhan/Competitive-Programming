#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define x first
#define y second
#define pb push_back
using namespace std;
using pii=pair <int,int>;
using tii=pair <pii,int>;
using rii=pair <int,pii>;
using qii=pair <pii,pii>;
using namespace __gnu_pbds;
int n,m,q;
int w[100010];
vector <int> g[100010];
int dfn[100010],lo[100010],tme;
bool visited[100010];
stack <int> st;
vector <int> bc[200010];
int curidx;
void dfs1(int cur){
    tme++;
    dfn[cur]=lo[cur]=tme;
    visited[cur]=1;
    st.push(cur);
    for (int i:g[cur]){
        if (!visited[i]){
            dfs1(i);
            lo[cur]=min(lo[cur],lo[i]);
            if (lo[i]==dfn[cur]){
                curidx++;
                bool ok=1;
                while (ok){
                    bc[st.top()].pb(curidx);
                    bc[curidx].pb(st.top());
                    if (st.top()==i) ok=0;
                    st.pop();
                }
                bc[cur].pb(curidx);
                bc[curidx].pb(cur);
            }
        } else {
            lo[cur]=min(lo[cur],dfn[i]);
        }
    }
}
multiset <int> ms[200010];
int pa[200010],oria[200010];
void dfs2(int cur,int prv){
    pa[cur]=prv;
    for (int i:bc[cur]){
        if (i==prv) continue;
        dfs2(i,cur);
        if (cur>n) ms[cur].insert(oria[i]);
    }
    if (cur<=n) oria[cur]=w[cur];
    else oria[cur]=*ms[cur].begin();
}
int sz[200010],dep[200010],hson[200010];
void dfs3(int cur,int prv){
    sz[cur]=1;
    if (prv) dep[cur]=dep[prv]+1;
    int mxz=-1;
    for (int i:bc[cur]){
        if (i==prv) continue;
        dfs3(i,cur);
        sz[cur]+=sz[i];
        if (sz[i]>mxz){
            mxz=sz[i];
            hson[cur]=i;
        }
    }
}
int tp[200010],id[200010],a[200010];
void dfs4(int cur,int topn){
    tme++;
    id[cur]=tme;
    tp[cur]=topn;
    a[tme]=oria[cur];
    if (!hson[cur]) return;
    dfs4(hson[cur],topn);
    for (int i:bc[cur]){
        if (i==hson[cur]||i==pa[cur]) continue;
        dfs4(i,i);
    }
}
int seg[800040];
void build(int id,int tl,int tr){
    if (tl==tr){
        seg[id]=a[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*id,tl,tm);
    build(2*id+1,tm+1,tr);
    seg[id]=min(seg[2*id],seg[2*id+1]);
}
void update(int id,int tl,int tr,int pos,int val){
    if (tl==tr){
        a[pos]=val;
        seg[id]=val;
        return;
    }
    int tm=(tl+tr)/2;
    if (pos<=tm) update(2*id,tl,tm,pos,val);
    else update(2*id+1,tm+1,tr,pos,val);
    seg[id]=min(seg[2*id],seg[2*id+1]);
}
int query(int id,int tl,int tr,int l,int r){
    if (l>r) return 1e18;
    if (l<=tl&&tr<=r) return seg[id];
    int tm=(tl+tr)/2;
    int lx=query(2*id,tl,tm,l,min(r,tm));
    int rx=query(2*id+1,tm+1,tr,max(l,tm+1),r);
    return min(lx,rx);
}
void update_node(int u,int val){
    if (u!=1){
        int p=pa[u];
        ms[p].erase(ms[p].find(a[id[u]]));
        ms[p].insert(val);
        int thsval=*ms[p].begin();
        update(1,1,2*n,id[p],thsval);
    }
    update(1,1,2*n,id[u],val);
}
int query_path(int u,int v){
    int ans=1e18;
    while (tp[u]!=tp[v]){
        if (dep[tp[u]]<dep[tp[v]]) swap(u,v);
        int ths=query(1,1,2*n,id[tp[u]],id[u]);
        ans=min(ans,ths);
        u=pa[tp[u]];
    }
    if (dep[u]>dep[v]) swap(u,v);
    int ths=query(1,1,2*n,id[u],id[v]);
    ans=min(ans,ths);
    if (u>n) ans=min(ans,query(1,1,2*n,id[pa[u]],id[pa[u]]));
    return ans;
}
void solve(){
    cin>>n>>m>>q;
    for (int i=1; i<=n; i++) cin>>w[i];
    for (int i=1; i<=m; i++){
        int u,v; cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }
    curidx=n;
    dfs1(1);
    dfs2(1,0);
    dfs3(1,0);
    tme=0;
    dfs4(1,1);
    build(1,1,2*n);
    while (q--){
        char type; cin>>type;
        if (type=='A'){
            int u,v; cin>>u>>v;
            cout<<query_path(u,v)<<'\n';
        } else if (type=='C'){
            int u,val; cin>>u>>val;
            update_node(u,val);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //cin>>t;
    while (t--) solve();
}