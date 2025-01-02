// LUOGU_RID: 159882912
/*
 * _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|      _|_|
 *       _|    _|        _|                _|        _|  _|    _|
 *     _|      _|_|_|      _|_|          _|      _|_|        _|
 *   _|        _|              _|      _|            _|    _|
 * _|_|_|_|_|  _|        _|_|_|      _|        _|_|_|    _|_|_|_|
 */

#include <bits/stdc++.h>

const int maxN = 1e5 + 1;

int n, tr[maxN], ans[maxN];

void Add(int x, int v) {
  for (; x <= n; x += x & -x)
    tr[x] += v;
}

int Query(int x) {
  int v = 0;
  for (; x; x -= x & -x)
    v += tr[x];
  return v;
}

std::map<std::pair<int, int>, int> buc;
std::vector<std::pair<int, int>> qur[maxN], hull[maxN];

int main() {
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  freopen("task.err", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int k;
    std::cin >> k;
    while (k--) {
      int x, y;
      std::cin >> x >> y;
      hull[i].emplace_back(x, y);
    }
  }
  
  int q;
  std::cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    qur[l].emplace_back(r, i);
  }

  for (int i = n; i >= 1; i--) {
    const auto &h = hull[i];
    int m = (int) h.size();
    for (int j = 0; j < m; j++) {
      auto cur = h[j], nxt = h[(j + 1) % m];
      int dx = nxt.first - cur.first;
      int dy = nxt.second - cur.second;
      int d = std::gcd(dx, dy);
      std::pair<int, int> offset{dx / d, dy / d};
      if (buc.count(offset))
        Add(buc[offset], -1);
      buc[offset] = i;
    }
    Add(i, m);
    for (auto [r, id]: qur[i])
      ans[id] = Query(r);
  }

  for (int i = 1; i <= q; i++)
    std::cout << ans[i] << '\n';

  return 0;
}