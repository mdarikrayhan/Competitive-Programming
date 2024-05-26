#include <bits/stdc++.h>
#ifdef LOCAL
#include "utils/debug.h"
#else
#define debug(...)
#endif
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> grid(n);
  vector<pair<int, int>> pieces;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 'o') {
        pieces.emplace_back(i, j);
      }
    }
  }
  vector<string> res(2 * n - 1, string(2 * n - 1, 'x'));
  int m = n - 1;
  res[m][m] = 'o';
  for (auto &[r, c] : pieces) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == r && j == c) continue;
        if (grid[i][j] == '.') {
          res[m + i - r][m + j - c] = '.';
        }
      }
    }
  }
  vector<string> check(n, string(n, '.'));
  for (auto &[r, c] : pieces) {
    check[r][c] = 'o';
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == r && j == c) continue;
        if (check[i][j] == '.') {
          check[i][j] = res[m + i - r][m + j - c];
        }
      }
    }
  }
  if (check != grid) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (auto &r : res) cout << r << '\n';
  }
}
