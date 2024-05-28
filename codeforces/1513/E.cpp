#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back
#define FS first
#define SD second
#define ary(k) array<int,k>
template<class A,class B> void cmx(A& x, B y) {x=max<A>(x,y);}
template<class A,class B> void cmn(A& x, B y) {x=min<A>(x,y);}
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T>
struct Binomial {
  vector<T> f, g, h;
  Binomial(int MAX = 0) {
    assert(T::get_mod() != 0 && "Binomial<mint>()");
    f.resize(1, T{1});
    g.resize(1, T{1});
    h.resize(1, T{1});
    if (MAX > 0) extend(MAX + 1);
  }

  void extend(int m = -1) {
    int n = f.size();
    if (m == -1) m = n * 2;
    m = min<int>(m, T::get_mod());
    if (n >= m) return;
    f.resize(m);
    g.resize(m);
    h.resize(m);
    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);
    g[m - 1] = f[m - 1].inverse();
    h[m - 1] = g[m - 1] * f[m - 2];
    for (int i = m - 2; i >= n; i--) {
      g[i] = g[i + 1] * T(i + 1);
      h[i] = g[i] * f[i - 1];
    }
  }

  T fac(int i) {
    if (i < 0) return T(0);
    while (i >= (int)f.size()) extend();
    return f[i];
  }

  T finv(int i) {
    if (i < 0) return T(0);
    while (i >= (int)g.size()) extend();
    return g[i];
  }

  T inv(int i) {
    if (i < 0) return -inv(-i);
    while (i >= (int)h.size()) extend();
    return h[i];
  }

  T C(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fac(n) * finv(n - r) * finv(r);
  }

  inline T operator()(int n, int r) { return C(n, r); }

  template <typename I>
  T multinomial(const vector<I>& r) {
    static_assert(is_integral<I>::value == true);
    int n = 0;
    for (auto& x : r) {
      if (x < 0) return T(0);
      n += x;
    }
    T res = fac(n);
    for (auto& x : r) res *= finv(x);
    return res;
  }

  template <typename I>
  T operator()(const vector<I>& r) {
    return multinomial(r);
  }

  T C_naive(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    T ret = T(1);
    r = min(r, n - r);
    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
    return ret;
  }

  T P(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fac(n) * finv(n - r);
  }

  // [x^r] 1 / (1-x)^n
  T H(int n, int r) {
    if (n < 0 || r < 0) return T(0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
template <typename Int, typename UInt, typename Long, typename ULong, int id>
struct ArbitraryLazyMontgomeryModIntBase {
  using mint = ArbitraryLazyMontgomeryModIntBase;

  inline static UInt mod;
  inline static UInt r;
  inline static UInt n2;
  static constexpr int bit_length = sizeof(UInt) * 8;

  static UInt get_r() {
    UInt ret = mod;
    while (mod * ret != 1) ret *= UInt(2) - mod * ret;
    return ret;
  }
  static void set_mod(UInt m) {
    assert(m < (UInt(1u) << (bit_length - 2)));
    assert((m & 1) == 1);
    mod = m, n2 = -ULong(m) % m, r = get_r();
  }
  UInt a;

  ArbitraryLazyMontgomeryModIntBase() : a(0) {}
  ArbitraryLazyMontgomeryModIntBase(const Long &b)
      : a(reduce(ULong(b % mod + mod) * n2)){};

  static UInt reduce(const ULong &b) {
    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;
  }

  mint &operator+=(const mint &b) {
    if (Int(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }
  mint &operator-=(const mint &b) {
    if (Int(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }
  mint &operator*=(const mint &b) {
    a = reduce(ULong(a) * b.a);
    return *this;
  }
  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }

  bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  mint operator-() const { return mint(0) - mint(*this); }
  mint operator+() const { return mint(*this); }

  mint pow(ULong n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul, n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    Long t;
    is >> t;
    b = ArbitraryLazyMontgomeryModIntBase(t);
    return (is);
  }

  mint inverse() const {
    Int x = get(), y = get_mod(), u = 1, v = 0;
    while (y > 0) {
      Int t = x / y;
      swap(x -= t * y, y);
      swap(u -= t * v, v);
    }
    return mint{u};
  }

  UInt get() const {
    UInt ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static UInt get_mod() { return mod; }
};

// id に適当な乱数を割り当てて使う
template <int id>
using ArbitraryLazyMontgomeryModInt =
    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long,
                                      unsigned long long, id>;
template <int id>
using ArbitraryLazyMontgomeryModInt64bit =
    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,
                                      __uint128_t, id>;
using T = ArbitraryLazyMontgomeryModInt<0>;
signed main() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    T::set_mod(1e9+7);
    int n; cin >> n;
    Binomial<T> b(n+1);
    auto calc = [&](vi vec){
        map<int,int> mp;
        for(int x : vec) mp[x]++;
        T ans = b.fac(sz(vec));
        for(auto[k,v]:mp) ans /= b.fac(v);
        return ans;
    };
    ll sum = 0;
    vi a(n); for(int& v : a) cin >> v,sum += v;
    if(sum % n) return cout << "0\n",0; 
    sum /= n;
    int eq = 0;
    vi sm,big;
    for(int x : a){
        if(x == sum) eq++;
        else if(x < sum) sm.PB(x);
        else big.PB(x);
    }
    if(sz(sm) < 2 || sz(big) < 2){
        cout << calc(a) << "\n";
        return 0;
    }
    T ans = calc(sm)*calc(big)*2*b.C(n,eq);
    cout << ans << "\n"; 
}
