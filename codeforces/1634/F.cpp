#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define debug_arr(...)
#define debug_endl(...)
#endif

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

void solve() {
	int n, q, m;
	std::cin >> n >> q >> m;

	MInt<0>::set(m);

	std::vector<MInt<0>> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<MInt<0>> b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::vector<MInt<0>> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = a[i] - b[i] - (i ? a[i - 1] - b[i - 1] + (i - 1 ? a[i - 2] - b[i - 2] : 0) : 0);
	}

	std::vector<MInt<0>> f(n + 1);
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	int cur = std::ranges::count(d, 0);

	auto add = [&](int i, MInt<0> x) -> void {
		if (i < n) {
			cur -= d[i] == 0;
			d[i] += x;
			cur += d[i] == 0;
		}
	};

	while (q--) {
		char op;
		std::cin >> op;

		int l, r;
		std::cin >> l >> r;
		l--;

		add(l, f[0] * (op == 'A' ? 1 : -1));
		add(r, f[r - l] * (op == 'A' ? -1 : 1));
		add(r + 1, f[r - l - 1] * (op == 'A' ? -1 : 1));

		std::cout << (cur == n ? "YES" : "NO") << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	solve();

	return 0;
}