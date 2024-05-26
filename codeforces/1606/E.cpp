#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int MOD = 998244353;

int n, x;
int c[N][N], dp[N][N];

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int main() {
  cin >> n >> x;
  for (int i = 0; i <= n; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) 
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
  dp[n][0] = 1;
  for (int i = n; i > 1; i--) {
    for (int j = 0; j < x; ++j) {
      if (!dp[i][j]) continue;
      int pw = 1, nj = min(x, j + i - 1);
      for (int k = i; k >= 0; k--) {
        dp[k][nj] = add(dp[k][nj], mul(dp[i][j], mul(c[i][k], pw)));
        pw = mul(pw, nj - j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= x; ++i)
    ans = add(ans, dp[0][i]);
  cout << ans << endl;
}