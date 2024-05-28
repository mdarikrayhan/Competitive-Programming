#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &value : a) {
    cin >> value;
  }
  for (int &value : b) {
    cin >> value;
  }
  vector<int> ord_a(n);
  iota(ord_a.begin(), ord_a.end(), 0);
  sort(ord_a.begin(), ord_a.end(), [&](int x, int y) {
    return a[x] > a[y];
  });
  vector<vector<int>> nxt(n + 1, vector<int>(m, n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      nxt[i][j] = min(nxt[i][j], nxt[i + 1][j]);
      int p = i - (b[j] + a[ord_a[i]] - 1) / a[ord_a[i]] + 1;
      if (p >= 0) {
        nxt[p][j] = min(nxt[p][j], i + 1);
      }
    }
  }
  vector<int> dp(1 << m, n + 1), dp_last(1 << m, -1);
  dp[0] = 0;
  for (int mask = 0; mask < (1 << m); mask++) {
    if (dp[mask] > n) {
      continue;
    }
    for (int head = 0; head < m; head++) {
      int new_mask = mask | (1 << head);
      if (new_mask != mask && dp[new_mask] > nxt[dp[mask]][head]) {
        dp[new_mask] = nxt[dp[mask]][head];
        dp_last[new_mask] = head;
      }
    }
  }
  if (dp.back() > n) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  int msk = (1 << m) - 1;
  vector<array<int, 2>> path;
  while (msk > 0) {
    path.push_back({dp[msk], dp_last[msk]}); 
    msk ^= 1 << dp_last[msk];
  }
  path.push_back({0, -1});
  reverse(path.begin(), path.end());
  vector<vector<int>> answer(m);
  for (int i = 0; i < m; i++) {
    for (int j = path[i][0]; j < path[i + 1][0]; j++) {
      answer[path[i + 1][1]].push_back(ord_a[j]);
    }
  }
  for (int i = 0; i < m; i++) {
    int k = (int)answer[i].size();
    cout << k << " ";
    for (int j = 0; j < k; j++) {
      cout << 1 + answer[i][j] << " \n"[j + 1 == k];
    }
  }
}
