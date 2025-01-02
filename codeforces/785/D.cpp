#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define debug_arr(...)
#define debug_endl(...)
#endif

using u32 = unsigned int;

template<int P>
struct MInt {
	static int m;
	static constexpr int mod() {
		return P ? P : m;
	}
	static constexpr void set(int m) {
		MInt::m = m;
	}

	int x;

	constexpr MInt(): x(0) {}
	template<class T>
	constexpr MInt(const T &x): x(int(x % mod() + mod()) % mod()) {}

	template<class T>
	explicit constexpr operator T() const {
		return T(x);
	}

	template<class T>
	constexpr MInt pow(T b) const {
		MInt res = 1;
		for (auto a = *this; b; a *= a, b >>= 1) {
			if (b & 1) {
				res *= a;
			}
		}
		return res;
	}

	constexpr MInt inv() const {
		assert(x);
		return pow(mod() - 2);
	}

	constexpr MInt &operator+=(const MInt &b) {
		x += b.x;
		if (x >= mod()) {
			x -= mod();
		}
		return *this;
	}
	constexpr MInt &operator-=(const MInt &b) {
		x -= b.x;
		if (x < 0) {
			x += mod();
		}
		return *this;
	}
	constexpr MInt &operator*=(const MInt &b) {
		x = 1ll * x * b.x % mod();
		return *this;
	}
	constexpr MInt &operator/=(const MInt &b) {
		return *this = *this * b.inv();
	}

	friend constexpr MInt operator+(const MInt &a, const MInt &b) {
		return MInt(a) += b;
	}
	friend constexpr MInt operator-(const MInt &a, const MInt &b) {
		return MInt(a) -= b;
	}
	friend constexpr MInt operator*(const MInt &a, const MInt &b) {
		return MInt(a) *= b;
	}
	friend constexpr MInt operator/(const MInt &a, const MInt &b) {
		return MInt(a) /= b;
	}

	constexpr MInt &operator++() {
		return *this += 1;
	}
	constexpr MInt &operator--() {
		return *this -= 1;
	}

	constexpr MInt operator++(int) {
		auto res = *this;
		++*this;
		return res;
	}
	constexpr MInt operator--(int) {
		auto res = *this;
		--*this;
		return res;
	}

	constexpr MInt operator+() const {
		return *this;
	}
	constexpr MInt operator-() const {
		return 0 - *this;
	}
	
	friend constexpr bool operator==(const MInt &a, const MInt &b) {
		return int(a) == int(b);
	}
	friend constexpr bool operator!=(const MInt &a, const MInt &b) {
		return int(a) != int(b);
	}

	friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
		int v;
		is >> v;
		a = v;
		return is;
	}
	friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
		return os << int(a);
	}
};

template<int P>
int MInt<P>::m = 1;

template<int x, int P>
constexpr MInt<P> cinv = MInt<P>(x).inv();

template<int P>
struct Comb {
	int _n;
	std::vector<MInt<P>> _fac, _ifac;

	Comb(): _n(0), _fac{1}, _ifac{1} {}

	void reserve(int n) {
		if (n <= _n) {
			return;
		}

		n = std::min(int(std::bit_ceil<u32>(n)), MInt<P>::mod() - 1);

		_fac.resize(n + 1);
		for (int i = _n + 1; i <= n; i++) {
			_fac[i] = _fac[i - 1] * i;
		}

		_ifac.resize(n + 1);
		_ifac[n] = _fac[n].inv();
		for (int i = n; i > _n; i--) {
			_ifac[i - 1] = _ifac[i] * i;
		}

		_n = n;
	}

	MInt<P> fac(int n) {
		reserve(n);
		return _fac[n];
	}

	MInt<P> ifac(int n) {
		reserve(n);
		return _ifac[n];
	}

	MInt<P> inv(int n) {
		assert(n);
		return ifac(n) * fac(n - 1);
	}

	MInt<P> binom(int n, int m) {
		if (n < m || m < 0) {
			return 0;
		} else if (n < MInt<P>::mod()) {
			return fac(n) * ifac(m) * ifac(n - m);
		} else {
			return binom(n % MInt<P>::mod(), m % MInt<P>::mod()) * binom(n / MInt<P>::mod(), m / MInt<P>::mod());
		}
	}
};

template<int P>
Comb<P> comb;

constexpr int P = 1e9 + 7;

void solve() {
	std::string s;
	std::cin >> s;

	int n = s.length();

	std::vector<int> pre(n);
	pre[0] = s[0] == '(';
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + (s[i] == '(');
	}

	std::vector<int> suf(n);
	suf[n - 1] = s[n - 1] == ')';
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = suf[i + 1] + (s[i] == ')');
	}

	MInt<P> ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			ans += comb<P>.binom(pre[i] + suf[i] - 1, pre[i]);
		}
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	solve();

	return 0;
}