#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, a[501][501], b[501][501], dp[501][501][21];
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j]; 
        }
    }
    if (k & 1) {
        for (int i = 1; i <= n; cout << endl, i++) {
            for (int j = 1; j <= m; j++) {
                cout << -1 << ' ';
            }
        }
        return;
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j][0] = 0;
    
    for (int t = 1; t <= k / 2; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j][t] = min(dp[i][j][t], dp[i][j - 1][t - 1] + a[i][j - 1]);
                dp[i][j][t] = min(dp[i][j][t], dp[i - 1][j][t - 1] + b[i - 1][j]);

                if (j < m) {
                    dp[i][j][t] = min(dp[i][j][t], dp[i][j + 1][t - 1] + a[i][j]);
                }
                if (i < n) {
                    dp[i][j][t] = min(dp[i][j][t], dp[i + 1][j][t - 1] + b[i][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; cout << '\n', i++) {
        for (int j = 1; j <= m; j++) {
            cout << 2 * dp[i][j][k / 2] << ' ';
        }
    }
}
signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}