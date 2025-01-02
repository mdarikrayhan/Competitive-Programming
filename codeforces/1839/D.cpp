#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    
    //dp[i][j][k] : till index i with j non-empty gaps if I am taking ith element in sequence or not
    int dp[n + 1][n + 1][2];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;
    
    for (int i = 1; i <= n; i++) {
        dp[i][1][1] = max(dp[i][1][1], 1);
        dp[i][1][0] = max(dp[i][1][0], 0);
        for (int gaps = 0; gaps <= n; gaps++) {
            for (int j = i - 1; j >= 0; j--) {
                if (c[j] < c[i]) {
                    if (j == i - 1 and dp[j][gaps][1] != -1)
                        dp[i][gaps][1] = max(dp[i][gaps][1], dp[j][gaps][1] + 1);
                    else {
                        if (gaps > 0 and dp[j][gaps - 1][1] != -1) {
                            dp[i][gaps][1] = max(dp[i][gaps][1], dp[j][gaps - 1][1] + 1);
                        }
                    }
                }
                if (gaps == 0)
                    continue;
                if (dp[j][gaps - 1][1] != -1) {
                    dp[i][gaps][0] = max(dp[i][gaps][0], dp[j][gaps - 1][1]);
                }
            }
        }
    }
    
    for (int k = 1; k <= n; k++) {
        int ans = 1e9 + 7;
        for (int gaps = 0; gaps <= k; gaps++) {
            if (dp[n][gaps][1] != -1) {
                ans = min(ans, n - dp[n][gaps][1]);
            }
            if (dp[n][gaps][0] != -1) {
                ans = min(ans, n - dp[n][gaps][0]);
            }
        }
        cout << ans << " \n"[k == n];
    }
    
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}