#include <bits/stdc++.h>

int n;

typedef long long ll;
typedef std::complex <ll> P;

std::vector <P> a;

int dp[205][205];

constexpr const int mod = 1'000'000'007;

char can_mem[205][205];

ll sgn(ll x) {
	return (x > 0) - (x < 0);
}

ll cross(P A, P B) {
	return std::imag(std::conj(A) * B);
}

ll dot(P A, P B) {
	return std::real(std::conj(A) * B);
}

bool on(P A, P B, P C) {
	return !cross(A - C, B - C) && dot(A - C, B - C) <= 0LL;
}

bool intersects(int i1, int j1, int i2, int j2) {
	P A = a[i1], B = a[j1], C = a[i2], D = a[j2];
	ll oa = cross(D - C, A - C);
	ll ob = cross(D - C, B - C);
	ll oc = cross(B - A, C - A);
	ll od = cross(B - A, D - A);
	if (sgn(oa) * sgn(ob) < 0LL && sgn(oc) * sgn(od) < 0LL) return true;
	return on(C, D, A) || on(C, D, B) || on(A, B, C) || on(A, B, D);
}

ll area(const std::vector <P>& b) {
	ll res = 0;
	for (int i = 1; i <= (int) b.size(); i++) {
		res += cross(b[i % b.size()], b[i - 1]);
	}
	return llabs(res);
}

ll sg = 0;

bool can(int i, int j) {
	if (can_mem[i][j]) return can_mem[i][j] - 1;
	can_mem[i][j] = 1;
	// for (int u = 0, v = 1; v < n; u++, v++)
	// 	if (u != i && u != j && v != i && v != j)
	// 		can_mem[i][j] &= !intersects(i, j, u, v);
	// for (int u = 0; u < n; u++)
	// 	if (u != i && u != j)
	// 		can_mem[i][j] &= !on(a[i], a[j], a[u]);
	// std::vector <P> b1, b2;
	// for (int u = 0; u <= i; u++) b1.push_back(a[u]);
	// for (int u = j; u < n; u++) b1.push_back(a[u]);
	// for (int u = i; u <= j; u++) b2.push_back(a[u]);
	// can_mem[i][j] &= area(b1) + area(b2) == area(a);
	// if ((int) b1.size() > 2 && area(b1) == 0) can_mem[i][j] = 0;
	// if ((int) b2.size() > 2 && area(b2) == 0) can_mem[i][j] = 0;
	// can_mem[i][j]++;
	return cross(a[i + 1] - a[i], a[j] - a[i]) == sg;
	return can_mem[i][j] - 1;
}

int f(int l, int r) {
	if (r - l <= 1) return 1;
	if (~dp[l][r]) return dp[l][r];
	dp[l][r] = 0;
	for (int i = l + 1; i < r; i++) {
		// if (!can(l, i) || !can(i, r)) continue;
		if (cross(a[r] - a[l], a[i] - a[l]) <= 0) continue;
		dp[l][r] = (dp[l][r] + (ll) f(l, i) * f(i, r)) % mod;
	}
	return dp[l][r];
}

void it(int L) {
	if (L > n) return;
	for (int i = 1; i <= n - L + 1; i++) {
		for (int j = i + 1; j < L + i - 1; j++) {
			if (cross(a[L + i - 2] - a[i - 1], a[j - 1] - a[i - 1]) <= 0) continue;
			dp[i][i + L - 1] = (dp[i][i + L - 1] + (ll) dp[i][j] * dp[j][i + L - 1]) % mod;
		}
	}
	it(L + 1);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::cin >> n;
	a.resize(n);
	ll signed_area = 0;
	P prev;
	for (auto& x : a) {
		ll u, v; std::cin >> u >> v;
		x = P(u, v);
		static bool first = true;
		if (first) {
			first = false;
			prev = x;
			continue;
		}
		signed_area += cross(prev, x);
		// std::cerr << signed_area << "\n";
		prev = x;
	}
	signed_area += cross(a.back(), a.front());
	// sg = -1 * sgn(signed_area);
	// std::cerr << signed_area << "\n";
	if (signed_area > 0) std::reverse(a.begin(), a.end());
	memset(dp, 0, sizeof(dp));
	memset(can_mem, 0, sizeof(can_mem));
	// std::cout << f(0, n - 1) << "\n";
	for (int i = 0; i < n; i++) dp[i][i + 1] = 1;
	it(3);
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << i << ": ";
	// 	for (int j = 1; j <= n; j++)
	// 		std::cerr << dp[i][j] << " \n"[j == n];
	// }
	std::cout << dp[1][n] << "\n";
}
