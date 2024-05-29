#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5 + 9, A = 3;
int dat[N], id[N];
void sort65536_id(int *val, int n) {
  int *a = id, *b = dat, cnt[65536];
  iota(id, id + n, 0);
  for (int i = 0; i < n; ++i) val[i] += 1 << 30;
  for (int ps = 0; ps < 32; ps += 16, swap(a, b)) {
    memset(cnt, 0, sizeof cnt);
    for (int x : span(val, n)) ++cnt[x >> ps & 65535];
    partial_sum(cnt, cnt + 65536, cnt);
    for (int x : span(a, n) | views::reverse)
      b[--cnt[val[x] >> ps & 65535]] = x;
  }
  for (int i = 0; i < n; ++i) val[i] -= 1 << 30;
}
void sort65536(int *a, int n) {
  sort65536_id(a, n), memcpy(dat, a, n * sizeof(int));
  for (int i = 0; i < n; ++i) a[i] = dat[id[i]];
}
int n, m, e, s, pos[A][N], len[A], cst[A][N];
int tqry[N], res[N][A];
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> e >> s >> n >> m;
  for (int t, x; n; --n)
    if (cin >> t >> x, x < e)
      while (t--) pos[t][len[t]++] = x;
  auto calc = [](int x, int y, int z) {
    return cst[x][y] + max(pos[x][y] - z - s, 0ll);
  };
  for (int i = 0; i < A; ++i) {
    int *p = pos[i], n = len[i];
    sort65536(p, n), p[n] = e;
    for (int j = n - 1; ~j; --j) cst[i][j] = calc(i, j + 1, p[j]);
  }
  for (int &x : span(tqry, m)) cin >> x;
  sort65536_id(tqry, m);
  for (int i = 0; i < A; ++i) {
    int j = 0;
    for (int p = 0; p < m; ++p) {
      int x = tqry[id[p]];
      while (j <= len[i] && pos[i][j] < x) ++j;
      res[id[p]][i] = j;
    }
  }
  for (int i = 0, c[A]; i < m; ++i) {
    for (int j = 0; j < A; ++j) c[j] = calc(j, res[i][j], tqry[i]);
    if (c[0])
      cout << -1 << ' ' << -1 << '\n';
    else
      cout << c[1] << ' ' << c[2] - c[1] << '\n';
  }
  return cout << flush, 0;
}