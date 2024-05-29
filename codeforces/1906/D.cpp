#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
auto& operator<<(auto&, pair<auto, auto>);
auto operator<<(auto& o, auto x) -> decltype(x.end(), o) {
  o << '{';
  for (int i = 0; auto y : x) o << ", " + !i++ * 2 << y;
  return o << '}';
}
auto& operator<<(auto& o, pair<auto, auto> x) {
  return o << '(' << x.first << ", " << x.second << ')';
}
void __print(auto... x) { ((cerr << ' ' << x), ...) << endl; }
#define debug(x...) cerr << "[" #x "]:", __print(x)
#else
#define debug(...) 2137
#endif

/**
 * Opis: Podstawowy szablon do geometrii.
 * Do wszystkich porównań należy używać `sgn`.
 */
#pragma once

using D = ll;
const D EPS = D(1e-9);
int sgn(D x) { return (x > EPS) - (x < -EPS); }
struct P {
  D x, y;
  P operator+(P o) const { return {x + o.x, y + o.y}; }
  P operator-(P o) const { return {x - o.x, y - o.y}; }
  P operator*(D a) const { return {x * a, y * a}; }
  P operator/(D a) const { return {x / a, y / a}; }
  auto operator<=>(P o) const {
    return pair(sgn(x - o.x), sgn(y - o.y)) <=> pair(0, 0);
  }
  bool operator==(P o) const {
    return sgn(x - o.x) == 0 && sgn(y - o.y) == 0;
  }
};
D cross(P a, P b) { return a.x * b.y - a.y * b.x; }
D dot(P a, P b) { return a.x * b.x + a.y * b.y; }
D norm(P a) { return a.x * a.x + a.y * a.y; }
auto& operator<<(auto& o, P a) {
  return o << '(' << a.x << ", " << a.y << ')';
}
/**
 * Opis: Znajduje najbliższe punkty styczne różne od $a$.
 * Wielokąt musi być CCW i $n \geq 3$.
 * Punkt $a$ nie może leżeć w ściśłym wnętrzu wielokąta.
 * Czas: O(\log n)
 */
#pragma once

//#include "Point.h"

pair<P, P> tangents(const vector<P>& p, P a) {
  int n = ssize(p);
  P t[2];
  for (int it = 0; it < 2; it++) {
    auto dir = [&](int i) {
      P u = p[i] - a;
      P v = p[i < n - 1 ? i + 1 : 0] - a;
      int c = sgn(cross(u, v));
      if (c != 0) return c < 0;
      if (sgn(dot(u, v)) <= 0) return true;
      return sgn(norm(u) - norm(v)) > 0;
    };
    auto dirx = [&](int i) { return dir(i) ^ it; };
    if (dirx(0) == 1 && dirx(n - 1) == 0) {
      t[it] = p[0];
      continue;
    }
    int s[2] = {0, n - 1};
    while (s[1] - s[0] > 2) {
      int mid = (s[0] + s[1]) / 2;
      int x = dirx(mid);
      if (dirx(s[x ^ 1]) == (x ^ 1)) {
        s[x] = mid;
      } else {
        bool b = sgn(cross(p[mid] - a, p[s[1]] - a)) < 0;
        s[b ^ x ^ it ^ 1] = mid;
      }
    }
    t[it] = p[s[0] + 1 + (dirx(s[0] + 1) == 0)];
  }
  return {t[0], t[1]};
}

using ld = long double;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<P> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  int q;
  cin >> q;
  cout << fixed << setprecision(12);
  while (q--) {
    P a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    auto [al, ar] = tangents(p, a);
    auto [bl, br] = tangents(p, b);
    debug(a, al, ar);
    debug(b, bl, br);
    if (!(cross(al - a, b - a) < 0 && cross(b - a, ar - a) < 0 && cross(bl - b, a - b) < 0 && cross(a - b, br - b) < 0)) {
      cout << sqrt(norm(a - b)) << '\n';
      continue;
    }
    bool any = false;
    ld ans = 1e20;
    ll d = cross(al - a, br - b);
    if (d != 0) {
      any = true;
      ll u = cross(al - b, br - b);
      ll v = cross(br - b, a - b);
      ld x = ((ld)a.x * u + (ld)al.x * v) / d;
      ld y = ((ld)a.y * u + (ld)al.y * v) / d;
      debug(x, y);
      ans = min(ans, hypotl(x - a.x, y - a.y) + hypotl(x - b.x, y - b.y));
    }
    d = cross(ar - a, bl - b);
    if (d != 0) {
      any = true;
      ll u = cross(ar - b, bl - b);
      ll v = cross(bl - b, a - b);
      ld x = ld((ld)a.x * u + (ld)ar.x * v) / d;
      ld y = ld((ld)a.y * u + (ld)ar.y * v) / d;
      debug(x, y);
      ans = min(ans, hypotl(x - a.x, y - a.y) + hypotl(x - b.x, y - b.y));
    }
    if (any) {
      cout << ans << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
