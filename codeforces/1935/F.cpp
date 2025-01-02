#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
const int MX = 2e5 + 23;

vector<int> e[MX];
vector<pii> ans[MX];
int n;

void init() {
  for (int i = 1; i <= n; ++i) {
    e[i].clear();
    ans[i].clear();
  }
}

int mn[MX][2], mx[MX][2], fa[MX][18], dep[MX];

int jump(int x, int aim) {
  if (dep[x] <= dep[aim]) return fa[aim][0];
  for (int i = 17; ~i; --i)
    if (dep[fa[x][i]] > dep[aim])
      x = fa[x][i];
  if (fa[x][0] == aim)
    return x;
  return fa[aim][0];
}

void dapai(int x, int f, int depth) {
  dep[x] = depth;
  mn[x][0] = x;
  mx[x][0] = x;
  mn[x][1] = INF;
  mx[x][1] = -INF;
  fa[x][0] = f;
  for (int i = 1; i < 18; ++i)
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (auto y : e[x]) {
    if (y == f) continue;
    dapai(y, x, depth + 1);
    mn[x][1] = min(mn[x][1], mn[y][0]);
    if (mn[x][1] < mn[x][0]) swap(mn[x][1], mn[x][0]);
    mx[x][1] = max(mx[x][1], mx[y][0]);
    if (mx[x][1] > mx[x][0]) swap(mx[x][1], mx[x][0]);
  }
}

namespace DSU {
  int fa[MX], sz[MX];
  void init(vector<int> p) {
    for (auto i : p) fa[i] = i, sz[i] = 1;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  int isconnected(int x, int y) {
    return find(x) == find(y);
  }
  void link(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    fa[y] = x, sz[x] += sz[y];
  }
}

vector<int> use;
void dfs(int x, int f, int fmax, int fmin) {
  vector<array<int, 4>> E1;
  for (auto y : e[x]) {
    if (y == f) continue;
    if (mn[y][0] > 1) {
      E1.push_back({jump(mn[y][0] - 1, x), y, mn[y][0] - 1, mn[y][0]});
    }
    if (mx[y][0] < n) {
      E1.push_back({jump(mx[y][0] + 1, x), y, mx[y][0] + 1, mx[y][0]});
    }
  }

  if (fmax + 1 <= n && fmax >= 1) {
    E1.push_back({f, jump(fmax + 1, x), fmax, fmax + 1});
  }

  if (fmin - 1 >= 1 && fmin <= n) {
    E1.push_back({f, jump(fmin - 1, x), fmin, fmin - 1});
  }

  if (x - 1 >= 1 && x + 1 <= n) {
    E1.push_back({jump(x - 1, x), jump(x + 1, x), x - 1, x + 1});
  }

  use.clear();
  for (auto y : e[x]) use.push_back(y);
  DSU::init(use);
  int res = 0, cnt = 0;
  for (auto [y, z, u, v] : E1) {
    if (u == x || v == x) continue;
    if (!DSU::isconnected(y, z)) {
      res += abs(u - v);
      ++cnt;
      DSU::link(y, z);
      ans[x].push_back({u, v});
    }
  }

  for (auto y : e[x]) {
    if (y == f) continue;
    int nmx = mx[y][0] == mx[x][0] ? mx[x][1] : mx[x][0];
    int nmn = mn[y][0] == mn[x][0] ? mn[x][1] : mn[x][0];
    dfs(y, x, max(fmax, nmx), min(fmin, nmn));
  }
}

void output() {
  for (int i = 1; i <= n; ++i) {
    int w = 0;
    for (auto [x, y] : ans[i]) {
      w += abs(x - y);
    }
    cout << w << " " << ans[i].size() << "\n";
    for (auto [x, y] : ans[i]) {
      cout << x << " " << y << "\n";
    }
    cout << "\n";
    ans[i].clear();
  }
}

void solve() {
  cin >> n;
  init();
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dapai(1, 0, 1);
  dfs(1, 0, -INF, INF);
  output();
}

int main() {
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}