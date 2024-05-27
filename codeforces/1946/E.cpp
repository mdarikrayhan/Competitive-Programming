#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<utility>
#include<tuple>
#include<cstdint>
#include<cstdio>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<cctype>
#include<chrono>
#include<random>
#include<cassert>
#include<cstddef>
#include<iterator>
#include<string_view>
#include<type_traits>

#ifdef LOCAL
#  include "debug_print.hpp"
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

using namespace std;
#define rep1(a)          for(int i = 0; i < a; i++)
#define rep2(i, a)       for(int i = 0; i < a; i++)
#define rep3(i, a, b)    for(int i = a; i < b; i++)
#define rep4(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(a)          for(int i = (a)-1; i >= 0; i--)
#define rrep2(i, a)       for(int i = (a)-1; i >= 0; i--)
#define rrep3(i, a, b)    for(int i = (b)-1; i >= a; i--)
#define rrep4(i, a, b, c) for(int i = (b)-1; i >= a; i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using vvvvvc = vector<vvvvc<T>>;
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
template<typename T> using PQ = priority_queue<T,vector<T>>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void yesno(bool flag) {cout << (flag?"YES":"NO") << "\n";}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    int s = (int)v.size();
    for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
    return os;
}
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &x : v) is >> x;
    return is;
}
void in() {}
template<typename T, class... U>
void in(T &t, U &...u) {
    cin >> t;
    in(u...);
}
void out() { cout << "\n"; }
template<typename T, class... U, char sep = ' '>
void out(const T &t, const U &...u) {
    cout << t;
    if (sizeof...(u)) cout << sep;
    out(u...);
}
void outr() {}
template<typename T, class... U, char sep = ' '>
void outr(const T &t, const U &...u) {
    cout << t;
    outr(u...);
}

template<int mod> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % mod) {
        if (val < 0) val += mod;
    }
    constexpr int getmod() { return mod; }
    constexpr Fp operator - () const noexcept {
        return val ? mod - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % mod;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % mod;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<mod>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<mod> modpow(const Fp<mod> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int mod = fact_[0].getmod();
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[mod%i] * (mod/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T perm(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};

const int mod = 1e9+7;
// const int mod = 998244353;
using mint = Fp<mod>;
BiCoef<mint> bc;

void solve(){
    int n,m1,m2; in(n,m1,m2);
    vector<int> p(m1), s(m2); in(p,s);
    if(p.back() != s.front() or p.front() != 1 or s.back() != n){
        out(0);
        return;
    }
    mint ans = bc.com(n-1, p.back()-1);
    rep(i,m1-1) ans *= bc.fact(p[i+1]-p[i]-1) * bc.com(p[i+1]-2, p[i+1]-p[i]-1);
    rep(i,m2-1) ans *= bc.fact(s[i+1]-s[i]-1) * bc.com(n-s[i]-1, s[i+1]-s[i]-1);
    out(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bc.init(400004);
    int TCs = 1;
    in(TCs);
    while(TCs--){
        solve();
    }
}
