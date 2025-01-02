#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int f[N], deg[N];
int ans;

void dfs(int u, int pre) {
    for (int v : adj[u]) {
        if (v != pre) {
            dfs(v, u);
            f[u] += f[v];
            if (f[v] == 0) {
                deg[u]++;
            }
        }
    }
    f[u] += max(0, deg[u] - 1);
}
void dfs1(int u, int pre) {
    ans = min(ans, f[u] + 1);

    for (int v : adj[u]) {
        if (v != pre) {
            int fu = f[u], degu = deg[u], fv = f[v], degv = deg[v];

            f[u] -= max(0, deg[u] - 1);
            deg[u] -= f[v] == 0;
            f[u] -= f[v];
            f[u] += max(0, deg[u] - 1);

            f[v] += f[u];
            f[v] -= max(0, deg[v] - 1);
            if (f[u] == 0) {
                deg[v]++;
            }
            f[v] += max(0, deg[v] - 1);


            dfs1(v, u);

            f[u] = fu;
            deg[u] = degu;
            f[v] = fv;
            deg[v] = degv;
        }
    }    
}
void solve() {
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        deg[i] = 0;
        f[i] = 0;
    }
    for (int i = 0; i < n - 1 ; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 1e9;
    dfs(1, 1);
    dfs1(1, 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}