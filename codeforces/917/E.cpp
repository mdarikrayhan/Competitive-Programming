// LUOGU_RID: 157535344
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
// using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(ll x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int K = 18;
constexpr int N = 2e5 + 5;
constexpr int S = 26;
constexpr int mod = 1004535809;
constexpr int base = 131;
string s[N];
int n, m, q, pw[N];
int u[N], v[N], ulcp[N], vlcp[N], uarg[N], varg[N], d[N], k[N], ans[N];
namespace tree {
  vector<pii> e[N];
  int lg, dep[N], hsh[N], fch[N], anc[K][N];
  int get(int u, int v) {
    assert(dep[u] <= dep[v]);
    return (hsh[v] + mod - 1ll * hsh[u] * pw[dep[v] - dep[u]] % mod) % mod;
  }
  void dfs(int id, int ff) {
    dep[id] = dep[anc[0][id] = ff] + 1;
    for(pii _ : e[id]) {
      int it = _.first;
      if(it == ff) continue;
      hsh[it] = (1ll * hsh[id] * base + _.second) % mod;
      fch[it] = _.second, dfs(it, id);
    }
  }
  void build() {
    lg = 31 - __builtin_clz(n);
    dfs(1, 0);
    for(int i = 1; i <= lg; i++)
      for(int j = 1; j <= n; j++)
        anc[i][j] = anc[i - 1][anc[i - 1][j]];
  }
  int kth(int u, int k) {
    for(int i = lg; ~i; i--) if(k >> i & 1) u = anc[i][u];
    return u;
  }
  int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    u = kth(u, dep[u] - dep[v]);
    if(u == v) return u;
    for(int i = lg; ~i; i--) if(anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
    return anc[0][u];
  }
}
struct BIT {
  int c[N];
  void add(int x, int v) {while(x < N) c[x] += v, x += x & -x;}
  void add(int l, int r, int v) {add(l, v), add(r + 1, -v);}
  int query(int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;}
  int query(int l, int r) {return query(r) - query(l - 1);}
};
struct acam {
  int node, son[N][S], fa[N], ed[N];
  void ins(string s, int id) {
    int p = 0;
    for(char it : s) {
      if(!son[p][it - 'a']) son[p][it - 'a'] = ++node;
      p = son[p][it - 'a'];
    }
    ed[id] = p;
  }
  int dn, dfn[N], sz[N];
  vector<int> e[N], buc[N];
  void dfs(int id) {
    dfn[id] = ++dn, sz[id] = 1;
    for(int it : e[id]) dfs(it), sz[id] += sz[it];
  }
  void build() {
    queue<int> q;
    for(int i = 0; i < S; i++) if(son[0][i]) q.push(son[0][i]);
    while(!q.empty()) {
      int t = q.front(); q.pop();
      e[fa[t]].push_back(t);
      for(int i = 0; i < S; i++)
        if(son[t][i]) q.push(son[t][i]), fa[son[t][i]] = son[fa[t]][i];
        else son[t][i] = son[fa[t]][i];
    }
    dfs(0);
  }
  BIT tr;
  void solve(int id, int ff, int cur) {
    if(cur) tr.add(dfn[cur], 1);
    for(int it : buc[id]) {
      int id = abs(it), c = id / it;
      int x = ed[k[id]], l = dfn[x], r = dfn[x] + sz[x] - 1;
      ans[id] += tr.query(l, r) * c;
    }
    for(pii _ : tree::e[id]) {
      int it = _.first;
      if(it != ff) solve(it, id, son[cur][_.second - 'a']);
    }
    if(cur) tr.add(dfn[cur], -1);
  }
} A, AR;
struct border {
  int lg, dn, dfn[N], sz[N], nxt[N], anc[K][N];
  vector<int> e[N];
  void dfs(int id) {
    dfn[id] = ++dn, sz[id] = 1;
    for(int it : e[id]) dfs(it), sz[id] += sz[it];
  }
  void build(int n, int *s) {
    dn = 0;
    for(int i = 0; i <= n; i++) e[i].clear();
    for(int i = 2, j = 0; i <= n; i++) {
      while(j && s[j + 1] != s[i]) j = nxt[j];
      anc[0][i] = nxt[i] = j += s[j + 1] == s[i];
    }
    for(int i = 1; i <= n; i++) e[nxt[i]].push_back(i);
    dfs(0), lg = 31 - __builtin_clz(dn);
    for(int i = 1; i <= lg; i++)
      for(int j = 0; j <= dn; j++)
        anc[i][j] = anc[i - 1][anc[i - 1][j]];
  }
  int binary(int x, int lim) {
    if(x <= lim) return x;
    for(int i = lg; ~i; i--) if(anc[i][x] > lim) x = anc[i][x];
    return anc[0][x];
  }
} ori, rev;
namespace combine {
  vector<int> buc[N];
  BIT tr;
  void dfs(int n, int id) {
    int l = rev.dfn[n - id], r = l + rev.sz[n - id] - 1;
    if(id && id < n) tr.add(l, r, 1);
    for(int it : buc[id]) ans[it] += tr.query(rev.dfn[varg[it]]);
    for(int it : ori.e[id]) dfs(n, it);
    if(id && id < n) tr.add(l, r, -1);
  }
  void solve(int n, vector<int> &qu) {
    for(int i = 1; i <= n; i++) buc[i].clear();
    for(int it : qu) {
      uarg[it] = ori.binary(uarg[it], ulcp[it]);
      varg[it] = rev.binary(varg[it], vlcp[it]);
      if(uarg[it] + varg[it] < n) continue;
      buc[uarg[it]].push_back(it);
    }
    dfs(n, 0);
  }
}
namespace sa {
  int n, s[N];
  vector<int> qu[N];
  int sa[N], rk[N], ork[N], buc[N], id[N], hsh[N];
  int get(int l, int r) {return l--, (hsh[r] + mod - 1ll * hsh[l] * pw[r - l] % mod) % mod;}
  bool cmp(int a, int b, int w) {return ork[a] == ork[b] && ork[a + w] == ork[b + w];}
  void build() {
    int m = 1 << 7, p = 0;
    memset(rk, 0, n + 5 << 2);
    memset(buc, 0, m + 5 << 2);
    for(int i = 1; i <= n; i++) buc[rk[i] = s[i]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = n; i; i--) sa[buc[rk[i]]--] = i;
    for(int w = 1; ; w <<= 1, m = p, p = 0) {
      for(int i = n - w + 1; i <= n; i++) id[++p] = i;
      for(int i = 1; i <= n; i++) if(sa[i] > w) id[++p] = sa[i] - w;
      memset(buc, 0, m + 5 << 2);
      memcpy(ork, rk, n + 5 << 2);
      p = 0;
      for(int i = 1; i <= n; i++) buc[rk[i]]++;
      for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
      for(int i = n; i; i--) sa[buc[rk[id[i]]]--] = id[i];
      for(int i = 1; i <= n; i++) rk[sa[i]] = cmp(sa[i - 1], sa[i], w) ? p : ++p;
      if(p == n) break;
    }
  }
  pair<int, pii> lcp(int id, int d, int u) {
    assert(u != d);
    auto chk = [&](int p) {
      int dis = tree::dep[p] - tree::dep[d];
      if(id + dis - 1 > n) return false; // add this line
      return tree::get(d, p) == get(id, id + dis - 1);
    };
    for(int i = tree::lg; ~i; i--) {
      int x = tree::anc[i][u];
      if(tree::dep[x] <= tree::dep[d]) continue;
      if(!chk(x)) u = x;
    }
    int nct = 0;
    if(!chk(u)) nct = tree::fch[u], u = tree::anc[0][u];
    int L = tree::dep[u] - tree::dep[d];
    return {L, {s[id + L], nct}};
  }
  void solve() {
    for(int i = 1; i <= m; i++) {
      if(qu[i].empty()) continue;
      n = ::s[i].size(), s[n + 1] = 0;
      for(int j = 1; j <= n; j++) s[j] = ::s[i][n - j];
      auto calc = [&](border &T, int *u, int *L, int *arg) {
        for(int j = 1; j <= n; j++) hsh[j] = (1ll * hsh[j - 1] * base + s[j]) % mod;
        build(), T.build(n, s);
        for(int it : qu[i]) {
          int l = 0, r = n;
          while(l < r) {
            int m = l + r + 2 >> 1;
            pii dat = lcp(sa[m], d[it], u[it]).second;
            if(dat.first < dat.second) l = m;
            else r = m - 1;
          }
          if(l) {
            int tmp = lcp(sa[l], d[it], u[it]).first;
            if(tmp > L[it]) L[it] = tmp, arg[it] = sa[l];
          }
          if(l < n) {
            int tmp = lcp(sa[l + 1], d[it], u[it]).first;
            if(tmp > L[it]) L[it] = tmp, arg[it] = sa[l + 1];
          }
          if(!L[it]) continue; // add this line
          arg[it] = n - arg[it] + 1; // add this line
          // cout << "check " << d[it] << " " << u[it] << "\n";
          // cout << it << " " << L[it] << " " << arg[it] << "\n";
          // cout << l << " " << r << " " << n << "\n";
        }
      };
      calc(rev, u, ulcp, uarg), reverse(s + 1, s + n + 1);
      calc(ori, v, vlcp, varg), combine::solve(n, qu[i]);
    }
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> m >> q;
  for(int i = pw[0] = 1; i < N; i++) pw[i] = 1ll * pw[i - 1] * base % mod;
  for(int i = 1; i < n; i++) {
    int x = read(), y = read();
    char ch;
    cin >> ch;
    tree::e[x].push_back({y, ch});
    tree::e[y].push_back({x, ch});
  }
  tree::build();
  for(int i = 1; i <= m; i++) {
    cin >> s[i], A.ins(s[i], i);
    reverse(s[i].begin(), s[i].end()), AR.ins(s[i], i);
    reverse(s[i].begin(), s[i].end());
  }
  A.build(), AR.build();
  for(int i = 1; i <= q; i++) {
    u[i] = read(), v[i] = read(), k[i] = read();
    int L = s[k[i]].size();
    if(L > n) continue;
    d[i] = tree::lca(u[i], v[i]);
    int du = tree::dep[u[i]] - tree::dep[d[i]];
    if(du >= L) {
      int anc = tree::kth(u[i], du - L + 1);
      AR.buc[anc].push_back(-i);
      AR.buc[u[i]].push_back(i);
      u[i] = anc, du = L - 1;
    }
    int dv = tree::dep[v[i]] - tree::dep[d[i]];
    if(dv >= L) {
      int anc = tree::kth(v[i], dv - L + 1);
      A.buc[anc].push_back(-i);
      A.buc[v[i]].push_back(i);
      v[i] = anc, dv = L - 1;
    }
    if(u[i] != d[i] && v[i] != d[i] && du + dv >= L) sa::qu[k[i]].push_back(i);
  }
  A.solve(1, 0, 0);
  AR.solve(1, 0, 0);
  sa::solve();
  for(int i = 1; i <= q; i++) print(ans[i]), putchar('\n');
  cerr << TIME << " ms\n";
  return 0;
}