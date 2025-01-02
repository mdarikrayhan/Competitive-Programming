#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) {
        std::cin >> x;
    }

    std::vector<std::vector<int>> g(n);
    std::vector<int> w(n);
    std::vector<int> fa(n);
    for (int i = 1; i < n; i++) {
        std::cin >> fa[i] >> w[i];
        fa[i]--;
        g[fa[i]].push_back(i);
    }

    std::vector<ll> dep(n);
    auto dfs = [&](auto &&self, int u) -> void {
        for (int v : g[u]) {
            dep[v] = dep[u] + w[v];
            self(self, v);
        }
    };
    dfs(dfs, 0);

    std::vector<int> stk;
    std::vector<int> ans(n);
    auto dfs2 = [&](auto &&self, int u) -> void {
        if (u != 0 && w[u] <= a[u]) {
            int l = 0, r = stk.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (dep[u] - dep[stk[mid]] <= a[u]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[fa[u]]++;
            if (stk[l] != 0) {
                ans[fa[stk[l]]]--;
            }
        }
        stk.push_back(u);
        for (int v : g[u]) {
            self(self, v);
        }
        stk.pop_back();
    };
    dfs2(dfs2, 0);

    auto dfs3 = [&](auto &&self, int u) -> void {
        for (int v : g[u]) {
            self(self, v);
            ans[u] += ans[v];
        }
    };
    dfs3(dfs3, 0);

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }


    return 0;
}