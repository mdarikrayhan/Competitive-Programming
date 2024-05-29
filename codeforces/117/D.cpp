#line 1 "/home/maspy/compro/library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}
template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sum = 0;
  for (auto &&a: A) sum += a;
  return sum;
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
  assert(!que.empty());
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  assert(!que.empty());
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));
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
// based on yosupo's fastio
#include <unistd.h>

namespace fastio {
#define FASTIO
// クラスが read(), print() を持っているかを判定するメタ関数
struct has_write_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.write(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_write : public decltype(has_write_impl::check<T>(std::declval<T>())) {
};

struct has_read_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.read(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_read : public decltype(has_read_impl::check<T>(std::declval<T>())) {};

struct Scanner {
  FILE *fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <typename T,
            typename enable_if<has_read<T>::value>::type * = nullptr>
  inline bool read_single(T &x) {
    x.read();
    return true;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  bool read_single(char &ref) {
    string s;
    if (!read_single(s) || s.size() != 1) return false;
    ref = s[0];
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <size_t N = 0, typename T>
  void read_single_tuple(T &t) {
    if constexpr (N < std::tuple_size<T>::value) {
      auto &x = std::get<N>(t);
      read_single(x);
      read_single_tuple<N + 1>(t);
    }
  }
  template <class... T>
  bool read_single(tuple<T...> &tpl) {
    read_single_tuple(tpl);
    return true;
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string s) {
    for (char c: s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  void write(const long double x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  template <typename T,
            typename enable_if<has_write<T>::value>::type * = nullptr>
  inline void write(T x) {
    x.write();
  }
  template <class T>
  void write(const vector<T> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
  template <size_t N = 0, typename T>
  void write_tuple(const T t) {
    if constexpr (N < std::tuple_size<T>::value) {
      if constexpr (N > 0) { write(' '); }
      const auto x = std::get<N>(t);
      write(x);
      write_tuple<N + 1>(t);
    }
  }
  template <class... T>
  bool write(tuple<T...> tpl) {
    write_tuple(tpl);
    return true;
  }
  template <class T, size_t S>
  void write(const array<T, S> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  void write(i128 val) {
    string s;
    bool negative = 0;
    if (val < 0) {
      negative = 1;
      val = -val;
    }
    while (val) {
      s += '0' + int(val % 10);
      val /= 10;
    }
    if (negative) s += "-";
    reverse(all(s));
    if (len(s) == 0) s = "0";
    write(s);
  }
};
Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);
void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}
} // namespace fastio
using fastio::print;
using fastio::flush;
using fastio::read;

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
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

#line 2 "/home/maspy/compro/library/mod/modint_common.hpp"

struct has_mod_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});
  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>())) {};

template <typename mint>
mint inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {0, 1};
  assert(0 <= n);
  if (n >= mod) n %= mod;
  while (len(dat) <= n) {
    int k = len(dat);
    int q = (mod + k - 1) / k;
    dat.eb(dat[k * q - mod] * mint::raw(q));
  }
  return dat[n];
}

template <typename mint>
mint fact(int n) {
  static const int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  static vector<mint> dat = {1, 1};
  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));
  return dat[n];
}

template <typename mint>
mint fact_inv(int n) {
  static vector<mint> dat = {1, 1};
  if (n < 0) return mint(0);
  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));
  return dat[n];
}

template <class mint, class... Ts>
mint fact_invs(Ts... xs) {
  return (mint(1) * ... * fact_inv<mint>(xs));
}

template <typename mint, class Head, class... Tail>
mint multinomial(Head &&head, Tail &&... tail) {
  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);
}

template <typename mint>
mint C_dense(int n, int k) {
  static vvc<mint> C;
  static int H = 0, W = 0;
  auto calc = [&](int i, int j) -> mint {
    if (i == 0) return (j == 0 ? mint(1) : mint(0));
    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);
  };
  if (W <= k) {
    FOR(i, H) {
      C[i].resize(k + 1);
      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }
    }
    W = k + 1;
  }
  if (H <= n) {
    C.resize(n + 1);
    FOR(i, H, n + 1) {
      C[i].resize(W);
      FOR(j, W) { C[i][j] = calc(i, j); }
    }
    H = n + 1;
  }
  return C[n][k];
}

template <typename mint, bool large = false, bool dense = false>
mint C(ll n, ll k) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if constexpr (dense) return C_dense<mint>(n, k);
  if constexpr (!large) return multinomial<mint>(n, k, n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) x *= mint(n - i);
  return x * fact_inv<mint>(k);
}

template <typename mint, bool large = false>
mint C_inv(ll n, ll k) {
  assert(n >= 0);
  assert(0 <= k && k <= n);
  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);
  return mint(1) / C<mint, 1>(n, k);
}

// [x^d] (1-x) ^ {-n} の計算
template <typename mint, bool large = false, bool dense = false>
mint C_negative(ll n, ll d) {
  assert(n >= 0);
  if (d < 0) return mint(0);
  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }
  return C<mint, large, dense>(n + d - 1, d);
}
#line 2 "/home/maspy/compro/library/mod/primitive_root.hpp"

#line 2 "/home/maspy/compro/library/nt/primetest.hpp"
struct m64 {
  using i64 = int64_t;
  using u64 = uint64_t;
  using u128 = __uint128_t;

  inline static u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)
  static void set_mod(u64 m) {
    assert((m & 1) == 1);
    m64::m = m;
    n2 = -u128(m) % m;
    r = m;
    FOR(_, 5) r *= 2 - m * r;
    r = -r;
    assert(r * m == -1ull);
  }
  static u64 reduce(u128 b) { return (b + u128(u64(b) * r) * m) >> 64; }

  u64 x;
  m64() : x(0) {}
  m64(u64 x) : x(reduce(u128(x) * n2)){};
  u64 val() const {
    u64 y = reduce(x);
    return y >= m ? y - m : y;
  }
  m64 &operator+=(m64 y) {
    x += y.x - (m << 1);
    x = (i64(x) < 0 ? x + (m << 1) : x);
    return *this;
  }
  m64 &operator-=(m64 y) {
    x -= y.x;
    x = (i64(x) < 0 ? x + (m << 1) : x);
    return *this;
  }
  m64 &operator*=(m64 y) {
    x = reduce(u128(x) * y.x);
    return *this;
  }
  m64 operator+(m64 y) const { return m64(*this) += y; }
  m64 operator-(m64 y) const { return m64(*this) -= y; }
  m64 operator*(m64 y) const { return m64(*this) *= y; }
  bool operator==(m64 y) const {
    return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);
  }
  bool operator!=(m64 y) const { return not operator==(y); }
  m64 pow(u64 n) const {
    m64 y = 1, z = *this;
    for (; n; n >>= 1, z *= z)
      if (n & 1) y *= z;
    return y;
  }
};

bool primetest(const uint64_t x) {
  using u64 = uint64_t;
  if (x == 2 or x == 3 or x == 5 or x == 7) return true;
  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;
  if (x < 121) return x > 1;
  const u64 d = (x - 1) >> __builtin_ctzll(x - 1);
  m64::set_mod(x);
  const m64 one(1), minus_one(x - 1);
  auto ok = [&](u64 a) {
    auto y = m64(a).pow(d);
    u64 t = d;
    while (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;
    if (y != minus_one and t % 2 == 0) return false;
    return true;
  };
  if (x < (1ull << 32)) {
    for (u64 a: {2, 7, 61})
      if (not ok(a)) return false;
  } else {
    for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if (x <= a) return true;
      if (not ok(a)) return false;
    }
  }
  return true;
}
#line 3 "/home/maspy/compro/library/nt/factor.hpp"

mt19937_64 rng_mt{random_device{}()};
ll rnd(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng_mt); }

ll rho(ll n, ll c) {
  m64::set_mod(n);
  assert(n > 1);
  const m64 cc(c);
  auto f = [&](m64 x) { return x * x + cc; };
  m64 x = 1, y = 2, z = 1, q = 1;
  ll g = 1;
  const ll m = 1LL << (__lg(n) / 5); // ?
  for (ll r = 1; g == 1; r <<= 1) {
    x = y;
    FOR(_, r) y = f(y);
    for (ll k = 0; k < r and g == 1; k += m) {
      z = y;
      FOR(_, min(m, r - k)) y = f(y), q *= x - y;
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
  FOR(_, 100) {
    ll m = rho(n, rnd(n));
    if (primetest(m)) return m;
    n = m;
  }
  cerr << "failed" << endl;
  assert(false);
  return -1;
}

// ソートしてくれる
vc<pair<ll, int>> factor(ll n) {
  assert(n >= 1);
  vc<pair<ll, int>> pf;
  FOR3(p, 2, 100) {
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
#line 3 "/home/maspy/compro/library/mod/mod_pow.hpp"

// int
ll mod_pow(ll a, ll n, int mod) {
  assert(n >= 0);
  a %= mod;
  if (a < 0) a += mod;
  Barrett bt(mod);
  ll p = a, v = bt.modulo(1);
  while (n) {
    if (n & 1) v = bt.mul(v, p);
    p = bt.mul(p, p);
    n >>= 1;
  }
  return v;
}

ll mod_pow_long(ll a, ll n, ll mod) {
  assert(n >= 0);
  a %= mod;
  if (a < 0) a += mod;
  ll p = a, v = 1 % mod;
  while (n) {
    if (n & 1) v = i128(v) * p % mod;
    p = i128(p) * p % mod;
    n >>= 1;
  }
  return v;
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
#line 6 "/home/maspy/compro/library/mod/primitive_root.hpp"

// int
int primitive_root(int p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](int g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  while (1) {
    int x = RNG(1, p);
    if (is_ok(x)) return x;
  }
  return -1;
}

ll primitive_root_long(ll p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](ll g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow_long(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  while (1) {
    ll x = RNG(1, p);
    if (is_ok(x)) return x;
  }
  return -1;
}
#line 5 "/home/maspy/compro/library/mod/dynamic_modint.hpp"

struct Dynamic_Modint {
  static constexpr bool is_modint = true;
  using mint = Dynamic_Modint;
  u32 val;
  static Barrett bt;
  static u32 umod() { return bt.umod(); }

  static int get_mod() { return (int)(bt.umod()); }
  static void set_mod(int m) {
    assert(1 <= m);
    bt = Barrett(m);
  }

  static Dynamic_Modint raw(u32 v) {
    Dynamic_Modint x;
    x.val = v;
    return x;
  }
  Dynamic_Modint() : val(0) {}
  Dynamic_Modint(u32 x) : val(bt.modulo(x)) {}
  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}
  Dynamic_Modint(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}
  Dynamic_Modint(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}

  mint& operator+=(const mint& rhs) {
    val = (val += rhs.val) < umod() ? val : val - umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    val = (val += umod() - rhs.val) < umod() ? val : val - umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    val = bt.mul(val, rhs.val);
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inverse(); }
  mint operator-() const { return mint() - *this; }
  mint pow(ll n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x, n >>= 1;
    }
    return r;
  }
  mint inverse() const {
    int x = val, mod = get_mod();
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    if (u < 0) u += mod;
    return u;
  }

  friend mint operator+(const mint& lhs, const mint& rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint& lhs, const mint& rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint& lhs, const mint& rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint& lhs, const mint& rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint& lhs, const mint& rhs) {
    return lhs.val == rhs.val;
  }
  friend bool operator!=(const mint& lhs, const mint& rhs) {
    return lhs.val != rhs.val;
  }
#ifdef FASTIO
  void write() { fastio::printer.write(val); }
  void read() {
    fastio::scanner.read(val);
    val = bt.modulo(val);
  }
#endif
  static pair<int, int>& get_ntt() {
    static pair<int, int> p = {-1, -1};
    return p;
  }
  static void set_ntt_info() {
    int mod = get_mod();
    int k = lowbit(mod - 1);
    int r = primitive_root(mod);
    r = mod_pow(r, (mod - 1) >> k, mod);
    get_ntt() = {k, r};
  }
  static pair<int, int> ntt_info() { return get_ntt(); }
  static bool can_ntt() { return ntt_info().fi != -1; }
};

using dmint = Dynamic_Modint;
Barrett dmint::bt(1);
#line 5 "main.cpp"

using mint = dmint;

pair<mint, mint> F(ll N, ll M, ll u, ll v) {
  // 0, 1, ..., N - 1
  // prefix M 個
  if (u > v) return {0, 0};
  if (M == 0) return {0, 0};

  if (N == 1) {
    if (u <= 0 && 0 <= v) return {1, 0};
    return {0, 0};
  }
  if (M == N) {
    chmax(u, 0);
    chmin(v, N - 1);
    if (u > v) return {mint(0), mint(0)};
    i128 x = i128(u + v) * i128(v - u + 1) / 2;
    return {v - u + 1, mint(ll(x % mint::get_mod()))};
  }
  ll N1 = ceil(N, 2);
  ll N2 = floor(N, 2);
  if (M <= N1) {
    auto [cnt, sm] = F(N1, M, ceil(u, 2), floor(v, 2));
    return {cnt, sm + sm};
  }
  auto [c1, s1] = F(N1, N1, ceil(u, 2), floor(v, 2));
  auto [c2, s2] = F(N2, M - N1, ceil(u - 1, 2), floor(v - 1, 2));
  s1 += s1;
  s2 += s2 + c2;
  // print(N, M, u, v, c1 + c2, s1 + s2);
  return {c1 + c2, s1 + s2};
}

void solve() {
  LL(N, Q);
  INT(mod);
  mint::set_mod(mod);

  FOR(Q) {
    LL(L, R, u, v);
    --L;
    --u, --v;
    auto [c1, s1] = F(N, R, u, v);
    auto [c2, s2] = F(N, L, u, v);
    mint ANS = s1 - s2 + (c1 - c2);
    print(ANS);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
