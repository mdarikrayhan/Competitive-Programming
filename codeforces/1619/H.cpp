#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<int> r(n + 1), a(n + 1);
    for (int i = 0; i < n; i++) {
        r[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int x = i;

        for (int j = 0; j < 100; j++) {
            x = p[x];
        }

        a[i] = x;
    }
    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;

        if (t == 2) {
            x--;

            while (y >= 100) {
                y -= 100;
                x = a[x];
            }

            while (y--) {
                x = p[x];
            }

            std::cout << x + 1 << "\n";
        } else {
            x--;
            y--;

            std::swap(r[p[x]], r[p[y]]);
            std::swap(p[x], p[y]);

            int ax = x;

            for (int i = 0; i < 100; i++) {
                ax = p[ax];
            }

            int x2 = x;

            for (int i = 0; i < 100; i++) {
                a[x] = ax;
                x = r[x];
                ax = r[ax];
            }

            std::swap(x, y);

            ax = x;

            for (int i = 0; i < 100; i++) {
                ax = p[ax];
            }

            x2 = x;

            for (int i = 0; i < 100; i++) {
                a[x] = ax;
                x = r[x];
                ax = r[ax];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
