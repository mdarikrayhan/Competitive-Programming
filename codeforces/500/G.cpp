#line 1 "/home/maspy/compro/library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else

// https://codeforces.com/blog/entry/96344
#pragma GCC optimize("Ofast,unroll-loops")
// いまの CF だとこれ入れると動かない？
// #pragma GCC target("avx2,popcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_mod_2(int x) { return __builtin_parity(x); }
int popcnt_mod_2(u32 x) { return __builtin_parity(x); }
int popcnt_mod_2(ll x) { return __builtin_parityll(x); }
int popcnt_mod_2(u64 x) { return __builtin_parityll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sm = 0;
  for (auto &&a: A) sm += a;
  return sm;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}
#endif
#line 1 "/home/maspy/compro/library/other/io.hpp"
#define FASTIO
#include <unistd.h>

// https://judge.yosupo.jp/submission/21623
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf
uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
  char num[10000][4];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i][j] = n % 10 | '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
  if (pir < SZ) ibuf[pir++] = '\n';
}

inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

void rd(char &c) {
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
}

void rd(string &x) {
  x.clear();
  char c;
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
  do {
    x += c;
    if (pil == pir) load();
    c = ibuf[pil++];
  } while (!isspace(c));
}

template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}

template <typename T>
void rd_integer(T &x) {
  if (pil + 100 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') { minus = 1, c = ibuf[pil++]; }
  }
  x = 0;
  while ('0' <= c) { x = x * 10 + (c & 15), c = ibuf[pil++]; }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
}

void rd(int &x) { rd_integer(x); }
void rd(ll &x) { rd_integer(x); }
void rd(i128 &x) { rd_integer(x); }
void rd(u32 &x) { rd_integer(x); }
void rd(u64 &x) { rd_integer(x); }
void rd(u128 &x) { rd_integer(x); }
void rd(double &x) { rd_real(x); }
void rd(long double &x) { rd_real(x); }
void rd(f128 &x) { rd_real(x); }

template <class T, class U>
void rd(pair<T, U> &p) {
  return rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
  if constexpr (N < std::tuple_size<T>::value) {
    auto &x = std::get<N>(t);
    rd(x);
    rd_tuple<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd_tuple(tpl);
}

template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d: x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
  for (auto &d: x) rd(d);
}

void read() {}
template <class H, class... T>
void read(H &h, T &... t) {
  rd(h), read(t...);
}

void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const string s) {
  for (char c: s) wt(c);
}
void wt(const char *s) {
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) wt(s[i]);
}

template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  if (x < 0) { obuf[por++] = '-', x = -x; }
  int outi;
  for (outi = 96; x >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[x % 10000], 4);
    x /= 10000;
  }
  if (x >= 1000) {
    memcpy(obuf + por, pre.num[x], 4);
    por += 4;
  } else if (x >= 100) {
    memcpy(obuf + por, pre.num[x] + 1, 3);
    por += 3;
  } else if (x >= 10) {
    int q = (x * 103) >> 10;
    obuf[por] = q | '0';
    obuf[por + 1] = (x - q * 10) | '0';
    por += 2;
  } else
    obuf[por++] = x | '0';
  memcpy(obuf + por, out + outi + 4, 96 - outi);
  por += 96 - outi;
}

template <typename T>
void wt_real(T x) {
  ostringstream oss;
  oss << fixed << setprecision(15) << double(x);
  string s = oss.str();
  wt(s);
}

void wt(int x) { wt_integer(x); }
void wt(ll x) { wt_integer(x); }
void wt(i128 x) { wt_integer(x); }
void wt(u32 x) { wt_integer(x); }
void wt(u64 x) { wt_integer(x); }
void wt(u128 x) { wt_integer(x); }
void wt(double x) { wt_real(x); }
void wt(long double x) { wt_real(x); }
void wt(f128 x) { wt_real(x); }

template <class T, class U>
void wt(const pair<T, U> val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T t) {
  if constexpr (N < std::tuple_size<T>::value) {
    if constexpr (N > 0) { wt(' '); }
    const auto x = std::get<N>(t);
    wt(x);
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(tuple<T...> tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T>
void wt(const vector<T> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}

void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(forward<Tail>(tail)...);
}

// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
} // namespace fastio
using fastio::read;
using fastio::print;
using fastio::flush;

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define U32(...)   \
  u32 __VA_ARGS__; \
  read(__VA_ARGS__)
#define U64(...)   \
  u64 __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 3 "main.cpp"

#line 2 "/home/maspy/compro/library/graph/tree.hpp"

#line 2 "/home/maspy/compro/library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
};

template <typename T = int, bool directed = false>
struct Graph {
  static constexpr bool is_directed = directed;
  int N, M;
  using cost_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<int> indptr;
  vector<edge_type> csr_edges;
  vc<int> vc_deg, vc_indeg, vc_outdeg;
  bool prepared;

  class OutgoingEdges {
  public:
    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}

    const edge_type* begin() const {
      if (l == r) { return 0; }
      return &G->csr_edges[l];
    }

    const edge_type* end() const {
      if (l == r) { return 0; }
      return &G->csr_edges[r];
    }

  private:
    const Graph* G;
    int l, r;
  };

  bool is_prepared() { return prepared; }

  Graph() : N(0), M(0), prepared(0) {}
  Graph(int N) : N(N), M(0), prepared(0) {}

  void build(int n) {
    N = n, M = 0;
    prepared = 0;
    edges.clear();
    indptr.clear();
    csr_edges.clear();
    vc_deg.clear();
    vc_indeg.clear();
    vc_outdeg.clear();
  }

  void add(int frm, int to, T cost = 1, int i = -1) {
    assert(!prepared);
    assert(0 <= frm && 0 <= to && to < N);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

#ifdef FASTIO
  // wt, off
  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off); }

  void read_graph(int M, bool wt = false, int off = 1) {
    for (int m = 0; m < M; ++m) {
      INT(a, b);
      a -= off, b -= off;
      if (!wt) {
        add(a, b);
      } else {
        T c;
        read(c);
        add(a, b, c);
      }
    }
    build();
  }
#endif

  void build() {
    assert(!prepared);
    prepared = true;
    indptr.assign(N + 1, 0);
    for (auto&& e: edges) {
      indptr[e.frm + 1]++;
      if (!directed) indptr[e.to + 1]++;
    }
    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto&& e: edges) {
      csr_edges[counter[e.frm]++] = e;
      if (!directed)
        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});
    }
  }

  OutgoingEdges operator[](int v) const {
    assert(prepared);
    return {this, indptr[v], indptr[v + 1]};
  }

  vc<int> deg_array() {
    if (vc_deg.empty()) calc_deg();
    return vc_deg;
  }

  pair<vc<int>, vc<int>> deg_array_inout() {
    if (vc_indeg.empty()) calc_deg_inout();
    return {vc_indeg, vc_outdeg};
  }

  int deg(int v) {
    if (vc_deg.empty()) calc_deg();
    return vc_deg[v];
  }

  int in_deg(int v) {
    if (vc_indeg.empty()) calc_deg_inout();
    return vc_indeg[v];
  }

  int out_deg(int v) {
    if (vc_outdeg.empty()) calc_deg_inout();
    return vc_outdeg[v];
  }

#ifdef FASTIO
  void debug() {
    print("Graph");
    if (!prepared) {
      print("frm to cost id");
      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);
    } else {
      print("indptr", indptr);
      print("frm to cost id");
      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);
    }
  }
#endif

  vc<int> new_idx;
  vc<bool> used_e;

  // G における頂点 V[i] が、新しいグラフで i になるようにする
  // {G, es}
  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {
    if (len(new_idx) != N) new_idx.assign(N, -1);
    int n = len(V);
    FOR(i, n) new_idx[V[i]] = i;
    Graph<T, directed> G(n);
    vc<int> history;
    FOR(i, n) {
      for (auto&& e: (*this)[V[i]]) {
        if (len(used_e) <= e.id) used_e.resize(e.id + 1);
        if (used_e[e.id]) continue;
        int a = e.frm, b = e.to;
        if (new_idx[a] != -1 && new_idx[b] != -1) {
          history.eb(e.id);
          used_e[e.id] = 1;
          int eid = (keep_eid ? e.id : -1);
          G.add(new_idx[a], new_idx[b], e.cost, eid);
        }
      }
    }
    FOR(i, n) new_idx[V[i]] = -1;
    for (auto&& eid: history) used_e[eid] = 0;
    G.build();
    return G;
  }

private:
  void calc_deg() {
    assert(vc_deg.empty());
    vc_deg.resize(N);
    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;
  }

  void calc_deg_inout() {
    assert(vc_indeg.empty());
    vc_indeg.resize(N);
    vc_outdeg.resize(N);
    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }
  }
};
#line 4 "/home/maspy/compro/library/graph/tree.hpp"

// HLD euler tour をとっていろいろ。
template <typename GT>
struct Tree {
  using Graph_type = GT;
  GT &G;
  using WT = typename GT::cost_type;
  int N;
  vector<int> LID, RID, head, V, parent, VtoE;
  vc<int> depth;
  vc<WT> depth_weighted;

  Tree(GT &G, int r = 0, bool hld = 1) : G(G) { build(r, hld); }

  void build(int r = 0, bool hld = 1) {
    if (r == -1) return; // build を遅延したいとき
    N = G.N;
    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);
    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);
    depth.assign(N, -1), depth_weighted.assign(N, 0);
    assert(G.is_prepared());
    int t1 = 0;
    dfs_sz(r, -1, hld);
    dfs_hld(r, t1);
  }

  void dfs_sz(int v, int p, bool hld) {
    auto &sz = RID;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    int l = G.indptr[v], r = G.indptr[v + 1];
    auto &csr = G.csr_edges;
    // 使う辺があれば先頭にする
    for (int i = r - 2; i >= l; --i) {
      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i + 1]);
    }
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto e = csr[i];
      if (depth[e.to] != -1) continue;
      depth_weighted[e.to] = depth_weighted[v] + e.cost;
      VtoE[e.to] = e.id;
      dfs_sz(e.to, v, hld);
      sz[v] += sz[e.to];
      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto &&e: G[v]) {
      if (depth[e.to] <= depth[v]) continue;
      head[e.to] = (heavy ? head[v] : e.to);
      heavy = false;
      dfs_hld(e.to, times);
    }
  }

  vc<int> heavy_path_at(int v) {
    vc<int> P = {v};
    while (1) {
      int a = P.back();
      for (auto &&e: G[a]) {
        if (e.to != parent[a] && head[e.to] == v) {
          P.eb(e.to);
          break;
        }
      }
      if (P.back() == a) break;
    }
    return P;
  }

  int heavy_child(int v) {
    int k = LID[v] + 1;
    if (k == N) return -1;
    int w = V[k];
    return (parent[w] == v ? w : -1);
  }

  int e_to_v(int eid) {
    auto e = G.edges[eid];
    return (parent[e.frm] == e.to ? e.frm : e.to);
  }
  int v_to_e(int v) { return VtoE[v]; }

  int ELID(int v) { return 2 * LID[v] - depth[v]; }
  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }

  // 目標地点へ進む個数が k
  int LA(int v, int k) {
    assert(k <= depth[v]);
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }
  int la(int u, int v) { return LA(u, v); }

  int LCA(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }

  int meet(int a, int b, int c) { return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c); }
  int lca(int u, int v) { return LCA(u, v); }

  int subtree_size(int v, int root = -1) {
    if (root == -1) return RID[v] - LID[v];
    if (v == root) return N;
    int x = jump(v, root, 1);
    if (in_subtree(v, x)) return RID[v] - LID[v];
    return N - RID[x] + LID[x];
  }

  int dist(int a, int b) {
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  WT dist_weighted(int a, int b) {
    int c = LCA(a, b);
    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];
  }

  // a is in b
  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int jump(int a, int b, ll k) {
    if (k == 1) {
      if (a == b) return -1;
      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
    }
    int c = LCA(a, b);
    int d_ac = depth[a] - depth[c];
    int d_bc = depth[b] - depth[c];
    if (k > d_ac + d_bc) return -1;
    if (k <= d_ac) return LA(a, k);
    return LA(b, d_ac + d_bc - k);
  }

  vc<int> collect_child(int v) {
    vc<int> res;
    for (auto &&e: G[v])
      if (e.to != parent[v]) res.eb(e.to);
    return res;
  }

  vc<int> collect_light(int v) {
    vc<int> res;
    bool skip = true;
    for (auto &&e: G[v])
      if (e.to != parent[v]) {
        if (!skip) res.eb(e.to);
        skip = false;
      }
    return res;
  }

  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge) {
    // [始点, 終点] の"閉"区間列。
    vc<pair<int, int>> up, down;
    while (1) {
      if (head[u] == head[v]) break;
      if (LID[u] < LID[v]) {
        down.eb(LID[head[v]], LID[v]);
        v = parent[head[v]];
      } else {
        up.eb(LID[u], LID[head[u]]);
        u = parent[head[u]];
      }
    }
    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);
    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);
    reverse(all(down));
    up.insert(up.end(), all(down));
    return up;
  }

  vc<int> restore_path(int u, int v) {
    vc<int> P;
    for (auto &&[a, b]: get_path_decomposition(u, v, 0)) {
      if (a <= b) {
        FOR(i, a, b + 1) P.eb(V[i]);
      } else {
        FOR_R(i, b, a + 1) P.eb(V[i]);
      }
    }
    return P;
  }

  // path [a,b] と [c,d] の交わり. 空ならば {-1,-1}.
  // https://codeforces.com/problemset/problem/500/G
  pair<int, int> path_intersection(int a, int b, int c, int d) {
    int ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);
    int bc = lca(b, c), bd = lca(b, d), cd = lca(c, d);
    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd; // meet(a,b,c), meet(a,b,d)
    if (x != y) return {x, y};
    int z = ac ^ ad ^ cd;
    if (x != z) x = -1;
    return {x, x};
  }
};
#line 2 "/home/maspy/compro/library/mod/mod_inv.hpp"

// long でも大丈夫
// (val * x - 1) が mod の倍数になるようにする
// 特に mod=0 なら x=0 が満たす
ll mod_inv(ll val, ll mod) {
  if (mod == 0) return 0;
  mod = abs(mod);
  val %= mod;
  if (val < 0) val += mod;
  ll a = val, b = mod, u = 1, v = 0, t;
  while (b > 0) {
    t = a / b;
    swap(a -= t * b, b), swap(u -= t * v, v);
  }
  if (u < 0) u += mod;
  return u;
}
#line 1 "/home/maspy/compro/library/nt/coprime_factorization.hpp"

/*
互いに素な整数 p1, p2, ..., pk を用いて n_i = prod p_i^e_i と表す.
[21,60,140,400]
[3,7,20], [[(0,1),(1,1)],[(0,1),(2,1)],[(1,1),(2,1)],[(2,2)]]
*/
template <typename T>
pair<vc<T>, vvc<pair<int, int>>> coprime_factorization(vc<T> nums) {
  vc<T> basis;
  for (T val: nums) {
    vc<T> new_basis;
    for (T x: basis) {
      if (val == 1) {
        new_basis.eb(x);
        continue;
      }
      vc<T> dat = {val, x};
      FOR(p, 1, len(dat)) {
        FOR(i, p) {
          while (1) {
            if (dat[p] > 1 && dat[i] % dat[p] == 0) dat[i] /= dat[p];
            elif (dat[i] > 1 && dat[p] % dat[i] == 0) dat[p] /= dat[i];
            else break;
          }
          T g = gcd(dat[i], dat[p]);
          if (g == 1 || g == dat[i] || g == dat[p]) continue;
          dat[i] /= g, dat[p] /= g, dat.eb(g);
        }
      }
      val = dat[0];
      FOR(i, 1, len(dat)) if (dat[i] != 1) new_basis.eb(dat[i]);
    }
    if (val > 1) new_basis.eb(val);
    swap(basis, new_basis);
  }

  sort(all(basis));

  vvc<pair<int, int>> res(len(nums));
  FOR(i, len(nums)) {
    T x = nums[i];
    FOR(j, len(basis)) {
      int e = 0;
      while (x % basis[j] == 0) x /= basis[j], ++e;
      if (e) res[i].eb(j, e);
    }
  }
  return {basis, res};
}
#line 2 "/home/maspy/compro/library/nt/factor.hpp"

#line 2 "/home/maspy/compro/library/random/base.hpp"

u64 RNG_64() {
  static uint64_t x_
      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(
                     chrono::high_resolution_clock::now().time_since_epoch())
                     .count())
        * 10150724397891781847ULL;
  x_ ^= x_ << 7;
  return x_ ^= x_ >> 9;
}

u64 RNG(u64 lim) { return RNG_64() % lim; }

ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }
#line 2 "/home/maspy/compro/library/mod/mongomery_modint.hpp"

// odd mod.
// x の代わりに rx を持つ
template <int id, typename U1, typename U2>
struct Mongomery_modint {
  using mint = Mongomery_modint;
  inline static U1 m, r, n2;
  static constexpr int W = numeric_limits<U1>::digits;

  static void set_mod(U1 mod) {
    assert(mod & 1 && mod <= U1(1) << (W - 2));
    m = mod, n2 = -U2(m) % m, r = m;
    FOR(5) r *= 2 - m * r;
    r = -r;
    assert(r * m == U1(-1));
  }
  static U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }

  U1 x;
  Mongomery_modint() : x(0) {}
  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};
  U1 val() const {
    U1 y = reduce(x);
    return y >= m ? y - m : y;
  }
  mint &operator+=(mint y) {
    x = ((x += y.x) >= m ? x - m : x);
    return *this;
  }
  mint &operator-=(mint y) {
    x -= (x >= y.x ? y.x : y.x - m);
    return *this;
  }
  mint &operator*=(mint y) {
    x = reduce(U2(x) * y.x);
    return *this;
  }
  mint operator+(mint y) const { return mint(*this) += y; }
  mint operator-(mint y) const { return mint(*this) -= y; }
  mint operator*(mint y) const { return mint(*this) *= y; }
  bool operator==(mint y) const {
    return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);
  }
  bool operator!=(mint y) const { return not operator==(y); }
  mint pow(ll n) const {
    assert(n >= 0);
    mint y = 1, z = *this;
    for (; n; n >>= 1, z *= z)
      if (n & 1) y *= z;
    return y;
  }
};

template <int id>
using Mongomery_modint_32 = Mongomery_modint<id, u32, u64>;
template <int id>
using Mongomery_modint_64 = Mongomery_modint<id, u64, u128>;
#line 3 "/home/maspy/compro/library/nt/primetest.hpp"

bool primetest(const u64 x) {
  assert(x < u64(1) << 62);
  if (x == 2 or x == 3 or x == 5 or x == 7) return true;
  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;
  if (x < 121) return x > 1;
  const u64 d = (x - 1) >> lowbit(x - 1);

  using mint = Mongomery_modint_64<202311020>;

  mint::set_mod(x);
  const mint one(u64(1)), minus_one(x - 1);
  auto ok = [&](u64 a) -> bool {
    auto y = mint(a).pow(d);
    u64 t = d;
    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;
    if (y != minus_one && t % 2 == 0) return false;
    return true;
  };
  if (x < (u64(1) << 32)) {
    for (u64 a: {2, 7, 61})
      if (!ok(a)) return false;
  } else {
    for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if (!ok(a)) return false;
    }
  }
  return true;
}
#line 5 "/home/maspy/compro/library/nt/factor.hpp"

template <typename mint>
ll rho(ll n, ll c) {
  assert(n > 1);
  const mint cc(c);
  auto f = [&](mint x) { return x * x + cc; };
  mint x = 1, y = 2, z = 1, q = 1;
  ll g = 1;
  const ll m = 1LL << (__lg(n) / 5);
  for (ll r = 1; g == 1; r <<= 1) {
    x = y;
    FOR(r) y = f(y);
    for (ll k = 0; k < r && g == 1; k += m) {
      z = y;
      FOR(min(m, r - k)) y = f(y), q *= x - y;
      g = gcd(q.val(), n);
    }
  }
  if (g == n) do {
      z = f(z);
      g = gcd((x - z).val(), n);
    } while (g == 1);
  return g;
}

ll find_prime_factor(ll n) {
  assert(n > 1);
  if (primetest(n)) return n;
  FOR(100) {
    ll m = 0;
    if (n < (1 << 30)) {
      using mint = Mongomery_modint_32<20231025>;
      mint::set_mod(n);
      m = rho<mint>(n, RNG(0, n));
    } else {
      using mint = Mongomery_modint_64<20231025>;
      mint::set_mod(n);
      m = rho<mint>(n, RNG(0, n));
    }
    if (primetest(m)) return m;
    n = m;
  }
  assert(0);
  return -1;
}

// ソートしてくれる
vc<pair<ll, int>> factor(ll n) {
  assert(n >= 1);
  vc<pair<ll, int>> pf;
  FOR(p, 2, 100) {
    if (p * p > n) break;
    if (n % p == 0) {
      ll e = 0;
      do { n /= p, e += 1; } while (n % p == 0);
      pf.eb(p, e);
    }
  }
  while (n > 1) {
    ll p = find_prime_factor(n);
    ll e = 0;
    do { n /= p, e += 1; } while (n % p == 0);
    pf.eb(p, e);
  }
  sort(all(pf));
  return pf;
}

vc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {
  vc<pair<ll, int>> res;
  while (n > 1) {
    int p = lpf[n];
    int e = 0;
    while (n % p == 0) {
      n /= p;
      ++e;
    }
    res.eb(p, e);
  }
  return res;
}
#line 2 "/home/maspy/compro/library/mod/barrett.hpp"

// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
struct Barrett {
  u32 m;
  u64 im;
  explicit Barrett(u32 m = 1) : m(m), im(u64(-1) / m + 1) {}
  u32 umod() const { return m; }
  u32 modulo(u64 z) {
    if (m == 1) return 0;
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    return (z - y + (z < y ? m : 0));
  }
  u64 floor(u64 z) {
    if (m == 1) return z;
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    return (z < y ? x - 1 : x);
  }
  pair<u64, u32> divmod(u64 z) {
    if (m == 1) return {z, 0};
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    if (z < y) return {x - 1, z - y + m};
    return {x, z - y};
  }
  u32 mul(u32 a, u32 b) { return modulo(u64(a) * b); }
};

struct Barrett_64 {
  u128 mod, mh, ml;

  explicit Barrett_64(u64 mod = 1) : mod(mod) {
    u128 m = u128(-1) / mod;
    if (m * mod + mod == u128(0)) ++m;
    mh = m >> 64;
    ml = m & u64(-1);
  }

  u64 umod() const { return mod; }

  u64 modulo(u128 x) {
    u128 z = (x & u64(-1)) * ml;
    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);
    z = (x >> 64) * mh + (z >> 64);
    x -= z * mod;
    return x < mod ? x : x - mod;
  }

  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }
};
#line 5 "/home/maspy/compro/library/nt/crt.hpp"

// 非負最小解を mod new_mod で返す (garner), なければ -1.
template <typename T>
i128 CRT(vc<T> vals, vc<T> mods, ll new_mod = -1, bool coprime = false) {
  int n = len(vals);
  FOR(i, n) {
    vals[i] = ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] + mods[i]);
  }

  bool ng = 0;
  auto reduction_by_factor = [&]() -> void {
    unordered_map<T, pair<T, int>> MP;
    FOR(i, n) {
      for (auto&& [p, e]: factor(mods[i])) {
        T mod = 1;
        FOR(e) mod *= p;
        T val = vals[i] % mod;
        if (!MP.count(p)) {
          MP[p] = {mod, val % mod};
          continue;
        }
        auto& [mod1, val1] = MP[p];
        if (mod > mod1) swap(mod, mod1), swap(val, val1);
        if (val1 % mod != val) {
          ng = 1;
          return;
        }
      }
    }
    mods.clear(), vals.clear();
    for (auto&& [p, x]: MP) {
      auto [mod, val] = x;
      mods.eb(mod), vals.eb(val);
    }
    n = len(vals);
  };
  auto reduction_by_coprime_factor = [&]() -> void {
    auto [basis, pfs] = coprime_factorization<T>(mods);
    int k = len(basis);
    vc<pair<T, int>> dat(k, {1, 0});
    FOR(i, n) {
      for (auto&& [pid, exp]: pfs[i]) {
        T mod = 1;
        FOR(exp) mod *= basis[pid];
        T val = vals[i] % mod;
        auto& [mod1, val1] = dat[pid];
        if (mod > mod1) swap(mod, mod1), swap(val, val1);
        if (val1 % mod != val) {
          ng = 1;
          return;
        }
      }
    }
    mods.clear(), vals.clear();
    for (auto&& [mod, val]: dat) { mods.eb(mod), vals.eb(val); }
    n = len(vals);
  };
  if (!coprime) {
    (n <= 10 ? reduction_by_coprime_factor() : reduction_by_factor());
  }

  if (ng) return -1;
  if (n == 0) return 0;

  vc<ll> cfs(n);
  if (MAX(mods) < (1LL << 31)) {
    FOR(i, n) {
      Barrett bt(mods[i]);
      ll a = vals[i], prod = 1;
      FOR(j, i) {
        a = bt.modulo(a + cfs[j] * (mods[i] - prod));
        prod = bt.mul(prod, mods[j]);
      }
      cfs[i] = bt.mul(mod_inv(prod, mods[i]), a);
    }
  } else {
    FOR(i, n) {
      ll a = vals[i], prod = 1;
      FOR(j, i) {
        a = (a + i128(cfs[j]) * (mods[i] - prod)) % mods[i];
        prod = i128(prod) * mods[j] % mods[i];
      }
      cfs[i] = mod_inv(prod, mods[i]) * i128(a) % mods[i];
    }
  }
  i128 ret = 0, prod = 1;
  FOR(i, n) {
    ret += prod * cfs[i], prod *= mods[i];
    if (new_mod != -1) { ret %= new_mod, prod %= new_mod; }
  }
  return ret;
}
#line 2 "/home/maspy/compro/library/mod/min_of_linear_segments.hpp"

/*
ax + b (x>=0) が最小となるところの情報を返す。
prefix min を更新する x 全体が、等差数列の和集合。次を返す。
・等差数列の境界となる x_0, x_1, ..., x_n
・各境界の間での交差 dx_0, ..., dx_{n-1}
*/
pair<vc<int>, vc<int>> min_of_linear_segments(int a, int b, int mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  vc<int> X = {0};
  vc<int> DX;
  int g = gcd(a, mod);
  a /= g, b /= g, mod /= g;
  // p/q <= (mod-a)/mod <= r/s
  int p = 0, q = 1, r = 1, s = 1;
  int det_l = mod - a, det_r = a;
  int x = 0, y = b;

  while (y) {
    // upd r/s
    int k = det_r / det_l;
    det_r %= det_l;
    if (det_r == 0) {
      --k;
      det_r = det_l;
    }
    r += k * p;
    s += k * q;
    while (1) {
      int k = max(0, ceil(det_l - y, det_r));
      if (det_l - k * det_r <= 0) break;
      det_l -= k * det_r;
      p += k * r;
      q += k * s;
      // p/q <= a/mod
      // (aq - pmod) = det_l を y から引く
      k = y / det_l;
      y -= k * det_l;
      x += q * k;
      X.eb(x);
      DX.eb(q);
    }
    k = det_l / det_r;
    det_l -= k * det_r;
    p += k * r;
    q += k * s;
    assert(min({p, q, r, s}) >= 0);
  }
  return {X, DX};
}
#line 2 "/home/maspy/compro/library/mod/first_mod_range_of_linear.hpp"

// ax+b in {L, ..., R-1} mod となる最小の x>=0 を返す
// 例えば ax+b=1 なら ax+b in {-1} mod 2 のようにする
// 存在しなければ -1
int first_mod_range_of_linear(ll L, ll R, ll a, ll b, int mod) {
  assert(L <= R);
  b -= L, R -= L;
  if (R >= mod) return 0;
  a = bmod<ll>(a, mod), b = bmod<ll>(b, mod);
  // ax+b<R
  if (b < R) return 0;
  auto [X, DX] = min_of_linear_segments(a, b, mod);
  FOR(i, len(DX)) {
    ll x1 = X[i], x2 = X[i + 1];
    ll y2 = (a * x2 + b) % mod;
    if (y2 >= R) continue;
    ll y1 = (a * x1 + b) % mod;
    ll d = (y1 - y2) * DX[i] / (x2 - x1);
    ll k = floor(y1 - R, d) + 1;
    return x1 + k * DX[i];
  }
  return -1;
}
#line 7 "main.cpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  auto solve = [&](int a, int b, int c, int d) -> void {
    auto [s, t] = tree.path_intersection(a, b, c, d);
    if (s == -1) return print(-1);
    int n = tree.dist(a, b), s1 = tree.dist(a, s), t1 = tree.dist(a, t);
    int m = tree.dist(c, d), s2 = tree.dist(c, s), t2 = tree.dist(c, t);
    ll ANS = infty<ll>;
    auto F = [&](int n, int s1, int t1, int m, int s2, int t2) -> void {
      if (s1 > t1) { swap(s1, t1), swap(s2, t2); }
      if (s2 < t2) {
        // 同じ方向
        ll x = CRT(vc<int>({s1, s2}), vc<int>({n, m}), -1, 0);
        if (x != -1) chmin(ANS, x);
        return;
      }
      // kn + s1 in [l, r] mod m
      ll l = 2 * t2 - s2, r = s2;
      ll k = first_mod_range_of_linear(l, r + 1, n, s1, m);
      if (k == -1) return;
      ll a = k * n + s1;
      // km + s2 >= a
      k = ceil<ll>(a - s2, m);
      ll b = k * m + s2;
      if ((a + b) % 2 != 0) return;
      ll c = (a + b) / 2;
      chmin(ANS, c);
    };
    F(2 * n, s1, t1, 2 * m, s2, t2);
    F(2 * n, s1, t1, 2 * m, 2 * m - s2, 2 * m - t2);
    F(2 * n, 2 * n - s1, 2 * n - t1, 2 * m, s2, t2);
    F(2 * n, 2 * n - s1, 2 * n - t1, 2 * m, 2 * m - s2, 2 * m - t2);
    if (ANS == infty<ll>) ANS = -1;
    print(ANS);
  };

  LL(Q);
  FOR(Q) {
    INT(a, b, c, d);
    solve(--a, --b, --c, --d);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
