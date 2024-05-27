// LUOGU_RID: 159660499
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> edge(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v), edge[v].push_back(u);
    }

    vector<int> dep1(n + 1), dep2(n + 1), f(n + 1);
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        f[u] = fa;
        for (auto v : edge[u]) {
            if (v == fa)
                continue;
            dep1[v] = dep1[u] + 1;
            self(self, v, u);
        }
    };
    dfs1(dfs1, 1, 0);
    int st, ed, maxd = 0;
    for (int i = 1; i <= n; i++)
        if (dep1[i] > maxd) {
            maxd = dep1[i], st = i;
        }
    maxd = 0;
    dep1[st] = 0;
    dfs1(dfs1, st, 0);
    for (int i = 1; i <= n; i++)
        if (dep1[i] > maxd)
            maxd = dep1[i], ed = i;

    auto dfs2 = [&](auto self, int u, int fa) -> void {
        for (auto v : edge[u]) {
            if (v == fa)
                continue;
            dep2[v] = dep2[u] + 1;
            self(self, v, u);
        }
    };
    dfs2(dfs2, ed, 0);
    map<int, bool> b;
    for (int i = ed; i != st; i = f[i])
        b[i] = true;
    b[st] = true;
    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; i++)
        if (!b[i])
            ans += max(dep1[i], dep2[i]), sum++;
    sum = n - sum;
    ans += sum * (sum - 1) / 2;
    cout << ans << '\n';
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto v : edge[u]) {
            if (v == fa)
                continue;
            self(self, v, u);
        }
        if (!b[u])
            if (dep1[u] > dep2[u]) {
                cout << u << " " << st << " " << u << '\n';
            } else {
                cout << u << " " << ed << " " << u << '\n';
            }
    };
    dfs(dfs, st, 0);
    for (int i = ed; i != st; i = f[i])
        cout << i << " " << st << " " << i << '\n';
}