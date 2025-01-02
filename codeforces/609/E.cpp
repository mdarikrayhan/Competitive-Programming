#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define all(v) v.rbegin(), v.rend()
const int MAX = 3e5 + 5, LOGMAX = 21, oo = 1e18 + 9, MOD = 998244353;

int n, m;

struct DSU{
    int par[MAX];
    void init(){
        memset(par, -1, sizeof(par));
    }
    int get(int a){
        if(par[a] < 0) return a;
        return par[a] = get(par[a]);
    }
    bool unite(int u, int v){
        u = get(u);
        v = get(v);
        if(u == v) return 0;
        if(-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return 1;
    }
};

vector<pii> g[MAX];
int in[MAX], out[MAX];
array<int, 2> par[LOGMAX][MAX];

int t = 1;
void dfs(int node, int p){
    in[node] = t++;
    for(pii to : g[node]){
        if(to.first == p) continue;
        par[0][to.first][0] = node;
        par[0][to.first][1] = to.second;
        dfs(to.first, node);
    }
    out[node] = t++;
}

bool isA(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}

int lift(int u, int v){
    if(isA(u, v)) return 0;
    int mx = 0;
    for(int j = LOGMAX - 1; j >= 0; j--){
        if(!isA(par[j][u][0], v)){
            mx = max(mx, par[j][u][1]);
            u = par[j][u][0];
        }
    }
    return max(mx, par[0][u][1]);
}

int ans[MAX];
DSU dsu;
void solve(){
    cin >> n >> m;
    vector<array<int, 4>> E;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        E.push_back({w, u, v, i});
    }
    dsu.init();
    sort(E.begin(), E.end());
    int sum = 0;
    for(auto e : E){
        if(dsu.unite(e[1], e[2])){
            g[e[1]].push_back({e[2], e[0]});
            g[e[2]].push_back({e[1], e[0]});
            sum += e[0];
            ans[e[3]] = 1;
        }
    }
    par[0][1][0] = 1;
    dfs(1, 1);
    for(int j = 1; j < LOGMAX; j++){
        for(int i = 1; i <= n; i++){
            int a = par[j - 1][i][0];
            par[j][i][0] = par[j - 1][a][0];
            par[j][i][1] = max(par[j - 1][i][1], par[j - 1][a][1]);
        }
    }
    for(auto e : E){
        if(ans[e[3]]) ans[e[3]] = sum;
        else{
            ans[e[3]] = sum - max(lift(e[1], e[2]), lift(e[2], e[1])) + e[0];
        } 
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
}       
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--) solve();
}