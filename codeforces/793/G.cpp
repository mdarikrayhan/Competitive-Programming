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

#if defined(LOCAL)
#define SHOW(...) \
  SHOW_IMPL(__VA_ARGS__, SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)
#define SHOW_IMPL(_1, _2, _3, _4, NAME, ...) NAME
#define SHOW1(x) print(#x, "=", (x)), flush()
#define SHOW2(x, y) print(#x, "=", (x), #y, "=", (y)), flush()
#define SHOW3(x, y, z) print(#x, "=", (x), #y, "=", (y), #z, "=", (z)), flush()
#define SHOW4(x, y, z, w) \
  print(#x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w)), flush()
#else
#define SHOW(...)
#endif

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

#line 2 "/home/maspy/compro/library/ds/my_bitset.hpp"

// https://codeforces.com/contest/914/problem/F
// https://yukicoder.me/problems/no/142
// わずかに普通の bitset より遅いときもあるようだが，
// 固定長にしたくないときや slice 操作が必要なときに使う
struct My_Bitset {
  using T = My_Bitset;
  int N;
  vc<u64> dat;

  // x で埋める
  My_Bitset(int N = 0, int x = 0) : N(N) {
    assert(x == 0 || x == 1);
    u64 v = (x == 0 ? 0 : -1);
    dat.assign((N + 63) >> 6, v);
    if (N) dat.back() >>= (64 * len(dat) - N);
  }

  int size() { return N; }

  void resize(int size) {
    dat.resize((size + 63) >> 6);
    int remainingBits = size & 63;
    if (remainingBits != 0) {
      u64 mask = (u64(1) << remainingBits) - 1;
      dat.back() &= mask;
    }
    N = size;
  }

  // thanks to chatgpt!
  class Proxy {
  public:
    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}
    operator bool() const { return (dat[index >> 6] >> (index & 63)) & 1; }

    Proxy &operator=(u64 value) {
      dat[index >> 6] &= ~(u64(1) << (index & 63));
      dat[index >> 6] |= (value & 1) << (index & 63);
      return *this;
    }
    void flip() {
      dat[index >> 6] ^= (u64(1) << (index & 63)); // XOR to flip the bit
    }

  private:
    vc<u64> &dat;
    int index;
  };

  Proxy operator[](int i) { return Proxy(dat, i); }

  bool operator==(const T &p) {
    assert(N == p.N);
    FOR(i, len(dat)) if (dat[i] != p.dat[i]) return false;
    return true;
  }

  T &operator&=(const T &p) {
    assert(N == p.N);
    FOR(i, len(dat)) dat[i] &= p.dat[i];
    return *this;
  }
  T &operator|=(const T &p) {
    assert(N == p.N);
    FOR(i, len(dat)) dat[i] |= p.dat[i];
    return *this;
  }
  T &operator^=(const T &p) {
    assert(N == p.N);
    FOR(i, len(dat)) dat[i] ^= p.dat[i];
    return *this;
  }
  T operator&(const T &p) const { return T(*this) &= p; }
  T operator|(const T &p) const { return T(*this) |= p; }
  T operator^(const T &p) const { return T(*this) ^= p; }
  T operator~() const {
    T p = (*this);
    p.flip_range(0, N);
    return p;
  }

  int count() {
    int ans = 0;
    for (u64 val: dat) ans += popcnt(val);
    return ans;
  }

  int next(int i) {
    chmax(i, 0);
    if (i >= N) return N;
    int k = i >> 6;
    {
      u64 x = dat[k];
      int s = i & 63;
      x = (x >> s) << s;
      if (x) return (k << 6) | lowbit(x);
    }
    FOR(idx, k + 1, len(dat)) {
      if (dat[idx] == 0) continue;
      return (idx << 6) | lowbit(dat[idx]);
    }
    return N;
  }

  int prev(int i) {
    chmin(i, N - 1);
    if (i <= -1) return -1;
    int k = i >> 6;
    if ((i & 63) < 63) {
      u64 x = dat[k];
      x &= (u64(1) << ((i & 63) + 1)) - 1;
      if (x) return (k << 6) | topbit(x);
      --k;
    }
    FOR_R(idx, k + 1) {
      if (dat[idx] == 0) continue;
      return (idx << 6) | topbit(dat[idx]);
    }
    return -1;
  }

  My_Bitset range(int L, int R) {
    assert(L <= R);
    My_Bitset p(R - L);
    int rm = (R - L) & 63;
    FOR(rm) {
      p[R - L - 1] = bool((*this)[R - 1]);
      --R;
    }
    int n = (R - L) >> 6;
    int hi = L & 63;
    int lo = 64 - hi;
    int s = L >> 6;
    if (hi == 0) {
      FOR(i, n) { p.dat[i] ^= dat[s + i]; }
    } else {
      FOR(i, n) { p.dat[i] ^= (dat[s + i] >> hi) ^ (dat[s + i + 1] << lo); }
    }
    return p;
  }

  int count_range(int L, int R) {
    assert(L <= R);
    int cnt = 0;
    while ((L < R) && (L & 63)) cnt += (*this)[L++];
    while ((L < R) && (R & 63)) cnt += (*this)[--R];
    int l = L >> 6, r = R >> 6;
    FOR(i, l, r) cnt += popcnt(dat[i]);
    return cnt;
  }

  // [L,R) に p を代入
  void assign_to_range(int L, int R, My_Bitset &p) {
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) { (*this)[L++] = bool(p[a++]); }
    while (L < R && (R & 63)) { (*this)[--R] = bool(p[--b]); }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6, t = b >> t;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] = p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
  }

  // [L,R) に p を xor
  void xor_to_range(int L, int R, My_Bitset &p) {
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) {
      dat[L >> 6] ^= u64(p[a]) << (L & 63);
      ++a, ++L;
    }
    while (L < R && (R & 63)) {
      --b, --R;
      dat[R >> 6] ^= u64(p[b]) << (R & 63);
    }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6, t = b >> t;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] ^= p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
  }

  // [L,R) に p を and
  void and_to_range(int L, int R, My_Bitset &p) {
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) {
      if (!p[a++]) (*this)[L++] = 0;
    }
    while (L < R && (R & 63)) {
      if (!p[--b]) (*this)[--R] = 0;
    }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6, t = b >> t;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] &= p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
  }

  // [L,R) に p を or
  void or_to_range(int L, int R, My_Bitset &p) {
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) {
      dat[L >> 6] |= u64(p[a]) << (L & 63);
      ++a, ++L;
    }
    while (L < R && (R & 63)) {
      --b, --R;
      dat[R >> 6] |= u64(p[b]) << (R & 63);
    }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6, t = b >> t;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] |= p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
  }

  // [L,R) を 1 に変更
  void set_range(int L, int R) {
    while (L < R && (L & 63)) { set(L++); }
    while (L < R && (R & 63)) { set(--R); }
    FOR(i, L >> 6, R >> 6) dat[i] = u64(-1);
  }

  // [L,R) を 1 に変更
  void reset_range(int L, int R) {
    while (L < R && (L & 63)) { reset(L++); }
    while (L < R && (R & 63)) { reset(--R); }
    FOR(i, L >> 6, R >> 6) dat[i] = u64(0);
  }

  // [L,R) を flip
  void flip_range(int L, int R) {
    while (L < R && (L & 63)) { flip(L++); }
    while (L < R && (R & 63)) { flip(--R); }
    FOR(i, L >> 6, R >> 6) dat[i] ^= u64(-1);
  }

  // bitset に仕様を合わせる
  void set(int i) { (*this)[i] = 1; }
  void reset(int i) { (*this)[i] = 0; }
  void flip(int i) { (*this)[i].flip(); }
  void set() {
    fill(all(dat), u64(-1));
    resize(N);
  }
  void reset() { fill(all(dat), 0); }
  void flip() {
    FOR(i, len(dat) - 1) { dat[i] = u64(-1) ^ dat[i]; }
    int i = len(dat) - 1;
    FOR(k, 64) {
      if (64 * i + k >= size()) break;
      flip(64 * i + k);
    }
  }
  bool any() {
    FOR(i, len(dat)) {
      if (dat[i]) return true;
    }
    return false;
  }

  int _Find_first() { return next(0); }
  int _Find_next(int p) { return next(p + 1); }

  static string TO_STR[256];
  string to_string() const {
    if (TO_STR[0].empty()) precompute();
    string S;
    for (auto &x: dat) { FOR(i, 8) S += TO_STR[(x >> (8 * i) & 255)]; }
    S.resize(N);
    return S;
  }

  static void precompute() {
    FOR(s, 256) {
      string x;
      FOR(i, 8) x += '0' + (s >> i & 1);
      TO_STR[s] = x;
    }
  }
};
string My_Bitset::TO_STR[256];
#line 1 "/home/maspy/compro/library/flow/bipartite_dense.hpp"

// vc<bitset> で biadj matrix を渡す
// N_1^2N_2/w.
// (5000,5000) で 300ms 程度で動く場合がある
// https://qoj.ac/problem/6308
// (10000?, 5000) 655ms
// https://codeforces.com/contest/1045/problem/A
// (10000, 20000) で 3837ms
// https://codeforces.com/contest/786/problem/E
template <typename BS>
struct BipartiteMatching_Dense {
  int N1, N2;
  vc<BS>& adj;
  vc<int> match_1, match_2;
  vc<int> que;
  vc<int> prev;
  BS vis;

  BipartiteMatching_Dense(vc<BS>& adj, int N1, int N2)
      : N1(N1), N2(N2), adj(adj), match_1(N1, -1), match_2(N2, -1) {
    if constexpr (is_same_v<BS, My_Bitset>) vis.resize(N2);
    FOR(s, N1) bfs(s);
  }

  void bfs(int s) {
    if (match_1[s] != -1) return;
    que.resize(N1), prev.resize(N1);
    int l = 0, r = 0;
    prev[s] = -1;
    vis.set();

    que[r++] = s;
    while (l < r) {
      int u = que[l++];
      BS cand = vis & adj[u];
      for (int v = cand._Find_first(); v < N2; v = cand._Find_next(v)) {
        vis[v] = 0;
        if (match_2[v] != -1) {
          que[r++] = match_2[v];
          prev[match_2[v]] = u;
          continue;
        }
        int a = u, b = v;
        while (a != -1) {
          int t = match_1[a];
          match_1[a] = b, match_2[b] = a, a = prev[a], b = t;
        }
        return;
      }
    }
    return;
  }

  vc<pair<int, int>> matching() {
    vc<pair<int, int>> res;
    FOR(v, N1) if (match_1[v] != -1) res.eb(v, match_1[v]);
    return res;
  }

  pair<vc<int>, vc<int>> vertex_cover() {
    vc<int> que(N1);
    int l = 0, r = 0;
    vis.set();
    vc<bool> done(N1);
    FOR(i, N1) {
      if (match_1[i] == -1) done[i] = 1, que[r++] = i;
    }
    while (l < r) {
      int a = que[l++];
      BS cand = adj[a] & vis;
      for (int b = cand._Find_first(); b < N2; b = cand._Find_next(b)) {
        vis[b] = 0;
        int to = match_2[b];
        assert(to != -1);
        if (!done[to]) done[to] = 1, que[r++] = to;
      }
    }
    vc<int> left, right;
    FOR(i, N1) if (!done[i]) left.eb(i);
    FOR(i, N2) if (!vis[i]) right.eb(i);
    return {left, right};
  }
};
#line 6 "main.cpp"

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
#line 2 "/home/maspy/compro/library/random/shuffle.hpp"

template <typename T>
void shuffle(vc<T>& A) {
  FOR(i, len(A)) {
    int j = RNG(0, i + 1);
    if (i != j) swap(A[i], A[j]);
  }
}
#line 8 "main.cpp"

// using BS = My_Bitset;
using BS = bitset<10000>;

void solve() {
  LL(N, Q);
  vc<BS> adj(N);
  FOR(i, N) adj[i].set();

  vc<int> idx(N);
  FOR(i, N) idx[i] = i;
  shuffle(idx);

  FOR(Q) {
    INT(x1, y1, x2, y2);
    --x1, --y1;
    FOR(x, x1, x2) { FOR(y, y1, y2) adj[x][idx[y]] = 0; }
  }

  // shuffle(adj);

  BipartiteMatching_Dense<BS> BM(adj, N, N);
  auto match = BM.matching();
  print(len(match));
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
