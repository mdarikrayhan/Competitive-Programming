// LUOGU_RID: 160430878
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const int mod = 998244353;

int n, w, b, tw, tb, t;

ll fac[N], ifac[N], ans;

inline ll qpow(ll a, ll b) {
	a %= mod;
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

inline ll inv(ll a) {
	return qpow(a, mod - 2);
}

inline void get_fac() {
	fac[0] = 1;
	for (int i = 1; i <= (n << 1); ++i) {
		fac[i] = fac[i - 1] * i % mod;
	}
	ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= (n << 1); ++i) {
		ifac[i] = (mod - mod / i) * ifac[mod % i] % mod;
	}
	for (int i = 1; i <= (n << 1); ++i) {
		ifac[i] = ifac[i] * ifac[i - 1] % mod;
	}
}

inline ll C(ll n, ll m) {
	if (n < m || m < 0) {
		return 0;
	}
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

string s[N];

inline int check() {
	int res = 2;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == "B?" || s[i] == "?W" || s[i] == "BW") {
			--res;
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (s[i] == "?B" || s[i] == "W?" || s[i] == "WB") {
			--res;
			break;
		}
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	get_fac();
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		if (s[i] == "WW") {
			++w;
		} else if (s[i] == "BB") {
			++b;
		} else if (s[i] == "?W" || s[i] == "W?") {
			++tw;
		} else if (s[i] == "?B" || s[i] == "B?") {
			++tb;
		} else if (s[i] == "??") {
			++t;
		}
	}
	ans = C(tw + tb + (t << 1), b - w + tb + t);
	if (!w && !b) {
		ans = (ans - qpow(2, t) + check() + mod) % mod;
	}
	cout << ans << "\n";
	return 0;
}