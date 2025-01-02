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
int n, m;
//----------------------------------------------------------------------------------------------------
vector<int> adj[N];
int sz[N], arr[N], vis[N], cc[20];
ll ans[N], cnt[1 << 20];
string s;
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
 
ll dfs_calc(int v, int p, int mask) {
    mask ^= arr[v];
    ll ret = cnt[mask];
    for (int i = 0; i < 20; ++i) {
        ret += cnt[mask ^ cc[i]];
    }
    for (auto &u: adj[v]) {
        if (u == p || vis[u])continue;
        ret += dfs_calc(u, v, mask);
    }
    ans[v] += ret;
    return ret;
}
 
 
void dfs_update(int v, int p, int mask, int va) {
    mask ^= arr[v];
    cnt[mask] += va;
    for (auto &u: adj[v]) {
        if (u == p || vis[u])continue;
        dfs_update(u, v, mask, va);
    }
 
}
 
void DFS(int v) {
    dfs_sz(v, 0);
    centroid = get_centroid(v, v, sz[v] / 2);
    cnt[arr[centroid]] = 1;
    vis[centroid] = 1;
    for (auto &u: adj[centroid]) {
        if (vis[u])continue;
        ans[centroid] += dfs_calc(u, centroid, 0);
        dfs_update(u, centroid, arr[centroid], 1);
    }
    cnt[arr[centroid]]--;
    for (auto &u: adj[centroid]) {
        if (vis[u])continue;
        dfs_update(u, centroid, arr[centroid], -1);
        dfs_calc(u, centroid, 0);
    }
    for (auto &u: adj[centroid]) {
        if (vis[u])continue;
        DFS(u);
    }
}
 
 
void solve() {
    cin >> n;
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s;
    for (int i = 0; i < 20; ++i) {
        cc[i] = (1 << i);
    }
    for (int i = 0; i < n; ++i) {
        arr[i + 1] = cc[s[i] - 'a'];
        ans[i + 1] = 1;
    }
    DFS(1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i + 1] << " ";
    }
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