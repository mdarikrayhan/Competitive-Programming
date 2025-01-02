#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;

        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    vector<vector<bool>> dp(n, vector<bool>(32));
    vector<vector<vector<int>>> prev(n);
    vector<int> size(n);

    auto dfs = [&](auto self, int v, int p) -> void {
        dp[v][a[v]] = true;
        size[v] = 1;

        for (auto u : adj[v]) {
            if (u == p) continue;
            self(self, u, v);

            size[v] += size[u];

            vector<bool> upd(32);

            prev[v].push_back(vector<int>(32));

            for (int i = 0; i < 32; i++) {
                if (!dp[v][i]) continue;
                for (int j = 0; j < 32; j++) {
                    if (!dp[u][j]) continue;

                    if (!upd[i ^ j]) {
                        upd[i ^ j] = true;
                        prev[v][prev[v].size() - 1][i ^ j] = j;
                    }
                }
            }

            dp[v] = upd;
        }

        if (size[v] % 2 == 0) {
            dp[v][0] = true;
        }
    };

    dfs(dfs, 0, -1);

    if (!dp[0][0]) cout << -1 << "\n";
    else {
        vector<int> ans;
        auto recover = [&](auto self, int v, int p, int want) -> void {
            reverse(adj[v].begin(), adj[v].end());

            if (want == 0 && size[v] % 2 == 0) {
                ans.push_back(v);
                ans.push_back(v);
                return;
            }

            int c = prev[v].size() - 1;
            for (auto u : adj[v]) {
                if (u == p) continue;
                self(self, u, v, prev[v][c][want]);
                want ^= prev[v][c][want];
                c--;
            }
        };

        recover(recover, 0, -1, 0);

        ans.push_back(0);

        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
        }
    }

    return 0;
}
