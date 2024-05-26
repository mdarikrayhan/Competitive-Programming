#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
void solve () {
  int n, m;
  cin >> n >> m;
  vector < int > st[n + 1], ed[n + 1];
  for (int i = 0; i < m; i ++) {
    int x, y;
    cin >> x >> y;
    st[x].push_back(x);
    ed[y].push_back(x);
  }

  multiset < int > current;
  vector < int > pref(n + 1, 0), dp(n + 1, 0);
  for (int i = 1; i <= n; i ++) {
    for (int it : st[i]) {
      current.insert(it);
    }
    int id = 0, sz = current.size();
    if (sz > 0) {
      id = *current.begin() - 1;
    }

    dp[i] = pref[id] + sz;
    pref[i] = max(pref[i - 1], dp[i]);

    for (int it : ed[i]) {
      current.erase(current.find(it));
    }
  }
  cout << pref[n] << "\n";
}
signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc --) {
    solve();
  }
}
