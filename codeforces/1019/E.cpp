// LUOGU_RID: 159883531
/*
 * _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|      _|_|
 *       _|    _|        _|                _|        _|  _|    _|
 *     _|      _|_|_|      _|_|          _|      _|_|        _|
 *   _|        _|              _|      _|            _|    _|
 * _|_|_|_|_|  _|        _|_|_|      _|        _|_|_|    _|_|_|_|
 */

#include <bits/stdc++.h>

template <typename D> int Sign(D x) {
  constexpr D EPS = std::is_integral<D>::value ? 0 : 1E-10;
  /*
    if (x > +EPS) return +1;
    if (x < -EPS) return -1;
    return 0;
  */
  return (x > +EPS) - (x < -EPS);
}

template<typename D, typename LD>
struct Vector {
  D x{}, y{};

  Vector() {}
  Vector(D x, D y) : x(x), y(y) {}

  Vector operator-() const { return {-x, -y}; }

  Vector operator*(D scalar) const { return {x * scalar, y * scalar}; }
  Vector operator/(D scalar) const { return {x / scalar, y / scalar}; }

  Vector operator+(const Vector& rhs) const { return {x + rhs.x, y + rhs.y}; }
  Vector operator-(const Vector& rhs) const { return {x - rhs.x, y - rhs.y}; }

  bool operator!=(const Vector& rhs) const { return x != rhs.x || y != rhs.y; }

  friend LD dot(Vector a, Vector b) { return (LD) a.x * b.x + (LD) a.y * b.y; }
  friend LD crs(Vector a, Vector b) { return (LD) a.x * b.y - (LD) a.y * b.x; }

  D sqd() const { return x * x + y * y; }
  D len() const { return std::sqrt(sqd()); }
  D ang() const { return std::atan2(y, x); }

  Vector norm() const { return (*this) / len(); }

  friend bool par(Vector a, Vector b) { return Sign(crs(a, b)) == 0; }

  friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
    return os << '(' << v.x << ", " << v.y << ')';
  }
};

using D = long long;
using LD = __int128;
using Vec = Vector<D, LD>;

std::vector<Vec> ConvexHull(std::vector<Vec> points) {
  int n = (int) points.size(), top = 0;
  std::vector<Vec> sta(n), result;
  std::sort(points.begin(), points.end(), [&](Vec a, Vec b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
  });
  for (int i = 0; i < n; i++) {
    auto p = points[i];
    while (top > 1 && crs(p - sta[top - 2],
      sta[top - 1] - sta[top - 2]) <= 0) top--;
    if (!top || p != sta[top - 1]) sta[top++] = p;
  }
  for (int i = 0; i < top; i++)
    result.emplace_back(sta[i]);
  return result;
}

const int maxN = 1e5 + 1, maxM = 2e5 + 1;

bool cut[maxM];
int vTot, eTot, siz[maxM];
std::tuple<int, int, Vec> edge[maxM];
std::vector<std::pair<int, Vec>> pTree[maxN];
std::vector<std::tuple<int, Vec, int>> vTree[maxM];

void MakeVTree(int u, int prt) {
  int p = u;
  auto Edge = [&](int u, int v, Vec w) {
    edge[++eTot] = std::make_tuple(u, v, w);
    vTree[u].emplace_back(v, w, eTot);
    vTree[v].emplace_back(u, w, eTot);
    // std::cerr << u << ' ' << v << ' ' << line << '\n';
  };
  for (auto [v, w] : pTree[u])
    if (v != prt) {
      Edge(p, v, w);
      MakeVTree(v, u);
      Edge(p, ++vTot, Vec());
      p = vTot;
    }
}

void GetTSize(int u, int prt) {
  siz[u] = 1;
  for (auto [v, w, id] : vTree[u])
    if (v != prt && !cut[id])
      GetTSize(v, u), siz[u] += siz[v];
}

std::pair<int, int> FindEdge(int u, int prt, int sum) {
  std::pair<int, int> ans(INT_MAX, -1);
  for (auto [v, w, id] : vTree[u])
    if (v != prt && !cut[id]) {
      std::pair<int, int> pv(std::max(sum - siz[v], siz[v]), id);
      ans = std::min({ans, FindEdge(v, u, sum), pv});
    }
  return ans;
}

std::vector<Vec> points, all;

void DFS(int u, int prt, Vec line) {
  bool son = false;
  for (auto [v, w, id] : vTree[u])
    if (v != prt && !cut[id])
      DFS(v, u, w + line), son = true;
  if (!son) points.emplace_back(line);
}

void Solve(int u) {
  GetTSize(u, 0);
  int ct = FindEdge(u, 0, siz[u]).second;
  if (~ct) cut[ct] = true;
  else return;
  auto [p1, p2, base] = edge[ct];
  // std::cerr << p1 << ' ' << p2 << ' ' << ct << '\n';

  std::vector<Vec> segs;
  for (int step = 0; step < 2; step++) {
    points.clear(), DFS(p1, p2, Vec());
    auto hull = ConvexHull(points);
    base = base + hull[0];
    for (int i = 0; i < (int) hull.size() - 1; i++)
      segs.emplace_back(hull[i + 1] - hull[i]);

    // std::cerr << '\n';
    // for (auto p : hull) std::cerr << p << '\n';

    std::swap(p1, p2);
  }

  std::sort(segs.begin(), segs.end(), [&](Vec a, Vec b) {
    return crs(a, b) < 0;
  });

  // std::cerr << '\n' << base;
  all.emplace_back(base);
  for (auto v : segs) {
    all.emplace_back(base = base + v);
    // std::cerr << '\n' << base;
  }

  // std::cerr << "\n\n";
  Solve(p1), Solve(p2);
}

int main() {
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  freopen("task.err", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i < n; i++) {
    Vec w;
    int u, v;
    std::cin >> u >> v >> w.x >> w.y;
    pTree[u].emplace_back(v, w);
    pTree[v].emplace_back(u, w);
  }
  vTot = n, MakeVTree(1, 0), Solve(1);

  // for (auto v : all) std::cout << v << '\n';
  all.emplace_back(0, 0);
  auto hull = ConvexHull(all);
  // for (auto v : hull) std::cerr << v << '\n';
  auto cur = hull.begin(), nxt = std::next(cur);
  for (int i = 0; i < m; i++) {
    auto Get = [&](Vec line) {return i * line.x + line.y; };
    while (nxt != hull.end() && Get(*nxt) >= Get(*cur)) cur++, nxt++;
    std::cout << Get(*cur) << ' ';
  }

  return 0;
}