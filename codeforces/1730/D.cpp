// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define _ << ' ' <<
using ll = long long;
using ull = unsigned long long;
using dd = long double;
using str = string;
#define mset multiset
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define fun function
#define vec vector
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vdd vector<long double>
#define vvdd vector<vector<long double>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mt make_tuple
#define tii tuple<int, int>
#define vtii vector<tuple<int, int>>
#define tiii tuple<int, int, int>
#define tiil tuple<int, int, ll>
#define tll tuple<ll, ll>
#define tli tuple<ll, int>
#define tlii tuple<ll, int, int>
#define til tuple<int, ll>
#define till tuple<int, ll, ll>
#define tlll tuple<ll, ll, ll>
#define tiiii tuple<int, int, int, int>
#define tiiiii tuple<int, int, int, int, int>
#define vtiii vector<tiii>
#define vtiiii vector<tiiii>
#define vtiiiii vector<tiiiii>
#define vtll vector<tll>
#define vtli vector<tli>
#define vtil vector<til>
#define vtiil vector<tiil>
#define vtill vector<till>
#define vtlll vector<tlll>
#define vvtii vector<vtii>
#define vvtiii vector<vtiii>
#define vvtll vector<vtll>
#define vvtli vector<vtli>
#define vvtil vector<vtil>
#define vvtiil vector<tiil>
#define vvtill vector<vtill>
#define vvtlll vector<vtlll>
#define qi queue<int>
#define qll queue<ll>
#define qtii queue<tii>
#define si set<int>
#define sl set<ll>
#define usi uset<int>
#define sc set<char>
#define usc uset<char>
#define stii set<tii>
#define ustii uset<tii>
#define mii map<int, int>
#define umii umap<int, int>
#define mci map<char, int>
#define umci umap<char, int>
#define mli map<ll, int>
#define umli umap<ll, int>
#define mil map<int, ll>
#define umil umap<int, ll>
#define mll map<ll, ll>
#define umll umap<ll, ll>
#define mivi map<int, vi>
#define umivi umap<int, vi>
#define mivl map<int, vl>
#define umivl umap<int, vl>
#define mlvi map<ll, vi>
#define umlvi umap<ll, vi>
#define mlvl map<ll, vl>
#define umlvl umap<ll, vl>
#define msi map<string, int>
#define vmii vector<mii>
#define iss istringstream
#define pf push_front
#define ef emplace_front
#define pb push_back
#define popb pop_back
#define eb emplace_back
#define ins insert
#define lb lower_bound
#define up upper_bound
#define sordefault(a) sort(all(a))
#define sorcmp(a, cmp) sort(all((a)), (cmp))
#define GET_SORT(_1, _2, NAME, ...) NAME
#define sor(...) GET_SORT(__VA_ARGS__, sorcmp, sordefault)(__VA_ARGS__)
#define rev(a) reverse(all(a))
#define repb(i, b) for (int i = 0; i < (b); ++i)
#define repab(i, a, b) for (int i = (a); i < (b); ++i)
#define repabd(i, a, b, d) for (int i = (a); i < (b); i += (d))
#define GET_REP(_1, _2, _3, _4, NAME, ...) NAME
#define re(...) GET_REP(__VA_ARGS__, repabd, repab, repb)(__VA_ARGS__)
#define repra(i, a) for (int i = (a)-1; i >= 0; i--)
#define reprab(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define reprabd(i, a, b, d) for (int i = (a)-1; i >= (b); i -= (d))
#define GET_REPR(_1, _2, _3, _4, NAME, ...) NAME
#define rer(...) GET_REPR(__VA_ARGS__, reprabd, reprab, repra)(__VA_ARGS__)
#define eachone(a, x) for (auto &a : x)
#define eachtwo(k, v, x) for (auto &[k, v] : x)
#define eachthree(a, b, c, x) for (auto &[a, b, c] : x)
#define eachfour(a, b, c, d, x) for (auto &[a, b, c, d] : x)
#define eachfive(a, b, c, d, e, x) for (auto &[a, b, c, d, e] : x)
#define GET_EACH(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define ea(...) GET_EACH(__VA_ARGS__, eachfive, eachfour, eachthree, eachtwo, eachone)(__VA_ARGS__)
#define rvi(v, n) vi v = vi((n)); re(___i, n) cin >> v[___i];
#define rvi2(v, n, m) vvi v = vvi((n), vi((m))); re(___i, n) re(___j, m) cin >> v[___i][___j];
#define rvc(v, n) vc v = vc((n)); re(___i, n) cin >> v[___i];
#define rvc2(v, n, m) vvc v = vvc((n), vc((m))); re(___i, n) re(___j, m) cin >> v[___i][___j];
#define rvl(v, n) vl v = vl((n)); re(___i, n) cin >> v[___i];
#define rvl2(v, n, m) vvl v = vvl((n), vl((m))); re(___i, n) re(___j, m) cin >> v[___i][___j];
#define rvmi(v, n) vmi v = vmi((n)); re(___i, n) cin >> v[___i];
#define rvmi2(v, n, m) vvmi v = vvmi((n), vmi((m))); re(___i, n) re(___j, m) cin >> v[___i][___j];
#define rvs(v, n) vs v = vs((n)); re(___i, n) cin >> v[___i];
#define fail() fflush(stdout); cout.flush(); assert(false);
#define YES cout << "YES\n"
#define YESR { cout << "YES\n"; return; }
#define Yes cout << "Yes\n"
#define Yesr { cout << "Yes\n"; return; }
#define yes cout << "yes\n"
#define yesr { cout << "yes\n"; return; }
#define NO cout << "NO\n"
#define NOR { cout << "NO\n"; return; }
#define No cout << "No\n"
#define Nor { cout << "No\n"; return; }
#define no cout << "no\n";
#define nor { cout << "no\n"; return; }
#define n0 cout << "0\n"
#define n0r { cout << "0\n"; return; }
#define n1 cout << "-1\n"
#define n1r { cout << "-1\n"; return; }
template <typename A> using pqmax = priority_queue<A>;
template <typename A> using pqmin = priority_queue<A, vector<A>, greater<A>>;

template <typename A, typename T>
inline int lowb(const A& a, const T& v) { return static_cast<int>(distance(a.begin(), lower_bound(a.begin(), a.end(), v))); }
template <typename A, typename T>
inline int uppb(const A& a, const T& v) { return static_cast<int>(distance(a.begin(), upper_bound(a.begin(), a.end(), v))); }

template <typename T>
inline typename T::value_type mine(const T& a) { return *std::min_element(a.begin(), a.end()); }
template <typename T>
inline typename T::value_type maxe(const T& a) { return *std::max_element(a.begin(), a.end()); }
template <typename T>
inline int mini(const T& a) {
  return (int) distance(a.begin(), min_element(a.begin(), a.end()));
}
template <typename T>
inline int maxi(const T& a) {
  return (int) distance(a.begin(), max_element(a.begin(), a.end()));
}

const int MOD = (int) 1e9 + 7;
// const int MOD = 998244353;
const dd PI = acos((dd) -1);
const int e1 = (int)1e1, e2 = (int)1e2, e3 = (int)1e3, e4 = (int)1e4, e5 = (int)1e5, e6 = (int)1e6, e7 = (int)1e7, e8 = (int)1e8, e9 = (int) 1e9;
const ll e10 = (ll)1e10, e11 = (ll)1e11, e12 = (ll)1e12, e13 = (ll)1e13, e14 = (ll)1e14, e15 = (ll)1e15, e16 = (ll) 1e16, e17 = (ll)1e17, e18 = (ll) 1e18;

template <typename A>
vector<tuple<int, A>> enumerate(vector<A> v) {
  vector<tuple<int, A>> res(sz(v));
  re(i, sz(v)) res[i] = make_tuple(i, v[i]);
  return res;
}

template <typename T, typename First>
auto _mkvec(const T& init, First first) {
  return vector<T>(first, init);
}
template <typename T, typename First, typename... Rest>
auto _mkvec(const T& init, First first, Rest... rest) {
  return vector(first, _mkvec<T, Rest...>(init, rest...));
}
template <typename... Args, typename T>
auto mkvec(const tuple<Args...>& dims, const T& init) {
  return apply([&](auto&... dimsVariadic) {
    return _mkvec<T, Args...>(init, dimsVariadic...);
  }, dims);
}

template<int MOD>
struct mint {
  int v;
  explicit operator ll() const { return v; }
  mint() { v = 0; }
  mint(ll _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  mint& operator+=(const mint& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
  mint& operator-=(const mint& m) { if ((v -= m.v) < 0) v += MOD; return *this; }
  mint& operator*=(const mint& m) { v = (int) ((ll) v * m.v % MOD); return *this; }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, ll p) {
    mint ans = 1; assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p&1) ans *= a;
    return ans;}
  friend mint inv(const mint& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);}
  mint operator-() const { return mint(-v); }
  mint &operator++() { return *this += 1; }
  mint &operator--() { return *this -= 1; }
  mint operator++(int) {
    mint temp = *this += 1;
    return temp;}
  mint operator--(int) {
    mint temp = *this -= 1;
    return temp;}
  friend mint operator+(mint a, const mint &b) { return a += b; }
  friend mint operator-(mint a, const mint &b) { return a -= b; }
  friend mint operator*(mint a, const mint &b) { return a *= b; }
  friend mint operator/(mint a, const mint &b) { return a /= b; }
  friend ostream &operator<<(ostream &os, const mint &m) {
    os << m.v;
    return os;
  }
  friend istream &operator>>(istream &is, mint &m) {
    ll x;
    is >> x;
    m.v = (int) ((x % MOD) + MOD) % MOD;
    return is;
  }
};
using mi = mint<MOD>;
string to_string(mi x) { return to_string(x.v); }
mi operator"" _mi(ull x) { return x; }

typedef vector<mi> vmi;
typedef vector<vector<mi>> vvmi;
typedef vector<vector<vector<mi>>> vvvmi;
typedef tuple<mi, mi> tmimi;
typedef tuple<mi, mi, mi> tmimimi;
typedef vector<tmimi> vmimi;
typedef vector<tmimimi> vmimimi;
typedef queue<mi> qmi;

template <typename T, typename = void> struct is_hashable_container {
  static constexpr bool value = false;
};
template <typename T>
struct is_hashable_container<T, void_t<decltype(T{}.begin()), decltype(T{}.end())>> {
  static constexpr bool value = true;
};
template <typename T, typename = void> struct is_tuple_like {
  static constexpr bool value = false;
};
template <typename T>
struct is_tuple_like<T, void_t<typename tuple_size<T>::type>> {
  static constexpr bool value = true;
};
template <typename T, typename = void> struct is_hashable {
  static constexpr bool value = false;
};
template <typename T> struct is_hashable<T, void_t<decltype(hash<T>{}(T{}))>> {
  static constexpr bool value = true;
};

vector<size_t> VALS;
struct custom_hash {
  static size_t getfixed(int i) {
    while ((int) VALS.size() < i + 1)
      if (VALS.empty())
        VALS.push_back((size_t) chrono::steady_clock::now().time_since_epoch().count());
      else
        VALS.push_back(splitmix64(VALS.back()));
    return VALS[i];
  }
  static size_t splitmix64(size_t x) {
    x += (size_t)0x9e3779b97f4a7c15;
    x = (x ^ (x >> (size_t)30)) * (size_t)0xbf58476d1ce4e5b9;
    x = (x ^ (x >> (size_t)27)) * (size_t)0x94d049bb133111eb;
    return x ^ (x >> (size_t)31);
  }
  size_t operator()(size_t x) const { return splitmix64(x + getfixed(0)); }
  template <typename T>
  enable_if_t<is_tuple_like<T>::value, size_t> operator()(const T &t) const {
    int ic = 0;
    size_t rh = 0;
    apply([&](auto &&...args) {
      ((rh ^= splitmix64(hash<decay_t<decltype(args)>>{}(args) + getfixed(ic++))), ...);
    }, t);
    return rh;
  }
  template <typename T>
  enable_if_t<is_hashable_container<T>::value, size_t> operator()(const T &t) const {
    int ic = 0; size_t rh = getfixed(0);
    for (auto& x : t) rh &= splitmix64(x + getfixed(ic++));
    return rh;
  }
};

// Fix assignment/swap speed for gp_hash_table. https://codeforces.com/blog/entry/60737?#comment-850908
// see temp/gp_swap.cpp for some tests
template<class K, class V, class H = std::hash<K>>
class fixed_gp : public __gnu_pbds::gp_hash_table<K, V, H> {
  using base = __gnu_pbds::gp_hash_table<K, V, H>;
public:
  fixed_gp() : base() {}
  fixed_gp(const fixed_gp &other) : base(other) {}
  fixed_gp(fixed_gp &&other) : base() { this->swap(other); }
  auto operator=(const fixed_gp &other) -> fixed_gp & {
    static_cast<base &>(*this).operator=(other);
    return *this;
  }
  auto operator=(fixed_gp &&other) -> fixed_gp & {
    this->swap(other);
    other.clear();
    return *this;
  }
  size_t count(const K &key) const { return this->find(key) != this->end(); }
};
template <typename A, typename B> using umap = fixed_gp<A, B, custom_hash>;
template <typename A> using uset = fixed_gp<A, null_type, custom_hash>;

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int pct(long long x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { return x == 0 ? -1 : 31 - __builtin_clz(x); }
constexpr int bits(long long x) { return x == 0 ? -1 : 63 - __builtin_clzll(x); }
constexpr ll p2(int x) { assert(x < 64); return 1LL << x; }
// msk2(i) = a mask with i+1 1s. msk2(-1) = 0.
constexpr int msk2(int x) { return x == 31 ? 0xFFFFFFFF : ((uint32_t)1 << (x + 1)) - 1; }
constexpr bool test(int x, int i) { assert(i < 32); return (x & (1 << i)) != 0; }
constexpr bool test(long long x, int i) { assert(i < 64); return (x & (1LL << i)) != 0; }
int bitsrange(int l, int u) { assert(l <= u); return msk2(u) & ~msk2(l - 1); }

template <class T, class U> T ipow(T a, U p) {
  T ans = 1; assert(p >= 0);
  while (true) {
    if (p&1) ans *= a;
    p /= 2;
    if (!p) break;
    a *= a;
  }
  return ans;
}
template <class T, class U> T ipow(T a, U p, T m) {
  T ans = 1; assert(p >= 0);
  for (; p; p /= 2, a = (a * a) % m) if (p&1) ans = (ans * a) % m;
  return ans;
}

template <class T, class U> T fstTrue(T lo, T hi, U f) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}

template <class T, class U> T lstTrue(T lo, T hi, U f) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}

// Requirements: f is unimodal. f has adjacent-distinct values except possibly at its mode
template <class T, class U>
T ternary_search(T lo, T hi, U f, bool find_min = false) {
  assert(lo <= hi);
  return fstTrue(lo, hi - 1, [&](T n) { return find_min ? f(n) <= f(n + 1) : f(n) >= f(n + 1); });
}

template <class T> T sum(vector<T> &v) {
  if (v.empty()) return 0LL;
  T sum = v[0];
  for (int i = 1; i < (int) v.size(); i++) {
    sum += v[i];
  }
  return sum;
}

template <class F> F posmod(F a, F b) { return ((a % b) + b) % b; }
template <class F> F floordiv(F a, F d) { F res = a / d; if (res * d != a) res -= 1 & ((a>0)^(d>0)); return res; }
template <class F> F ceildiv(F a, F d) { F res = a / d; if (res * d != a) res += 1 & ((a<0)^(d>0)); return res; }
template <class F> F sq(F a) { return a * a; }
ll lcm(ll a, ll b) { return a*b / __gcd(a, b); }

ll arithprog(ll l, ll r, ll g=1) { // l + ... + r
#ifdef LOCAL
  assert((r - l) % g == 0);
#endif
  return ((r-l)/g + 1)*(l+r)/2;
}

long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

// Not const T &b so that ckmax works with gp_hash_table with uninitialized element.
template <class T> bool ckmin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

// The sequence function from haskell but only for vectors, aka the cartesian product.
// https://hackage.haskell.org/package/base-4.18.0.0/docs/Prelude.html#v:sequence
// example:
// > sequence [[1,2,3],[4,5,6]]
// [[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,4],[3,5],[3,6]]
template <class A>
vec<vec<A>> sequence(const vec<vec<A>>& a) {
  vec<vec<A>> res;
  vec<A> current;
  auto f = [&](auto&& self, int i) {
    if (i == sz(a)) {
      res.pb(current);
      return;
    }
    ea(x, a[i]) {
      current.pb(x);
      self(self, i + 1);
      current.popb();
    }
  };
  f(f, 0);
  return res;
}

double time() { return (double)chrono::steady_clock::now().time_since_epoch().count() / 1e9; }

#ifdef LOCAL
mt19937 rng(2222);
#else
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
#endif
int rint(int a=std::numeric_limits<int>::min(), int b=std::numeric_limits<int>::max()) { // inclusive bounds
  return uniform_int_distribution<int>(a, b)(rng);
}
ll rlong(ll a=std::numeric_limits<ll>::min(), ll b=std::numeric_limits<ll>::max()) { // inclusive bounds
  return uniform_int_distribution<ll>(a, b)(rng);
}
double rdouble(double a, double b) {
  return uniform_real_distribution<double>(a, b)(rng);
}

template <class T> void shuffle(vector<T> &v) {
  auto r0 = [](int x) { return rint(0, x-1); };
  random_shuffle(all(v), r0);
}

template <class T> void remdup(vector<T> &v, bool do_sort = true) { // sort and remove duplicates
  if (do_sort) sort(all(v));
  v.erase(unique(all(v)), end(v));
}

template <class F> void print(const F a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}

template <class F> void print(const vector<F> &a) {
  for (int i = 0; i < (int) a.size(); i++) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}

template <class F> void print2(const vector<vector<F>> &a) {
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[i].size(); j++) {
      if (j > 0) cout << ' ';
      cout << a[i][j];
    }
    cout << '\n';
  }
}

void printAdj(vvi &adj) {
  int n = sz(adj);
  re(u, n) {
    ea(v, adj[u]) {
      if (u < v) cout << u _ v << '\n';
    }
  }
  cout << '\n';
}

string reps(string s, int t) {
  string res = ""; res.reserve(sz(s) * t);
  re(i, t) res += s;
  return res;
}

string reps(char c, int t) { return string(t, c); }

ll binary_to_ll(string s) { return stoll(s, nullptr, 2); }
string ll_to_binary(ll x) {
  assert(x >= 0);
  return !x ? "0" : bitset<64>(x).to_string().substr(63 - bits(x), 1 + bits(x));
}

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;
  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }
  res.push_back(s.substr(pos_start));
  return res;
}

vector<string> split(string s, char delimiter) { return split(s, string(1, delimiter)); }

template <typename... Ts> string to_string(const tuple<Ts...> t);
template <typename A, typename B> string to_string(const pair<A, B> t);

string to_string(const string s) { return string(s); }
string to_string(const char c) { return string(1, c); }

template <class T, size_t K> string to_string(array<T, K> v) {
  string out = "[";
  re(i, (int) K) { if (i > 0) out += ", "; out += to_string(v[i]); }
  out += ']';
  return out;
}

template <class T, size_t K> ostream &operator<<(ostream &output, const array<T, K> v) {
  output << to_string(v);
  return output;
}

template<typename T, typename = void>
struct is_container : std::false_type {};

template<typename T>
struct is_container<T, std::void_t<decltype(T{}.begin()), decltype(T{}.end())>> : std::true_type {};

template<typename CharT, typename Traits, typename Alloc>
struct is_container<std::basic_string<CharT, Traits, Alloc>, void> : std::false_type {};

template <class T> enable_if_t<is_container<T>::value, string> to_string(T &t) {
  string out = "[";
  int i = 0;
  for (const auto &x : t) { if (i++ > 0) out += ", "; out += to_string(x); }
  out += ']';
  return out;
}

template <class T> enable_if_t<is_container<T>::value, ostream> &operator<<(ostream &output, T &t) {
    output << to_string(t);
    return output;
}

template <typename... Ts> string to_string(const tuple<Ts...> t) {
  string out;
  out += '(';
  apply([&](auto &&...args) { ((out += to_string(args) + ", "), ...); }, t);
  out.pop_back();
  out.pop_back();
  out += ')';
  return out;
}

template <typename... Ts>
ostream &operator<<(ostream &output, const tuple<Ts...> t) {
  output << to_string(t);
  return output;
}

template <typename A, typename B> string to_string(const pair<A, B> t) {
  string out;
  out += '(';
  out += to_string(t.first);
  out += ", ";
  out += to_string(t.second);
  out += ')';
  return out;
}

template <typename A, typename B> ostream &operator<<(ostream &output, const pair<A, B> t) {
  output << to_string(t);
  return output;
}

template <typename A> string to_string(const optional<A> t) {
  string out;
  if (t.has_value()) {
    out += "Just ";
    out += to_string(t.value());
  } else {
    out += "None";
  }
  return out;
}

template <typename A> ostream &operator<<(ostream &output, const optional<A> t) {
  output << to_string(t);
  return output;
}

#ifdef LOCAL
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args> void logger(string vars, Args &&...values) {
  cout << "| " << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
#else
#define dbg(...) 0
#endif

const int FMX = 1e6 + 30;
bool facinit = false;
mi facs[FMX];
mi facInvs[FMX];

mi ncr(ll a, ll b) {
  assert(facinit && a < FMX && b < FMX);
  assert(a >= 0 && b >= 0 && b <= a); // disable this assert whenever necessary
  if (b > a || a < 0 || b < 0)
    return 0;
  mi cur = facs[a];
  cur = cur * facInvs[b];
  cur = cur * facInvs[a - b];
  return cur;
}

void initfacs() {
  facs[0] = 1;
  re(i, 1, FMX) facs[i] = i * facs[i - 1];
  facInvs[FMX - 1] = inv(facs[FMX - 1]);
  rer(i, FMX - 1) facInvs[i] = facInvs[i + 1] * (i + 1);
  facinit = true;
}

void setIO() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout << fixed << setprecision(15);
  #ifdef GDB
  #define STRINGIZE(x) #x
  #define STRINGIZE_VALUE_OF(x) STRINGIZE(x)
  string basename = STRINGIZE_VALUE_OF(FNAME);
  basename = basename.substr(1, sz(basename)-2);
  string file_in = basename + ".in";
  string file_out = basename + ".out";
  freopen(file_in.c_str(), "r", stdin);
  freopen(file_out.c_str(), "w", stdout);
  #endif
}

void solve() {
  int n; cin >> n;
  str s1, s2; cin >> s1 >> s2;

  map<tuple<char, char>, int> m;
  re(i, n) {
    char c1 = s1[i];
    char c2 = s2[n-1-i];
    if (c1 > c2) swap(c1, c2);
    m[{c1, c2}]++;
  }

  bool oddN = n % 2 == 1;
  bool mid = false;
  bool bad = false;
  ea(k, v, m) {
    if (v % 2 == 1) {
      if (!mid && oddN && g0(k) == g1(k)) {
        mid = true;
      } else {
        bad = true;
      }
    }
  }
  if (bad) NOR;
  YESR;
}

int32_t main() {
  setIO();
  int t = 1;
  cin >> t;

  #ifdef LOCAL
  double time_start = time();
  #endif
  re(_t, t) solve();
  #ifdef LOCAL
  cout << "done. elapsed: " << setprecision(2) << time() - time_start << endl;
  #endif
  return 0;
}
