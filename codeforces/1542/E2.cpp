#include <bits/stdc++.h>
using ll = long long;
int mod = 998244353;

const int B = 130000;
int n, w[2][2 * B + 5], s[2][2 * B + 5], ans[505];

void solve() {
    std::cin >> n >> mod;

    w[0][B] = s[0][B] = 1;
    for (int i = B; i <= 2 * B; i++) {
        s[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int curs = 1, I = i & 1, J = I ^ 1;
        memset(w[I], 0, sizeof(w[I])), memset(s[I], 0, sizeof(s[I]));
        for (int u = i * (i - 1) / 2, j = -u + B; j <= u + B; j++) {
            w[I][j] = curs;
            curs = (0ll + curs - s[J][j] + s[J][j - i] + s[J][j + i] - s[J][j] +
                    2ll * mod) %
                   mod;
        }
        for (int j = B - i * (i - 1) / 2, v = (i + 2) * (i + 1) / 2 + B; j <= v;
             j++) {
            s[I][j] = (s[I][j - 1] + w[I][j]) % mod;
        }
        for (int j = 1; j < i; j++) {
            ans[i] = (ans[i] +
                      1ll * (s[J][(i + 1) * i / 2 + B] - s[J][j + B] + mod) %
                          mod * (i - j)) %
                     mod;
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
