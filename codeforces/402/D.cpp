#include <vector>
#include <map>
#include <cassert>
#include <functional>

struct Sieve {
    const int M;
    std::vector<int> min_p;
    std::vector<int> primes;

    std::vector<int> min_pe;

    explicit Sieve(int n) : M(n), min_p(n+1) {
        primes.reserve(n/5);
        for (int i=2; i<=n; i++) {
            if (!min_p[i]) {
                min_p[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p * i > M) break;
                min_p[p * i] = p;
                if (min_p[i] == p) break;
            }
        }
    }

    void _prepare_min_pe() {
        if (min_pe.size() == M+1) return;
        min_pe.resize(M+1);
        for (int i=2; i<=M; i++) {
            int x = i / min_p[i];
            if ((x) % min_p[i] == 0) {
                min_pe[i] = min_p[i] * min_pe[x];
            } else {
                min_pe[i] = min_p[i];
            }
        }
    }

    // Prime factorization for 1 <= x <= MAXN^2
    // Complexity: O(log x)           (x <= MAXN)
    //             O(MAXN / log MAXN) (MAXN < x <= MAXN^2)
    template <class T> std::map<T, int> factorize(T x) const {
        std::map<T, int> ret;
        assert(x > 0 and
               x <= ((long long)M) * ((long long)M));
        for (const auto &p : primes) {
            if (x <= T(M)) break;
            while (!(x % p)) x /= p, ret[p]++;
        }
        if (x > T(M)) ret[x]++, x = 1;
        while (x > 1) ret[min_p[x]]++, x /= min_p[x];
        return ret;
    }

    // Mobius function Table, (-1)^{# of different prime factors} for square-free x
    // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...] https://oeis.org/A008683
    std::vector<int> GenerateMobiusFunctionTable() {
        std::vector<int> ret(M+1);
        for (int i = 1; i <= M; i++) {
            if (i == 1) {
                ret[i] = 1;
            } else if ((i / min_p[i]) % min_p[i] == 0) {
                ret[i] = 0;
            } else {
                ret[i] = -ret[i / min_p[i]];
            }
        }
        return ret;
    }

    std::vector<int> GenerateEulerPhiFunctionTable() {
        std::vector<int> phi(M+1);
        phi[1] = 1;
        for (int i=2; i<=M; i++) {
            if (min_p[i] == i) {
                phi[i] = i-1;
            } else {
                if ((i / min_p[i]) % min_p[i] == 0) {
                    phi[i] = phi[i / min_p[i]] * min_p[i];
                } else {
                    phi[i] = phi[i / min_p[i]] * (min_p[i] - 1);
                }
            }
        }
        return phi;
    }

    // 根据 f(p^(e-1)), p, p^e 生成积性函数表
    // when i == p^e, f(i) = g(f(p^(e-1)), p, p^e);
    // fixme 这里 T 一般需要显式指定，不太方便
    template<typename T=int>
    std::vector<T> GenerateMultiplicativeFunctionTable(std::function<T(T,int,int)> g) {
        _prepare_min_pe();
        std::vector<T> f(M+1);
        f[1] = 1;
        for (int i=2; i<=M; i++) {
            if (min_pe[i] == i) {
                f[i] = g(f[i / min_p[i]], min_p[i], min_pe[i]);
            } else {
                f[i] = f[min_pe[i]] * f[i / min_pe[i]];
            }
        }
        return f;
    }
};

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <functional>
#include <string.h>
#include <numeric>

using namespace std;

typedef long long ll;
using i64 = int64_t;
using i128 = __int128_t;
using f64 = double;

const int maxn = 200050;

int gcd(int a, int b) {
    return b==0?a:gcd(b, a%b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(20);

    Sieve sie(maxn);
    int n, m;
    cin >> n >> m;
    vector<int> A(n+1), B(m);
    vector<int> G(n+1);
    G[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> A[i];
        G[i] = gcd(G[i-1], A[i]);
    }
    set<int> bad;
    for (int &x : B) {
        cin >> x;
        bad.insert(x);
    }
    int g = 1;
    auto f = [&](int x) {
        auto facs = sie.factorize(x);
        int ans = 0;
        for (auto [p, e] : facs) {
            if (bad.count(p)) {
                ans -= e;
            } else {
                ans += e;
            }
        }
        return ans;
    };
    int ans = 0;
    for (int i=n; i>=1; i--) {
        int gg = G[i] / g;
        int v = f(gg);
        if (v < 0) {
            g *= gg;
        }
        ans += f(A[i] / g);
    }
    cout << ans;
}