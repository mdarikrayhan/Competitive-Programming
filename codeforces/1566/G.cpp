#line 1 "library/my_template.hpp"
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
#line 1 "library/other/io.hpp"
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

#line 2 "library/ds/segtree/segtree.hpp"

template <class Monoid>
struct SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  using value_type = X;
  vc<X> dat;
  int n, log, size;

  SegTree() {}
  SegTree(int n) { build(n); }
  template <typename F>
  SegTree(int n, F f) {
    build(n, f);
  }
  SegTree(const vc<X>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> X { return MX::unit(); });
  }
  void build(const vc<X>& v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, MX::unit());
    FOR(i, n) dat[size + i] = f(i);
    FOR_R(i, 1, size) update(i);
  }

  X get(int i) { return dat[size + i]; }
  vc<X> get_all() { return {dat.begin() + size, dat.begin() + size + n}; }

  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }
  void set(int i, const X& x) {
    assert(i < n);
    dat[i += size] = x;
    while (i >>= 1) update(i);
  }

  void multiply(int i, const X& x) {
    assert(i < n);
    i += size;
    dat[i] = Monoid::op(dat[i], x);
    while (i >>= 1) update(i);
  }

  X prod(int L, int R) {
    assert(0 <= L && L <= R && R <= n);
    X vl = Monoid::unit(), vr = Monoid::unit();
    L += size, R += size;
    while (L < R) {
      if (L & 1) vl = Monoid::op(vl, dat[L++]);
      if (R & 1) vr = Monoid::op(dat[--R], vr);
      L >>= 1, R >>= 1;
    }
    return Monoid::op(vl, vr);
  }

  X prod_all() { return dat[1]; }

  template <class F>
  int max_right(F check, int L) {
    assert(0 <= L && L <= n && check(Monoid::unit()));
    if (L == n) return n;
    L += size;
    X sm = Monoid::unit();
    do {
      while (L % 2 == 0) L >>= 1;
      if (!check(Monoid::op(sm, dat[L]))) {
        while (L < size) {
          L = 2 * L;
          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm, dat[L++]); }
        }
        return L - size;
      }
      sm = Monoid::op(sm, dat[L++]);
    } while ((L & -L) != L);
    return n;
  }

  template <class F>
  int min_left(F check, int R) {
    assert(0 <= R && R <= n && check(Monoid::unit()));
    if (R == 0) return 0;
    R += size;
    X sm = Monoid::unit();
    do {
      --R;
      while (R > 1 && (R % 2)) R >>= 1;
      if (!check(Monoid::op(dat[R], sm))) {
        while (R < size) {
          R = 2 * R + 1;
          if (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }
        }
        return R + 1 - size;
      }
      sm = Monoid::op(dat[R], sm);
    } while ((R & -R) != R);
    return 0;
  }

  // prod_{l<=i<r} A[i xor x]
  X xor_prod(int l, int r, int xor_val) {
    static_assert(Monoid::commute);
    X x = Monoid::unit();
    for (int k = 0; k < log + 1; ++k) {
      if (l >= r) break;
      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]); }
      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]); }
      l /= 2, r /= 2, xor_val /= 2;
    }
    return x;
  }
};
#line 1 "library/ds/bit_vector.hpp"
struct Bit_Vector {
  vc<pair<u32, u32>> dat;
  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }

  void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }

  void build() {
    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);
  }

  // [0, k) 内の 1 の個数
  int rank(int k, bool f = 1) {
    auto [a, b] = dat[k >> 5];
    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));
    return (f ? ret : k - ret);
  }
};
#line 3 "library/ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp"

template <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>
struct Wavelet_Matrix_2D_Range_Dynamic_Monoid {
  // 点群を Y 昇順に並べる.
  // X を整数になおして binary trie みたいに振り分ける
  using MX = Monoid;
  using X = typename MX::value_type;
  static_assert(MX::commute);

  template <bool SMALL>
  struct TO_IDX {
    vc<XY> key;
    XY mi, ma;
    vc<int> dat;

    void build(vc<XY>& X) {
      if constexpr (SMALL) {
        mi = (X.empty() ? 0 : MIN(X));
        ma = (X.empty() ? 0 : MAX(X));
        dat.assign(ma - mi + 2, 0);
        for (auto& x: X) { dat[x - mi + 1]++; }
        FOR(i, len(dat) - 1) dat[i + 1] += dat[i];
      } else {
        key = X;
        sort(all(key));
      }
    }
    int operator()(XY x) {
      if constexpr (SMALL) {
        return dat[clamp<XY>(x - mi, 0, ma - mi + 1)];
      } else {
        return LB(key, x);
      }
    }
  };

  TO_IDX<SMALL_X> XtoI;
  TO_IDX<SMALL_Y> YtoI;

  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vc<int> new_idx;
  vc<int> A;
  // 各段に fenwick tree
  vc<SegTree<Monoid>> dat;

  template <typename F>
  Wavelet_Matrix_2D_Range_Dynamic_Monoid(int N, F f) {
    build(N, f);
  }

  template <typename F>
  void build(int N_, F f) {
    N = N_;
    if (N == 0) {
      lg = 0;
      return;
    }
    vc<XY> tmp(N), Y(N);
    vc<X> S(N);
    FOR(i, N) tie(tmp[i], Y[i], S[i]) = f(i);
    auto I = argsort(Y);
    tmp = rearrange(tmp, I), Y = rearrange(Y, I), S = rearrange(S, I);
    XtoI.build(tmp), YtoI.build(Y);
    new_idx.resize(N);
    FOR(i, N) new_idx[I[i]] = i;

    // あとは普通に
    lg = __lg(XtoI(MAX(tmp) + 1)) + 1;
    mid.resize(lg), bv.assign(lg, Bit_Vector(N));
    dat.resize(lg);
    A.resize(N);
    FOR(i, N) A[i] = XtoI(tmp[i]);

    vc<XY> A0(N), A1(N);
    vc<X> S0(N), S1(N);
    FOR_R(d, lg) {
      int p0 = 0, p1 = 0;
      FOR(i, N) {
        bool f = (A[i] >> d & 1);
        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }
        if (f) { S1[p1] = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }
      }
      mid[d] = p0;
      bv[d].build();
      swap(A, A0), swap(S, S0);
      FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];
      dat[d].build(N, [&](int i) -> X { return S[i]; });
    }
    FOR(i, N) A[i] = XtoI(tmp[i]);
  }

  int count(XY x1, XY x2, XY y1, XY y2) {
    if (N == 0) return 0;
    x1 = XtoI(x1), x2 = XtoI(x2);
    y1 = YtoI(y1), y2 = YtoI(y2);
    return prefix_count(y1, y2, x2) - prefix_count(y1, y2, x1);
  }

  X prod(XY x1, XY x2, XY y1, XY y2) {
    if (N == 0) return MX::unit();
    assert(x1 <= x2 && y1 <= y2);
    x1 = XtoI(x1), x2 = XtoI(x2);
    y1 = YtoI(y1), y2 = YtoI(y2);
    X res = MX::unit();
    prod_dfs(y1, y2, x1, x2, lg - 1, res);
    return res;
  }

  // 最初に与えた点群の index
  void set(int i, X x) {
    assert(0 <= i && i < N);
    i = new_idx[i];
    int a = A[i];
    FOR_R(d, lg) {
      if (a >> d & 1) {
        i = mid[d] + bv[d].rank(i, 1);
      } else {
        i = bv[d].rank(i, 0);
      }
      dat[d].set(i, x);
    }
  }
  void multiply(int i, X x) {
    assert(0 <= i && i < N);
    i = new_idx[i];
    int a = A[i];
    FOR_R(d, lg) {
      if (a >> d & 1) {
        i = mid[d] + bv[d].rank(i, 1);
      } else {
        i = bv[d].rank(i, 0);
      }
      dat[d].multiply(i, x);
    }
  }

private:
  int prefix_count(int L, int R, int x) {
    int cnt = 0;
    FOR_R(d, lg) {
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      if (x >> d & 1) {
        cnt += r0 - l0, L += mid[d] - l0, R += mid[d] - r0;
      } else {
        L = l0, R = r0;
      }
    }
    return cnt;
  }

  void prod_dfs(int L, int R, int x1, int x2, int d, X& res) {
    chmax(x1, 0), chmin(x2, 1 << (d + 1));
    if (x1 >= x2) { return; }
    assert(0 <= x1 && x1 < x2 && x2 <= (1 << (d + 1)));
    if (x1 == 0 && x2 == (1 << (d + 1))) {
      res = MX::op(res, dat[d + 1].prod(L, R));
      return;
    }
    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
    prod_dfs(l0, r0, x1, x2, d - 1, res);
    prod_dfs(L + mid[d] - l0, R + mid[d] - r0, x1 - (1 << d), x2 - (1 << d),
             d - 1, res);
  }
};
#line 5 "main.cpp"

/*
min weight edge (a,b)

(1) a,b と接続しない辺を含む解 : wt(a,b) + x

あとは使う辺がすべて a,b と接続する場合を考えればよい
(2) au + bv
(3) ab + (au + av)
(4) ab + (bu + bv)

(1) がむずかしい？
*/

struct Mono {
  using value_type = int;
  using X = value_type;
  static X op(X x, X y) { return min(x, y); }
  static constexpr X unit() { return 2 * infty<int>; }
  static constexpr bool commute = 1;
};

void solve() {
  LL(N, M);
  vc<tuple<int, int, int>> init;
  FOR(M) {
    INT(a, b, c);
    if (a > b) swap(a, b);
    init.eb(--a, --b, c);
  }

  INT(Q);
  vc<tuple<int, int, int, int>> query(Q);
  FOR(q, Q) {
    INT(t);
    if (t == 0) {
      INT(a, b);
      if (a > b) swap(a, b);
      --a, --b;
      query[q] = {t, a, b, -1};
    }
    if (t == 1) {
      INT(a, b, c);
      if (a > b) swap(a, b);
      --a, --b;
      query[q] = {t, a, b, c};
    }
  }

  vc<pair<int, int>> ALL;
  for (auto& [a, b, c]: init) ALL.eb(a, b);
  for (auto& [t, a, b, c]: query) ALL.eb(a, b);
  UNIQUE(ALL);

  int n = len(ALL);
  vc<int> wt(n, 2 * infty<int>);

  vc<pqg<pair<int, int>>> que(N + 1);

  for (auto& [a, b, c]: init) {
    pair<int, int> p = {a, b};
    assert(0 <= a && a < b && b < N);
    int idx = LB(ALL, p);
    assert(0 <= idx && idx < n);
    wt[idx] = c;
    que[a].emplace(c, idx);
    que[b].emplace(c, idx);
    que[N].emplace(c, idx);
  }

  Wavelet_Matrix_2D_Range_Dynamic_Monoid<Mono, int, 1, 1> WM(
      n, [&](int i) -> tuple<int, int, int> {
        auto [a, b] = ALL[i];
        return {a, b, wt[i]};
      });

  auto add_edge = [&](int a, int b, int c) -> void {
    pair<int, int> p = {a, b};
    int idx = LB(ALL, p);
    wt[idx] = c;
    WM.set(idx, c);
    que[a].emplace(c, idx);
    que[b].emplace(c, idx);
    que[N].emplace(c, idx);
  };
  auto rm_edge = [&](int a, int b) -> void {
    pair<int, int> p = {a, b};
    int idx = LB(ALL, p);
    wt[idx] = 2 * infty<int>;
    WM.set(idx, 2 * infty<int>);
  };

  auto get = [&](int v) -> vc<pair<int, int>> {
    vc<pair<int, int>> res;
    while (len(que[v]) && len(res) <= 2) {
      auto [w, idx] = POP(que[v]);
      if (wt[idx] != w) continue;
      res.eb(w, idx);
    }
    for (auto& [a, b]: res) que[v].emplace(a, b);
    return res;
  };

  auto calc = [&]() -> void {
    while (len(que[N])) {
      auto [w, idx] = que[N].top();
      if (wt[idx] != w) {
        POP(que[N]);
        continue;
      }
      break;
    }
    auto [w, idx] = que[N].top();
    auto [a, b] = ALL[idx];
    ll ANS = infty<ll>;
    // (1)
    {
      ll mi = 2 * infty<int>;
      chmin(mi, WM.prod(0, a, 0, a));
      chmin(mi, WM.prod(0, a, a + 1, b));
      chmin(mi, WM.prod(0, a, b + 1, N));
      chmin(mi, WM.prod(a + 1, b, a + 1, b));
      chmin(mi, WM.prod(a + 1, b, b + 1, N));
      chmin(mi, WM.prod(b + 1, N, b + 1, N));
      chmin(ANS, mi + w);
    }
    auto E1 = get(a), E2 = get(b);
    // (2) au + bv
    for (auto& [x, i]: E1) {
      for (auto& [y, j]: E2) {
        auto [p, q] = ALL[i];
        auto [r, s] = ALL[j];
        if (p != r && p != s && q != r && q != s) chmin(ANS, x + y);
      }
    }
    // (3) ab+au+av
    FOR(2) {
      swap(E1, E2);
      if (len(E1) == 3) {
        ll x = E1[0].fi;
        ll y = E1[1].fi;
        ll z = E1[2].fi;
        chmin(ANS, x + y + z);
      }
    }
    print(ANS);
  };

  calc();
  for (auto& [t, a, b, c]: query) {
    if (t == 1) {
      add_edge(a, b, c);
    } else {
      rm_edge(a, b);
    }
    calc();
  }
}

signed main() {
  solve();
  return 0;
}
