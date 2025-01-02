#include<bits/stdc++.h>
using namespace std;
using LL = long long;

template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
    bool operator == (const ModInt &a) const { return x == a.x; };
    bool operator != (const ModInt &a) const { return x != a.x; };
    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator /= (const ModInt &a) { *this = *this / a; }
    friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
    friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
    friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}

    ModInt pow(int64_t n) const {
        ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
    
};
using mint = ModInt<1000000007>;

template<typename T>
void fast_walsh_hadamard_transform(vector<T> &f, bool inv = false){
    const int n = (int) f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; j += i << 1){
            for(int k = 0; k < i; k++){
                T s = f[j + k], t = f[j + k + i];
                f[j + k] = s + t;
                f[j + k + i] = s - t;
            }
        }
    }
    if (inv){
        T inv_n = T(1) / n;
        for(auto &x : f) x *= inv_n;
    }
}

template<typename T>
vector<T> bitwise_xor_convolution(vector<T> f, vector<T> g){
    const int n = (int)f.size();
    assert(f.size() == g.size());
    assert((n & (n - 1)) == 0);
    fast_walsh_hadamard_transform(f, false);
    fast_walsh_hadamard_transform(g, false);
    for(int i = 0; i < n; i++) f[i] *= g[i];
    fast_walsh_hadamard_transform(f, true);
    return f;
}

template<typename T>
void subset_zeta_transform(vector<T> &f) {
    const int n = (int) f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; j += i << 1) {
            for(int k = 0; k < i; k++) {
                f[j + k + i] += f[j + k];
            }
        }
    }
}

template<typename T>
void subset_moebius_transform(vector<T> &f) {
    const int n = (int) f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; j += i << 1) {
            for(int k = 0; k < i; k++) {
                f[j + k + i] -= f[j + k];
            }
        }
    }
}

template<typename T>
vector<T> bitwise_or_convolution(vector<T> f, vector<T> g) {
    const int n = (int) f.size();
    assert(f.size() == g.size());
    assert((n & (n - 1)) == 0);
    subset_zeta_transform(f);
    subset_zeta_transform(g);
    for(int i = 0; i < n; i++) f[i] *= g[i];
    subset_moebius_transform(f);
    return f;
}

template<typename T>
void superset_zeta_transform(vector<T> &f) {
    const int n = (int) f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; j += i << 1) {
            for(int k = 0; k < i; k++) {
                f[j + k] += f[j + k + i];
            }
        }
    }
}

template<typename T>
void superset_moebius_transform(vector<T> &f) {
    const int n = (int) f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; j += i << 1) {
            for(int k = 0; k < i; k++) {
                f[j + k] -= f[j + k + i];
            }
        }
    }
}

template<typename T>
vector<T> bitwise_and_convolution(vector<T> f, vector<T> g) {
    const int n = (int) f.size();
    assert(f.size() == g.size());
    assert((n & (n - 1)) == 0);
    superset_zeta_transform(f);
    superset_zeta_transform(g);
    for(int i = 0; i < n; i++) f[i] *= g[i];
    superset_moebius_transform(f);
    return f;
}


int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    const int N = 1 << 17, M = 17;
    vector<mint> fib(N);
    fib[0] = 0, fib[1] = 1;
    for(int i = 2; i < N; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int n;
    cin >> n;
    vector<mint> f(N);
    vector<vector<mint> > g(M + 1, vector<mint>(N));
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        f[x] += 1;
        g[__builtin_popcount(x)][x] += 1;
    }
    vector<mint> a(N);
    for(int i = 0; i <= M; i++){
        subset_zeta_transform(g[i]);
    }
    for(int i = 0; i <= M; i++){
        vector<mint> h(N);
        for(int j = 0; j <= i; j++){
            for(int k = 0; k < N; k++){
                h[k] += g[j][k] * g[i - j][k];
            }
        }
        subset_moebius_transform(h);
        for(int k = 0; k < N; k++){
            if (__builtin_popcount(k) == i){
                a[k] = h[k];
            }
        }
    }
    auto b = bitwise_xor_convolution(f, f);
    for(int i = 0; i < N; i++){
        f[i] *= fib[i];
        a[i] *= fib[i];
        b[i] *= fib[i];
    }
    auto c = bitwise_and_convolution(a, f);
    auto d = bitwise_and_convolution(c, b);
    mint ans = 0;
    for(int i = 1; i < N; i *= 2){
        ans += d[i];
    }
    cout << ans << "\n";
}