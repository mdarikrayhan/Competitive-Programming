#include <bits/stdc++.h>

using i64 = long long;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int leader(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[leader(x)];
    }
};
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        
        if (std::pair(a[u], u) < std::pair(a[v], v)) {
            std::swap(u, v);
        }
        adj[u].push_back(v);
    }
    
    std::vector<bool> ok(n);
    
    std::vector<int> order(n);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int i, int j) {
        return std::pair(a[i], i) < std::pair(a[j], j);
    });
    
    DSU dsu(n);
    
    for (auto x : order) {
        ok[x] = a[x] == 0;
        for (auto y : adj[x]) {
            y = dsu.leader(y);
            if (ok[y] && dsu.size(y) >= a[x]) {
                ok[x] = true;
            }
            dsu.merge(x, y);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!dsu.same(0, i)) {
            std::cout << "NO\n";
            return;
        }
    }
    
    if (ok[dsu.leader(0)]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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