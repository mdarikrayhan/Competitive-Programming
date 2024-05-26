#include <bits/stdc++.h>
#define V vector
#define Vi vector<int>
#define sz(a) ((int)a.size())
#define fi first
#define se second
#define Int pair<int, int>
#define Inf ((int)1e9)
#define pb push_back
#define ins insert
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define Rep(i, x, y) for (int i = (x); i >= (y); i--)
#define seg int p, int l, int r
#define lid p << 1, l, mid
#define all(a) a.begin(), a.end()
#define rid p << 1 | 1, mid + 1, r
#define mid ((l + r) / 2)
#define Ceil(x, y) (((x) + (y)-1) / (y))
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
#define IO(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;

V<pair<Int, Int>> solve(int n, int m, int T) {
  V<set<int>> e(n + 5);
  V<pair<Int, Int>> Ans;
  auto add = [&](int x, int y, int xx, int yy) {
    e[x].erase(y), e[y].erase(x);
    e[xx].ins(yy), e[yy].ins(xx);
    if (T) swap(x, xx), swap(y, yy);
    Ans.pb({{x, y}, {xx, yy}});
  };

  for (int i = 1, x, y; i <= m; i++) cin >> x >> y, e[x].ins(y), e[y].ins(x);

  Vi vis(n + 5), F(n + 5), d(n + 5), res, dep(n + 5), in(n + 5), out(n + 5);
  int ti = 0;
  V<Int> gg;
  V<V<Int>> tr(n + 5);
  auto dfs = [&](auto lf, int x, int fa, int ff = 0) -> void {
    F[x] = fa, vis[x] = 1, dep[x] = dep[fa] + 1, in[x] = ++ti;
    int tmp = 0;
    for (int y : e[x])
      if (y ^ fa) {
        if (vis[y] && dep[y] < dep[x]) {
          if (y != F[F[x]]) gg.pb({x, y});
          d[x] = d[F[x]] = 1;
          if (F[F[x]] != 1 && F[x] != 1) tmp = 1;
        } else if (!vis[y])
          lf(lf, y, x, ff);
      }
    if (ff && tmp) res.pb(x);
    out[x] = ti;
  };
  dfs(dfs, 1, 0);

  for (auto i : gg) add(i.fi, i.se, i.fi, F[F[i.fi]]);
  gg.clear();

  For(i, 2, n) if (!d[i]) add(i, F[i], 1, i);

  fill(all(vis), 0), fill(all(d), 0);
  ti = 0;
  dfs(dfs, 1, 0, 1);

  int g = 0;
  for (int x : e[1])
    if (!d[x]) g = x;

  sort(all(res), [&](int x, int y) { return dep[x] > dep[y]; });
  for (int x : res) {
    if (in[x] < in[g] || in[x] > out[g]) {
      add(1, g, x, g);
      add(x, F[F[x]], F[x], g);
      add(F[x], F[F[x]], 1, F[x]);
      add(F[x], g, 1, x);
      add(g, x, 1, g);
    } else {
      add(1, g, 1, x);
      add(x, F[F[x]], F[x], 1);
      add(F[x], F[F[x]], 1, g);
    }
  }

  For(i, 2, n) e[i].erase(1);
  int K = m - (n - 1);
  for (int i = 2, j = 1; j <= K; j++, i += 2) {
    if (sz(e[i + 1])) {
      int t = *e[i + 1].begin();
      For(p, i, n) if (!sz(e[p])) g = p;
      add(i + 1, t, t, g);
    }
    if (sz(e[i])) {
      int t = *e[i].begin();
      add(i, t, i, i + 1);
    } else {
      For(p, i + 2, n) if (sz(e[p])) g = p;
      add(g, *e[g].begin(), i, i + 1);
    }
  }
  return Ans;
}

int main() {
#ifndef ONLINE_JUDGE
  IO(1);
#endif
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  if ((n - 1) + (n - 1) / 2 == m && n % 2 == 1) {
    map<Int, int> mp;
    for (int i = 1, x, y; i <= m; i++)
      cin >> x >> y, mp[{x, y}]++, mp[{y, x}]++;
    for (int i = 1, x, y; i <= m; i++)
      cin >> x >> y, mp[{x, y}]--, mp[{y, x}]--;
    for (auto i : mp) {
      if (i.se) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    cout << "0\n";
    return 0;
  }

  auto res1 = solve(n, m, 0), res2 = solve(n, m, 1);
  reverse(all(res2));
  for (auto x : res2) res1.pb(x);

  cout << "YES\n";
  cout << sz(res1) << '\n';
  for (auto i : res1)
    cout << i.fi.fi << ' ' << i.fi.se << ' ' << i.se.fi << ' ' << i.se.se
         << '\n';
}