#include "bits/stdc++.h"

using namespace std;

using lint = long long;

void solve(int tc) {
  lint x;
  cin >> x;
  x = (x % 360 + 360) % 360;
  x = (x + 44) % 360;

  lint ans = (x % 359) / 90;
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cerr << __cplusplus << endl;

  int t = 1;
  // cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    // cout << tc << ' ';
    solve(tc);
    cout << '\n';
  }

  return 0;
}

