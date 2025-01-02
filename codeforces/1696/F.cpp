#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector f(n, std::vector<std::string>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            std::cin >> f[i][j];
            f[j][i] = f[i][j];
        }
    }
    
    for (int x = 1; x < n; x++) {
        std::vector<bool> vis(n);
        vis[0] = true;
        vis[x] = true;
        std::vector<std::pair<int, int>> edges;
        edges.emplace_back(0, x);
        auto dfs = [&](auto self, int u, int v) -> void {
            for (int i = 0; i < n; i++) {
                if (vis[i] || f[i][u][v] == '0') {
                    continue;
                }
                vis[i] = true;
                edges.emplace_back(v, i);
                self(self, v, i);
            }
        };
        dfs(dfs, 0, x);
        dfs(dfs, x, 0);
        
        if (edges.size() != n - 1) {
            continue;
        }
        
        std::vector<std::vector<int>> adj(n);
        for (auto [u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector dis(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            auto dfs = [&](auto self, int v, int p) -> void {
                for (auto u : adj[v]) {
                    if (u == p) {
                        continue;
                    }
                    dis[i][u] = dis[i][v] + 1;
                    self(self, u, v);
                }
            };
            dfs(dfs, i, -1);
        }
        
        bool ok = true;
        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) {
                for (int z = 0; z < n; z++) {
                    if ((f[x][y][z] == '1') != (dis[x][z] == dis[y][z])) {
                        ok = false;
                    }
                }
            }
        }
        if (ok) {
            std::cout << "Yes\n";
            for (auto [u, v] : edges) {
                std::cout << u + 1 << " " << v + 1 << "\n";
            }
            return;
        }
    }
    std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}