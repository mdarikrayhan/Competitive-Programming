#include <bits/stdc++.h>
namespace std {
    template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T,U>& p) { return os << p.first << ' ' << p.second; }
    template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { return apply([&](auto&&... args){ ((os << args << ' '), ...); }, t), os; }
    template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (auto& e : v) os << e << ' '; return os; }
    template<typename T, typename U> istream& operator>>(istream& is, pair<T,U>& p) { return is >> p.first >> p.second; }
    template<typename... Args> istream& operator>>(istream& is, tuple<Args...>& t) { return apply([&](auto&&... args){ ((is >> args), ...); }, t), is; }
    template<typename T> istream& operator>>(istream& is, complex<T>& v) { T x; is >> x; v.real(x); is >> x; v.imag(x); return is; }
    template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& e : v) is >> e; return is; }
    template<typename T> bool operator<(const complex<T>& a, const complex<T>& b) { return pair{a.real(), a.imag()} < pair{b.real(), b.imag()}; }
}
using namespace std;
template<typename T> ostream& operator,(ostream& os, const T& x) { return os << x << ' '; }
using num = long long;
using ull = unsigned long long;
using seq = vector<num>;
using bits = vector<char>;
template<typename T> using Table = vector<vector<T>>;
#define dbg(a) cerr << (#a) << " = " << (a) << endl
#define rep(a, b) for (num a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)
constexpr num operator ""_e(unsigned long long x) { num ans = 1; rep(i, static_cast<num>(x)) ans *= 10; return ans; }
mt19937 rng(static_cast<unsigned>(chrono::steady_clock::now().time_since_epoch().count()));

template <num m>
struct modular {
	num a;
#define addIfNegative(a, m) a += (a >> 63) & (m)
	constexpr void normalize () {
		a %= m;
		addIfNegative(a, m);
	}

	constexpr modular (const num& x = 0) : a{x} { normalize(); }
	explicit operator num() { return a; };

	modular& operator += (const modular& other) {
		a -= m;
		a += other.a;
		addIfNegative(a, m);
		return *this;
	}

	modular& operator -= (const modular& other) {
		a -= other.a;
		addIfNegative(a, m);
		return *this;
	}

	modular& operator *= (const modular& other) {
		if constexpr(m <= 1ll << 31)
			return a *= other.a, a %= m, *this;
		else
			return a = __int128(a) * other.a % m, *this;
	}

	modular operator ! () const {
		// [For m = 9_e + 7, 1 <= a <= 7_e]
		// [2800ms] Clean but slow: return a == 1 ?: -(m / a / modular(m % a));
		// [1020ms] Only for primes: return *this ^ (m - 2);
		// [1985ms] Requires extra code: return modular(euclid(a, m).first);
		return *this ^ (m - 2);
	}

	friend modular operator ^ (modular b, num power) {
		if (power < 0)
			return !b ^ -power;
		modular ans{1};
		for (; power; power >>= 1, b *= b)
			if (power & 1)
				ans *= b;
		return ans;
	}

	friend istream& operator >> (istream& stream, modular& mod) {
		stream >> mod.a;
		mod.normalize();
		return stream;
	}

	modular& operator ++ () { return *this += 1; }
	modular& operator -- () { return *this -= 1; }
	modular operator ++ (int) { const modular result (*this); ++*this; return result; }
	modular operator -- (int) { const modular result (*this); --*this; return result; }
	modular operator + () const { return *this; }
	modular operator - () const { return modular(-a); }
	modular& operator /= (const modular& other) { return *this *= !other; }
	modular& operator ^= (const num& power) { return *this = *this ^ power; }
	friend modular operator + (modular self, const modular& other) { return self += other; }
	friend modular operator - (modular self, const modular& other) { return self -= other; }
	friend modular operator * (modular self, const modular& other) { return self *= other; }
	friend modular operator / (modular self, const modular& other) { return self /= other; }
	auto operator<=>(const modular& other) const = default;
	friend ostream& operator << (ostream& os, const modular& mod) { return os << mod.a; }

	// Combinatorics

	static modular factorial(int n) {
		static vector<modular> factorials{1};
		for (static int i = 1; i <= n; i++)
			factorials.push_back(factorials.back() * i);
		return factorials[n];
	}

    static modular ifactorial(int n) {
        static vector<modular> ifactorials{1};
        if (n >= ssize(ifactorials)) {
            int last = bit_ceil((unsigned) n + 1), prev = ssize(ifactorials);
            ifactorials.resize(last--);
            ifactorials[last] = !factorial(last);
            iota(begin(ifactorials) + prev, end(ifactorials) - 1, prev + 1);
            partial_sum(rbegin(ifactorials), rend(ifactorials) - prev, rbegin(ifactorials), multiplies<>());
        }
        return ifactorials[n];
    }

    static modular binom(int n, int k) {
        return k < 0 || k > n ? 0 : factorial(n) * ifactorial(k) * ifactorial(n - k);
    }

	static vector<modular> inverses(const vector<modular>& x) {
		modular denominator = !reduce(all(x), modular(1), multiplies<>());
		vector<modular> pre(size(x)), suf(pre);
		exclusive_scan(all(x), begin(pre), modular(1), multiplies<>());
		exclusive_scan(rbegin(x), rend(x), rbegin(suf), modular(1), multiplies<>());
		transform(all(pre), begin(suf), begin(pre), multiplies<>());
		transform(all(pre), begin(pre), [&] (const modular& z) { return z * denominator; });
		return pre;
	}

	// Polynomial Hashes
	static modular base(int i = 1) {
		static vector<modular> b{1, uniform_int_distribution<num>(7_e, 9_e)(rng)}, ib{1, !b[1]};
        auto& c = i >= 0 ? b : ib;
        i = abs(i);
        if (i >= (1 << 25))
            return c[1] ^ i;
        while (ssize(c) <= i)
            c.push_back(c.back() * c[1]);
        return c[i];
	}
    static vector<modular> phash(const auto& s) {
        vector<modular> ans(size(s) + 1);
        rep(i, ssize(s)) ans[i + 1] = s[i] << i;
        partial_sum(all(ans), begin(ans));
        return ans;
    }
	modular& operator<<= (num i) {
        return *this *= base(i);
    }
	modular& operator>>= (num i) { return *this >>= -i; }
	friend modular operator>> (modular self, num i) { return self >>= i; }
	friend modular operator<< (modular self, num i) { return self <<= i; }
	struct Hash { num operator() (modular r) const { return num(r); } };
#undef addIfNegative
};
using mod = modular<998244353>;
num module = 998244353;
constexpr mod root = 3;
void ntt(vector<mod>& a) {
    num n = ssize(a), L = bit_width(size(a)) - 1;
    static vector<mod> rt(2, 1);
    for (static num k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        vector<mod> z{1, root ^ (module >> s)};
        for (num i = k; i < 2 * k; i++)
            rt[i] = rt[i / 2] * z[i & 1];
    }
    seq rev(n);
    rep(i,n)
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,n)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, k) {
                mod z = rt[j + k] * a[i + j + k], &ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? module : 0);
                ai += (ai + z >= module ? z - module : z);
            }
}

vector<mod> convolve(const vector<mod> &a, const vector<mod> &b) {
    num s = ssize(a) + ssize(b) - 1;
    num n = 2 * bit_floor(static_cast<unsigned long long>(s));
    vector<mod> x(a), y(b), out(n);
    x.resize(n), y.resize(n);
    ntt(x), ntt(y);
    mod inverse = !mod(n);
    rep(i, n)
        out[-i & (n - 1)] = x[i] * y[i] * inverse;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

auto solve() {
    num n, k;
    cin >> n >> k;
    seq a(n), b(k);
    cin >> a >> b;
    map<num,num> ma;
    for (num x : a) ma[x]++;
    map<num,mod> ans;
    for (num x : b) {
        num ones{0}, twos{0};
        for (auto [y, z] : ma) {
            if (y >= x) break;
            (z == 1 ? ones : twos)++;
        }
        vector<mod> d(n + 1), e(n + 1);
        // twos: (1 + 2x + x^2) = (x + 1)^2 -> (x + 1)^(2*twos) -> (2*twos choose i)
        rep(i, n + 1) d[i] = mod::binom(2 * twos, i);
        // ones: (1 + 2x)^ones -> 2^i * (ones choose i)
        rep(i, n + 1) e[i] = (mod(2) ^ i) * mod::binom(ones, i);
        auto f = convolve(d, e);
        rep(i, n + 1) ans[2 * (i + 1 + x)] += f[i];
    }
    num q;
    cin >> q;
    rep(i, q) {
        num x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}

constexpr bool MULTI{false};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if (MULTI) cin >> t;
    while (t--)
        cout, solve(), '\n';
    return 0;
}
