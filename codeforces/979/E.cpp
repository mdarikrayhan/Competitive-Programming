// LUOGU_RID: 158502380
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 60;

int n,p,ans;
int col[maxn],pw[maxn];
int dp[maxn][2][2][2];

signed main()
{
    cin >> n >> p;
    for(int i = 1;i <= n;i++)cin >> col[i];
    pw[0] = 1;
    for(int i = 1;i <= n;i++)pw[i] = pw[i - 1] * 2 % mod;
    dp[n + 1][0][0][0] = 1;
    for(int i = n;i >= 1;i--)
    {
        for(int j = 0;j <= 1;j++)
        {
            for(int k = 0;k <= 1;k++)
            {
                for(int l = 0;l <= 1;l++)
                {
                    if(dp[i + 1][j][k][l] == 0)continue;
                    if(col[i] != 1)
                    {
                        if(l)
                        {
                            dp[i][j][k][l] = (dp[i][j][k][l] + pw[n - i - 1] * dp[i + 1][j][k][l] % mod) % mod;
                            dp[i][j ^ 1][1][l] = (dp[i][j ^ 1][1][l] + pw[n - i - 1] * dp[i + 1][j][k][l] % mod) % mod;
                        }
                        else
                        {
                            dp[i][j ^ 1][1][l] = (dp[i][j ^ 1][1][l] + pw[n - i] * dp[i + 1][j][k][l] % mod) % mod;
                        }
                    }
                    if(col[i] != 0)
                    {
                        if(k)
                        {
                            dp[i][j][k][l] = (dp[i][j][k][l] + pw[n - i - 1] * dp[i + 1][j][k][l] % mod) % mod;
                            dp[i][j ^ 1][k][1] = (dp[i][j ^ 1][k][1] + pw[n - i - 1] * dp[i + 1][j][k][l] % mod) % mod;
                        }
                        else
                        {
                            dp[i][j ^ 1][k][1] = (dp[i][j ^ 1][k][1] + pw[n - i] * dp[i + 1][j][k][l] % mod) % mod;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= 1;i++)
    {
        for(int j = 0;j <= 1;j++)
        {
            ans = (ans + dp[1][p][i][j]) % mod;
        }
    }
    cout << ans;
    return 0;
}
