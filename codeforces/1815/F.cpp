#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 2e6 + 6;

ll n, m;
std::vector adj(N, std::vector<std::pair<int, int>>());
std::vector<std::pair<int, int>> vis(1e7 + 5);
std::vector<std::array<int, 3>> e(N), f(N);
std::vector<ll> a(N), b(N);

void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> e[i][j];
      adj[e[i][j]].push_back({i, j});
    }
    f[i][0] = 3;
    f[i][1] = 1;
    f[i][2] = 1;
    a[e[i][0]] += f[i][0] + f[i][2];
    a[e[i][1]] += f[i][1] + f[i][0];
    a[e[i][2]] += f[i][2] + f[i][1];
  }
  for (int i = 1; i <= n; i++) {
    for (auto c : adj[i]) {
      for (int d = 0; d < c.second; d++) {
        vis[a[e[c.first][d]]] = {c.first, d};
      }
    }
    while (vis[a[i]].first != 0) {
      int ed = vis[a[i]].first;
      if (i == e[ed][1]) {
        a[i]++;
        a[e[ed][2]]++;
        f[ed][1]++;
      } else {
        a[i] += 2;

        f[ed][0]--;
        f[ed][1]++;
        f[ed][2]++;
      }
    }

    for (auto c : adj[i]) {
      for (int d = 0; d < c.second; d++) {
        vis[a[e[c.first][d]]] = {0, 0};
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
