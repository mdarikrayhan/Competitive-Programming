#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int M = 5, T = 120, A = 3125;
int n, k, t, ans, p[M], fa[T], sz[T], mul[T][T];
vector<tuple<int, int, int>> tmp, rec;
inline void findf(int& x) {
  while (x != fa[x]) x = fa[x] = fa[fa[x]];
}
inline void unite(int u, int v, int w) {
  if (findf(u), findf(v), u == v) return;
  if (tmp.emplace_back(u, v, w), u < v) swap(u, v);
  !v && (ans += sz[u] * w), sz[fa[u] = v] += sz[u];
}
inline int& getid() {
  static int bel[A];
  int s = 0;
  for (int x : span(p, k)) (s *= k) += x;
  return bel[s];
}
inline void init() {
  int a[T][M];
  iota(p, p + k, 0);
  do memcpy(a[getid() = t++], p, k * sizeof(int));
  while (next_permutation(p, p + k));
  for (int i = 0; i < t; ++i)
    for (int j = 0; j < t; ++j) {
      for (int z = 0; z < k; ++z) p[z] = a[j][a[i][z]];
      mul[i][j] = getid();
    }
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k, ans = n * (n + 1) >> 1, init();
  for (int i = 1; i <= n; ++i) {
    for (int& x : span(p, k)) cin >> x, --x;
    iota(fa, fa + t, 0), fill_n(sz, t, 1), rec = exchange(tmp, {});
    for (int j = 0, p = getid(); j < t; ++j) unite(j, mul[j][p], i);
    for (auto [u, v, w] : rec) unite(u, v, w);
  }
  return cout << ans << endl, 0;
}