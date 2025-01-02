#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define ll long long
void solve()
{
  ll n, l, k;
  cin >> n >> l >> k;
  vector<ll>d(n+1),a(n);
  for(int i=0;i<n;i++)
  cin>>d[i];
  d[n]=l;
  for(int i=0;i<n;i++)
    cin >> a[i];
  vector dp(n + 1, vector(n + 1, (ll)INF));
  dp[0][0] = 0;
  for(int i=0;i<n;i++)
  {
    for (int j = 0;j<=i;j++)
    {
      for (int x = i + 1; x <= n;x++)
      {
        dp[x][j + 1] = min(dp[x][j + 1], dp[i][j] + a[i] * (d[x] - d[i]));
      }
    }
  }
  ll ans=INF;
  for (int j = n - k;j<=n;j++)
  {
    ans = min(ans, dp[n][j]);
  }
  cout << ans << '\n';
  // ll n, k, l;
  // cin>>n>>l>>k;
  // vector<vector<array<ll, 2>>> dp(k + 1);
  // for (int i = 0;i<=k;i++)
  //   dp[i].resize(n + 1);
  // vector<ll> a(n + 1);
  // for (int i = 0;i<n;i++)
  //   cin>>a[i];
  // a[n] = l;
  // for (int i = n; i > 0;i--)
  //   a[i] = a[i] - a[i - 1];
  // for(int i=0;i<n;i++)
  // {
  //   cin >> dp[0][i][0];
  //   if(i)
  //     dp[0][i][1] = dp[0][i - 1][1] + a[i] * dp[0][i - 1][0];
  // }
  // dp[0][n][1] = dp[0][n - 1][1] + a[n] * dp[0][n - 1][0];
  // for (int z = 1; z <= k;z++)
  // {
  //   dp[z][0][1] = 0;
  //   for(int i=0;i<=n;i++)
  //   {
  //     dp[z][i][0] = dp[z - 1][i][0];
  //     if(i)
  //     dp[z][i][1] = dp[z][i - 1][1] + a[i] * dp[z][i - 1][0];

  //     ll temp = a[i];
  //     for (int j = 1; j <= z && i - j > 0; j++)
  //     {
  //       temp += a[i - j];
  //       if(dp[z-j][i-j-1][1]+temp*dp[z-j][i-j-1][0]<=dp[z][i][1])
  //       {
  //         dp[z][i - 1][0] = dp[z - j][i - j - 1][0];
  //         dp[z][i][1]=dp[z - j][i - j - 1][1] + temp *dp[z - j][i - j - 1][0];
  //       }
  //     }
  //   }
  // }
  // cout << dp[k][n][1] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
}