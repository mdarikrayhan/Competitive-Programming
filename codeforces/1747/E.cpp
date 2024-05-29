/*
    749291
                               .--.  
      /\_/\                   |o_o | 
     ( o.o )                  |:_/ |
     >  ^  <                 //   \ \ 
     /      \               (|     | )
     ｜　　　｜ ／￣￣＼       /'\  __/`\
      UU￣UU￣￣￣￣U       \___)=(___/ 
    wow~ ⊙o⊙
*/

#include <bits/stdc++.h>

using i64 = long long;

#define fi first
#define se second

template<typename T>
inline T min(const T& a, const T& b) { return a <= b ? a : b; }
template<typename T>
inline T min(const T& a, const T& b, const T& c) { return min(a, min(b, c)); }
template<typename T>
inline T max(const T& a, const T& b) { return a >= b ? a : b; }
template<typename T>
inline T max(const T& a, const T& b, const T& c) { return max(a, max(b, c)); }

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % P)} {}
    
    constexpr int norm(int x) const {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
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
    MInt &operator*=(const MInt& rhs) & {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt& rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt& rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(const MInt& rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, const MInt& rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, const MInt& rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, const MInt& rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, const MInt& rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(const MInt& lhs, const MInt& rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(const MInt& lhs, const MInt& rhs) {
        return lhs.val() != rhs.val();
    }
};
constexpr int P = 1e9 + 7;
using Z = MInt<P>;

const int N = 5e6 + 10;
Z fac[N], invfac[N], inv[N];
void init() {
    fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
    inv[0] = inv[1] = 1;

    for (int i = 2; i < N; i ++) {
        fac[i] = fac[i - 1] * i;
        inv[i] = (P - P / i) * inv[P % i];
        invfac[i] = invfac[i - 1] * inv[i];
    }
}

Z C(int n, int m) {
    if (m > n || m < 0) return 0;
    return fac[n] * invfac[n - m] * invfac[m];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);


    init();

    int T; std::cin >> T;
    while (T --) {
        int n, m; std::cin >> n >> m;

        Z inv_v = Z(2).inv();

        int t = min(n, m);

        Z ans = 0, po = power(Z(2), n + m);
        for (int i = 0; i <= t; i ++) {
            po *= inv_v;
            ans += C(n, i) * C(m, i) * po * (i + (n + m - i + 3) * inv_v);
        }
        std::cout << ans << "\n";
    }


    return 0;
}
