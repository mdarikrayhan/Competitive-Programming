#include <bits/stdc++.h>
using ll = long long;
int mod = 998244353;

void solve() {
    int n;
    std::cin >> n >> mod;

    int f[55][2005] = {1}, s[55][2005] = {1}, ans[55];
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
        s[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * (n - 1) / 2; j++) {
            if (j - i >= 0) {
                f[i][j] = (s[i - 1][j] - s[i - 1][j - i] + mod) % mod;
            } else {
                f[i][j] = s[i - 1][j];
            }
            s[i][j] = ((j ? s[i][j - 1] : 0) + f[i][j]) % mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = j + 1; k <= i; k++) {
                for (int o = 0; o <= (i - 1) * (i - 2) / 2; o++) {
                    int t = o - (k - j) - 1;
                    if (t < 0) {
                        continue;
                    }
                    ans[i] =
                        (ans[i] + 1ll * f[i - 1][o] * s[i - 1][t] % mod) % mod;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        ans[i] = (ans[i] + 1ll * i * ans[i - 1]) % mod;
    }
    std::cout << ans[n];
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
