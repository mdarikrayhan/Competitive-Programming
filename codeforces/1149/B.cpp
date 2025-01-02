#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 mod = 998244353;

i64 binexpo(i64 a, i64 b) {
  a %= mod;
  i64 ans = 1;
  while (b) {
    if (b & 1) {
      (ans *= a) %= mod;
    }
    (a *= a) %= mod;
    b >>= 1;
  }
  return ans;
}

i64 modinv(i64 a) {
  return binexpo(a, mod - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vector<int>> nxt(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = nxt[i + 1];
    nxt[i][s[i] - 'a'] = i;
  }
  vector<vector<vector<int>>> dp(1, vector<vector<int>> (1, vector<int>(1, n)));
  dp[0][0][0] = -1;
  vector<vector<int>> rel(3);
  int a = 0;
  int b = 0;
  int c = 0;
  while (q--) {
    char type;
    cin >> type;
    int pos;
    cin >> pos;
    --pos;
    if (type == '+') {
      if (pos == 0) {
        ++a;
      } else if (pos == 1) {
        ++b;
      } else if (pos == 2) {
        ++c;
      }
      char nw;
      cin >> nw;
      int inw = nw - 'a';
      rel[pos].push_back(inw);
      if (pos == 0) {
        if (dp.size() < a + 1) {
          dp.emplace_back();
        }
        while (dp[a].size() < b + 1) {
          dp[a].emplace_back();
        }
        for (int j = 0; j <= b; j++) {
          while (dp[a][j].size() < c + 1) {
            dp[a][j].emplace_back();
          }
          for (int k = 0; k <= c; k++) {
            dp[a][j][k] = n;
            if (a > 0 && dp[a - 1][j][k] < n) {
              dp[a][j][k] = min(dp[a][j][k], nxt[dp[a - 1][j][k] + 1][rel[0][a - 1]]);
            }
            if (j > 0 && dp[a][j - 1][k] < n) {
              dp[a][j][k] = min(dp[a][j][k], nxt[dp[a][j - 1][k] + 1][rel[1][j - 1]]);
            }
            if (k > 0 && dp[a][j][k - 1] < n) {
              dp[a][j][k] = min(dp[a][j][k], nxt[dp[a][j][k - 1] + 1][rel[2][k - 1]]);
            }
          }
        }
      } else if (pos == 1) {
        for (int i = 0; i <= a; i++) {
          if (dp[i].size() < b + 1) {
            dp[i].emplace_back();
          }
          while (dp[i][b].size() < c + 1) {
            dp[i][b].emplace_back();
          }
          for (int k = 0; k <= c; k++) {
            dp[i][b][k] = n;
            if (i > 0 && dp[i - 1][b][k] < n) {
              dp[i][b][k] = min(dp[i][b][k], nxt[dp[i - 1][b][k] + 1][rel[0][i - 1]]);
            }
            if (b > 0 && dp[i][b - 1][k] < n) {
              dp[i][b][k] = min(dp[i][b][k], nxt[dp[i][b - 1][k] + 1][rel[1][b - 1]]);
            }
            if (k > 0 && dp[i][b][k - 1] < n) {
              dp[i][b][k] = min(dp[i][b][k], nxt[dp[i][b][k - 1] + 1][rel[2][k - 1]]);
            }
          }
        }
      } else if (pos == 2) {
        for (int i = 0; i <= a; i++) {
          for (int j = 0; j <= b; j++) {
            if (dp[i][j].size() < c + 1) {
              dp[i][j].emplace_back();
            }
            dp[i][j][c] = n;
            if (i > 0 && dp[i - 1][j][c] < n) {
              dp[i][j][c] = min(dp[i][j][c], nxt[dp[i - 1][j][c] + 1][rel[0][i - 1]]);
            }
            if (j > 0 && dp[i][j - 1][c] < n) {
              dp[i][j][c] = min(dp[i][j][c], nxt[dp[i][j - 1][c] + 1][rel[1][j - 1]]);
            }
            if (c > 0 && dp[i][j][c - 1] < n) {
              dp[i][j][c] = min(dp[i][j][c], nxt[dp[i][j][c - 1] + 1][rel[2][c - 1]]);
            }
          }
        }
      }
    } else {
      if (pos == 0) {
        --a;
      } else if (pos == 1) {
        --b;
      } else if (pos == 2) {
        --c;
      }
      rel[pos].pop_back();
    }
    if (dp[a][b][c] < n) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}