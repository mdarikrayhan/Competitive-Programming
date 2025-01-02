#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define Acode ios::sync_with_stdio(false), cin.tie(0)
#define int long long
const int mod = 1e9 + 7;
int n, l, r, z, len;
int dp[72][2010][2];
int zz[100], num[100];
int C[1010][1010];

int dfs(int pos, int c, int f)
{
    if (pos > len)
    {
        if (!c && !f)
            return 1;
        else
            return 0;
    }
    if (dp[pos][c][f] != -1)
        return dp[pos][c][f];
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if ((i & 1) != zz[pos])
            continue;
        int now = ((i + c) & 1);
        int ff = (now < num[pos] ? 0 : (now == num[pos] ? f : 1));
        ans = (ans + dfs(pos + 1, (i + c) >> 1LL, ff) % mod * C[n][i] % mod) % mod;
    }
    dp[pos][c][f] = ans;
    return dp[pos][c][f];
}

int getsum(int x)
{
    if (x <= 0)
        return 0;
    if (x < z)
        return 0;
    len = 0;
    while (x)
    {
        num[++len] = (x & 1);
        x >>= 1;
    }
    memset(dp, -1, sizeof dp);
    return dfs(1, 0, 0);
}

void solve()
{
    cin >> n >> l >> r >> z;
    int cnt = 0;
    int t = z;
    while (t)
    {
        zz[++cnt] = (t & 1);
        t >>= 1;
    }
    cout << (getsum(r) - getsum(l - 1) + mod) % mod;
}

signed main()
{
    C[0][0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    Acode;
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}