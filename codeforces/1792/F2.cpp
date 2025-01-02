#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

/*
 * MOD must be prime.
 * MOD must be less than 2^30.
*/

template<uint32_t mod>
class montgomery {
    static_assert(mod < uint32_t(1) << 30, "mod < 2^30");
    using mint = montgomery<mod>;

private:
    uint32_t value;

    static constexpr uint32_t inv_neg_mod = []() {
        uint32_t x = mod;
        for (int i = 0; i < 4; ++i) {
            x *= uint32_t(2) - mod * x;
        }
        return -x;
    }();
    static_assert(mod * inv_neg_mod == -1);

    static constexpr uint32_t neg_mod = (-uint64_t(mod)) % mod;

    static uint32_t reduce(const uint64_t &value) {
        return (value + uint64_t(uint32_t(value) * inv_neg_mod) * mod) >> 32;
    }

    inline static const mint ONE = mint(1);

public:
    montgomery() : value(0) {}
    montgomery(const mint &x) : value(x.value) {}

    template<typename T, typename U = std::enable_if_t<std::is_integral<T>::value>>
    montgomery(const T &x) : value(!x ? 0 : reduce(int64_t(x % int32_t(mod) + int32_t(mod)) * neg_mod)) {}

    static constexpr uint32_t get_mod() {
        return mod;
    }

    uint32_t get() const {
        auto real_value = reduce(value);
        return real_value < mod ? real_value : real_value - mod;
    }

    template<typename T>
    mint power(T degree) const {
        degree = (degree % int32_t(mod - 1) + int32_t(mod - 1)) % int32_t(mod - 1);
        mint prod = 1, a = *this;
        for (; degree > 0; degree >>= 1, a *= a)
            if (degree & 1)
                prod *= a;

        return prod;
    }

    mint inv() const {
        return power(-1);
    }

    mint& operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint& operator+=(const mint &x) {
        if (int32_t(value += x.value - (mod << 1)) < 0) {
            value += mod << 1;
        }
        return *this;
    }

    mint& operator-=(const mint &x) {
        if (int32_t(value -= x.value) < 0) {
            value += mod << 1;
        }
        return *this;
    }

    mint& operator*=(const mint &x) {
        value = reduce(uint64_t(value) * x.value);
        return *this;
    }

    mint& operator/=(const mint &x) {
        return *this *= x.inv();
    }

    friend mint operator+(const mint &x, const mint &y) {
        return mint(x) += y;
    }

    friend mint operator-(const mint &x, const mint &y) {
        return mint(x) -= y;
    }

    friend mint operator*(const mint &x, const mint &y) {
        return mint(x) *= y;
    }

    friend mint operator/(const mint &x, const mint &y) {
        return mint(x) /= y;
    }

    mint& operator++() {
        return *this += ONE;
    }

    mint& operator--() {
        return *this -= ONE;
    }

    mint operator++(int) {
        mint prev = *this;
        *this += ONE;
        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        *this -= ONE;
        return prev;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    bool operator==(const mint &x) const {
        return get() == x.get();
    }

    bool operator!=(const mint &x) const {
        return get() != x.get();
    }

    bool operator<(const mint &x) const {
        return get() < x.get();
    }

    template<typename T>
    explicit operator T() {
        return get();
    }

    friend std::istream& operator>>(std::istream &in, mint &x) {
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

    friend std::ostream& operator<<(std::ostream &out, const mint &x) {
        return out << x.get();
    }

    static int32_t primitive_root() {
        if constexpr (mod == 1'000'000'007)
            return 5;
        if constexpr (mod == 998'244'353)
            return 3;
        if constexpr (mod == 786433)
            return 10;

        static int root = -1;
        if (root != -1)
            return root;

        std::vector<int> primes;
        int value = mod - 1;
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
                if ((mint(r).power((mod - 1) / p)).get() == 1) {
                    ok = false;
                    break;
                }

            if (ok)
                return root = r;
        }
    }
};

// constexpr uint32_t MOD = 1'000'000'007;
constexpr uint32_t MOD = 998'244'353;
using mint = montgomery<MOD>;

/*
 * Include static_modular_int or montgomery (a bit faster) to use it.
 * Don't need to care about precomputing primitive root.
 * Use it like vector<mint> with extra methods.
*/

template<typename mint>
class polynom_t : public std::vector<mint> {
public:
    using std::vector<mint>::empty;
    using std::vector<mint>::back;
    using std::vector<mint>::pop_back;
    using std::vector<mint>::size;
    using std::vector<mint>::clear;
    using std::vector<mint>::begin;
    using std::vector<mint>::end;

private:
    static constexpr int EVAL_N = 1 << 5;
    static constexpr int MUL_MIN_CUT = 20;
    static constexpr int MUL_MAX_CUT = 1 << 6;
    static constexpr int DIV_N_CUT = 1 << 7;
    static constexpr int DIV_M_CUT = 1 << 6;
    static constexpr int INV_BRUTE_FORCE_SIZE = 1 << 3;

    static void fft(polynom_t<mint> &a) {
        int n = a.size();
        static polynom_t<mint> b;
        b.resize(n);

        static const mint primitive_root = mint::primitive_root();
        for (int w = (n >> 1); w > 0; w >>= 1, std::swap(a, b)) {
            mint r = mint(primitive_root).power((mint::get_mod() - 1) / n * w);
            mint m = 1;
            for (int i = 0; i < n; i += (w << 1), m *= r)
                for (int j = 0; j < w; j++) {
                    mint u = a[i + j];
                    mint v = a[i + j + w] * m;
                    b[(i >> 1) + j] = u + v;
                    b[(i >> 1) + j + (n >> 1)] = u - v;
                }
        }
    }

    static void inv_fft(polynom_t<mint> &a) {
        if (a.empty())
            return;

        fft(a);
        mint inv_n = mint(a.size()).inv();
        reverse(a.begin() + 1, a.end());
        for (auto &x : a)
            x *= inv_n;
    }

public:
    template<typename V>
    polynom_t(const std::initializer_list<V> &lst) : std::vector<mint>(lst.begin(), lst.end()) {}

    template<typename... Args>
    polynom_t(Args&&... args) : std::vector<mint>(std::forward<Args>(args)...) {}

    polynom_t<mint>& resize(int n) {
        std::vector<mint>::resize(n);
        return *this;
    }

    // Removes extra zeroes.
    void normalize() {
        while (!empty() && back() == mint(0))
            pop_back();
    }

    // Returns -1 if all coefficients are zeroes (not O(1)!).
    int degree() const {
        int deg = int(size()) - 1;
        while (deg >= 0 && (*this)[deg] == mint(0))
            deg--;

        return deg;
    }

    mint eval(const mint &x) const {
        mint power = 1, value = 0;
        for (int i = 0; i < int(size()); i++, power *= x)
            value += (*this)[i] * power;

        return value;
    }

    // Calculates eval at the given points.
    // O(n log^2).
    std::vector<mint> multipoint_evaluation(const std::vector<mint> &points) const {
        const int n = points.size();
        if (n == 0)
            return {};

        const int tree_size = (n + EVAL_N - 1) / EVAL_N;
        std::vector<polynom_t<mint>> tree(tree_size << 1);
        for (int v = 0; v < tree_size; v++) {
            int from = v * EVAL_N, to = std::min(n, from + EVAL_N);
            tree[tree_size + v].resize(to - from + 1);
            tree[tree_size + v][0] = 1;
            for (int i = from; i < to; i++) {
                for (int j = i - from; j >= 0; j--) {
                    tree[tree_size + v][j + 1] += tree[tree_size + v][j];
                    tree[tree_size + v][j] *= -points[i];
                }
            }
        }
        for (int v = tree_size - 1; v > 0; v--)
            tree[v] = tree[v << 1] * tree[v << 1 | 1];

        tree[1] = (*this) % tree[1];
        for (int v = 2; v < 2 * tree_size; v++)
            tree[v] = tree[v >> 1] % tree[v];

        std::vector<mint> eval(n);
        for (int v = 0; v < tree_size; v++)
            for (int i = v * EVAL_N; i < std::min(n, (v + 1) * EVAL_N); i++)
                eval[i] = tree[tree_size + v].eval(points[i]);

        return eval;
    }

    polynom_t<mint> operator-() const {
        return polynom_t(*this) * mint(-1);
    }

    polynom_t<mint>& operator+=(const polynom_t<mint> &another) {
        if (size() < another.size())
            resize(another.size());
        
        for (int i = 0; i < int(another.size()); i++)
            (*this)[i] += another[i];

        return *this;
    }

    polynom_t<mint>& operator-=(const polynom_t<mint> &another) {
        if (size() < another.size())
            resize(another.size());
        
        for (int i = 0; i < int(another.size()); i++)
            (*this)[i] -= another[i];

        return *this;
    }

    polynom_t<mint>& operator*=(const polynom_t<mint> &another) {
        if (empty() || another.empty()) {
            clear();
            return *this;
        }

        if (std::min(size(), another.size()) <= MUL_MIN_CUT
            || std::max(size(), another.size()) <= MUL_MAX_CUT) {
            polynom_t<mint> product(int(size() + another.size()) - 1);
            for (int i = 0; i < int(size()); i++)
                for (int j = 0; j < int(another.size()); j++)
                    product[i + j] += (*this)[i] * another[j];

            product.swap(*this);
            return *this;
        }

        int real_size = int(size() + another.size()) - 1, n = 1;
        while (n < real_size)
            n <<= 1;

        resize(n);
        polynom_t b = another;
        b.resize(n);
        fft(*this), fft(b);
        for (int i = 0; i < n; i++)
            (*this)[i] *= b[i];

        inv_fft(*this);
        resize(real_size);
        return *this;
    }

    // Division with remainder.
    // O(nlog).
    polynom_t<mint>& operator/=(const polynom_t<mint> &another) {
        polynom_t<mint> a(*this), b(another);
        a.normalize(), b.normalize();
        assert(!b.empty());
        int n = int(a.size()), m = int(b.size());
        if (n < m)
            return *this = {};

        if (n <= DIV_N_CUT || m <= DIV_M_CUT) {
            polynom_t<mint> quotient(n - m + 1);
            mint inv_b = mint(1) / b.back();
            for (int i = n - 1; i >= m - 1; i--) {
                int pos = i - m + 1;
                quotient[pos] = a[i] * inv_b;
                for (int j = 0; j < m; j++)
                    a[pos + j] -= b[j] * quotient[pos];
            }
            quotient.normalize();
            return *this = quotient;
        }

        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        polynom_t<mint> quotient = a * b.inv(n - m + 1);
        quotient.resize(n - m + 1);
        std::reverse(quotient.begin(), quotient.end());
        quotient.normalize();
        return *this = quotient;
    }

    // O(nlog)
    polynom_t<mint>& operator%=(const polynom_t<mint> &another) {
        *this -= (*this) / another * another;
        normalize();
        return *this;
    }

    // Returns derivative.
    // O(n).
    polynom_t<mint> derivative() const {
        polynom_t<mint> der(std::max(0, int(size()) - 1));
        for (int i = 0; i < int(der.size()); i++)
            der[i] = mint(i + 1) * (*this)[i + 1];

        return der;
    }

    // Returns integral.
    // O(n).
    polynom_t<mint> integral(const mint &constant = mint(0)) const {
        polynom_t<mint> in(size() + 1);
        in[0] = constant;
        for (int i = 1; i < int(in.size()); i++)
            in[i] = (*this)[i - 1] / mint(i);

        return in;
    }

    // Returns p^{-1} modulo x^{degree}.
    // O(nlog).
    polynom_t<mint> inv(int degree) const {
        assert(!empty() && (*this)[0] != mint(0) && "polynom is not invertable");

        int result_size = 1;
        while (result_size < degree)
            result_size <<= 1;

        polynom_t<mint> inv(result_size);
        inv[0] = (*this)[0].inv();

        int brute_calculation = std::min(degree, INV_BRUTE_FORCE_SIZE);
        mint start_inv = (*this)[0].inv();

        polynom_t<mint> have(brute_calculation);
        for (int i = 0; i < brute_calculation; i++) {
            inv[i] = ((i == 0 ? 1 : 0) - have[i]) * start_inv;
            int steps = std::min<int>(size(), have.size() - i);
            for (int j = 0; j < steps; j++)
                have[i + j] += inv[i] * (*this)[j];
        }

        polynom_t<mint> this_copy;
        this_copy.reserve(result_size);
        polynom_t<mint> inv_copy;
        inv_copy.reserve(result_size);

        for (int power = brute_calculation; power < degree; power <<= 1) {
            this_copy.resize(power << 1);
            std::fill(this_copy.begin() + min<int>(size(), power << 1), this_copy.end(), 0);
            std::copy(begin(), begin() + min<int>(size(), power << 1), this_copy.begin());
            inv_copy.resize(power << 1);
            std::copy(inv.begin(), inv.begin() + power, inv_copy.begin());

            fft(this_copy);
            fft(inv_copy);
            for (int i = 0; i < (power << 1); i++)
                this_copy[i] *= inv_copy[i];

            inv_fft(this_copy);
            std::fill(this_copy.begin(), this_copy.begin() + power, 0);
            fft(this_copy);
            for (int i = 0; i < (power << 1); i++)
                this_copy[i] *= inv_copy[i];

            inv_fft(this_copy);
            for (int i = power; i < (power << 1); i++)
                inv[i] = -this_copy[i];
        }
        return inv.resize(degree);
    }

    // Returns log(p) modulo x^{degree}.
    // O(nlog).
    polynom_t<mint> log(int degree) const {
        assert(!empty() && (*this)[0] == mint(1) && "log is not defined");
        return (derivative().resize(degree) * inv(degree)).resize(degree).integral(mint(0)).resize(degree);
    }

    // Returns exp(p) modulo x^{degree}.
    // O(nlog), but with a huge constant.
    polynom_t<mint> exp(int degree) const {
        assert(!empty() && (*this)[0] == mint(0) && "exp is not defined");
        polynom_t<mint> exp{1};
        for (int power = 1; power < degree; power <<= 1) {
            exp *= (polynom_t<mint>{1} - exp.log(power << 1)
                + polynom_t<mint>(begin(), begin() + std::min<int>(size(), power << 1)));
            exp.resize(std::min(degree, power << 1));
        }
        exp.resize(degree);
        return exp;
    }

    // Returns p^{d} modulo x^{degree}.
    // O(nlog), but with a very huge constant.
    polynom_t<mint> power(int64_t d, int degree) const {
        if (!d || !degree)
            return polynom_t<mint>{1}.resize(degree);

        int pos = 0;
        while (pos < int(size()) && (*this)[pos] == mint(0))
            pos++;

        if (pos == int(size()) || pos >= (degree + d - 1) / d)
            return polynom_t<mint>(degree);

        int coeffs_left = degree - d * pos;
        polynom_t<mint> result = ((polynom_t<mint>(begin() + pos, end()) / (*this)[pos]).log(coeffs_left)
                            * mint(d)).exp(coeffs_left) * (*this)[pos].power(d);
        result.resize(degree);
        for (int i = degree - 1; i - (degree - coeffs_left) >= 0; i--)
            result[i] = result[i - (degree - coeffs_left)];

        std::fill(result.begin(), result.end() - coeffs_left, mint(0));
        return result;
    }

    template<typename V>
    std::enable_if_t<!std::is_same_v<V, polynom_t<mint>>, polynom_t<mint>&> operator*=(const V &value) {
        for (auto &x : *this)
            x *= value;

        return *this;
    }

    template<typename V>
    std::enable_if_t<!std::is_same_v<V, polynom_t<mint>>, polynom_t<mint>&> operator/=(const V &value) {
        for (auto &x : *this)
            x /= value;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream &out, const polynom_t<mint> &p) {
        for (int i = 0; i < int(p.size()); i++) {
            if (i) out << ' ';
            out << p[i];
        }
        return out;
    }

    friend polynom_t<mint> operator+(const polynom_t<mint> &p, const polynom_t<mint> &q) {
        return polynom_t(p) += q;
    }

    friend polynom_t<mint> operator-(const polynom_t<mint> &p, const polynom_t<mint> &q) {
        return polynom_t(p) -= q;
    }

    friend polynom_t<mint> operator*(const polynom_t<mint> &p, const polynom_t<mint> &q) {
        return polynom_t(p) *= q;
    }

    friend polynom_t<mint> operator/(const polynom_t<mint> &p, const polynom_t<mint> &q) {
        return polynom_t(p) /= q;
    }

    friend polynom_t<mint> operator%(const polynom_t<mint> &p, const polynom_t<mint> &q) {
        return polynom_t(p) %= q;
    }

    template<typename V>
    friend std::enable_if_t<!std::is_same_v<V, polynom_t<mint>>, polynom_t<mint>>
        operator*(const V &value, const polynom_t<mint> &p) {
        return polynom_t<mint>(p) *= value;
    }

    template<typename V>
    friend std::enable_if_t<!std::is_same_v<V, polynom_t<mint>>, polynom_t<mint>>
        operator*(const polynom_t<mint> &p, const V &value) {
        return polynom_t<mint>(p) *= value;
    }

    template<typename V>
    friend std::enable_if_t<!std::is_same_v<V, polynom_t<mint>>, polynom_t<mint>>
        operator/(const V &value, const polynom_t<mint> &p) {
        return polynom_t<mint>(p) /= value;
    }

    template<typename V>
    friend std::enable_if_t<!std::is_same_v<V, polynom_t<mint>>, polynom_t<mint>>
        operator/(const polynom_t<mint> &p, const V &value) {
        return polynom_t<mint>(p) /= value;
    }
};

using polynom = polynom_t<mint>;

/*
 * Include static_modular_int to use it.
 * No need to run any init function.
 * If MOD is not prime inv and ifact won't be correct.
*/

namespace combinatorics {
    std::vector<mint> fact_, ifact_, inv_;

    void reserve(int size) {
        fact_.reserve(size + 1);
        ifact_.reserve(size + 1);
        inv_.reserve(size + 1);
    }

    void resize(int size) {
        if (fact_.empty()) {
            fact_ = {mint(1), mint(1)};
            ifact_ = {mint(1), mint(1)};
            inv_ = {mint(0), mint(1)};
        }
        for (int pos = fact_.size(); pos <= size; pos++) {
            fact_.push_back(fact_.back() * mint(pos));
            inv_.push_back(-inv_[MOD % pos] * mint(MOD / pos));
            ifact_.push_back(ifact_.back() * inv_[pos]);
        }
    }

    struct combinatorics_info {
        std::vector<mint> &data;

        combinatorics_info(std::vector<mint> &data) : data(data) {}

        mint operator[](int pos) {
            if (pos >= int(data.size()))
                resize(pos);

            return data[pos];
        }
    } fact(fact_), ifact(ifact_), inv(inv_);

    // From n choose k.
    mint choose(int n, int k) {
        if (n < k || k < 0 || n < 0)
            return mint(0);
 
        return fact[n] * ifact[k] * ifact[n - k];
    }

    // From n choose k.
    // O(min(k, n - k)).
    mint choose_slow(int n, int k) {
        if (n < k || k < 0 || n < 0)
            return mint(0);
        
        k = std::min(k, n - k);
        mint result = 1;
        for (int i = k; i >= 1; i--) {
            result *= (n - i + 1);
            result *= inv[i];
        }
        return result;
    }
}

using combinatorics::fact;
using combinatorics::ifact;
using combinatorics::inv;
using combinatorics::choose;
using combinatorics::choose_slow;

// returns W(e^{sub} * c) mod x^{deg}
polynom lambert_w(int deg, polynom sub, mint c, mint w0) {
    polynom f;
    f.push_back(w0);

    while (len(f) < deg) {
        int s = len(f);
        auto g = f;
        g.resize(2 * s);
        for (int i = 0; i < min(2 * s, len(sub)); i++) {
            g[i] -= sub[i];
        }

        auto exp = g.exp(2 * s);
        auto prod = (f * exp).resize(2 * s);
        auto diff = prod;
        diff[0] -= c;

        f -= diff * (prod + exp).inv(2 * s);
        f.resize(2 * s);
    }
    return f.resize(deg);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    polynom sub(2);
    sub[1] = mint(2).inv();
    sub[0] = -sub[1];

    auto g = lambert_w(n + 1, sub, sub[0], sub[0]);
    g = sub - g;

    cout << g[n] * fact[n] * 2 - 2 << '\n';
}
