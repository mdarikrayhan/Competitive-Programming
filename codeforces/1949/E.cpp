
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int64_t> h(n);
  int64_t total = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    total += h[i];
  }
  sort(h.begin(), h.end());
  const int M = int(1e8);
  vector<int> pref(M + 1);
  for (int i = 0; i < n; i++) {
    if (h[i] <= M) {
      pref[h[i]] += 1;
    }
  }
  for (int i = 1; i <= M; i++) {
    pref[i] += pref[i - 1];
  }
  int best_x = -1;
  int64_t best_num = 1;
  int64_t best_den = 0;
  const int64_t inf = int64_t(8e18);
  auto Test = [&](int x) {
    int64_t den = k - x;
    int64_t lim;
    if (best_den == 0) {
      lim = inf;
    } else {
      __int128 tmp = __int128(best_num) * den / best_den;
      lim = int64_t(tmp < inf ? tmp : inf);
    }
    int64_t num = 0;
    int64_t m = 0;
    int i = 0;
    while (i < n) {
      if ((m + 1) * x >= h[i]) m += 1; else
      if ((m + 2) * x >= h[i]) m += 2; else {
        m = (h[i] + x - 1) / x;
      }
      int j = 0;
      if (m * x < M) {
        j = pref[m * x];
      } else {
        j = int(upper_bound(h.begin(), h.end(), m * x) - h.begin());
      }
      assert(i < j);
      num += (j - i) * m;
      i = j;
      if (num + (n - i) * (m + 1) > lim) {
        return;
      }
    }
    if (num * best_den < best_num * den) {
      best_x = x;
      best_num = num;
      best_den = den;
    }
  };
  for (int x = k / 2; x >= 1; x--) {
    if (__int128(total) * best_den >= __int128(best_num) * x * (k - x)) {
      break;
    }
    Test(x);
    if (x < k - x) {
      Test(k - x);
    }
  }
  cout << best_x << " " << k - best_x << '\n';
  return 0;
}
