// LUOGU_RID: 160380218
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 105
#define endl '\n'
int n, a[N], dp[N][N][N]; // dp[i][j][k]表示消除[i,j]以及j右边刚好k个相同字符的情况
string s;
void solve() // 状态转移方程:dp[i][j][k]=max(f[i][j−1][0]+a[k+1],dp[l+1][j−1][0]+dp[i][l][k+1])
{
    cin >> n;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i; i--)
        for (int j = i; j <= n; j++)
            for (int k = 0; k < n; k++)
            {
                dp[i][j][k] = dp[i][j - 1][0] + a[k + 1];
                for (int l = i; l < j; l++)
                    if (s[l] == s[j])
                        dp[i][j][k] = max(dp[i][j][k], dp[l + 1][j - 1][0] + dp[i][l][k + 1]);
            }
    cout << dp[1][n][0] << endl;
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}