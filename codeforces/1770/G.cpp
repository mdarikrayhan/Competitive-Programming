#ifdef DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <complex>
#include <numeric>
#include <assert.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, long long>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
template <typename T>
using uset = unordered_set<T>;
template <typename T1, typename T2>
using umap = unordered_map<T1, T2>;

template<typename T>
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod)
        value %= mod;

    if (value < 0)
        value += mod;

    if (value >= mod)
        value -= mod;

    return value;
}

template<typename T>
struct dynamic_modular_int {
    using mint = dynamic_modular_int<T>;

    int value;

    dynamic_modular_int() : value(0) {}
    dynamic_modular_int(const mint& x) : value(x.value) {}

    template<typename U, typename V = std::enable_if_t<std::is_integral<U>::value>>
    dynamic_modular_int(U value) : value(normalize(value, T::mod)) {}

    template<typename U>
    mint power(U degree) const {
        mint prod = 1;
        mint a = *this;

        for (; degree > 0; degree >>= 1, a *= a)
            if (degree & 1)
                prod *= a;

        return prod;
    }

    mint inv() const {
        return power(T::mod - 2);
    }

    mint& operator=(const mint& x) {
        value = x.value;
        return *this;
    }

    mint& operator+=(const mint& x) {
        value += x.value;
        if (value >= T::mod)
            value -= T::mod;

        return *this;
    }

    mint& operator-=(const mint& x) {
        value -= x.value;
        if (value < 0)
            value += T::mod;

        return *this;
    }

    mint& operator*=(const mint& x) {
        value = (long long)value * x.value % T::mod;
        return *this;
    }

    mint& operator/=(const mint& x) {
        return *this *= x.inv();
    }

    friend mint operator+(const mint& x, const mint& y) {
        return mint(x) += y;
    }

    friend mint operator-(const mint& x, const mint& y) {
        return mint(x) -= y;
    }

    friend mint operator*(const mint& x, const mint& y) {
        return mint(x) *= y;
    }

    friend mint operator/(const mint& x, const mint& y) {
        return mint(x) /= y;
    }

    mint& operator++() {
        ++value;
        if (value == T::mod)
            value = 0;

        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1)
            value = T::mod - 1;

        return *this;
    }

    mint operator++(int) {
        mint prev = *this;
        value++;
        if (value == T::mod)
            value = 0;

        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        value--;
        if (value == -1)
            value = T::mod - 1;

        return prev;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    bool operator==(const mint& x) const {
        return value == x.value;
    }

    bool operator!=(const mint& x) const {
        return value != x.value;
    }

    template<typename U>
    explicit operator U() {
        return value;
    }

    friend std::istream& operator>>(std::istream& in, mint& x) {
        std::string s;
        in >> s;
        x = 0;
        bool neg = s[0] == '-';
        for (const auto c : s)
            if (c != '-')
                x = x * 10 + (c - '0');

        if (neg)
            x *= -1;

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const mint& x) {
        return out << x.value;
    }

    static int primitive_root() {
        if (T::mod == 1'000'000'007)
            return 5;

        if (T::mod == 998'244'353)
            return 3;

        if (T::mod == 786433)
            return 10;

        static int root = -1;
        if (root != -1)
            return root;

        std::vector<int> primes;
        int value = T::mod - 1;
        for (int i = 2; i * i <= value; i++)
            if (value % i == 0) {
                primes.push_back(i);
                while (value % i == 0)
                    value /= i;
            }

        if (value != 1)
            primes.push_back(value);

        for (int r = 2;; r++) {
            bool ok = true;
            for (auto p : primes)
                if ((mint(r).power((T::mod - 1) / p)).value == 1) {
                    ok = false;
                    break;
                }

            if (ok)
                return root = r;
        }
    }
};

struct dynamic_modular_int_mod {
    static int mod;
};

int dynamic_modular_int_mod::mod = 998244353;
const int mod = 998244353;

using mint = dynamic_modular_int<dynamic_modular_int_mod>;

using polynom = vector<mint>;

ostream& operator<<(ostream& out, polynom p) {
    for (auto i : p)
        out << i << ' ';
    return out;
}

const int FFT_SIZE = (1 << 20) + 1;
mint w[21][FFT_SIZE];
int lg[FFT_SIZE], rev[21][FFT_SIZE];

void prepareFFT(int n) {
    int lay = lg[n];
    mint root = mint::primitive_root();
    root = root.power((mod - 1) / n);
    for (int i = 1; i < n; i++) {
        w[lay][i] = w[lay][i - 1] * root;
        rev[lay][i] = rev[lay][i ^ (1 << lg[i])] ^ (1 << (lg[n] - 1 - lg[i]));
    }
}

void fft(polynom& p, bool inv = false) {
    int n = p.size();
    int lay = lg[n];
    for (int i = 0; i < n; i++)
        if (i < rev[lay][i])
            swap(p[i], p[rev[lay][i]]);
    for (int len = 1; len < n; len <<= 1)
        for (int i = 0; i < n; i += len << 1)
            for (int j = 0; j < len; j++) {
                mint x = w[lay][j << (lg[n] - 1 - lg[len])] * p[i + j + len];
                p[i + j + len] = p[i + j] - x;
                p[i + j] += x;
            }
    if (inv) {
        reverse(p.begin() + 1, p.end());
        mint in = mint(n).inv();
        for (int i = 0; i < n; i++)
            p[i] *= in;
    }
}

polynom poly_multiply(polynom a, polynom b) {
    int n = a.size();
    int m = b.size();
    int deg = n + m - 1;
    if (n & (n - 1))
        n = 2 << lg[n];
    if (m & (m - 1))
        m = 2 << lg[m];
    int sz = max(n, m) << 1;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    fft(b);
    for (int i = 0; i < sz; i++)
        a[i] *= b[i];
    fft(a, true);
    a.resize(deg);
    return a;
}

const int N = 5e5 + 1;
int special[N];
mint fact[N], rfact[N];

mint C(int n, int k) {
    return fact[n] * rfact[k] * rfact[n - k];
}

polynom slow(polynom dp, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        if (special[i] > special[i - 1]) {
            for (int j = 0; j < (int)dp.size() - 1; j++)
                dp[j] += dp[j + 1];
        }
        else {
            dp.push_back(0);
            for (int j = (int)dp.size() - 1; j > 0; j--)
                dp[j] += dp[j - 1];
        }
    }
    return dp;
}

polynom divide(polynom dp, int l, int r) {
    if (r - l <= (1 << 6))
        return slow(dp, l, r);
    polynom dpr;
    int points = special[r] - special[l];
    if ((int)dp.size() > points) {
        polynom tmp;
        for (int i = points; i < (int)dp.size(); i++)
            tmp.push_back(dp[i]);
        polynom F(r - l + 1);
        for (int i = 0; i <= r - l; i++)
            F[i] = C(r - l, i);
        dpr = poly_multiply(tmp, F);
        if (!points)
            return dpr;
        dp.resize(points);
    }
    int mid = (l + r) / 2;
    polynom tmp = divide(dp, l, mid);
    tmp = divide(tmp, mid, r);
    if (dpr.size() < tmp.size())
        dpr.resize(tmp.size());
    for (int i = 0; i < (int) tmp.size(); i++)
        dpr[i] += tmp[i];
    return dpr;
}

mint calc(string &s) {
    if (count(s.begin(), s.end(), ')') == 0)
        return 1;
    int n = s.size();
    int bal = 0;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            bal--;
        } else {
            bal++;
            ptr++;
            special[ptr] = max(bal, special[ptr - 1]);
        }
    }
    polynom dp(1);
    dp[0] = 1;
    dp = divide(dp, 0, ptr);
    return dp[0];
}

inline void solve(int test = 0) {
    //mt19937 rnd(test);
    string s;
    cin >> s;
    int n = s.size();
    int split = -1;
    int minBal = 0;
    int bal = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            bal++;
        else
            bal--;
        if (bal <= minBal) {
            minBal = bal;
            split = i;
        }
    }
    string l, r;
    for (int i = 0; i <= split; i++)
        l += s[i];
    for (int i = split + 1; i < n; i++)
        r += s[i];
    reverse(r.begin(), r.end());
    for (char& c : r)
        c = c == '(' ? ')' : '(';
    mint ans = 1;
    ans *= calc(l);
    ans *= calc(r);
    cout << ans << '\n';
}

signed main() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i;
    rfact[N - 1] = fact[N - 1].inv();
    for (int i = N - 2; i > -1; i--)
        rfact[i] = rfact[i + 1] * (i + 1);
    for (int i = 2; i < FFT_SIZE; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int n = 1; n <= (1 << 20); n <<= 1) {
        w[lg[n]][0] = 1;
        prepareFFT(n);
    }
#ifdef DEBUG
    freopen("01.dat", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
#ifdef DEBUG
    cin >> tt;
#endif
    for (int _ = 1; _ <= tt; _++) {
#ifdef DEBUG
        cout << "Testcase#\n";
#endif
        solve(_);
    }
    return 0;
}
