#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int cnt0, cnt1;
std::vector<int> col, comp;
std::vector<std::vector<std::pair<int, int>>> g;

void dfs(int v, int c, int cmp) {
    col[v] = c;
    if (col[v] == 0) {
        ++cnt0;
    } else {
        ++cnt1;
    }
    comp[v] = cmp;
    for (auto [to, change] : g[v]) {
        if (col[to] == -1) {
            dfs(to, c ^ change, cmp);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(2, std::vector<int>(n));
    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
            --a[i][j];
            pos[a[i][j]].push_back(j);
        }
    }
    bool bad = false;
    g = std::vector<std::vector<std::pair<int, int>>>(n);
    for (int i = 0; i < n; ++i) {
        if (pos[i].size() != 2) {
            bad = true;
            break;
        }
        int c1 = pos[i][0], c2 = pos[i][1];
        if (c1 == c2) {
            continue;
        }
        int r1 = a[0][c1] != i, r2 = a[0][c2] != i;
        g[c1].push_back({c2, r1 == r2});
        g[c2].push_back({c1, r1 == r2});
    }
    col = comp = std::vector<int>(n, -1);
    int cnt = 0;
    std::vector<std::pair<int, int>> colcnt;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            cnt0 = cnt1 = 0;
            dfs(i, 0, cnt);
            ++cnt;
            colcnt.push_back({cnt0, cnt1});
            ans += std::min(cnt0, cnt1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto [j, diff] : g[i]) {
            if ((col[i] ^ col[j]) != diff) {
                bad = true;
            }
        }
    }
    if (bad) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
            int changeZero = colcnt[comp[i]].first < colcnt[comp[i]].second;
            if (col[i] ^ changeZero) {
                std::cout << i + 1 << " ";
            }
        }
        std::cout << '\n';
    }
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
