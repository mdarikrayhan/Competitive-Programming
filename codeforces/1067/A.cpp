//Written by: Jethro_
//----------------------
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
long long dp[N][201][2], mod = 998244353;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= 200; ++i) dp[0][i][0] = 1;
    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= 200; ++j) {
            if (a[i] != j && a[i] != -1) continue;
            dp[i][j][0] = ((dp[i - 1][200][0] - dp[i - 1][j - 1][0] + mod) % mod + (dp[i - 1][j][1] - dp[i - 1][j - 1][1] + mod)) % mod; 
            dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % mod;
        }

        for (int j = 1; j <= 200; ++j) {

            for (int m = 0; m < 2; ++m) {
                dp[i][j][m] = (dp[i][j][m] + dp[i][j - 1][m]) % mod;
            }
        }
    }
    
    cout << dp[n][200][0] << '\n';
}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();

}