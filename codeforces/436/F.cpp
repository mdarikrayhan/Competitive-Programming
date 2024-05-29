// LUOGU_RID: 156719574
# include <bits/stdc++.h>

using namespace std;

namespace lyre {
  constexpr int nmax = 100'100;
  constexpr int bmax = sqrt(nmax) + 5;
  int n, m, w, B;
  int a[nmax], b[nmax];
  vector<int> atb[nmax];
  long long ans[nmax];
  long long val[nmax];
  int pos[nmax];
  struct block {
    int lazy, L, R;
    int q[bmax], head, tail;
    constexpr block() : lazy(), L(), R(), q(), head(), tail() {}
    constexpr void add(int k) { lazy += k; }
    void rebuild() {
      for (int i = L; i <= R; ++i)
        val[i] += 1ll * lazy * i;
      head = 1, tail = 0, lazy = 0;
      auto shrink = [&] (int x) -> bool {
        if (head >= tail) return false;
        auto dx = q[tail] - q[tail - 1];
        auto dy = val[q[tail]] - val[q[tail - 1]];
        auto du = x - q[tail];
        auto dv = val[x] - val[q[tail]];
        if (dy * du <= dv * dx) return --tail, true;
        return false;
      };
      for (int i = L; i <= R; ++i) {
        while (shrink(i));
        q[++tail] = i;
      }
    }
    pair<long long, int> qmax() {
      auto shrink = [&] () -> bool {
        if (head >= tail) return false;
        auto dx = q[head + 1] - q[head];
        auto dy = val[q[head + 1]] - val[q[head]];
        if (dy > -1ll * lazy * dx) return ++head, true;
        return false;
      };
      while (shrink());
      return make_pair(val[q[head]] + 1ll * lazy * q[head], q[head]);
    }
  } blk[bmax];
  void ins(int x) {
    for (int i = 0; i < x / B; ++i) blk[i].add(1);
    for (int i = blk[x / B].L; i <= x; ++i) val[i] += i;
    blk[x / B].rebuild();
  }
  pair<long long, int> qmax() {
    pair<long long, int> r;
    for (int i = 0; i <= m / B; ++i) {
      auto [v, p] = blk[i].qmax();
      if (v >= r.first) r = make_pair(v, p);
    }
    return r;
  }
  void main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i] >> b[i];
      atb[b[i]].push_back(a[i]);
    }
    auto u = *max_element(b + 1, b + n + 1) + 1;
    m = *max_element(a + 1, a + n + 1) + 1;
    m = max(m, u), B = sqrt(m);
    for (int i = 0; i <= m / B; ++i) {
      blk[i].L = i * B;
      blk[i].R = min((i + 1) * B - 1, m);
      blk[i].rebuild();
    }
    for (int i = u; i >= 0; --i)
      ans[i] = ans[i + 1] + atb[i].size();
    for (int i = 0; i <= u; ++i)
      ans[i] = 1ll * w * i * ans[i];
    for (int i = 0; i <= u; ++i) {
      auto [v, p] = qmax();
      ans[i] += v, pos[i] = p;
      for (auto x : atb[i]) ins(x);
    }
    for (int i = 0; i <= u; ++i)
      cout << ans[i] << ' ' << pos[i] << '\n';
  }
}

int main() { lyre::main(); }
