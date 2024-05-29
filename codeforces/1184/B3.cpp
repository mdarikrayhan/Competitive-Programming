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

#define SHOW(x) print(#x, "=", (x)), flush()

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
#line 3 "/home/maspy/compro/library/graph/shortest_path/warshall_floyd.hpp"

// 負辺があっても負閉路がなければ正しく動作する。
// 負閉路があるかどうかは、dist[v][v] < 0 となる v があるかどうかで判定。
template <typename T, typename GT>
vc<vc<T>> warshall_floyd(GT& G) {
  ll N = G.N;
  vv(T, dist, N, N, infty<T>);
  FOR(v, N) {
    dist[v][v] = 0;
    for (auto&& e: G[v]) chmin(dist[v][e.to], e.cost);
  }
  FOR(k, N) FOR(i, N) {
    if (dist[i][k] == infty<T>) continue;
    FOR(j, N) {
      if (dist[k][j] == infty<T>) continue;
      chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
  return dist;
}
#line 1 "/home/maspy/compro/library/flow/maxflow.hpp"
// incremental に辺を追加してよい
// 辺の容量の変更が可能
// 変更する capacity が F のとき、O((N+M)|F|) 時間で更新
template <typename Cap>
struct MaxFlow {
  struct Edge {
    int to, rev;
    Cap cap; // 残っている容量. したがって cap+flow が定数.
    Cap flow = 0;
  };

  const int N, source, sink;
  vvc<Edge> edges;
  vc<pair<int, int>> pos;
  vc<int> prog, level;
  vc<int> que;
  bool calculated;

  MaxFlow(int N, int source, int sink)
      : N(N),
        source(source),
        sink(sink),
        edges(N),
        calculated(0),
        flow_ans(0) {}

  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {
    calculated = 0;
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= cap);
    int a = len(edges[frm]);
    int b = (frm == to ? a + 1 : len(edges[to]));
    pos.eb(frm, a);
    edges[frm].eb(Edge{to, b, cap, 0});
    edges[to].eb(Edge{frm, a, rev_cap, 0});
  }

  void change_capacity(int i, Cap after) {
    auto [frm, idx] = pos[i];
    auto& e = edges[frm][idx];
    Cap before = e.cap + e.flow;
    if (before < after) {
      calculated = (e.cap > 0);
      e.cap += after - before;
      return;
    }
    e.cap = after - e.flow;
    // 差分を押し戻す処理発生
    if (e.cap < 0) flow_push_back(e);
  }

  void flow_push_back(Edge& e0) {
    auto& re0 = edges[e0.to][e0.rev];
    int a = re0.to;
    int b = e0.to;
    /*
    辺 e0 の容量が正になるように戻す
    path-cycle 分解を考えれば、
    - uv 辺を含むサイクルを消す
    - suvt パスを消す
    前者は残余グラフで ab パス（flow_ans が変わらない）
    後者は残余グラフで tb, as パス
    */

    auto find_path = [&](int s, int t, Cap lim) -> Cap {
      vc<bool> vis(N);
      prog.assign(N, 0);
      auto dfs = [&](auto& dfs, int v, Cap f) -> Cap {
        if (v == t) return f;
        for (int& i = prog[v]; i < len(edges[v]); ++i) {
          auto& e = edges[v][i];
          if (vis[e.to] || e.cap <= Cap(0)) continue;
          vis[e.to] = 1;
          Cap a = dfs(dfs, e.to, min(f, e.cap));
          assert(a >= 0);
          if (a == Cap(0)) continue;
          e.cap -= a, e.flow += a;
          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow -= a;
          return a;
        }
        return 0;
      };
      return dfs(dfs, s, lim);
    };

    while (e0.cap < 0) {
      Cap x = find_path(a, b, -e0.cap);
      if (x == Cap(0)) break;
      e0.cap += x, e0.flow -= x;
      re0.cap -= x, re0.flow += x;
    }
    Cap c = -e0.cap;
    while (c > 0 && a != source) {
      Cap x = find_path(a, source, c);
      assert(x > 0);
      c -= x;
    }
    c = -e0.cap;
    while (c > 0 && b != sink) {
      Cap x = find_path(sink, b, c);
      assert(x > 0);
      c -= x;
    }
    c = -e0.cap;
    e0.cap += c, e0.flow -= c;
    re0.cap -= c, re0.flow += c;
    flow_ans -= c;
  }

  // frm, to, flow
  vc<tuple<int, int, Cap>> get_flow_edges() {
    vc<tuple<int, int, Cap>> res;
    FOR(frm, N) {
      for (auto&& e: edges[frm]) {
        if (e.flow <= 0) continue;
        res.eb(frm, e.to, e.flow);
      }
    }
    return res;
  }

  vc<bool> vis;

  // 差分ではなくこれまでの総量
  Cap flow() {
    if (calculated) return flow_ans;
    calculated = true;
    while (set_level()) {
      prog.assign(N, 0);
      while (1) {
        Cap x = flow_dfs(source, infty<Cap>);
        if (x == 0) break;
        flow_ans += x;
        chmin(flow_ans, infty<Cap>);
        if (flow_ans == infty<Cap>) return flow_ans;
      }
    }
    return flow_ans;
  }

  // 最小カットの値および、カットを表す 01 列を返す
  pair<Cap, vc<int>> cut() {
    flow();
    vc<int> res(N);
    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);
    return {flow_ans, res};
  }

  // O(F(N+M)) くらい使って経路復元
  // simple path になる
  vvc<int> path_decomposition() {
    flow();
    auto edges = get_flow_edges();
    vvc<int> TO(N);
    for (auto&& [frm, to, flow]: edges) { FOR(flow) TO[frm].eb(to); }
    vvc<int> res;
    vc<int> vis(N);

    FOR(flow_ans) {
      vc<int> path = {source};
      vis[source] = 1;
      while (path.back() != sink) {
        int to = POP(TO[path.back()]);
        while (vis[to]) { vis[POP(path)] = 0; }
        path.eb(to), vis[to] = 1;
      }
      for (auto&& v: path) vis[v] = 0;
      res.eb(path);
    }
    return res;
  }

  void debug() {
    print("source", source);
    print("sink", sink);
    print("edges (frm, to, cap, flow)");
    FOR(v, N) {
      for (auto& e: edges[v]) {
        if (e.cap == 0 && e.flow == 0) continue;
        print(v, e.to, e.cap, e.flow);
      }
    }
  }

private:
  Cap flow_ans;

  bool set_level() {
    que.resize(N);
    level.assign(N, -1);
    level[source] = 0;
    int l = 0, r = 0;
    que[r++] = source;
    while (l < r) {
      int v = que[l++];
      for (auto&& e: edges[v]) {
        if (e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[v] + 1;
          if (e.to == sink) return true;
          que[r++] = e.to;
        }
      }
    }
    return false;
  }

  Cap flow_dfs(int v, Cap lim) {
    if (v == sink) return lim;
    Cap res = 0;
    for (int& i = prog[v]; i < len(edges[v]); ++i) {
      auto& e = edges[v][i];
      if (e.cap > 0 && level[e.to] == level[v] + 1) {
        Cap a = flow_dfs(e.to, min(lim, e.cap));
        if (a > 0) {
          e.cap -= a, e.flow += a;
          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow -= a;
          res += a;
          lim -= a;
          if (lim == 0) break;
        }
      }
    }
    return res;
  }
};
#line 2 "/home/maspy/compro/library/flow/binary_optimization.hpp"

template <typename T, bool MINIMIZE>
struct Binary_Optimization {
  int n;
  int nxt;
  int source, sink;
  T base_cost;
  map<pair<int, int>, T> edges;

  Binary_Optimization(int n) : n(n), base_cost(0) {
    source = n;
    sink = n + 1;
    nxt = n + 2;
  }

  // xi を 0, 1 にするときにかかるコストを追加する。
  void add_1(int i, T x0, T x1) {
    assert(0 <= i && i < n);
    if (!MINIMIZE) { x0 = -x0, x1 = -x1; }
    _add_1(i, x0, x1);
  }

  // (xi,xj) = (00,01,10,11) とするときにかかるコストを追加する。
  // コストが劣モ x00 + x11 <= x10 + x10 になっている必要がある。
  // 特に、対角成分に利得を与えることができる。
  void add_2(int i, int j, T x00, T x01, T x10, T x11) {
    assert(i != j);
    assert(0 <= i && i < n);
    assert(0 <= j && j < n);
    if (!MINIMIZE) {
      x00 = -x00, x01 = -x01;
      x10 = -x10, x11 = -x11;
    }
    _add_2(i, j, x00, x01, x10, x11);
  }

  // (xi,xj,xk) = (000,001,010,011,100,101,110,111)
  // とするときにかかるコストを追加する。劣モになっている必要がある。
  // 特に、000 や 111 に利得を与えることができる。
  void add_3(int i, int j, int k, T x000, T x001, T x010, T x011, T x100,
             T x101, T x110, T x111) {
    assert(i != j && i != k && j != k);
    assert(0 <= i && i < n);
    assert(0 <= j && j < n);
    assert(0 <= k && k < n);
    if (!MINIMIZE) {
      x000 = -x000, x001 = -x001;
      x010 = -x010, x011 = -x011;
      x100 = -x100, x101 = -x101;
      x110 = -x110, x111 = -x111;
    }
    _add_3(i, j, k, x000, x001, x010, x011, x100, x101, x110, x111);
  }

  // 最小値および、01 列を返す
  pair<T, vc<int>> calc() {
    MaxFlow<T> G(nxt, source, sink);
    for (auto&& [key, cap]: edges) {
      auto [frm, to] = key;
      G.add(frm, to, cap);
    }

    auto [val, cut] = G.cut();
    val += base_cost;
    chmin(val, infty<T>);
    cut.resize(n);
    if (!MINIMIZE) val = -val;
    return {val, cut};
  }

  void debug() {
    print("base_cost", base_cost);
    print("source=", source, "sink=", sink);
    for (auto&& [key, cap]: edges) print(key, cap);
  }

private:
  void add_base(T t) {
    base_cost += t;
    assert(-infty<T> < base_cost && base_cost < infty<T>);
  }
  void add_edge(int i, int j, T t) {
    assert(t >= 0);
    if (t == 0) return;
    pair<int, int> key = mp(i, j);
    edges[key] += t;
    assert(edges[key] <= infty<T>);
  }

  void _add_1(int i, T x0, T x1) {
    if (x0 <= x1) {
      add_base(x0);
      add_edge(source, i, x1 - x0);
    } else {
      add_base(x1);
      add_edge(i, sink, x0 - x1);
    }
  }

  void _add_2(int i, int j, T x00, T x01, T x10, T x11) {
    assert(x00 + x11 <= x01 + x10);
    _add_1(i, x00, x10);
    _add_1(j, 0, x11 - x10);
    add_edge(i, j, x01 + x10 - x00 - x11);
  }

  void _add_3(int i, int j, int k, T x000, T x001, T x010, T x011, T x100,
              T x101, T x110, T x111) {
    T p = x000 - x100 - x010 - x001 + x110 + x101 + x011 - x111;
    if (p > 0) {
      add_base(x000);
      _add_1(i, 0, x100 - x000);
      _add_1(j, 0, x010 - x000);
      _add_1(k, 0, x001 - x000);
      _add_2(i, j, 0, 0, 0, x000 + x110 - x100 - x010);
      _add_2(i, k, 0, 0, 0, x000 + x101 - x100 - x001);
      _add_2(j, k, 0, 0, 0, x000 + x011 - x010 - x001);
      // あとは、111 のときに利得 p を追加する
      add_base(-p);
      // 111 以外だとコスト p
      add_edge(i, nxt, p);
      add_edge(j, nxt, p);
      add_edge(k, nxt, p);
      add_edge(nxt, sink, p);
      ++nxt;
    } else {
      p = -p;
      add_base(x111);
      _add_1(i, x011 - x111, 0);
      _add_1(i, x101 - x111, 0);
      _add_1(i, x110 - x111, 0);
      _add_2(i, j, x111 + x001 - x011 - x101, 0, 0, 0);
      _add_2(i, k, x111 + x010 - x011 - x110, 0, 0, 0);
      _add_2(j, k, x111 + x100 - x101 - x110, 0, 0, 0);
      // 000 のときに利得 p を追加する
      add_base(-p);
      // 000 以外だとコスト p
      add_edge(nxt, i, p);
      add_edge(nxt, j, p);
      add_edge(nxt, k, p);
      add_edge(source, nxt, p);
      ++nxt;
    }
  }
};
#line 6 "main.cpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G0(N);
  G0.read_graph(M);
  auto dist = warshall_floyd<int>(G0);

  LL(S, B, K);
  vi U(S), A(S), F(S), P(S);
  FOR(i, S) read(U[i], A[i], F[i], P[i]), --U[i];
  vi V(B), D(B), G(B);
  FOR(i, B) read(V[i], D[i], G[i]), --V[i];

  vi val(S, -infty<ll>);
  /*
  ここを高速化する必要がある
  FOR(i, S) FOR(j, B) {
    chmin(F[i], N);
    ll d = dist[U[i]][V[j]];
    if (d <= F[i] && A[i] >= D[j]) { chmax(val[i], G[j]); }
  }
  */
  // (d,g)
  vvc<int> IDS(N);
  FOR(i, B) IDS[V[i]].eb(i);
  vvc<ll> DD(N);
  vvc<ll> GG(N);
  FOR(v, N) {
    vi X, Y;
    for (auto& j: IDS[v]) { X.eb(D[j]), Y.eb(G[j]); }
    auto I = argsort(X);
    X = rearrange(X, I);
    Y = rearrange(Y, I);
    FOR(i, len(X) - 1) { chmax(Y[i + 1], Y[i]); }
    DD[v] = X, GG[v] = Y;
  }

  FOR(i, S) {
    chmin(F[i], N);
    FOR(v, N) {
      ll d = dist[U[i]][v];
      if (d > F[i]) continue;
      ll a = A[i];
      ll k = UB(DD[v], a);
      --k;
      if (0 <= k && k < len(DD[v])) { chmax(val[i], GG[v][k]); }
    }
  }

  Binary_Optimization<i128, 0> BO(S);
  FOR(i, S) BO.add_1(i, 0, val[i] - P[i]);

  FOR(K) {
    LL(a, b);
    --a, --b;
    if (a == b) { continue; }
    BO.add_2(a, b, 0, 0, -infty<ll>, 0);
  }

  auto [ans, x] = BO.calc();
  // print(val);
  // print(P);
  // print(x);
  print(ans);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
