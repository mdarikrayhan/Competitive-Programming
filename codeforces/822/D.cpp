#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

template<class T>
constexpr T power(T a, ll b) {
    T res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(ll x) : x{norm(x % P)} {}

    constexpr int norm(int z) const {
        if (z < 0) {
            z += P;
        }
        if (z >= P) {
            z -= P;
        }
        return z;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr MInt &operator*=(MInt rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        ll v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
constexpr int P = MOD;
using Mint = MInt<P>;

/*
const int N = 5e5; //MAKE SURE THE BOUNDS ARE CORRECT
Mint factorial[N];
Mint inverse_factorial[N];
Mint mod_inverse[N];

//CALL THIS FUNCTION FROM MAIN
void precalculate_factorials() {
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    inverse_factorial[N - 1] = factorial[N - 1].inv();
    for (int i = N - 1; i > 0; i--) {
        inverse_factorial[i - 1] = inverse_factorial[i] * i;
        mod_inverse[i] = inverse_factorial[i] * factorial[i - 1];
    }
}

Mint C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return factorial[n] * inverse_factorial[k] * inverse_factorial[n - k];
}
*/

const int N = 5e6 + 4;
ll f[N];

vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}


void pre_calc() {
    for (int i = 0; i < N; i++) {
        f[i] = INF;
    }
    f[0] = 0;
    f[1] = 0;
    f[2] = 1;
    f[3] = 3;

    auto get = [&](ll n, ll x) -> ll {
        ll groups = n / x;
        return (x * (x - 1) / 2) * groups + f[n / x];
    };

    for (ll i = 4; i < N; i++) {
        int cur = i;
        while (cur != 1) {
            int p = minp[cur];
            f[i] = min(f[i], get(i, p));
            while (cur % p == 0) cur /= p;
        }
    }

}


void solve() {
    int t, l, r;
    cin >> t >> l >> r;
    Mint ans = 0;
    Mint t_pow = 1;
    for (int i = l; i <= r; i++) {
        ans += t_pow * f[i];
        t_pow *= t;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve(N);
    pre_calc();
    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}