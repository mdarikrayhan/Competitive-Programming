#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int n, cur;
std::vector<std::vector<std::pair<int, int>>> sl;

void dfs(int v, std::vector<bool> &vis) {
    vis[v] = true;
    for (auto e : sl[v]) {
        int u = e.first, w = e.second;
        if (!vis[u] && (cur | w) == cur) {
            dfs(u, vis);
        }
    }
}

void cnt(int pw) {
    if (pw < 0) {
        return;
    }
    int d = (ll)1 << pw;
    cur -= d;
    std::vector<bool> used(n);
    dfs(0, used);
    for (bool b : used) {
        if (!b) {
            cur += d;
            break;
        }
    }
    cnt(pw - 1);
}

void solve() {
    int m;
    std::cin >> n >> m;

    sl.assign(n, std::vector<std::pair<int, int>>(0));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        sl[u].emplace_back(v, w);
        sl[v].emplace_back(u, w);
    }
    cur = 1;
    int bit = 0;
    for (; cur < 1e9; bit++) {
        cur = 2 * cur + 1;
    }
    cnt(bit);
    std::cout << cur << '\n';
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
