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
#line 2 "/home/maspy/compro/library/ds/fastset.hpp"

// 64-ary tree
// space: (N/63) * u64
struct FastSet {
  static constexpr u32 B = 64;
  int n, log;
  vvc<u64> seg;

  FastSet() {}
  FastSet(int n) { build(n); }

  int size() { return n; }

  template <typename F>
  FastSet(int n, F f) {
    build(n, f);
  }

  void build(int m) {
    seg.clear();
    n = m;
    do {
      seg.push_back(vc<u64>((m + B - 1) / B));
      m = (m + B - 1) / B;
    } while (m > 1);
    log = len(seg);
  }
  template <typename F>
  void build(int n, F f) {
    build(n);
    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }
    FOR(h, log - 1) {
      FOR(i, len(seg[h])) {
        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);
      }
    }
  }

  bool operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }
  void insert(int i) {
    for (int h = 0; h < log; h++) {
      seg[h][i / B] |= u64(1) << (i % B), i /= B;
    }
  }
  void add(int i) { insert(i); }
  void erase(int i) {
    u64 x = 0;
    for (int h = 0; h < log; h++) {
      seg[h][i / B] &= ~(u64(1) << (i % B));
      seg[h][i / B] |= x << (i % B);
      x = bool(seg[h][i / B]);
      i /= B;
    }
  }
  void remove(int i) { erase(i); }

  // min[x,n) or n
  int next(int i) {
    assert(i <= n);
    chmax(i, 0);
    for (int h = 0; h < log; h++) {
      if (i / B == seg[h].size()) break;
      u64 d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      i += lowbit(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += lowbit(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }

  // max [0,x], or -1
  int prev(int i) {
    assert(i >= -1);
    if (i >= n) i = n - 1;
    for (int h = 0; h < log; h++) {
      if (i == -1) break;
      u64 d = seg[h][i / B] << (63 - i % B);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      i -= __builtin_clzll(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += topbit(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }

  bool any(int l, int r) { return next(l) < r; }

  // [l, r)
  template <typename F>
  void enumerate(int l, int r, F f) {
    for (int x = next(l); x < r; x = next(x + 1)) f(x);
  }

  string to_string() {
    string s(n, '?');
    for (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');
    return s;
  }
};
#line 3 "/home/maspy/compro/library/graph/toposort.hpp"

// 辞書順最小の toposort を返す
template <typename GT>
vc<int> toposort(GT& G) {
  static_assert(GT::is_directed);
  assert(G.is_prepared());
  const int N = G.N;
  auto [indeg, outdeg] = G.deg_array_inout();
  FastSet que(N);
  vc<int> V;
  FOR(v, N) if (indeg[v] == 0) que.insert(v);
  while (1) {
    int v = que.next(0);
    if (v == N) break;
    que.erase(v), V.eb(v);
    for (auto&& e: G[v]) {
      if (--indeg[e.to] == 0) que.insert(e.to);
    }
  }
  return (len(V) < N ? vc<int>{} : V);
}
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
#line 2 "/home/maspy/compro/library/mod/modint61.hpp"

struct modint61 {
  static constexpr u64 mod = (1ULL << 61) - 1;
  u64 val;
  constexpr modint61() : val(0ULL) {}
  constexpr modint61(u32 x) : val(x) {}
  constexpr modint61(u64 x) : val(x % mod) {}
  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x) {}
  constexpr modint61(ll x)
      : val(((x %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod))
                                              : x) {}
  static constexpr u64 get_mod() { return mod; }
  modint61 &operator+=(const modint61 &a) {
    val = ((val += a.val) >= mod) ? (val - mod) : val;
    return *this;
  }
  modint61 &operator-=(const modint61 &a) {
    val = ((val -= a.val) >= mod) ? (val + mod) : val;
    return *this;
  }
  modint61 &operator*=(const modint61 &a) {
    const unsigned __int128 y = static_cast<unsigned __int128>(val) * a.val;
    val = (y >> 61) + (y & mod);
    val = (val >= mod) ? (val - mod) : val;
    return *this;
  }
  modint61 operator-() const { return modint61(val ? mod - val : u64(0)); }
  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse()); }
  modint61 operator+(const modint61 &p) const { return modint61(*this) += p; }
  modint61 operator-(const modint61 &p) const { return modint61(*this) -= p; }
  modint61 operator*(const modint61 &p) const { return modint61(*this) *= p; }
  modint61 operator/(const modint61 &p) const { return modint61(*this) /= p; }
  bool operator==(const modint61 &p) const { return val == p.val; }
  bool operator!=(const modint61 &p) const { return val != p.val; }
  modint61 inverse() const {
    ll a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint61(u);
  }
  modint61 pow(ll n) const {
    assert(n >= 0);
    modint61 ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul, n >>= 1;
    }
    return ret;
  }
};

#ifdef FASTIO
void rd(modint61 &x) {
  fastio::rd(x.val);
  assert(0 <= x.val && x.val < modint61::mod);
}

void wt(modint61 x) { fastio::wt(x.val); }
#endif
#line 4 "/home/maspy/compro/library/string/rollinghash.hpp"

struct RollingHash {
  using mint = modint61;
  static constexpr u64 mod = mint::get_mod();
  const mint base;
  vc<mint> power;

  static inline mint generate_base() { return RNG(mod); }

  inline void expand(size_t sz) {
    if (power.size() < sz + 1) {
      int pre_sz = (int)power.size();
      power.resize(sz + 1);
      FOR(i, pre_sz - 1, sz) power[i + 1] = power[i] * base;
    }
  }

  explicit RollingHash(mint base = generate_base()) : base(base), power{1} {}

  template <typename STRING>
  vector<mint> build(const STRING& s) const {
    int sz = s.size();
    vector<mint> hashed(sz + 1, mint(0));
    for (int i = 0; i < sz; i++) { hashed[i + 1] = hashed[i] * base + s[i]; }
    return hashed;
  }

  template <typename STRING>
  mint eval(STRING& s) {
    mint x = 0;
    for (auto& ch: s) x = base * x + ch;
    return x;
  }

  mint query(const vc<mint>& s, int l, int r) {
    assert(0 <= l && l <= r && r < len(s));
    expand(r - l);
    return (s[r] - s[l] * power[r - l]);
  }

  mint combine(mint h1, mint h2, int h2len) {
    expand(h2len);
    return h1 * power[h2len] + h2;
  }

  mint add_char(mint h, int x) { return h * base + mint(x); }

  int lcp(const vc<mint>& a, int l1, int r1, const vc<mint>& b, int l2,
          int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return low;
  }
};
#line 6 "main.cpp"

/*
ある文字列の suffix が余っている状態
非自明状態を通るサイクルがあるかということ
ぴったりのところ：特殊頂点としてまとめる
単にサイクルがあるかということになる
*/

bool F(vc<string> S) {
  // cycle なしなら return 1
  // toposort 可能なら return 1
  int N = len(S);
  vvc<int> idx(N);
  FOR(i, N) idx[i].resize(len(S[i]) + 1);
  int p = 1;
  FOR(i, N) FOR(j, 1, len(S[i])) idx[i][j] = p++;
  RollingHash RH;
  using mint = decltype(RH)::mint;
  vvc<mint> SH(N);
  FOR(i, N) SH[i] = RH.build(S[i]);

  vc<int> sz(N);
  FOR(i, N) sz[i] = len(S[i]);

  Graph<int, 1> G(p);
  FOR(i, N) {
    FOR(p, sz[i]) {
      FOR(j, N) {
        int n = min<int>(sz[i] - p, sz[j]);
        if (RH.query(SH[i], p, p + n) != RH.query(SH[j], 0, n)) continue;
        int frm = idx[i][p];
        int to = (p + n == sz[i] ? idx[j][sz[i] - p] : idx[i][p + n]);
        if (frm == 0 && to == 0) continue;
        G.add(frm, to);
      }
    }
  }
  G.build();
  auto V = toposort(G);
  return !V.empty();
}

void solve() {
  LL(N);
  VEC(string, S, N);

  auto check = [&](ll L, ll R) -> bool {
    return F({S.begin() + L, S.begin() + R});
  };

  ll ANS = 0;
  ll R = 0;
  FOR(L, N) {
    chmax(R, L);
    while (R < N && check(L, R + 1)) ++R;
    ANS += R - L;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
