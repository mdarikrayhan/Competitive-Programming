
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int N = 2e5 + 2;
int dp[N][2][2];

void solve() {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) dp[i][j][k] = -3 * n;

    dp[0][0][0] = 0;
    if (s[1][0] == '1') { dp[0][1][1] = 1; }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            // dp[i][j][0] = dp[i - 1][j][0];
            // dp[i][j][1] = dp[i - 1][j][1];
            if (s[j][i] == '1') {
                dp[i][j][0] =
                    max({dp[i][j][0], dp[i - 1][j][0], dp[i - 1][j][1]}) + 1;
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j ^ 1][0] + 1);
                if (s[j ^ 1][i] == '1') {
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j ^ 1][0] + 2);
                }
            }
             else {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                dp[i][j][1] = dp[i - 1][j][1];
            }
        }
    }
    n--;
    cout << max({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]}) << "\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
