/*
 * Time complexity:  O(n * m)
 * Space complexity: Theta(n * m)
 */
#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

static constexpr int N = 16, M = 16;

static bool h[N + 1][M], v[M + 1][N];

static void solve(void) {
  int n, m, k;
  cin >> n >> m >> k;
  int b = n + m - 2, t = k - b;
  if (k < b || t % 4 == 1 || t % 4 == 3) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  bool c = 1;
  if (t % 4)
    v[2][1] = 1;
  for (int i = 2; i < n; i++, c ^= 1)
    v[1][i] = c;
  for (int i = 1; i < m; i++, c ^= 1)
    h[n][i] = c;
  if (t / 4) {
    v[m][n - 1] = c;
    h[n - 1][m - 1] = c ^= 1;
    v[m - 1][n - 1] = c ^= 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++)
      cout << (h[i][j] ? 'B' : 'R') << " ";
    cout << endl;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++)
      cout << (v[j][i] ? 'B' : 'R') << " ";
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (; t; t--)
    solve();
  return 0;
}
