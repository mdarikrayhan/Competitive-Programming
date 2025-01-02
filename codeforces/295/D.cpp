#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int N = 2e3 + 7;
const int M = 1e9 + 7;

int n, m;
int dp[N][N];

int add(int a, int b) {
    return a + b >= M ? a + b - M : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + M : a - b;
}

int mul(int a, int b) {
    return (ll) a * b % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n + 1; ++i) {
        int sum = 0;
        for (int j = 2; j <= m; ++j) {
            sum = add(sum, dp[i - 1][j]);
            dp[i][j] = add(dp[i][j - 1], sum);
        }
        for (int j = 2; j <= m; ++j) {
            dp[i][j] = add(dp[i][j], 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            ans = add(ans, mul(mul(dp[i][j], sub(dp[n - i + 1][j], dp[n - i][j])), m - j + 1));
        }
    }
    cout << ans << "\n";
    return 0;
}