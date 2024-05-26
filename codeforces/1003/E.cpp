#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d, k;
  cin >> n >> d >> k;
  if (n == 1 or d >= n or (k == 1 and (d != 1 or n != 2))) {
    return cout << "NO", 0;
  }
  vector<pair<int, int>> edges;
  queue<array<int, 3>> q; /// [ depth , degree , u]
  int u = 1;
  for (int l = d, r = 0; u <= d + 1; ++u, --l, ++r) {
    q.push({min(l, r), 1 + (u != 1 and u != d + 1), u});
    if (u > 1)
      edges.emplace_back(u, u - 1);
  }
  while (edges.size() != n - 1) {
    if (q.empty()) return cout << "NO", 0;
    auto [dep, deg, v] = q.front();
    q.pop();
    if (deg == k)continue;
    if (dep == 0)continue;
    edges.emplace_back(u, v);
    q.push({dep, deg + 1, v});
    q.push({dep - 1, 1, u});
    ++u;
  }
  cout << "YES\n";
  for (auto [u, v]: edges) {
    cout << u << ' ' << v << '\n';
  }

  return 0;
}