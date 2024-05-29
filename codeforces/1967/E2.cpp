#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
using ll = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // yay python!
 
// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second
 
#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
 
// vectors
#define sz(x) int(size(x))
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
 
#define lb lower_bound
#define ub upper_bound
tcT > int lwb(const V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(const V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }
 
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)
 
const int MOD = 998244353;  // 1e9+7;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18;  // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); }  // # of bits set
constexpr int bits(int x) {  // assert(x >= 0); // make C++11 compatible until
	                         // USACO updates ...
	return x == 0 ? 0 : 31 - __builtin_clz(x);
}  // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
 
ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down
 
tcT > bool ckmin(T &a, const T &b) {
	return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)
 
tcTU > T fstTrue(T lo, T hi, U f) {
	++hi;
	assert(lo <= hi);  // assuming f is increasing
	while (lo < hi) {  // find first index such that f is true
		T mid = lo + (hi - lo) / 2;
		f(mid) ? hi = mid : lo = mid + 1;
	}
	return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
	--lo;
	assert(lo <= hi);  // assuming f is decreasing
	while (lo < hi) {  // find first index such that f is true
		T mid = lo + (hi - lo + 1) / 2;
		f(mid) ? lo = mid : hi = mid - 1;
	}
	return lo;
}
tcT > void remDup(vector<T> &v) {  // sort and remove duplicates
	sort(all(v));
	v.erase(unique(all(v)), end(v));
}
tcTU > void safeErase(T &t, const U &u) {
	auto it = t.find(u);
	assert(it != end(t));
	t.erase(it);
}
 
inline namespace IO {
#define SFINAE(x, ...)                                                         \
	template <class, class = void> struct x : std::false_type {};              \
	template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
 
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));
 
template <auto &is> struct Reader {
	template <class T> void Impl(T &t) {
		if constexpr (DefaultI<T>::value) is >> t;
		else if constexpr (Iterable<T>::value) {
			for (auto &x : t) Impl(x);
		} else if constexpr (IsTuple<T>::value) {
			std::apply([this](auto &...args) { (Impl(args), ...); }, t);
		} else static_assert(IsTuple<T>::value, "No matching type for read");
	}
	template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }
};
 
template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
#define def(t, args...)                                                        \
	t args;                                                                    \
	re(args);
 
template <auto &os, bool debug, bool print_nd> struct Writer {
	string comma() const { return debug ? "," : ""; }
	template <class T> constexpr char Space(const T &) const {
		return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n'
		                                                             : ' ';
	}
	template <class T> void Impl(T const &t) const {
		if constexpr (DefaultO<T>::value) os << t;
		else if constexpr (Iterable<T>::value) {
			if (debug) os << '{';
			int i = 0;
			for (auto &&x : t)
				((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
			if (debug) os << '}';
		} else if constexpr (IsTuple<T>::value) {
			if (debug) os << '(';
			std::apply(
			    [this](auto const &...args) {
				    int i = 0;
				    (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)),
				     ...);
			    },
			    t);
			if (debug) os << ')';
		} else static_assert(IsTuple<T>::value, "No matching type for print");
	}
	template <class T> void ImplWrapper(T const &t) const {
		if (debug) os << "\033[0;31m";
		Impl(t);
		if (debug) os << "\033[0m";
	}
	template <class... Ts> void print(Ts const &...ts) const {
		((Impl(ts)), ...);
	}
	template <class F, class... Ts>
	void print_with_sep(const std::string &sep, F const &f,
	                    Ts const &...ts) const {
		ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
	}
	void print_with_sep(const std::string &) const { os << '\n'; }
};
 
template <class... Ts> void pr(Ts const &...ts) {
	Writer<cout, false, true>{}.print(ts...);
}
template <class... Ts> void ps(Ts const &...ts) {
	Writer<cout, false, true>{}.print_with_sep(" ", ts...);
}
}  // namespace IO
 
inline namespace Debug {
template <typename... Args> void err(Args... args) {
	Writer<cerr, true, false>{}.print_with_sep(" | ", args...);
}
template <typename... Args> void errn(Args... args) {
	Writer<cerr, true, true>{}.print_with_sep(" | ", args...);
}
 
void err_prefix(str func, int line, string args) {
	cerr << "\033[0;31m\u001b[1mDEBUG\033[0m"
	     << " | "
	     << "\u001b[34m" << func << "\033[0m"
	     << ":"
	     << "\u001b[34m" << line << "\033[0m"
	     << " - "
	     << "[" << args << "] = ";
}
 
#ifdef LOCAL
#define dbg(args...) err_prefix(__FUNCTION__, __LINE__, #args), err(args)
#define dbgn(args...) err_prefix(__FUNCTION__, __LINE__, #args), errn(args)
#else
#define dbg(...)
#define dbgn(args...)
#endif
 
const auto beg_time = std::chrono::high_resolution_clock::now();
// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
double time_elapsed() {
	return chrono::duration<double>(std::chrono::high_resolution_clock::now() -
	                                beg_time)
	    .count();
}
}  // namespace Debug
 
inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
	cin.tie(0)->sync_with_stdio(0);  // unsync C / C++ I/O streams
	cout << fixed << setprecision(12);
	// cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  // for old USACO
}
}  // namespace FileIO
 
// make sure to intialize ALL GLOBAL VARS between tcs!
 
/**
 * Description: modular arithmetic operations
 * Source:
 * KACTL
 * https://codeforces.com/blog/entry/63903
 * https://codeforces.com/contest/1261/submission/65632855 (tourist)
 * https://codeforces.com/contest/1264/submission/66344993 (ksun)
 * also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp
 * (ecnerwal) Verification: https://open.kattis.com/problems/modulararithmetic
 */
 
template <int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; }  // primitive root for FFT
	int v;
	explicit operator int() const {
		return v;
	}  // explicit -> don't silently convert to int
	mint() : v(0) {}
	mint(ll _v) {
		v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD;
	}
	bool operator==(const mint &o) const { return v == o.v; }
	friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
	friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
	friend istream &operator>>(istream &is, mint &a) {
		ll x;
		is >> x;
		a = mint(x);
		return is;
	}
	friend ostream &operator<<(ostream &os, mint a) {
		os << int(a);
		return os;
	}
 
	mint &operator+=(const mint &o) {
		if ((v += o.v) >= MOD) v -= MOD;
		return *this;
	}
	mint &operator-=(const mint &o) {
		if ((v -= o.v) < 0) v += MOD;
		return *this;
	}
	mint &operator*=(const mint &o) {
		v = int((ll)v * o.v % MOD);
		return *this;
	}
	mint &operator/=(const mint &o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		while (p < 0) p += MOD - 1;
		mint ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1) ans *= a;
		return ans;
	}
	friend mint inv(const mint &a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}
 
	mint operator-() const { return mint(-v); }
	mint &operator++() { return *this += 1; }
	mint &operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint &b) { return a += b; }
	friend mint operator-(mint a, const mint &b) { return a -= b; }
	friend mint operator*(mint a, const mint &b) { return a *= b; }
	friend mint operator/(mint a, const mint &b) { return a /= b; }
};
 
using mi = mint<MOD, 5>;  // 5 is primitive root for both common mods
using vmi = V<mi>;
using pmi = pair<mi, mi>;
using vpmi = V<pmi>;
 
V<vmi> scmb;  // small combinations
void genComb(int SZ) {
	scmb.assign(SZ, vmi(SZ));
	scmb[0][0] = 1;
	FOR(i, 1, SZ)
	F0R(j, i + 1) scmb[i][j] = scmb[i - 1][j] + (j ? scmb[i - 1][j - 1] : 0);
}
 
/**
 * Description: Combinations modulo a prime $MOD$. Assumes $2\le N \le MOD$.
 * Time: O(N)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 * Usage: F.init(10); F.C(6, 4); // 15
 */
 
struct {
	vmi invs, fac, ifac;
	void init(int N) {  // idempotent
		invs.rsz(N), fac.rsz(N), ifac.rsz(N);
		invs[1] = fac[0] = ifac[0] = 1;
		FOR(i, 2, N) invs[i] = mi(-(ll)MOD / i * (int)invs[MOD % i]);
		FOR(i, 1, N) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * invs[i];
	}
	mi C(int a, int b) {
		if (a < b || b < 0) return 0;
		assert(a < sz(fac));
		return fac[a] * ifac[b] * ifac[a - b];
	}
} F;
 
mi solve1(int N, int M, int b0) {
	vmi dp(M + 1);
	dp.at(min(b0, M)) = 1;
	rep(N) {
		vmi ndp(M + 1);
		F0R(i, sz(dp)) {
			if (i == M) ndp.at(i) += M * dp.at(i);
			else {
				if (i) ndp.at(i - 1) += dp.at(i);
				ndp.at(i + 1) += (M - 1) * dp.at(i);
			}
		}
		swap(dp, ndp);
	}
	return accumulate(all(dp), mi(0));
}
 
// never hit M or -1
 
mi solve2(int N, int M, int b0) {
	if (b0 >= M) return pow(mi(M), N);
	auto ways = [&](int x, int y) -> mi {
		assert((y - b0 + x) % 2 == 0);
		assert(0 <= y && y < M);  // y = -1 and y = M are banned
		int moves_up = (y - b0 + x) / 2;
		int moves_down = (b0 - y + x) / 2;
		if (moves_up < 0 || moves_down < 0) return 0;
 
		// dbg("START");
		mi ret = 0;
		{
			// int max_up = M - b0;
			int max_down = b0 + 1;
			auto add = [&](int start, int sgn) {
				if (start < 0) start += M + 1;
				const int inc = M + 1;
				for (int t = start; t >= 0; t -= inc) {
					// dbg(sgn, x, t);
					ret += sgn * F.C(x, t);
				}
				for (int t = start + inc; t <= x; t += inc) {
					// dbg(sgn, x, t);
					ret += sgn * F.C(x, t);
				}
			};
 
			add(moves_down, 1);
			add(moves_down - max_down, -1);
			// dbg(ret);
 
			// mi ans = cmb(x, y);
			// ans -= cmb(x + up, y - up);
			// ans -= cmb(x - down)
 
			// move_up - moves_down < M - b0
			// moves_down - moves_up < b0 + 1
		}
		return ret;
 
		// vmi dp(M);
		// dp.at(b0) = 1;
		// rep(x) {
		// 	vmi ndp(M);
		// 	F0R(i, M) {
		// 		if (i) ndp.at(i - 1) += dp.at(i);
		// 		if (i + 1 < M) ndp.at(i + 1) += dp.at(i);
		// 	}
		// 	swap(dp, ndp);
		// }
		// dbg("HUH", N, M, b0, x, y, ret, dp.at(y));
		// if (ret != dp.at(y)) exit(0);
		// return dp.at(y);
	};
	vmi pow_minus{1}, pow_eq{1};
	rep(N) {
		pow_minus.pb((M - 1) * pow_minus.bk);
		pow_eq.pb(M * pow_eq.bk);
	}
	mi ans = 0;
	for (int x = M - b0; x <= N; x += 2) {
		ans += pow_minus.at((x + M - b0) / 2) * pow_eq.at(N - x) *
		       ways(x - 1, M - 1);
	}
	for (int y = b0 - N; y <= b0 + N; y += 2)
		if (0 <= y && y < M) {
			ans += pow_minus.at((y - b0 + N) / 2) * ways(N, y);
		}
	return ans;
}
 
mi solve3(int N, int M, int b0) {
	if (b0 >= M) return pow(mi(M), N);
	if (M == 1) return 0;
	int min_high = max(cdiv(N - b0, 2), 0LL);
	// mi ans = 0;
	// if (min_high) {
	// 	F0R(up, min_high) {
	// 		mi contrib = pow(mi(M - 1), up);
	// 		mi mul = 0;
	// 		int u = up;
	// 		for (int t = 0; t <= 10 * N; ++t) {
	// 			if (t & 1) {
	// 				u = -1 - u + N - b0;
	// 			} else {
	// 				u = M - u + N - b0;
	// 			}
	// 			// if (t & 1) ans -= F.C(N, u) * contrib;
	// 			// else ans += F.C(N, u) * contrib;
	// 		}
	// 	}
	// }
	vmi cum_plus(N + 1), cum_neg(N + 1);
	auto add = [&](vmi &cum, int l, int r, mi x) {
		ckmax(l, 0);
		ckmin(r, N);
		if (l > r) return;
		cum.at(l) += x;
		if (r < N) cum.at(r + 1) -= x;
	};
	mi contrib_pos_fast = 0;
	auto add_pos = [&](int l, int r) {
		mi inv_sub = pow(mi(1) / (M - 1), M + 1);
		mi prod = 1;
		for (int a = 0; l + a * (M + 1) <= N; ++a) {
			// min_high ... N
			// + a * (M + 1)
			// (M-1) ^ {(-(M+1) * a}
			add(cum_plus, l + a * (M + 1), r + a * (M + 1), prod);
			prod *= inv_sub;
		}
	};
	add_pos(min_high, N);
	auto add_pos_2 = [&](int l, int r) {
		mi inv_sub = pow(mi(M - 1), M + 1);
		mi prod = -inv_sub;
		for (int a = 1; r - a * (M + 1) >= 0; ++a) {
			add(cum_plus, l - a * (M + 1), r - a * (M + 1), prod);
			prod *= inv_sub;
		}
	};
	if (min_high) add_pos_2(0, min_high - 1);
	auto add_neg = [&](int l, int r, int init) {
		const mi inv_sub = pow(mi(1) / (M - 1), M + 1);
		mi prod = -pow(mi(M - 1), init);
		for (int a = 0; - 1 - l + N - b0 - a * (M + 1) >= 0; ++a) {
			add(cum_neg, -1 - r - a * (M + 1) + N - b0,
			    -1 - l - a * (M + 1) + N - b0, prod);
			prod *= inv_sub;
		}
	};
	{
		FOR(i, 1, N + 1) cum_plus.at(i) += cum_plus.at(i - 1);
		mi mul = 1;
		F0R(i, N + 1) {
			cum_plus.at(i) *= mul;
			mul *= M - 1;
		}
		F0R(i, N + 1) contrib_pos_fast += cum_plus.at(i) * F.C(N, i);
	}
	mi contrib_neg_fast = 0;
	add_neg(min_high, N, N - b0 - 1);
	auto add_neg2 = [&](int l, int r, int init) {
		const mi inv_sub = pow(mi(M - 1), M + 1);
		mi prod = pow(mi(M - 1), init);
		for (int a = 0; M - r + N - b0 + a * (M + 1) <= N; ++a) {
			add(cum_neg, M - r + N - b0 + a * (M + 1),
			    M - l + N - b0 + a * (M + 1), prod);
			prod *= inv_sub;
		}
	};
	if (min_high) {
		// dbg("ADDING");
		add_neg2(0, min_high - 1, N + M - b0);
	}
	{
		FOR(i, 1, N + 1) cum_neg.at(i) += cum_neg.at(i - 1);
		const mi inv_minus = 1 / mi(M - 1);
		mi mul = 1;
		F0R(i, N + 1) {
			cum_neg.at(i) *= mul;
			mul *= inv_minus;
		}
		F0R(i, N + 1) contrib_neg_fast += cum_neg.at(i) * F.C(N, i);
	}
	return contrib_pos_fast + contrib_neg_fast;
	// l ... r
	// (M-1)^l ... (M-1)^r
	// -1-r+N-b0, -1-l+N-b0
	// val[i] += (M-1)^{-i} * (M-1)^{l-r-1+N-b0}
	// b0-N+r+1
 
	// mi tmp = 0;
	// FOR(up, min_high, N + 1) {
	// 	// min_high ... N
	// 	mi contrib = pow(mi(M - 1), up);
	// 	int u = up;
	// 	for (int t = 0; t <= 10 * N; ++t) {
	// 		if (t) {
	// 			if (t & 1) {
	// 				u = -1 - u + N - b0;
	// 			} else {
	// 				u = M - u + N - b0;
	// 			}
	// 		}
	// 		if (t & 1) tmp -= contrib * F.C(N, u);
	// 	}
	// }
	// if (tmp != -contrib_neg_fast) {
	// 	dbg("OOPS", N, M, b0, tmp, contrib_neg_fast);
	// 	exit(0);
	// }
	// dbg("HELLO", tmp, -contrib_neg_fast);
	// return ans + tmp + contrib_pos_fast;
}
 
void compare(int N, int M, int b0) {
	// dbg("COMPARE", N, M, b0);
	mi a1 = solve1(N, M, b0);
	mi a2 = solve3(N, M, b0);
	// dbg(a1, a2);
	if (a1 != a2) {
		dbg("FAIL", N, M, b0, a1, a2);
		exit(0);
	}
}
 
void solve(int tc) {
	def(int, N, M, b0);
	ps(solve3(N, M, b0));
	// auto a1 = solve1(N, M, b0);
	// auto a2 = solve2(N, M, b0);
	// assert(a1 == a2);
	// mi ans;
	// if (M <= N / M) ans = solve1(N, M, b0);
	// else ans = solve2(N, M, b0);
	// ps(ans);
	// ps(a1);
}
 
int main() {
	F.init(2000005);
	setIO();
	// FOR(N, 1, 11) FOR(M, 1, 11) F0R(b0, 10) {
	// 	compare(N, M, b0);
	// 	// solve1(N, M, b0);
	// 	// dbg("DONE SOLVE1");
	// 	// solve2(N, M, b0);
	// 	// dbg("DONE SOLVE2");
	// }
	// exit(0);
	int TC;
	re(TC);
	FOR(i, 1, TC + 1) solve(i);
}