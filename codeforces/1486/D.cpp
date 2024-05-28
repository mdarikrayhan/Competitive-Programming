#include <bits/stdc++.h>

using namespace std;


int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int &x: arr) cin >> x;
  int s = 1, e = n, md, ans;
  auto ok = [&](int m) {
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
      p[i + 1] = p[i] + (arr[i] < m ? -1 : 1);
    }
    int mn{}, mx = p[k];
    for (int i = k + 1; i <= n; ++i) {
      mn = min(mn, p[i - k]);
      mx = max(mx, p[i] - mn);
    }
    return mx > 0;
  };

  while (s <= e) {
    md = (e + s) >> 1;
    if (ok(md)) {
      ans = md, s = md + 1;
    } else {
      e = md - 1;
    }
  }
  cout << ans;
}