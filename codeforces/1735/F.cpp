// LUOGU_RID: 159883231
/*
 * _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|      _|_|
 *       _|    _|        _|                _|        _|  _|    _|
 *     _|      _|_|_|      _|_|          _|      _|_|        _|
 *   _|        _|              _|      _|            _|    _|
 * _|_|_|_|_|  _|        _|_|_|      _|        _|_|_|    _|_|_|_|
 */

#include <bits/stdc++.h>

int main() {
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  freopen("task.err", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  using D = long double;
  constexpr D EPS = 1E-13;

  int test;
  std::cin >> test;
  while (test--) {
    int n;
    D ux, uy, rx, ry;
    std::cin >> n >> ux >> uy, rx = ux, ry = uy;
    std::vector<D> p(n), q(n);
    for (auto &v: p) std::cin >> v;
    for (auto &v: q) std::cin >> v;
    std::multiset<std::pair<D, D>> st;

    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < n; i++) {
      if (!ux && !uy) {
        std::cout << 0 << '\n';
        continue;
      }

      ux -= p[i], uy += q[i];
      rx += p[i], ry -= q[i];
      st.emplace(q[i] / p[i], 2 * p[i]);
      
      while (ry < -EPS) {
        auto [k, dx] = *st.rbegin();
        st.erase(std::prev(st.end()));
        D dy = k * dx;
        if (ry + dy < -EPS)
          ry += dy, rx -= dx;
        else {
          D s = ry / dy;
          rx += s * dx, ry -= s * dy;
          st.emplace(k, (1 + s) * dx);
          break;
        }
      }

      while (ux < -EPS) {
        auto [k, dx] = *st.begin();
        st.erase(st.begin());
        D dy = k * dx;
        if (ux + dx < -EPS)
          ux += dx, uy -= dy;
        else {
          D s = ux / dx;
          ux -= s * dx, uy += s * dy;
          st.emplace(k, (1 + s) * dx);
          break;
        }
      }

      std::cout << rx << '\n';
    }
  }

  return 0;
}