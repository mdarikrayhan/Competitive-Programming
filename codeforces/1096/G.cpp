#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define FOR(i, to) for (int i = 0; i < (to); ++i)
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
#define MOD 998244353

template<int MODX>
struct ModInt {
    using T = typename decay<decltype(MODX)>::type; T v;
    ModInt(): v(0) {}
    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    ModInt(U v) { if(v < 0) v = v % MODX + MODX; if(v >= MODX) v %= MODX; this->v = static_cast<T>(v); }
    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    explicit operator U() const { return static_cast<U>(v); }
    friend istream& operator>>(istream& in, ModInt& m) { int64_t v_; in >> v_; m = ModInt(v_); return in; } 
    friend ostream& operator<<(ostream& os, const ModInt& m) { return os << m.v; }
 
    static T inv(T a, T m) {
        T g = m, x = 0, y = 1;
        while(a != 0) {
            T q = g / a;
            g %= a; swap(g, a);
            x -= q * y; swap(x, y);
        } return x < 0? x + m : x;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MODX) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif // x must be less than 2^32 * m
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    ModInt inv() const { return ModInt(inv(v, MODX)); }
    ModInt operator-() const { return ModInt(v? MODX-v : 0); }
    ModInt& operator++() { v++; if(v == MODX) v = 0; return *this; }
    ModInt& operator--() { if(v == 0) v = MODX; v--; return *this; }
    ModInt operator++(int) { ModInt a = *this; ++*this; return a; }
    ModInt operator--(int) { ModInt a = *this; --*this; return a; }
    ModInt& operator+=(const ModInt& o) { v += o.v; if (v >= MODX) v -= MODX; return *this; }
    ModInt& operator-=(const ModInt& o) { v -= o.v; if (v < 0) v += MODX; return *this; }
    ModInt& operator*=(const ModInt& o) { v = fast_mod(uint64_t(v) * o.v); return *this; }
    ModInt& operator/=(const ModInt& o) { return *this *= o.inv(); }
    friend ModInt operator+(const ModInt& a, const ModInt& b) { ModInt res = a; res += b; return res; }
    friend ModInt operator-(const ModInt& a, const ModInt& b) { ModInt res = a; res -= b; return res; }
    friend ModInt operator*(const ModInt& a, const ModInt& b) { ModInt res = a; res *= b; return res; }
    friend ModInt operator/(const ModInt& a, const ModInt& b) { ModInt res = a; res /= b; return res; }
    friend bool operator==(const ModInt& a, const ModInt& b) { return a.v == b.v; }
    friend bool operator!=(const ModInt& a, const ModInt& b) { return a.v != b.v; }
    friend bool operator<(const ModInt& a, const ModInt& b) { return a.v < b.v; }
    friend bool operator>(const ModInt& a, const ModInt& b) { return a.v > b.v; }
    friend bool operator<=(const ModInt& a, const ModInt& b) { return a.v <= b.v; }
    friend bool operator>=(const ModInt& a, const ModInt& b) { return a.v >= b.v; }
    ModInt operator^(int64_t p) {
        if(p < 0) return inv() ^ -p;
        ModInt a = *this, res{1}; while(p > 0) {
            if(p & 1) res *= a;
            p >>= 1; if(p > 0) a *= a;
        } return res;
    }
};

typedef ModInt<MOD> mint;
const int N = 200100;
 
namespace NTT {
    const int FFT_CUTOFF = 150;
    vector<mint> roots = {0, 1};
    vector<int> bit_order;
    int max_size = 1; mint root = 2;
 
    auto find_root = []() {
        int order = MOD-1;
        while(~order & 1) order >>= 1, max_size <<= 1;
        while((root ^ max_size) != 1 or (root ^ max_size/2) == 1)
            root++;
        return 'W';
    }();
 
    void prepare_roots(int n) {
        if(sz(roots) >= n) return;
        int len = __builtin_ctz(sz(roots));
        roots.resize(n);
        while(n > 1 << len) {
            mint z = root ^ max_size >> len + 1;
            for(int i = 1 << len-1; i < 1 << len; i++) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = roots[i] * z;
            } len++;
        }
    }
 
    void reorder_bits(int n, vector<mint>& a) {
        if(sz(bit_order) != n) {
            bit_order.assign(n, 0);
            int len = __builtin_ctz(n);
            for(int i = 0; i < n; i++)
                bit_order[i] = (bit_order[i >> 1] >> 1) + ((i & 1) << len-1);
        }
        for(int i = 0; i < n; i++)
            if(i < bit_order[i]) swap(a[i], a[bit_order[i]]);
    }
 
    void fft(int n, vector<mint>& a) {
        assert(n <= max_size);
        prepare_roots(n); reorder_bits(n, a);
        for(int len = 1; len < n; len <<= 1)
            for(int i = 0; i < n; i += len << 1)
                for(int j = 0; j < len; j++) {
                    mint even = a[i + j];
                    mint odd = a[i + len + j] * roots[len + j];
                    a[i + j] = even + odd; a[i + len + j] = even - odd;
                }
    }
 
    template<typename T>
    vector<mint> multiply(const vector<T>& a, const vector<T>& b, bool trim = true) {
        int n = sz(a), m = sz(b);
        if(n == 0 or m == 0)
            return vector<mint>{0};
 
        if(min(n, m) < FFT_CUTOFF) {
            vector<mint> res(n + m - 1);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    res[i + j] += mint(a[i]) * mint(b[j]);
            if(trim) {
                while(!res.empty() && res.back() == 0)
                    res.pop_back();
            } return res;
        }
 
        int N = [](int x) { while(x & x-1) x = (x | x-1) + 1; return x; }(n + m - 1);
        vector<mint> fa(all(a)), fb(all(b));
        fa.resize(N); fb.resize(N);
 
        bool equal = fa == fb;
        fft(N, fa);
 
        if(equal) fb = fa;
        else fft(N, fb);
 
        mint inv_N = mint(N) ^ -1;
        for(int i = 0; i < N; i++)
            fa[i] *= fb[i] * inv_N;
        reverse(fa.begin() + 1, fa.end());
 
        fft(N, fa);
        fa.resize(n + m - 1);
 
        if(trim) {
            while(!fa.empty() && fa.back() == 0)
                fa.pop_back();
        }
 
        return fa;
    }
 
    template<typename T>
    vector<mint> expo(const vector<T>& a, int e, bool trim = true) {
        int n = sz(a);
        int N = [](int x) { while(x & x-1) x = (x | x-1) + 1; return x; }((n-1) * e + 1);
        vector<mint> fa(all(a)); fa.resize(N);
 
        fft(N, fa);
 
        mint inv_N = mint(N) ^ -1;
        for(int i = 0; i < N; i++)
            fa[i] = (fa[i] ^ e) * inv_N;
        reverse(fa.begin() + 1, fa.end());
 
        fft(N, fa);
        fa.resize((n-1) * e + 1);
 
        if(trim) {
            while(!fa.empty() && fa.back() == 0)
                fa.pop_back();
        }
 
        return fa;
    }
 
} // namespace NTT

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int k, n;
  cin>>n>>k;
  vector<mint> v;
  v.resize(10);

  FOR(i,k) {
    int x; cin>>x;
    v[x] = 1;
  }

  v = NTT::expo(v, n/2);

  mint ret = 0;
  FOR(k, n/2 * 9+1) {
    ret += v[k] * v[k];
  }

  cout<<ret<<"\n";
  return 0;
}