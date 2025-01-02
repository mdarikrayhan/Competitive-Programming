#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int q;
    std::cin >> q;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 4>> Q(q);

    for (int i = 0; i < q; ++i) {
        auto& [x1, y1, x2, y2] = Q[i];
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) {
            std::swap(x1, x2);
        }
        if (y1 > y2) {
            std::swap(y1, y2);
        }
    }

    std::array<int, 4> T;
    std::cin >> T[0] >> T[1] >> T[2] >> T[3];

    std::vector<std::array<int, 4>> ans(q + 1);

    std::vector<std::vector<std::array<int, 2>>> X(n + 1), Y(m + 1);

    // L -> R
    for (int i = 0; i < q; ++i) {
        auto& [x1, y1, x2, y2] = Q[i];
        if (x1 == x2) {
            X[x1].push_back({i, 0});
        } else {
            X[x1].push_back({q, 0});
            X[x2].push_back({i, -1});
        }
        if (y1 == y2) {
            Y[y1].push_back({i, 0});
        } else {
            Y[y1].push_back({q, 0});
            Y[y2].push_back({i, -1});
        }
    }

    for (int i = 1, cnt = 0; i <= n; ++i) {
        for (auto& [id, add] : X[i]) {
            ans[id][0] += cnt + add;
        }
        while (X[i].size()) {
            auto [id, add] = X[i].back();
            if (add != -1) {
                ++cnt;
            }
            X[i].pop_back();
        }
    }

    for (int i = 1, cnt = 0; i <= m; ++i) {
        for (auto& [id, add] : Y[i]) {
            ans[id][2] += cnt + add;
        }
        while (Y[i].size()) {
            auto [id, add] = Y[i].back();
            if (add != -1) {
                ++cnt;
            }
            Y[i].pop_back();
        }
    }

    // R -> L
    for (int i = 0; i < q; ++i) {
        auto& [x1, y1, x2, y2] = Q[i];
        if (x1 == x2) {
            X[x1].push_back({i, 0});
        } else {
            X[x1].push_back({i, -1});
            X[x2].push_back({q, 0});
        }
        if (y1 == y2) {
            Y[y1].push_back({i, 0});
        } else {
            Y[y1].push_back({i, -1});
            Y[y2].push_back({q, 0});
        }
    }

    for (int i = n, cnt = 0; i >= 1; --i) {
        for (auto& [id, add] : X[i]) {
            ans[id][1] += cnt + add;
        }
        while (X[i].size()) {
            auto [id, add] = X[i].back();
            if (add != -1) {
                ++cnt;
            }
            X[i].pop_back();
        }
    }

    for (int i = m, cnt = 0; i >= 1; --i) {
        for (auto& [id, add] : Y[i]) {
            ans[id][3] += cnt + add;
        }
        while (Y[i].size()) {
            auto [id, add] = Y[i].back();
            if (add != -1) {
                ++cnt;
            }
            Y[i].pop_back();
        }
    }

    for (int i = 0; i < q; ++i) {
        if (ans[i] == T) {
            std::cout << i + 1 << "\n";
            return;
        }
    }

    std::cout << -1 << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}