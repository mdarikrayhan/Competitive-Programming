#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + 1] = std::max(
                dp[i + 1][j + 1], dp[i][j] + ((a[i + 1] == j + 1) ? 1 : 0));
        }
    }
    int ans = -1;
    for (int i = n; i >= 0; i--) {
        if (dp[n][i] >= k) {
            ans = n - i;
            break;
        }
    }
    std::cout << ans << '\n';
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
