#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define triple pair<ll, pair<ll, ll>>
#define e cout << "\n";
#define pop_count __builtin_popcountll
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define txt_input freopen("input.txt", "r", stdin);
#define txt_output freopen("output.txt", "w", stdout);
#define FastIO                  \
    ios::sync_with_stdio(NULL); \
    cin.tie(0);                 \
    cout.tie(0);
const ll MAX = 1e18L;
const ll oo = 0x3f3f3f3f;
const ll N = 2e5 + 7;
const ll mod = 1e9 + 7;
 
int n, m;
//----------------------------------------------------------------------------------------------------
vector<int> adj[N];
int sz[N], vis[N];
ll ans, arr[N], pre[2], cnt[2];
int centroid;
 
int dfs_sz(int v, int p) {
    sz[v] = 1;
    for (auto &u: adj[v]) {
        if (vis[u] || p == u)continue;
        sz[v] += dfs_sz(u, v);
    }
    return sz[v];
}
 
int get_centroid(int v, int p, int szn) {
    for (auto &u: adj[v]) {
        if (u == p || vis[u])continue;
        if (sz[u] >= szn)return get_centroid(u, v, szn);
    }
    return v;
}
 
void dfs_calc(int v, int p, bool odd, ll sum) {
    if (odd) {
        sum = (arr[v] + sum + mod) % mod;
        ans = (ans + pre[1] + (sum * cnt[1]) % mod + mod) % mod;
    } else {
        sum = (sum - arr[v] + 2 * mod) % mod;
        ans = (ans + pre[0] + (((2 * mod - sum) % mod) * cnt[0]) % mod + mod) % mod;
    }
    for (auto &u: adj[v]) {
        if (u == p || vis[u])continue;
        dfs_calc(u, v, !odd, sum);
    }
}
 
 
void dfs_update(int v, int p, bool odd, ll sum, int si) {
    if (odd) {
        sum = (arr[v] + sum + mod) % mod;
        cnt[1] += si;
        pre[1] = (pre[1] + (si * sum + mod) % mod + mod) % mod;
    } else {
        sum = (sum - arr[v] + 2ll * mod) % mod;
        cnt[0] += si;
        pre[0] = (pre[0] + ((si * -1 * sum) + mod) % mod + mod) % mod;
    }
    for (auto &u: adj[v]) {
        if (u == p || vis[u])continue;
        dfs_update(u, v, !odd, sum, si);
    }
}
 
void DFS(int v) {
    dfs_sz(v, 0);
    centroid = get_centroid(v, v, sz[v] / 2);
    vis[centroid] = 1;
    ans = (ans + arr[centroid] + mod) % mod;
    pre[0] = pre[1] = cnt[0] = cnt[1] = 0;
    pre[0] = arr[centroid];
    cnt[0] = 1;
    for (auto &u: adj[centroid]) {
        if (vis[u])continue;
        dfs_calc(u, centroid, true, 0);
        dfs_update(u, centroid, true, (-arr[centroid] + mod) % mod, 1);
    }
    for (auto &u: adj[centroid]) {
        if (vis[u])continue;
        dfs_update(u, centroid, true, (-arr[centroid] + mod) % mod, -1);
        dfs_calc(u, centroid, true, 0);
    }
    for (auto &u: adj[centroid]) {
        if (vis[u])continue;
        DFS(u);
    }
}
 
 
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i + 1];
        if (arr[i + 1] < 0)arr[i + 1] = (arr[i + 1] + mod) % mod;
    }
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
    cout << ans;
    e
}
 
//----------------------------------------------------------------------------------------------------
int main() {
    FastIO
    //   cout.precision ( 9 );
    //   cout << fixed;
    int t = 1;
    //cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
}