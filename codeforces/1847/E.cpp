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
#line 1 "/home/maspy/compro/library/other/io2.hpp"
#define INT(...) \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...) \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...) \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...) \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S> void read(pair<T, S> &p) { read(p.first), read(p.second); }
template <class T> void read(vector<T> &a) {for(auto &i : a) read(i);}
template <class T> void read(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  read(head);
  IN(tail...);
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
  cout.flush();
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
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
#line 1 "/home/maspy/compro/library/enumerate/product.hpp"
// [0, A0) x [0, A1) x ...
template <typename F>
void enumerate_product(vc<int> A, F query) {
  int N = len(A);
  auto dfs = [&](auto& dfs, vc<int>& p) -> void {
    int n = len(p);
    if (n == N) return query(p);
    FOR(x, A[n]) {
      p.eb(x);
      dfs(dfs, p);
      p.pop_back();
    }
  };
  vc<int> p;
  dfs(dfs, p);
}
#line 5 "main.cpp"

ll F(ll a, ll b, ll c) {
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a + b <= c) return 0;
  ll x = a + b + c;
  x *= -a + b + c;
  x *= +a - b + c;
  x *= +a + b - c;
  return x;
}

using ARR = array<ll, 10>;
map<ARR, vc<array<int, 5>>> MP;

void init() {
  FOR(a, 1, 5) FOR(b, 1, 5) FOR(c, 1, 5) {
    FOR(d, 1, 5) FOR(e, 1, 5) {
      ARR x;
      x[0] = F(a, b, c);
      x[1] = F(a, b, d);
      x[2] = F(a, c, d);
      x[3] = F(b, c, d);
      x[4] = F(a, b, e);
      x[5] = F(a, c, e);
      x[6] = F(a, d, e);
      x[7] = F(b, c, e);
      x[8] = F(b, d, e);
      x[9] = F(c, d, e);
      // x[10] = F(a, b, f);
      // x[11] = F(a, c, f);
      // x[12] = F(a, d, f);
      // x[13] = F(a, e, f);
      // x[14] = F(b, c, f);
      // x[15] = F(b, d, f);
      // x[16] = F(b, e, f);
      // x[17] = F(c, d, f);
      // x[18] = F(c, e, f);
      // x[19] = F(d, e, f);
      ll ma = 0;
      FOR(i, len(x)) chmax(ma, x[i]);
      assert(ma > 0);
      MP[x].eb(array<int, 5>{int(a), int(b), int(c), int(d), int(e)});
    }
  }
  // for (auto [k, dat]: MP) {
  //   if (len(dat) == 1) continue;
  //   for (auto& [a, b, c, d, e]: dat) print(a, b, c, d, e);
  //   print();
  // }
}

/*
5 個みる → nonzero area が見つかる
- たいていの場合は確定する
- 確定しない場合：1 が複数あって、1 の場所は確定している
- 同一種類かつ確定したものが 2 個以上あるとき
  - 2, 3, 4 であれば、残り全部決められる.

問題となる場合は、1 が 2 個以上はわかっている場合
unknown が 4 個出てきた時点ですべて確定する
*/

void solve() {
  LL(N);
#if defined(LOCAL)
  N = 6;
  vi god(N);
  FOR(i, N) god[i] = RNG(1, 5);
  // if (RNG(0, 2)) { god[0] = god[1] = 1; }
  god[0] = god[1] = 1;
#endif

  vc<int> ANS(N, -1);
  map<tuple<int, int, int>, ll> memo;

  auto ask = [&](int i, int j, int k) -> ll {
    assert(i != j && i != k && j != k);
    tuple<int, int, int> t = {i, j, k};
    if (memo.count(t)) return memo[t];
    print("?", 1 + i, 1 + j, 1 + k);
#if defined(LOCAL)
    return memo[t] = F(god[i], god[j], god[k]);
#endif
    LL(x);
    return memo[t] = x;
  };

  auto out = [&]() -> void {
#if defined(LOCAL)
    print("god=", god);
    print("ANS=", ANS);
    FOR(i, N) if (ANS[i] != -1) assert(ANS[i] == god[i]);
    print("AC");
    return;
#endif
    bool unique = 1;
    FOR(i, N) if (ANS[i] == -1) unique = 0;
    if (unique) {
      print("!", ANS);
    } else {
      print("!", -1);
    }
  };

  if (N <= 4) {
    ll cnt = 0;
    enumerate_product(vc<int>(N, 5), [&](vc<int> A) -> void {
      if (MIN(A) == 0) return;
      bool ok = 1;
      FOR(k, N) FOR(j, k) FOR(i, j) {
        if (ask(i, j, k) != F(A[i], A[j], A[k])) ok = 0;
      }
      if (ok) {
        ++cnt;
        ANS = A;
      }
    });
    if (cnt != 1) fill(all(ANS), -1);
    return out();
  }

  assert(N >= 5);
  ARR x;
  {
    int a = 0, b = 1, c = 2, d = 3, e = 4;
    x[0] = ask(a, b, c);
    x[1] = ask(a, b, d);
    x[2] = ask(a, c, d);
    x[3] = ask(b, c, d);
    x[4] = ask(a, b, e);
    x[5] = ask(a, c, e);
    x[6] = ask(a, d, e);
    x[7] = ask(b, c, e);
    x[8] = ask(b, d, e);
    x[9] = ask(c, d, e);
  }
  auto dat = MP[x];
  if (len(dat) == 1) {
    auto x = dat[0];
    FOR(i, 5) ANS[i] = x[i];
  } else {
    auto x = dat[0];
    FOR(i, 5) ANS[i] = (x[i] == 1 ? 1 : -1);
  }

  auto [a, b] = [&]() -> pair<int, int> {
    FOR(j, 5) FOR(i, j) {
      if (ANS[i] != -1 && ANS[i] == ANS[j]) return {i, j};
    }
    assert(0);
  }();

  if (ANS[a] != 1) {
    // 全部決まる
    FOR(i, N) {
      if (ANS[i] == -1) {
        FOR(x, 1, 5) {
          if (F(ANS[a], ANS[b], x) == ask(a, b, i)) {
            ANS[i] = x;
            break;
          }
        }
      }
      assert(ANS[i] != -1);
    }
    return out();
  }

  assert(ANS[a] == 1 && ANS[b] == 1);
  FOR(i, 5) if (ANS[i] != 1) ANS[i] = -1;
  // unknown index
  vc<int> I;
  FOR(i, N) {
    if (len(I) >= 4) break;
    if (ANS[i] != -1) continue;
    ll x = ask(a, b, i);
    if (x > 0) {
      ANS[i] = 1;
      continue;
    }
    I.eb(i);
  }

  auto [p, q] = [&]() -> pair<int, int> {
    for (auto& i: I) {
      for (auto& j: I) {
        if (i < j) {
          ll x = ask(a, i, j);
          if (x != 0) return {i, j};
        }
      }
    }
    return {-1, -1};
  }();

  if (p == -1) {
    // 1....1,2,3,4 の sub
    return out();
  }

  ANS[p] = ANS[q] = [&]() -> int {
    FOR(x, 1, 5) {
      if (ask(p, q, a) == F(x, x, 1)) return x;
    }
    assert(0);
  }();

  a = p, b = q;
  FOR(i, N) {
    if (ANS[i] == -1) {
      FOR(x, 1, 5) {
        if (F(ANS[a], ANS[b], x) == ask(a, b, i)) {
          ANS[i] = x;
          break;
        }
      }
    }
    assert(ANS[i] != -1);
  }
  return out();
}

signed main() {
  init();
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
