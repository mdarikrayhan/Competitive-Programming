#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> size(n), par(n);
    vector<set<pair<int, int>>> s(n);
    vector<long long> sum(n);
    auto dfs = [&](auto dfs, int x, int p) -> void {
        size[x] = 1;
        sum[x] = a[x];
        for (int y : adj[x]) {
            if (y == p) {
                continue;
            }
            dfs(dfs, y, x);
            size[x] += size[y];
            par[y] = x;
            s[x].insert({size[y], -y});
            sum[x] += sum[y];
        }
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < m; i++) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            cout << sum[x] << "\n";
        } else {
            if (s[x].empty()) {
                continue;
            }
            int y = -prev(s[x].end())->second;
            int p = par[x];
            s[x].erase({size[y], -y});
            s[p].erase({size[x], -x});
            size[x] -= size[y];
            size[y] += size[x];
            par[y] = p;
            par[x] = y;
            s[p].insert({size[y], -y});
            s[y].insert({size[x], -x});
            sum[x] -= sum[y];
            sum[y] += sum[x];
        }
    }
    return 0;
}