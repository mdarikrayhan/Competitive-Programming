#include <bits/stdc++.h>
using namespace std;

// Mint {{{
template<int MOD=998244353>
struct Mint {
	static constexpr int EXP_MOD = MOD - 1;
	
	int v;

	Mint(int _v) : v(_v % MOD + (_v < 0) * MOD) {}
	Mint(long long _v) : v(_v % MOD + (_v < 0) * MOD) {}
	Mint(unsigned _v=0) : v(_v % MOD) {}
	Mint(unsigned long _v) : v(_v % MOD) {}
	Mint(unsigned long long _v) : v(_v % MOD) {}

	explicit operator int() const { return v; }
	
	bool operator==(const Mint &rhs) const { return v == rhs.v; }
	bool operator!=(const Mint &rhs) const { return v != rhs.v; }

	Mint &operator+=(const Mint &rhs) { v += rhs.v; v -= (v >= MOD) * MOD; return *this; }
	Mint &operator-=(const Mint &rhs) { v += (rhs.v > v) * MOD - rhs.v; return *this; }
	Mint &operator*=(const Mint &rhs) { v = (long long) v * rhs.v % MOD; return *this; }
	Mint &operator/=(const Mint &rhs) { return *this *= inv(rhs); }
	
	friend Mint operator+(Mint lhs, const Mint &rhs) { return lhs += rhs; }
	friend Mint operator-(Mint lhs, const Mint &rhs) { return lhs -= rhs; }
	friend Mint operator*(Mint lhs, const Mint &rhs) { return lhs *= rhs; }
	friend Mint operator/(Mint lhs, const Mint &rhs) { return lhs /= rhs; }

	Mint operator-() { return Mint(-v); }
	
	friend Mint pow(Mint b, long long e) {
		Mint rv = 1;
		for (; e; e >>= 1, b *= b) if (e & 1) rv *= b;
		return rv;
	}

	friend Mint pow(Mint b, Mint<EXP_MOD> e) {
		return pow(b, (int) e);
	}

	friend Mint inv(Mint m) {
		auto Gcd = [](int a, int b) -> tuple<int, int, int> {
			int x = 1, y = 0, z = 0, w = 1;
			while (b) {
				int q = a / b;
				tie(x, z) = make_pair(z, x - q * z);
				tie(y, w) = make_pair(w, y - q * w);
				tie(a, b) = make_pair(b, a - q * b);
			}
			return {a, x, y};
		};

		auto [g, x, y] = Gcd(m.v, MOD);
		if (g != 1) throw runtime_error("inverse does not exist");
		return Mint(x);
	}

	friend Mint log(Mint b, Mint p) {
		constexpr int n = sqrt(MOD) + 1;

		unordered_map<int, int> small;
		Mint P = p;
		for (int e = 0; e <= n; e++, P *= b) {
			small[(int) P] = e;
		}

		Mint B = pow(b, n);
		P = 1;
		for (int e = 1; e <= n; e++) {
			P *= B;
			if (small.find((int) P) != small.end()) {
				return n * e - small[(int) P];
			}
		}
		
		throw runtime_error("logarithm does not exist");
	}

	friend istream &operator>>(istream &in, Mint &m) {
		long long v; in >> v;
		m.v = v % MOD + (v < 0) % MOD;
		return in;
	}

	friend ostream &operator<<(ostream &out, const Mint &m) {
		out << m.v;
		return out;
	}
};

template<int MOD=998244353>
Mint<MOD> fact(int n) {
	if (n < 0) return 0;
	static vector<Mint<MOD>> fact(1, 1);
	for (static int i = 1; i <= n; i++) {
		fact.push_back(fact.back() * i);
	}
	return fact[n];
}

template<int MOD=998244353>
Mint<MOD> binom(int n, int k) {
	if (n < 0 or k < 0 or n - k < 0) return 0;
	return fact<MOD>(n) * inv(fact<MOD>(k) * fact<MOD>(n - k));
}
// }}}
using mint = Mint<>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	string A;
	cin >> A;

	string B;
	cin >> B;

	vector<int> counts1(26), counts2(26);
	for (auto Ai : A) counts1[Ai - 'A']++;
	for (auto Bi : B) counts2[Bi - 'A']++;

	vector dp(26 + 1, vector(N + 2, (mint) 0));
	dp[0][0] = 1;
	for (int i = 0; i < 26; i++) {
		int pcount = i - 1 >= 0 ? counts1[i - 1] : 0;
		for (int j = 0; j <= pcount; j++) {
			int l = clamp(counts1[i] - (counts2[i] - j), 0, N + 1);
			int r = clamp(counts1[i] + 1, 0, N + 1);
			if (l >= r) continue;

			mint v = dp[i][j] / fact(j) / fact(pcount - j);
			dp[i + 1][l] += v;
			dp[i + 1][r] -= v;
		}

		for (int j = 0; j <= N; j++) {
			dp[i + 1][j + 1] += dp[i + 1][j];
		}
	}

	mint ans = fact(N) * dp[26][0] / fact(counts1[26 - 1]);
	cout << ans << '\n';
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


*/
