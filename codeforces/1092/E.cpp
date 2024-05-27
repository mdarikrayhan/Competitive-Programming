#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct DSU {
    int n, cnt;
    vector<int> fa, sz;
    DSU(int n = 0) : n(n), cnt(n), fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }
    int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            // if (sz[u] < sz[v]) { swap(u, v); }
            sz[u] += sz[v];
            fa[v] = u;
            cnt--;
            return true;
        }
        return false;
    }
    bool same(int u, int v) { return find(u) == find(v); }
    int size(int u) { return sz[find(u)]; }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto solve = [&]() {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        DSU d(n);

        auto addEdge = [&](int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            d.join(u, v);
        };

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            addEdge(u, v);
        }

        vector<int> dis(n, -1);

        auto work = [&](int r) {
            vector<int> q, dis(n, -1);

            auto bfs = [&](int s) {
                dis.assign(n, -1);
                q = {s};
                dis[s] = 0;

                for (int i = 0; i < q.size(); i++) {
                    int u = q[i];
                    for (auto v : adj[u]) {
                        if (dis[v] == -1) {
                            dis[v] = dis[u] + 1;
                            q.push_back(v);
                        }
                    }
                }

                return max_element(dis.begin(), dis.end()) - dis.begin();
            };

            int x = bfs(r);
            int y = bfs(x);
            int d = dis[y];
            auto dx = dis;
            bfs(y);
            auto dy = dis;

            int c = -1;
            for (auto u : q) {
                if (dx[u] == d / 2 && dy[u] == d - d / 2) {
                    c = u;
                    break;
                }
            }

            return pair(d, c);
        };

        vector<pair<int, int>> comps;

        for (int i = 0; i < n; i++) {
            if (d.find(i) == i) {
                comps.emplace_back(work(i));
            }
        }

        sort(comps.rbegin(), comps.rend());
        vector<pair<int, int>> ans;

        for (int i = 1; i < comps.size(); i++) {
            addEdge(comps[0].second, comps[i].second);
            ans.emplace_back(comps[0].second, comps[i].second);
        }

        cout << work(0).first << '\n';
        for (auto [u, v] : ans) {
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    };
    
    solve();
    
    return 0;
}
