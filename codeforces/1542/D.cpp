#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        char op;
        std::cin >> op;
        if (op == '+') {
            std::cin >> a[i];
        }
    }

    ll ans = 0;
    for (int t = 1; t <= n; t++) {
        if (!a[t]) {
            continue;
        }
        std::vector<std::vector<int>> f(n + 2, std::vector<int>(n + 2));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (!a[i]) {
                    if (i <= t || j > 0) {
                        f[i][std::max(j - 1, 0)] =
                            (f[i][std::max(j - 1, 0)] + f[i - 1][j]) % mod;
                    }
                } else {
                    if (a[i] < a[t] || (a[i] == a[t] && i < t)) {
                        f[i][j + 1] = (f[i][j + 1] + f[i - 1][j]) % mod;
                    } else {
                        f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
                    }
                }
                if (i != t) {
                    f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            ans = (ans + 1LL * f[n][i] * a[t]) % mod;
        }
    }
    std::cout << ans << '\n';
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
