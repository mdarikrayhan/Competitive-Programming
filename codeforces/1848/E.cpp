#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <int &MOD>
struct Modint {
    static constexpr int &P = MOD;

private:
    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : m - 1LL * minv(m, a) * m / a;
    }

public:
    Modint() : v(0) {}
    Modint(i64 v_) : v(v_ % P) {
        if (v < 0) v += P;
    }
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream &out, const Modint &n) {
        return out << int(n);
    }
    friend istream& operator>>(istream &in, Modint &n) {
        i64 v;
        in >> v;
        n = Modint(v);
        return in;
    }
    friend string to_string(Modint a) {
        return to_string(int(a));
    }

    friend bool operator==(const Modint &a, const Modint &b) {
        return a.v == b.v;
    }
    friend bool operator!=(const Modint &a, const Modint &b) {
        return a.v != b.v;
    }

    Modint inv() const {
        Modint res;
        res.v = minv(v, P);
        return res;
    }

    Modint operator-() const {
        Modint res;
        res.v = v ? P - v : 0;
        return res;
    }

    Modint& operator++() {
        v++;
        if (v == P) v = 0;
        return *this;
    }
    Modint& operator--() {
        if (v == 0) v = P;
        v--;
        return *this;
    }
    Modint& operator+=(const Modint &o) {
        v -= P - o.v;
        v = (v < 0) ? v + P : v;
        return *this;
    }
    Modint& operator-=(const Modint &o) {
        v -= o.v;
        v = (v < 0) ? v + P : v;
        return *this;
    }
    Modint& operator*=(const Modint &o) {
        v = 1LL * v * o.v % P;
        return *this;
    }
    Modint& operator/=(const Modint &o) { return *this *= o.inv(); }

    friend Modint operator++(Modint &a, int) {
        Modint r = a;
        ++a;
        return r;
    }
    friend Modint operator--(Modint &a, int) {
        Modint r = a;
        --a;
        return r;
    }

    friend Modint operator+(const Modint &a, const Modint &b) {
        return Modint(a) += b;
    }
    friend Modint operator-(const Modint &a, const Modint &b) {
        return Modint(a) -= b;
    }
    friend Modint operator*(const Modint &a, const Modint &b) {
        return Modint(a) *= b;
    }
    friend Modint operator/(const Modint &a, const Modint &b) {
        return Modint(a) /= b;
    }
    
    Modint qpow(i64 p) {
        Modint res = 1, x = v;
        while (p > 0) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
};

int P;
using Mint = Modint<P>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto solve = [&]() {
        int X, q;
        cin >> X >> q >> P;

        constexpr int V = 1e6;
        vector<int> minp(V + 1), primes;
        for (int i = 2; i <= V; i++) {
            if (!minp[i]) {
                primes.push_back(i);
                minp[i] = i;
            }
            for (int p : primes) {
                if (p > V / i) {
                    break;
                }
                minp[p * i] = p;
                if (i % p == 0) {
                    break;
                }
            }
        }

        vector<Mint> pows(V + 1, 1);
        int zeros = 0;
        Mint ans = 1;

        auto add = [&](int p) {
            assert(p <= V);

            if (pows[p] == 0) {
                zeros--;
            } else {
                assert(int(pows[p]) < P);
                ans /= pows[p];
            }

            pows[p]++;

            if (pows[p] == 0) {
                zeros++;
            } else {
                ans *= pows[p];
            }
        };

        X >>= __builtin_ctz(X);
        for (int i = 2; i * i <= X; i++) {
            while (X % i == 0) {
                add(i);
                X /= i;
            }
        }
        if (X > 1) {
            if (X <= V) {
                add(X);
            } else {
                ans *= 2;
            }
        }

        while (q--) {
            int x;
            cin >> x;

            x >>= __builtin_ctz(x);
            while (x > 1) {
                int p = minp[x];
                add(p);
                x /= p;
            }

            cout << (zeros > 0 ? 0 : ans) << '\n';
        }
    };
    
    solve();
    
    return 0;
}
