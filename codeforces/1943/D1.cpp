#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define fi first
#define se second
#define REP(i, n) for (auto i = 0; i < (n); ++i)
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (auto i = (a); i >= (b); --i)
#define FORE(i, a, b) for (auto i = (a); i < (b); ++i)
#define MASK(x) (1LL << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALL(x) (x).begin(), (x).end()
#define left ___left
#define right ___right
#define __builtin_popcount __builtin_popcountll

template <class T>
T inverse(T a, T m) {
    assert(0 <= a and a < m);
    T x = a, y = m;
    T vx = 1, vy = 0;
    while (x) {
        T k = y / x;
        y %= x;
        vy -= k * vx;
        swap(x, y);
        swap(vx, vy);
    }
    assert(y == 1);
    return vy < 0 ? m + vy : vy;
}

template <class T>
struct static_modint {

    static constexpr int mod() { return T::mod; }

    int val;

    static_modint(long long x = 0) : val(x % mod()) { if(val < 0) val += mod(); }

    friend bool operator == (const static_modint &a, const static_modint &b) { return a.val == b.val; }
    friend bool operator != (const static_modint &a, const static_modint &b) { return a.val != b.val; }
    friend bool operator < (const static_modint &a, const static_modint &b) { return a.val < b.val; }
    friend bool operator > (const static_modint &a, const static_modint &b) { return a.val > b.val; }
    friend bool operator <= (const static_modint &a, const static_modint &b) { return a.val <= b.val; }
    friend bool operator >= (const static_modint &a, const static_modint &b) { return a.val >= b.val; }


    static_modint& operator = (const long long &x) { val = x % mod(); if(val < 0) val += mod(); return *this; }
    static_modint& operator = (const static_modint &x) { val = x.val; return *this; }

    friend istream & operator >> (istream &in, static_modint &a) { long long x; in >> x; a = static_modint(x); return in; }
    friend ostream & operator << (ostream &out, const static_modint &a) { return out << a.val; }

    explicit operator int() const { return val; }
    explicit operator bool() const { return val > 0; }

    static_modint inv() const {
        static_modint res;
        res.val = inverse(val, mod());
        return res;
    }

    static_modint operator ++() { (*this) += 1; return *this; }
    static_modint operator --() { (*this) -= 1; return *this; }
    static_modint operator ++(int) { (*this) += 1; return *this - 1; }
    static_modint operator --(int) { (*this) -= 1; return *this + 1; }

    static_modint operator + () const { return *this; }
    static_modint operator - () const {
        static_modint res;
        res.val = (val ? mod() - val : 0);
        return res;
    }

    static_modint& operator += (const static_modint &a) {
        val += a.val;
        if(val >= mod()) val -= mod();
        return *this;
    }
    static_modint& operator -= (const static_modint &a) {
        val -= a.val;
        if(val < 0) val += mod();
        return *this;
    }
    static_modint& operator *= (const static_modint &a) {
        val = 1LL * val * a.val % mod();
        return *this;
    }
    static_modint& operator /= (const static_modint &a) {
        (*this) *= a.inv();
        return *this;
    }
    friend static_modint operator + (const static_modint &a, const static_modint &b) { return static_modint(a) += b; }
    friend static_modint operator - (const static_modint &a, const static_modint &b) { return static_modint(a) -= b; }
    friend static_modint operator * (const static_modint &a, const static_modint &b) { return static_modint(a) *= b; }
    friend static_modint operator / (const static_modint &a, const static_modint &b) { return static_modint(a) /= b; }
};


template <class T> T pow(T a, long long b) {
    T ans = 1, mul = a;
    for (; b; b >>= 1) {
        if(b & 1LL) ans *= mul;
        mul *= mul;
    }
    return ans;
}

struct modular { static int mod; }; int modular::mod = 1;

// struct modular {
//     static constexpr int mod = static_cast <int> (
//         1e9 + 7
//         // 998244353
//         // 1e9 + 9
//     );
// };

using Modint = static_modint <modular>;

template <int D, typename T>
struct Vec : public vector < Vec < D - 1, T >> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector < Vec < D - 1, T >> (n, Vec < D - 1, T > (args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};

void you_make_it(void) {
    int n, k; cin >> n >> k >> modular::mod;
    Vec <3, Modint> dp(n + 2, k + 1, 2), f(n + 2, k + 1, 2), g(n + 2, k + 1, 2);
    dp[0][0][0] = 1;
    FOR(p, 0, k) f[0][p][0] = 1;
    
    FOR(i, 1, n + 1) {
        FOR(p, 0, k) REP(x, 2) {
            dp[i][p][x] += f[i - 1][k][x];
            if(p < k and i > 1) {
                dp[i][p][x] += (k - p) * f[i - 2][k - p - 1][1 ^ x] - g[i - 2][k - p - 1][1 ^ x];
            }
            f[i][p][x] = dp[i][p][x];
            g[i][p][x] = dp[i][p][x] * p;
            if(p) {
                f[i][p][x] += f[i][p - 1][x];
                g[i][p][x] += g[i][p - 1][x];
            }
        }
    }
    Modint ans = 0;
    ans = dp[n + 1][0][0] - dp[n + 1][0][1];
    cout << ans; 
}

signed main() {

#ifdef LOCAL
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif // LOCAL
    auto start_time = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test = 1;
    cin >> test;

    for (int i = 0; i < test; ++i) {
        you_make_it();
        cout << '\n';
    }
    auto end_time = chrono::high_resolution_clock::now();

    cerr << "\nExecution time : " << chrono::duration_cast <chrono::milliseconds> (end_time - start_time).count() << "[ms]" << endl;
    return (0 ^ 0);
}

// Dream it. Wish it. Do it.
