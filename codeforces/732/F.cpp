#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef set<ll> sll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {return a == 0? b: gcd(b%a,a);}
ll lcm(ll a, ll b) {return a * (b / gcd(a,b));}
#define pb(x) push_back(x)
#define rep(i, x,n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define fo(x) find_by_order(x)
#define ok(x) order_of_key(x)
ll mod = 1e9 + 7;
const int MAXLEN = 1e6;
const ll inf = 1e17;
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

void dfs(vector<vii> &adj, int u, int p, vi &dp, vi &bridge, vi &depth){
    for (auto [v, i] : adj[u]){
        if (v == p) continue;
        if (depth[v] == -1){
            depth[v] = depth[u] + 1;
            dfs(adj, v, u, dp, bridge, depth);
            dp[u] += dp[v];
            if (dp[v] == 0)
                bridge[i] = 1;
        }else if (depth[v] < depth[u]){
            dp[u]++;
            dp[v]--;
        }
    }
}

int size(vector<vii> &adj, int u, vi &vis, vi &bridge){
    vis[u] = 1;
    int cnt = 1;
    for (auto [v, i] : adj[u]) {
        if (!vis[v] && !bridge[i])
            cnt += size(adj, v, vis, bridge);
    }
    return cnt;
}

void dfs2(vector<vii> &adj, int u, int p, vi &depth, vii &ans, vi &bridge) {

    for (auto [v, i] : adj[u]) {
        if (v == p) continue;
        if (depth[v] == -1){
            depth[v] = depth[u] + 1;
            if (bridge[i])
                ans[i] = {v, u};
            else
                ans[i] = {u, v};

            dfs2(adj, v, u, depth, ans, bridge);
        }else if (depth[v] < depth[u])
            ans[i] = {u, v};
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vii> adj(n);
    vi dp(n), bridge(m), depth(n, -1), vis(n);
    depth[0] = 0;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    dfs(adj, 0, -1, dp, bridge, depth);
    int sz = -1, s = 0;
    rep(i, 0, n)
        if (!vis[i]) {
            int csz = size(adj, i, vis, bridge);
            if (csz > sz)
                sz = csz, s = i;
        }
    fill(all(depth), -1);
    depth[s] = 0;
    vii ans(m);
    dfs2(adj, s, -1, depth, ans, bridge);
    cout << sz << "\n";
    for (auto [u, v] : ans)
        cout << u + 1 << " " << v + 1 << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    while (t--)
        solve();
   return 0;
}