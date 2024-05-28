// LUOGU_RID: 160063285
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 5000 + 10;
int f[maxn][maxn], g[maxn][maxn];
void solve()
{
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    s.insert(s.begin(), ' ');
    t.insert(t.begin(), ' ');
    for (int i=0;i<=n;++i) memset(f[i], 0x3f, sizeof(f[i]));
    f[0][0] = 0;
    for (int i=1;i<=n;++i)
        for (int j=0;j<=m;++j)
        {
            f[i][j] = f[i - 1][j] + 2;
            if (s[i] == t[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (s[i] == t[j]) g[i][j] = g[i - 1][j - 1] + 1;
            else g[i][j] = 0;
    int ans = 0x3f3f3f3f;
    int mm = m;
    for (int i=n;i>=0;--i)
    {
        if (i < n && mm && s[i + 1] == t[mm]) --mm;
        for (int j=mm;j<=m;++j) ans = min(ans, n - i + f[i - g[i][j]][j - g[i][j]] + (i != g[i][j]));
    }
    if (ans == 0x3f3f3f3f) ans = -1;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}