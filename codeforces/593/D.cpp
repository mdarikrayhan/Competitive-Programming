#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define X first
#define Y second

const int N = 2e5+5;
int n,q;
int depth[N],parent[N],g[N];
ll a[N];
vector<int> adj[N];
int tin[N],tout[N],timer;

void dfs(int u,int p){
    tin[u] = ++timer;
    depth[u] = depth[p]+1;
    parent[u] = p;
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    tout[u] = timer;
}

int get_first(int u){
    if(a[g[u]]>1) return g[u];
    return g[u] = get_first(parent[g[u]]);
}

void work(int u,int v,ll &cv){
    // cout << u << ' ';
    u = get_first(u);
    // cout << u << ' ' << v << ' ' << cv << '\n';
    while((cv > 0) and (u != 0) and (!(tin[u] <= tin[v] and tout[u] >= tout[v]))){
        cv /= a[u];
        u = parent[u];
        u = get_first(u);
    }
}

void solve(){
    a[0] = 2;
    cin>>n>>q;
    for(int i=1;i<=n;++i) g[i] = i;
    vector<pair<int,int>> edges(n);
    vector<ll> nv(n);
    for(int i=1;i<=n-1;++i){
        int u,v; cin>>u>>v>>nv[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u,v};
    }
    dfs(1,0);
    for(int i=1;i<=n-1;++i){
        if(depth[edges[i].X]>depth[edges[i].Y]) swap(edges[i].X,edges[i].Y);
        a[edges[i].Y] = nv[i];
    }
    ll idx,c,t,u,v,val;
    while(q--){
        cin>>t;
        if(t==1){
            cin>>u>>v>>val;
            work(u,v,val);
            work(v,u,val);
            // cout << u << ' ' << v << ' ';
            cout << val << '\n';
        }
        else{
            cin>>idx>>val;
            a[edges[idx].Y] = val;
        }
    }
}

int main()
{
ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;++i){
        solve();
    }
}