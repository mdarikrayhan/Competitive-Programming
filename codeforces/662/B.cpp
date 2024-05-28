#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, char>> edges(m);
    for (auto &[u, v, c] : edges) {
        cin >> u >> v >> c;
        --u, --v;
    }   

    vector<vector<pair<int, int>>> adj(n);
    vector<int> color(n, -1);

    function<bool(int, vector<int>&)> dfs = [&](int u, vector<int> &node) -> bool {
        if (color[u] == -1) {
            color[u] = 0;
        }
        int ok = 1;
        node.push_back(u);
        for (auto [v, c] : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ c;
                ok &= dfs(v, node);
            } else if (color[v] != (color[u] ^ c)) {
                ok = 0;
            }
        }
        return ok;
    };

    auto solve = [&](char ch) -> vector<int> {
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (auto &[u, v, c] : edges) {
            adj[u].push_back({v, !(c == ch)});
            adj[v].push_back({u, !(c == ch)});
        }
        vector<int> ans;

        fill(color.begin(), color.end(), -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                vector<int> nodes;
                if (!dfs(i, nodes)) {
                    for (int j = 0; j < n + 1; ++j) {
                        ans.push_back(-1);                        
                    }
                    return ans;
                }

                int cnt0 = 0;
                for (int u : nodes) {
                    cnt0 += color[u] == 0;
                }

                int cnt1 = (int)nodes.size() - cnt0;
                
                for (int u : nodes) {
                    if (color[u] == (cnt0 < cnt1 ? 0 : 1)) {
                        ans.push_back(u);
                    }
                }
            }
        }
        return ans;
    };

    vector<int> ans1 = solve('B');
    vector<int> ans2 = solve('R');

    if (ans1.size() > ans2.size()) {
        swap(ans1, ans2);
    }

    if (ans1.size() > n) {
        cout << -1;
    } else {
        cout << ans1.size() << '\n';
        for (int i : ans1) {
            cout << i + 1 << ' ';
        }
    }


    return 0;
}