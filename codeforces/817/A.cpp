#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int x, y;
    std::cin >> x >> y;

    x2 -= x1, y2 -= y1;

    if (std::abs(x2) % x || std::abs(y2) % y) {
        std::cout << "NO\n";
    } else if (std::abs(x2) / x % 2 != std::abs(y2) / y % 2) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
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