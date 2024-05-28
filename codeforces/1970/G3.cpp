#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, m, c;
vector<pair<int, int>> g[N];
pair<int, int> e[500005];
int low[N], num[N], time_dfs;
int child[N];
int cc;
int br;
int is_bridge[500005];
bool used[500005];
vector<pair<int, int>> choice[N];

void reset() {
  for (int u = 1; u <= n; u++) {
    g[u].clear();
    child[u] = 0;
    low[u] = num[u] = 0;
  }
  for (int i = 1; i <= m; i++) {
    is_bridge[i] = used[i] = 0;
  }
  for (int i = 1; i <= cc; i++) {
    choice[i].clear();
  }
  time_dfs = 0;
  cc = 0;
  br = 0;
}

void dfs(int u) {
  low[u] = num[u] = ++time_dfs;
  child[u] = 1;
  for (auto [v, i] : g[u]) {
    if (used[i]) continue;
    used[i] = true;
    if (!num[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
      child[u] += child[v];
      if (low[v] >= num[v]) {
        is_bridge[i] = true;
        choice[cc].push_back({v, 0});
        ++br;
      }
    } else {
      low[u] = min(low[u], num[v]);
    }
  }
}

template <int SIZE = 1>
int64_t solve(int n) {
  if (n/2+1 >= SIZE) {
    return solve<min(SIZE * 2, N)>(n);
  }
  bitset<SIZE> bs[2];
  bs[0][0] = 1;
  for (int i = 1; i <= cc; i++) {
    int s = choice[i][0].first + choice[i][0].second;
    bs[1] |= bs[1] << s;
    for (auto [a, b] : choice[i]) {
      bs[1] |= bs[0] << a;
      bs[1] |= bs[0] << b;
    }
    bs[0] |= bs[0] << s;
  }
  int64_t best = 9e18;
  for (int i = 0; i <= n / 2; i++) {
    if (bs[0][i] or bs[1][i]) {
      best = min<int64_t>(best, 1ll * i * i + 1ll * (n - i) * (n - i));
    }
  }
  return best;
}

void solve() {
  cin >> n >> m >> c;
  reset();
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[i] = {u, v};
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }
  for (int u = 1; u <= n; u++) {
    if (!num[u]) {
      time_dfs = 0;
      ++cc;
      dfs(u);
      for (auto& [a, b] : choice[cc]) {
        int v = a;
        a = child[v];
        b = time_dfs - child[v];
      }
      choice[cc].emplace_back(0, time_dfs);
    }
  }
  if (cc == 1 and br == 0) {
    cout << "-1\n";
    return;
  }
  int64_t ans = solve(n);
  if (ans == 9e18) {
    cout << "-1\n";
    return;
  }
  cout << ans + 1ll * (cc - 1) * c << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
#define task "a"
#else
#define task ""
#endif
  if (fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
