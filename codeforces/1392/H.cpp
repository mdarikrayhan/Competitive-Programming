// LUOGU_RID: 160328690
#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
const int N = 2e6+5;
const int Mod = 998244353;

int n, m;
ll inv[N], fac[N], ifac[N], ans;

inline void Add(ll &a, ll b) { a += b; if (a >= Mod) a -= Mod; }
inline ll qpow(int a, int b) {
	ll base = a, ans = 1;
	while (b) {
		if (b & 1) ans = ans * base % Mod;
		base = base * base % Mod;
		b >>= 1;
	}
	return ans;
}

ll C(ll n, ll m) { return m > n ? 0 : fac[n] * ifac[m] % Mod * ifac[n - m] % Mod; }

int main() {
	scanf("%d%d", &n, &m);

	fac[0] = 1;
	for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % Mod;
	ifac[N - 1] = qpow(fac[N - 1], Mod - 2);
	for (int i = N - 1; i; i--) {
		ifac[i - 1] = ifac[i] * i % Mod;
		inv[i] = ifac[i] * fac[i - 1] % Mod;
	}

	for (int i = 1; i <= n; i++) {
		ll t = C(n, i) * (1 + m * inv[i] % Mod) % Mod;
		Add(ans, i & 1 ? t : Mod - t);
	}

	ans = ans * (n + m + 1) % Mod * inv[m + 1] % Mod;

	printf("%lld", ans);
	return 0;
}