#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using pii = pair<int, int>; 

constexpr int N = 1e5 + 10;
vector<int> adj[N];
int n, m, c, sz[N];int64_t ans;

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto x : adj[u]) {
        if (x == fa) 
            continue;
        dfs(x, u);
        sz[u] += sz[x];
    }
    ans = min(ans, 1ll * (n - sz[u]) * (n - sz[u]) + 1ll * sz[u] * sz[u]);
}

void sol() {
    cin >> n >> m >> c;ans = LONG_LONG_MAX;
    for (int i = 1;i <= n;i ++ )
        adj[i].clear();
    for (int i = 0;i < m;i ++ ) {   
        int a, b;cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << '\n';
}       

signed main() {
    cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
    int T;cin >> T;
    while (T -- ) sol();
}