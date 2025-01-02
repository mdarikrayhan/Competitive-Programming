// LUOGU_RID: 160509488
#include <bits/stdc++.h>

using namespace std;

// #define int long long 
struct E {
    int u,v,w,c,id;
}; 
bool operator<(const E& a, const E& b) { if (a.w!=b.w) return a.w<b.w; return a.c<b.c; }
vector<E> e;
int n, m, k, ans;
vector<int> sol;

int check(int mid, vector<int>& sol) {
    int cnt=0; ans=0; sol.clear();
    auto ed=e;
    for (auto& [u,v,w,c,id]: ed) if (!c) w-=mid;
    vector<int> fa(n+1); for (int i=1; i<=n; ++i) fa[i]=i;
    function<int(int)> get=[&](int x) { return fa[x]==x?x:fa[x]=get(fa[x]); };
    sort(ed.begin(),ed.end());
    for (auto& [u,v,w,c,id]: ed) {
        u=get(u); v=get(v); 
        if (u==v) continue; 
        ans+=w; cnt+=!c; fa[u]=v; sol.push_back(id);
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1,u,v,w,c; i<=m; ++i) cin>>u>>v>>w, e.push_back({u,v,w,!(u==1||v==1),i});
    int l=-1e5, r=1e5;
    while (l<r) {
        int mid=(l+r)>>1;
        if (check(mid,sol)>=k) r=mid;
        else l=mid+1;
    }
    int cnt=check(l,sol); set<int> st(sol.begin(),sol.end());
    vector<vector<int>> g(n+1);
    vector<int> fa(n+1), val(n+1), vis(n+1); for (int i=1; i<=n; ++i) fa[i]=i;
    function<int(int)> get=[&](int x) { return fa[x]==x?x:fa[x]=get(fa[x]); };
    for (auto &[u,v,w,c,id]: e) {
        if (!c) w-=l;
        if (st.count(id)) {
            g[u].push_back(v);
            g[v].push_back(u);
            if (!c) {
                if (u<v) swap(u,v);
                val[u]=w; vis[u]=id;
            }
        }
    }
    function<void(int,int,int)> dfs=[&](int u, int cur, int f) {
        fa[u]=cur;
        for (auto v: g[u]) if (v!=f) { dfs(v,cur,u); }
    };
    for (auto v: g[1]) dfs(v,v,1);
    sort(e.begin(),e.end());
    if (cnt>k) for (auto [u,v,w,c,id]: e) {
        if (!c || st.count(id)) continue;
        int p=get(u), q=get(v);
        if (p==q) continue;
        if (val[p]==w) {
            fa[p]=q; --cnt;
            st.erase(vis[p]); vis[p]=0;
            st.insert(id);
        }
        else if (val[q]==w) {
            fa[q]=p; --cnt;
            st.erase(vis[q]); vis[q]=0;
            st.insert(id);
        }
        if (cnt<=k) break;
    }
    if(cnt!=k || st.size()<n-1) return cout<<-1, 0;
    cout<<n-1<<'\n';
    for (auto i: st) cout<<i<<' ';
    
}