// LUOGU_RID: 158487146
// Problem: C. Card Guessing
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/problemset/problem/1765/C
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 2020;
const ll mod = 998244353;

inline ll qpow(ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			res = res * b % mod;
		}
		b = b * b % mod;
		p >>= 1;
	}
	return res;
}

ll n, m, fac[maxn], ifac[maxn], f[5][maxn][2];

inline ll C(ll n, ll m) {
	if (n < m || n < 0 || m < 0) {
		return 0;
	} else {
		return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
	}
}

void solve() {
	scanf("%lld%lld", &n, &m);
	fac[0] = 1;
	for (int i = 1; i <= n * 4; ++i) {
		fac[i] = fac[i - 1] * i % mod;
	}
	ifac[n * 4] = qpow(fac[n * 4], mod - 2);
	for (int i = n * 4 - 1; ~i; --i) {
		ifac[i] = ifac[i + 1] * (i + 1) % mod;
	}
	m = min(m, n * 4 - 1);
	ll ans = 0;
	for (int i = 0; i * 4 <= m; ++i) {
		mems(f, 0);
		f[0][0][0] = 1;
		for (int j = 1; j <= 4; ++j) {
			for (int k = 0; k <= n * 4; ++k) {
				for (int l = i; l <= k && l <= n; ++l) {
					for (int o = 0; o <= 1; ++o) {
						int no = o | (l == i);
						f[j][k][no] = (f[j][k][no] + f[j - 1][k - l][o] * ifac[l] % mod * ifac[n - l]) % mod;
					}
				}
			}
		}
		for (ll j = 1; j <= n * 4; ++j) {
			ll c = min(j - 1, m);
			ans = (ans + fac[c] * fac[n * 4 - c] % mod * C(n * 4 - c - 1, n - i - 1) % mod * qpow(C(n * 4 - c, n - i), mod - 2) % mod * f[4][c][1]) % mod;
		}
	}
	ans = ans * ifac[n * 4] % mod * fac[n] % mod * fac[n] % mod * fac[n] % mod * fac[n] % mod;
	printf("%lld\n", ans);
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
