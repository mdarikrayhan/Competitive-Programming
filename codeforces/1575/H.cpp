#include <bits/stdc++.h>

using namespace std;
const int N = 502;
short dp[N][N][N];
int nxt[N][2];
string s, t;
int n, m;

void build() {
  int phi[m + 1];
  t += '2';
  phi[0] = 0;
  for (int i = 1, k = 0; i < m; ++i) {
    while (k and t[k] != t[i]) k = phi[k - 1];
    phi[i] = (k += (t[k] == t[i]));
  }
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (i > 0 and '0' + j != t[i])
        nxt[i][j] = nxt[phi[i - 1]][j];
      else
        nxt[i][j] = i + ('0' + j == t[i]);
    }
  }
  t.pop_back();
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> s >> t;
  memset(dp, 31, sizeof dp);
  const int inf = dp[0][0][0];
  build();
  dp[0][t[0] == s[0]][t[0] == s[0] and t.size() == 1] = 0;
  dp[0][t[0] != s[0]][t[0] != s[0] and t.size() == 1] = 1;
  for (int i = 0; i + 1 < n; ++i) {
    for (int l = 0; l <= m; ++l) {
      for (int k = 0; k <= n - m + 2; ++k) {
        if (dp[i][l][k] == inf)continue;
        if (s[i + 1] == '0') {
          int newL = nxt[l][0];
          dp[i + 1][newL][k + (newL == m)] = min(
              dp[i + 1][newL][k + (newL == m)],
              dp[i][l][k]
          );
          newL = nxt[l][1];
          dp[i + 1][newL][k + (newL == m)] = min(
              (int) dp[i + 1][newL][k + (newL == m)],
              dp[i][l][k] + 1
          );
        } else {
          int newL = nxt[l][1];
          dp[i + 1][newL][k + (newL == m)] = min(
              dp[i + 1][newL][k + (newL == m)],
              dp[i][l][k]
          );
          newL = nxt[l][0];
          dp[i + 1][newL][k + (newL == m)] = min(
              (int) dp[i + 1][newL][k + (newL == m)],
              dp[i][l][k] + 1
          );
        }
      }
    }
  }
  for (int k = 0; k < n - m + 2; ++k) {
    short res = 505;
    for (int i = 0; i <= m; ++i) {
      res = min(
          res,
          dp[n - 1][i][k]
      );
    }
    if (res == 505)res = -1;
    cout << res << ' ';
  }
}