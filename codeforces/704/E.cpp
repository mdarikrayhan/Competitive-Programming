// LUOGU_RID: 159253304
#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i <= (r); ++i)
#define ROF(i, l, r) for (int i = r; i >= (l); --i)
#define rep(n) FOR (_, 1, n)
#define each(i, x) for (auto& i : x)

using namespace std;

using ll = long long;
using db = long double;
using str = string;

#define mp make_pair
#define f first
#define s second

#define il inline
#define ttt template <typename T
ttt > using V = vector<T>;
ttt, size_t n > using A = array<T, n>;

#define sz(x) int((x).size())
#define bg begin
#define all(x) bg(x), end(x)
#define rsz resize
#define pb push_back
#define eb emplace_back

ttt > il bool ckmin(T& x, const T& y) { return y < x ? x = y, true : false; }
ttt > il bool ckmax(T& x, const T& y) { return x < y ? x = y, true : false; }

constexpr int N = 1e5 + 5;
int n, m;
db ans = 1e18;
A<int, N> siz, fa, dep, top;
A<V<int>, N> adj;

il ll cmp(ll a, ll b, ll c, ll d) {
  return (b ^ d) >= 0 ? a * d - b * c : b * c - a * d;
}
struct Seg {
  int x, v, b, e;
  bool chk(int p, int q) const {
    return cmp(p, q, b, v) >= 0 && cmp(p, q, e, v) <= 0;
  }
};
il bool operator<(const Seg& x, const Seg& y) {
  return cmp(x.b, x.v, y.b, y.v) < 0;
}
il bool operator==(const Seg& x, const Seg& y) {
  return cmp(x.b, x.v, y.b, y.v) == 0;
}
A<V<Seg>, N> seg;

void dfs1(int u, int p) {
  siz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1;
  each (v, adj[u]) {
    adj[v].erase(find(all(adj[v]), u));
    dfs1(v, u), siz[u] += siz[v];
    if (siz[v] > siz[adj[u][0]]) swap(v, adj[u][0]);
  }
}
void dfs2(int u) {
  each (v, adj[u]) top[v] = v == adj[u][0] ? top[u] : v, dfs2(v);
}
int lca(int u, int v) {
  for (; top[u] != top[v]; u = fa[top[u]])
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  return dep[u] < dep[v] ? u : v;
}
void add(int t, int c, int u, int v) {
  t *= c;
  int l = lca(u, v), x = u, y = v;
  for (int z; (z = top[x]) != top[l]; x = fa[z])
    seg[z].pb({dep[x], -c, -(t + dep[u] - dep[x]), -(t + dep[u] - dep[z] + 1)});
  for (int z; (z = top[y]) != top[l]; y = fa[z])
    seg[z].pb({dep[z] - 1, c, t + dep[u] + dep[z] - 1 - 2 * dep[l],
               t + dep[u] + dep[y] - 2 * dep[l]});
  if (dep[x] > dep[y])
    seg[top[l]].pb(
        {dep[x], -c, -(t + dep[u] - dep[x]), -(t + dep[u] - dep[l])});
  else
    seg[top[l]].pb(
        {dep[l], c, t + dep[u] - dep[l], t + dep[u] + dep[y] - 2 * dep[l]});
}

db t;
int p, q;
struct Cmp {
  bool operator()(const Seg& a, const Seg& b) const {
    return cmp((a.x - a.b) - (b.x - b.b), 1, (ll)p * (b.v - a.v), q) < 0;
  }
};
void consider(const Seg& a, const Seg& b) {
  int p = (a.x - a.b) - (b.x - b.b), q = b.v - a.v;
  if (q == 0) {
    if (p == 0) return void(ans = t);
  }
  if (a.chk(p, q) && b.chk(p, q)) ckmin(ans, (db)p / q);
}
void proc(V<Seg>& a) {
  sort(all(a));
  V<pair<int, db>> b;
  each (i, a) {
    b.eb(i.x, (db)i.b / i.v);
    if (i.b != i.e) b.eb(i.x + i.e - i.b, (db)i.e / i.v);
  }
  sort(all(b));
  FOR (i, 0, sz(b) - 2)
    if (b[i] == b[i + 1]) ckmin(ans, b[i].s);
  set<Seg, Cmp> s;
  each (i, a) {
    t = (db)i.b / i.v;
    if (t >= ans) break;
    p = i.b, q = i.v;
    auto it = s.lower_bound(i);
    while (it != end(s) && cmp(it->e, it->v, i.b, i.v) <= 0) it = s.erase(it);
    while (it != begin(s) && cmp(prev(it)->e, prev(it)->v, i.b, i.v) <= 0)
      s.erase(prev(it));
    if (it != end(s)) consider(i, *it);
    if (it != begin(s)) consider(i, *prev(it));
    s.insert(it, i);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false), cin.exceptions(cin.failbit);
  cin >> n >> m;

  rep (n - 1) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs1(1, 0), top[1] = 1, dfs2(1);

  rep (m) {
    int t, c, u, v;
    cin >> t >> c >> u >> v;
    add(t, c, u, v);
  }
  FOR (i, 1, n) proc(seg[i]);

  if (ans == 1e18)
    cout << "-1\n";
  else
    cout << fixed << setprecision(10) << ans << "\n";
}
