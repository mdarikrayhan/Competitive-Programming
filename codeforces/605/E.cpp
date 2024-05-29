#include <bits/stdc++.h>

using i64 = long long;

typedef std::pair<int, int> PII;
const int mod = 998244353;
const int N = 2e6 + 1000;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> p(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            std::cin >> p[i][j];

    std::vector<double> dp(n + 1, INF), prob(n + 1, 1), coef(n + 1, 0);
    std::vector<int> vis(n + 1);
    dp[n] = 0;
    for (int t = 1; t <= n; t ++) {
        double min = INF;
        int id;
        for (int i = 1; i <= n; i ++) if (!vis[i] && min > dp[i]) {
            min = dp[i];
            id = i;
        }

        if (id == 1) {
            std::cout << std::fixed << std::setprecision(10) << dp[1] << "\n";
            return ;
        }

        vis[id] = true;
        for (int i = 1; i <= n; i ++) if (!vis[i]) {
            coef[i] += 0.01 * p[i][id] * prob[i] * dp[id];
            prob[i] *= (1 - 0.01 * p[i][id]);
            if (prob[i] < 1 - eps) dp[i] = (1 + coef[i]) / (1 - prob[i]);
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;
//    std::cin >> t;
    while (t--)
        solve();
    return 0;
}