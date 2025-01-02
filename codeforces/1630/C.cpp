#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
#warning That's the baby, that's not my baby

typedef long long ll;

const int NMAX = 2e5 + 3;

int aint[2 * NMAX + 1];
int n;
void update(int pos, int value) {
  pos += n;
  aint[pos] = std::min(aint[pos], value);
  for (; pos > 1; pos >>= 1) {
    aint[pos >> 1] = std::min(aint[pos], aint[pos ^ 1]);
  }
}
int query(int l, int r) {
  l += n;
  r += n;
  int ret = 1e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      ret = std::min(ret, aint[l++]);
    }
    if (r & 1) {
      ret = std::min(ret, aint[--r]);
    }
  }
  return ret;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;

  int a[n + 1] = {};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  int first[n + 1] = {};
  int last[n + 1] = {};
  for (int i = 1; i <= n; i++) {
    if (!first[a[i]]) {
      first[a[i]] = i;
    }
    last[a[i]] = i;
  }

  std::vector<std::pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    if (first[i] != 0) {
      v.push_back({first[i], last[i]});
    }
  }

  std::sort(v.begin(), v.end(), [&](std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
  });

  int dp[n + 3];
  dp[0] = 0;
  for (int i = 1; i <= n + 2; i++) {
    dp[i] = 1e9;
  }
  for (int i = 0; i <= 2 * n + 2; i++) {
    aint[i] = 1e9;
  }
  for (const auto &[x, y] : v) {
    dp[y] = std::min(dp[y], dp[x - 1] + 1 + (x != y));
    if (x + 1 <= y - 1) {
      dp[y] = std::min(dp[y], 1 + query(x + 1, y));
    }
    update(y, dp[y]);
  }

  std::cout << n - dp[n];

  return 0;
}
