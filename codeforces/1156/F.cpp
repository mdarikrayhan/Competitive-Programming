#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <int P>
struct Modint {
    int v;

    constexpr Modint() : v(0) {}
    constexpr Modint(i64 v_) : v(v_ % P) {
        if (v < 0) {
            v += P;
        }
    }
    constexpr explicit operator int() const { return v; }
    constexpr friend ostream& operator<<(ostream &out, Modint n) {
        return out << int(n);
    }
    constexpr friend istream& operator>>(istream &in, Modint &n) {
        i64 v;
        in >> v;
        n = Modint(v);
        return in;
    }

    constexpr friend bool operator==(Modint a, Modint b) {
        return a.v == b.v;
    }
    constexpr friend bool operator!=(Modint a, Modint b) {
        return a.v != b.v;
    }

    constexpr Modint operator-() {
        Modint res;
        res.v = v ? P - v : 0;
        return res;
    }

    constexpr Modint& operator++() {
        v++;
        if (v == P) v = 0;
        return *this;
    }
    constexpr Modint& operator--() {
        if (v == 0) v = P;
        v--;
        return *this;
    }
    constexpr Modint& operator+=(Modint o) {
        v -= P - o.v;
        v = (v < 0) ? v + P : v;
        return *this;
    }
    constexpr Modint& operator-=(Modint o) {
        v -= o.v;
        v = (v < 0) ? v + P : v;
        return *this;
    }
    constexpr Modint& operator*=(Modint o) {
        v = 1LL * v * o.v % P;
        return *this;
    }
    constexpr Modint& operator/=(Modint o) { return *this *= o.inv(); }

    constexpr friend Modint operator++(Modint &a, int) {
        Modint r = a;
        ++a;
        return r;
    }
    constexpr friend Modint operator--(Modint &a, int) {
        Modint r = a;
        --a;
        return r;
    }

    constexpr friend Modint operator+(Modint a, Modint b) {
        return Modint(a) += b;
    }
    constexpr friend Modint operator-(Modint a, Modint b) {
        return Modint(a) -= b;
    }
    constexpr friend Modint operator*(Modint a, Modint b) {
        return Modint(a) *= b;
    }
    constexpr friend Modint operator/(Modint a, Modint b) {
        return Modint(a) /= b;
    }

    constexpr Modint qpow(i64 p) {
        Modint res = 1, x = v;
        while (p > 0) {
            if (p & 1) { res *= x; }
            x *= x;
            p >>= 1;
        }
        return res;
    }
    constexpr Modint inv() {
        return qpow(P - 2);
    }
};

constexpr int P = 998244353;
using Mint = Modint<P>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto solve = [&]() {
        int n;
        cin >> n;

        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }

        vector<Mint> inv(n + 1);
        for (int i = 1; i <= n; i++) {
            inv[i] = i == 1 ? 1 : -P / i * inv[P % i];
        }

        // increasing
        vector<Mint> dp(n + 1);

        // dp[i][j] = (cnt[i] - 1) / (n - j) + \sum i < x cnt[x] * dp[x][j + 1] / (n - j)

        for (int i = n - 1; i >= 0; i--) {
            vector<Mint> suf(n + 1);
            for (int j = n; j >= 0; j--) {
                suf[j] = cnt[j] * dp[j];
                if (j < n) {
                    suf[j] += suf[j + 1];
                }
            }

            vector<Mint> ndp(n + 1);
            for (int j = n; j >= 0; j--) {
                if (cnt[j] > 0) {
                    ndp[j] += cnt[j] - 1;
                }
                if (j < n) {
                    ndp[j] += suf[j + 1];
                }
                ndp[j] *= inv[n - i];
            }

            dp = move(ndp);
        }

        cout << dp[0] << '\n';
    };
    
    solve();
    
    return 0;
}
