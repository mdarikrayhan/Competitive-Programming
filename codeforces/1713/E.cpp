#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include </algo/debug.h>
#else
#define debug(...) 42
#endif
#define tr(x, v) for (auto &x : v)
#define rp(i, v) for (int i = 0; i < sz(v); i++)
#define rep(i, x, y) for (int i = x; i < y; i++)
#define pr(i, v) for (int i = sz(v) - 1; i >= 0; i--)
#define per(i, x, y) for (int i = x; i > y; i--)
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  if (x > y)
    x = y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  if (x < y)
    x = y;
}
using ll = long long;
using E = vector<vector<int>>;
using EW = vector<vector<array<int, 2>>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define ed(x) end(x)
#define all(x) bg(x), ed(x)
#define lb lower_bound
#define ub upper_bound
#define sort(x) sort(all(x))
#define unique(x) (x).erase(unique(all(x)), x.end())
#define reverse(x) reverse(all(x))
void out(bool t) { cout << (t ? "YES" : "NO") << "\n"; }
template <class T> T max(const vector<T> &v) { return *max_element(all(v)); }
template <class T> T min(const vector<T> &v) { return *min_element(all(v)); }
template <class T> istream &operator>>(istream &is, vector<T> &v) {
  tr(x, v) cin >> x;
  return is;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  if (v.empty()) {
    os << "\n";
  } else {
    rp(i, v) os << v[i] << " \n"[i + 1 == (int)v.size()];
  }
  return os;
}

void run_case() {
  int n;
  cin >> n;
  vector<int> p(n);
  iota(all(p), 0);
  function<int(int)> find = [&](int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  };
  auto e = EW(n);
  auto merge = [&](int x, int y, int z) {
    int X = find(x), Y = find(y);
    if (X == Y)
      return;
    e[x].push_back({y, z});
    e[y].push_back({x, z});
    p[X] = Y;
  };

  vector<vector<int>> a(n, vector<int>(n, 0));
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) rep(j, i + 1, n) if (a[i][j] != a[j][i])
      merge(i, j, a[i][j] > a[j][i]);

  vector<int> weight(n);

  auto dfs = [&](auto self, int u, int p) -> void {
    for (auto [v, w] : e[u])
      if (v != p)
        weight[v] = weight[u] ^ w, self(self, v, u);
  };
  rep(i, 0, n) if (find(i) == i) weight[i] = 0, dfs(dfs, i, -1);
  rep(i, 0, n) rep(j, 0, n) cout << (weight[i] == weight[j] ? a[i][j] : a[j][i])
                                 << " \n"[j + 1 == n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    run_case();
  }

  return 0;
}