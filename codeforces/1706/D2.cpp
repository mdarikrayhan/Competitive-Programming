/*
 * d.cc
 * 2022-07-18 23:02:12
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    const int N = (int) 1e5 + 1;
    vector<vector<int>> at(N);
    for (int i = 0; i < n; i++) {
      at[a[i]].push_back(i);
    }
    int ans = N, mn = a[0];
    for (int mx = N - 1; mx >= 0; mx--) {
      ans = min(ans, mx - mn);
      if (mx > 0) {
        bool fail = false;
        for (int i : at[mx]) {
          int p = a[i] / mx + 1;
          if (p > k) {
            fail = true;
            break;
          }
          int r = a[i] / p;
          mn = min(mn, r);
          at[r].push_back(i);
        }
        if (fail) break;
        vector<int>().swap(at[mx]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}