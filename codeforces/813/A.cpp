#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    i64 s = std::accumulate(a.begin(), a.end(), 0LL);
    i64 ans = 1e9;

    int q;
    std::cin >> q;
    std::vector<std::array<i64, 2>> L(q);

    for (auto& [l, r] : L) {
        std::cin >> l >> r;
        if (s <= r) {
            ans = std::min(ans, std::max(s, l));
        }
    }

    std::cout << (ans == 1e9 ? -1 : ans) << "\n";
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