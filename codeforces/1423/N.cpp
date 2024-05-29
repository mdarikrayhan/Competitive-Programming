#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 9;
int n, m, s[N], w[N], eu[N], ev[N], vst[N];
bool chg[N];
vector<pair<int, int>> es[N];
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m, fill_n(w + 1, m, 1);
  for (int i = 1; i <= m; ++i) {
    cin >> eu[i] >> ev[i];
    auto [u, v] = minmax(eu[i], ev[i]);
    es[v].emplace_back(u, i), ++s[u], ++s[v];
  }
  for (int u = 1; u <= n; ++u) {
    for (auto [v, i] : es[u]) {
      if (!chg[v]) chg[v] = true, --w[i], --s[u];
      vst[s[v]] = u;
    }
    for (auto [v, i] : es[u]) {
      if (vst[s[u]] != u) break;
      chg[v] = false, ++w[i], ++s[u];
    }
  }
  cout << count(chg + 1, chg + n + 1, true) << '\n';
  for (int i = 1; i <= n; ++i)
    if (chg[i]) cout << i << ' ';
  cout << '\n';
  for (int i = 1; i <= m; ++i)
    cout << eu[i] << ' ' << ev[i] << ' ' << w[i] << '\n';
  return cout << flush, 0;
}