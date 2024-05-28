#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define Acode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
const int N = 2e5 + 10;
int t[N], x[N], y[N];
int dp[N], s[N];

void solve()
{
    int r, n;
    cin >> r >> n;
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    t[0] = 0, x[0] = 1, y[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (t[i] - t[j] > 2 * r)
            {
                dp[i] = max(dp[i], s[j] + 1);
                break;
            }
            int xx = t[i] - t[j];
            int len = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if (xx >= len)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        s[i] = max(s[i - 1], dp[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
}

signed main()
{
    Acode;
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}