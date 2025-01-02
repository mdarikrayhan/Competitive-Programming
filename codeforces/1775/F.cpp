#include <bits/stdc++.h>
using namespace std;

// PBDS {{{
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// }}}
// splay_map (requires PBDS) {{{
template<typename T, typename S>
using splay_map = tree<T, S, less<T>, splay_tree_tag, null_node_update>;
// }}}
// DynaMint (requires splay_map) {{{
struct DynaMint {
	static long long mod;

	static void set_mod(long long mod) { DynaMint::mod = mod; }

	static void with_mod(long long mod, function<void()> f) {
		swap(DynaMint::mod, mod);
		f();
		DynaMint::mod = mod;
	}

	long long v;

	DynaMint(int _v) : v(_v % mod + (_v < 0) * mod) {}
	DynaMint(long long _v) : v(_v % mod + (_v < 0) * mod) {}
	DynaMint(unsigned _v=0) : v(_v % mod) {}
	DynaMint(unsigned long _v) : v(_v % mod) {}
	DynaMint(unsigned long long _v) : v(_v % mod) {}

	explicit operator int() const { return v; }
	explicit operator long long() const { return v; }
	
	bool operator==(const DynaMint &rhs) const { return v == rhs.v; }
	bool operator!=(const DynaMint &rhs) const { return v != rhs.v; }

	DynaMint &operator+=(const DynaMint &rhs) { v += rhs.v; v -= (v >= mod) * mod; return *this; }
	DynaMint &operator-=(const DynaMint &rhs) { v += (rhs.v > v) * mod - rhs.v; return *this; }
	DynaMint &operator*=(const DynaMint &rhs) { v = (__int128) v * rhs.v % mod; return *this; }
	DynaMint &operator/=(const DynaMint &rhs) { return *this *= inv(rhs); }
	
	friend DynaMint operator+(DynaMint lhs, const DynaMint &rhs) { return lhs += rhs; }
	friend DynaMint operator-(DynaMint lhs, const DynaMint &rhs) { return lhs -= rhs; }
	friend DynaMint operator*(DynaMint lhs, const DynaMint &rhs) { return lhs *= rhs; }
	friend DynaMint operator/(DynaMint lhs, const DynaMint &rhs) { return lhs /= rhs; }

	DynaMint operator-() { return DynaMint(-v); }
	
	friend DynaMint pow(DynaMint b, long long e) {
		DynaMint rv = 1;
		for (; e; e >>= 1, b *= b) if (e & 1) rv *= b;
		return rv;
	}

	friend DynaMint inv(DynaMint m) {
		auto Gcd = [](long long a, long long b) -> tuple<long long, long long, long long> {
			long long x = 1, y = 0, z = 0, w = 1;
			while (b) {
				long long q = a / b;
				tie(x, z) = make_pair(z, x - q * z);
				tie(y, w) = make_pair(w, y - q * w);
				tie(a, b) = make_pair(b, a - q * b);
			}
			return {a, x, y};
		};

		auto [g, x, y] = Gcd(m.v, mod);
		if (g != 1) throw runtime_error("inverse does not exist");
		return DynaMint(x);
	}

	friend DynaMint log(DynaMint b, DynaMint p) {
		int n = sqrt(mod) + 1;

		unordered_map<long long, int> small;
		DynaMint P = p;
		for (int e = 0; e <= n; e++, P *= b) {
			small[(long long) P] = e;
		}

		DynaMint B = pow(b, n);
		P = 1;
		for (int e = 1; e <= n; e++) {
			P *= B;
			if (small.find((long long) P) != small.end()) {
				return n * e - small[(long long) P];
			}
		}
		
		throw runtime_error("logarithm does not exist");
	}

	friend istream &operator>>(istream &in, DynaMint &m) {
		long long v; in >> v;
		m.v = v % mod + (v < 0) % mod;
		return in;
	}

	friend ostream &operator<<(ostream &out, const DynaMint &m) {
		out << m.v;
		return out;
	}
};

DynaMint fact(int n) {
	if (n < 0) return 0;
	static splay_map<long long, pair<vector<DynaMint>, long long>> cache;		
	
	auto it = cache.find(DynaMint::mod);
	if (it == cache.end()) {
		it = cache.insert({DynaMint::mod, {{1}, 1}}).first;
	}

	auto &[fact, i] = it->second;
	for (; i <= n; i++) {
		fact.push_back(fact.back() * i);
	}
	return fact[n];
}

DynaMint binom(int n, int k) {
	if (n < 0 or k < 0 or n - k < 0) return 0;
	return fact(n) * inv(fact(k) * fact(n - k));
}

long long DynaMint::mod = 998244353;
// }}}
using mint = DynaMint;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T, U;
	cin >> T >> U;

	vector ans0(631 + 1, (mint) 0);
	int M;
	if (U == 2) {
		cin >> M;
	
		mint::with_mod(M, [&]() {
			vector dp0(631 + 1, vector(631 + 1, (mint) 0));
			dp0[0][631] = 1;
			for (int i = 0; i <= 631; i++) {
				for (int j = 631; j - 1 >= 0; j--) {
					dp0[i][j - 1] += dp0[i][j];
				}
				for (int j = 1; i + j <= 631; j++) {
					dp0[i + j][j] += dp0[i][j];
				}
			}

			vector dp(631 + 1, vector(4 + 1, (mint) 0));
			dp[0][0] = 1;
			for (int i = 0; i <= 631; i++) {
				for (int j = 0; j < 4; j++) {
					for (int k = 0; i + k <= 631; k++) {
						dp[i + k][j + 1] += dp[i][j] * dp0[k][0];
					}
				}
			}
			
			for (int i = 0; i <= 631; i++) {
				ans0[i] = dp[i][4];
			}
		});
	}

	while (T--) {
		int N;
		cin >> N;

		int l = 1, r = N;
		while (l < r) {
			int m = l + (r - l + 1) / 2;
			m <= (N - 1) / m + 1 ? l = m : r = m - 1;
		}

		if (U == 1) {
			int h = l, w = (N - 1) / h + 1;
			cout << h << ' ' << w << '\n';
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cout << (i * w + j < N ? '#' : '.');
				}
				cout << '\n';
			}
		}

		if (U == 2) {
			mint::with_mod(M, [&]() {
				mint ans = 0;
				auto Count = [&](int h, int w) -> void {
					ans += ans0[h * w - N];
				};				
			
				int h0 = l, w0 = (N - 1) / h0 + 1;
				for (int h = l; h <= N; h++) {
					int w = (N - 1) / h + 1;
					if (h + w > h0 + w0) break;
					Count(h, w);
				}
				for (int h = l - 1; h >= 1; h--) {
					int w = (N - 1) / h + 1;
					if (h + w > h0 + w0) break;
					Count(h, w);
				}

				cout << 2 * (h0 + w0) << ' ' << ans << '\n';
			});
		}
	}
}
/*
1. Think big picture!

2. Don't waste time coding before thinking it through!

3. Think fast! Don't be afraid to churn through ideas!

4. Try modelling the problem with as few moving parts as possible!
	- What does the problem look like?
	- What might the solution look like?

5. Try solving an easier version of the problem!
	- What if the problem didn't have this constraint?
	- How would I solve a more general version of the problem?

6. Ask questions!
	- What has similar behavior?
	- I've assumed this, what now?

We can pop out the indents in any convex arrangement to find that
the perimeter of the bounding box is equal to the amount of
insulation needed

Effectively, we just need to find the minimum h + w such that h * w
>= n

For this, we can use binary search
*/
