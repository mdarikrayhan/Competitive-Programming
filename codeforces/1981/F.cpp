#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int maxn = 25050;
const int inf = 0x3f3f3f3f;

int n, m, a[maxn], f[maxn][4000];
std::vector<int> G[maxn];

void dfs(int u) {
    if (G[u].empty()) {
        for (int i = 1; i <= m; ++i) {
            f[u][i] = (i == a[u] ? inf : 0);
        }
        return;
    }
    if ((int)G[u].size() == 1) {
        int x = G[u][0];
        dfs(x);
        int mn = inf;
        for (int i = 1; i <= m; ++i) {
            if (i != a[u]) {
                mn = std::min(mn, f[x][i] + i);
            }
        }
        if (u == 1) {
            std::cout << mn << '\n';
            return;
        }
        for (int i = 1; i <= m; ++i) {
            f[u][i] = (i == a[u] ? inf : std::min(f[x][i], mn));
        }
        return;
    }
    int x = G[u][0], y = G[u][1], mnx = inf, mny = inf, k = inf;
    dfs(x);
    dfs(y);
    for (int i = 1; i <= m; ++i) {
        if (i != a[u]) {
            mnx = std::min(mnx, f[x][i] + i);
            mny = std::min(mny, f[y][i] + i);
            k = std::min(k, f[x][i] + f[y][i] + i);
        }
    }
    k = std::min(k, mnx + mny);
    if (u == 1) {
        std::cout << k << '\n';
        return;
    }
    for (int i = 1; i <= m; ++i) {
        f[u][i] =
            (i == a[u] ? inf : std::min({f[x][i] + mny, f[y][i] + mnx, k}));
    }
}

void solve() {
    std::cin >> n;
    m = std::min(n + 1, 3863);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        std::vector<int>().swap(G[i]);
    }
    for (int i = 2, p; i <= n; ++i) {
        std::cin >> p;
        G[p].push_back(i);
    }
    dfs(1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
