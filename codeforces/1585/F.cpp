// LUOGU_RID: 159945389
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5, mod = 998244353;

int n, a[maxn];
int dp[maxn][2], pre[maxn][2];
stack<int> stk;

signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    dp[0][0] = pre[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if (stk.empty()) {
            dp[i][0] = 1ll * pre[i - 1][1] * a[i] % mod;
            dp[i][1] = 1ll * pre[i - 1][0] * a[i] % mod;
        } else {
            int p = stk.top();
            for (int j = 0; j <= 1; j++) {
                (dp[i][j] = 1ll * dp[p][j] + 1ll * (pre[i - 1][j ^ 1] - pre[p - 1][j ^ 1] + mod) * a[i] % mod) %= mod;
            }
        }
        for (int j = 0; j <= 1; j++)
            (pre[i][j] = pre[i - 1][j] + dp[i][j]) %= mod;
        stk.push(i);
    }
    int sgn = (n & 1) ? -1 : 1;
    printf("%d\n", ((dp[n][0] - dp[n][1]) * sgn + mod) % mod);

    return 0;
}