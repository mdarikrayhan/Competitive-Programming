#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    std::vector<std::vector<std::pair<int, int>>> G(n);
    auto check = [&](int r) -> bool {
        std::vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (G[i].size() % 2) {
                odd.emplace_back(i);
            }
        }
        if (odd.size() > 2) {
            return false;
        }
        if (odd.size() == 2 && odd[0] != r && odd[1] != r) {
            return false;
        }

        std::vector<bool> vis(n);
        vis[r] = true;
        std::queue<int> q;
        q.emplace(r);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto &[v, id] : G[u]) {
                if (vis[v]) {
                    continue;
                }
                q.emplace(v);
                vis[v] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i] && G[i].size() > 0) {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        std::set<int> S;
        for (auto &[v, id] : adj[i]) {
            if (adj[v].size() % 2) {
                S.insert(v);
            }
        }

        for (int j = 0; j <= adj[i].size(); j++) {
            int x = -1;
            if (j < adj[i].size()) {
                x = adj[i][j].first;
            }
            G.assign(n, std::vector<std::pair<int, int>>());
            for (int k = 0; k < n; k++) {
                for (auto &[v, id] : adj[k]) {
                    if ((x == v && k == i) || (i == v && k == x) || !((S.count(k) && v == i) || (S.count(v) && k == i))) {
                        G[k].emplace_back(v, id);
                    }
                }
            }
            if (check(i)) {
                std::vector<bool> used(m);
                std::vector<int> nxt(n), ans;
                std::function<void(int)> dfs = [&](int u) -> void {
                    while (nxt[u] < G[u].size()) {
                        auto &[v, id] = G[u][nxt[u]];
                        nxt[u]++;
                        if (used[id]) {
                            continue;
                        }
                        used[id] = true;
                        dfs(v);
                    }
                    ans.emplace_back(u);
                };
                dfs(i);
                ans.emplace_back(-2);
                for (auto v : S) {
                    if (v == x) {
                        continue;
                    }
                    ans.emplace_back(v);
                    ans.emplace_back(i);
                }
                std::cout << ans.size() << "\n";
                for (int i = 0; i < ans.size(); i++) {
                    std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
                }
                return 0;
            }
        }
    }
    std::cout << 0 << "\n";

    return 0;
}