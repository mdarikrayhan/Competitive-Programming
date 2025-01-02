#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

const int N = 1e6 + 10, mod = 998244353;

int F[N], G[N], H[N], A[N], B[N], m, lim, rev[N];

int qpow(int x, int y) {
	if (!y) {
		return 1;
	}
	int ss = qpow(x, y >> 1);
	if (y & 1) {
		return 1ll * ss * ss % mod * x % mod;
	} else {
		return 1ll * ss * ss % mod;
	}
}

inline void init(int n) {
	m = 0; lim = 1; while (lim <= n) lim <<= 1, ++m;
	for (int i = 0; i < lim; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (m - 1));
}

inline void NTT(int* f, int len, int on) {
	for (int i = 0; i < len; i++) {
		if (i < rev[i]) {
			swap(f[i], f[rev[i]]);
		}
	}
	for (int h = 2; h <= len; h <<= 1) {
		int gn = qpow(3, (ll)((mod - 1) / h) * on % (mod - 1));
		for (int j = 0; j < len; j += h)
			for (int k = j, g = 1; k < j + h / 2; ++k, g = (ll)g * gn % mod)
			{
				int u = f[k], t = (ll)g * f[k + h / 2] % mod;
				f[k] = (u + t) % mod; f[k + h / 2] = ((u - t) % mod + mod) % mod;
			}
	}
	if (on == mod - 2) for (int i = 0, inv = qpow(len, mod - 2); i < len; ++i) f[i] = (ll)f[i] * inv % mod;
}

char s[N]; int b12[N], b21[N], ax1[110][110], a1x[110][110], a12[110][N], a21[110][N];
int fac[N], ifac[N], Ax1[N], A1x[N], B1x[N];

inline int C(int n, int m) { return (ll)fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

inline void initF(int n) {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; i; --i) ifac[i] = (ll)ifac[i + 1] * (i + 1) % mod;
}

inline void mul(int* des, int* src, int n, int m) {
	for (int i = 0; i < n; ++i) A[i] = des[i];
	for (int i = 0; i < m; ++i) B[i] = src[i];
	for (int i = n; i < lim; ++i) A[i] = 0;
	for (int i = m; i < lim; ++i) B[i] = 0;
	NTT(A, lim, 1); NTT(B, lim, 1);
	for (int i = 0; i < lim; ++i) A[i] = (ll)A[i] * B[i] % mod;
	NTT(A, lim, mod - 2);
}

inline void cdq(int l, int r) {
	if (l + 1 == r) {
		return !l ? void() : ((F[l] += G[l - 1]) %= mod, F[l] = (ll)F[l] * qpow(l, mod - 2) % mod, void());	 
	}
	int mid = (l + r) >> 1;
	cdq(l, mid);
	init(r - l);
	mul(F + l, H, mid - l, r - l - 1);
	for (int i = mid; i < r; ++i) {
		(F[i] += A[i - l - 1]) %= mod;
	}
	cdq(mid, r);
	return;
}

inline int Q(int x, char c) {
	return !s[x] || s[x] == c;
}

int main() {
	int n, m;
	scanf("%d%d%s", &n, &m, s + 1);
	initF(n);
	b12[2] = b21[2] = b12[3] = b21[3] = 1;
	for (int i = 4; i <= n + 2; i++) {
		b12[i] = 2ll * b12[i - 1] % mod;
		b21[i] = 2ll * b21[i - 1] % mod;
	}
	for (int k = 1; k <= n; k++) {
		for (int l = 1; l <= m && l + k - 1 <= n + 1; l++) {
			int r = l + k - 1;
			if (l == r) {
				a12[l][r] = a21[l][r] = 0; 
			} else {
				if (l + 1 == r) {
					a12[l][r] = Q(l, '<'), a21[l][r] = Q(l, '>');
				} else {
					if (l + 2 == r) {
						a12[l][r] = Q(l, '<') * Q(l + 1, '>');
						a21[l][r] = Q(l, '<') * Q(l + 1, '>');
					} else {
						if (l < m) {
							a12[l][r] = (Q(l, '<') * a21[l + 1][r] + Q(r - 1, '>') * a12[l][r - 1]) % mod;
							a21[l][r] = (Q(l, '<') * a21[l + 1][r] + Q(r - 1, '>') * a12[l][r - 1]) % mod;
						} else {
							a12[l][r] = (Q(l, '<') * b21[r - l] + Q(r - 1, '>') * a12[l][r - 1]) % mod;
							a21[l][r] = (Q(l, '<') * b21[r - l] + Q(r - 1, '>') * a12[l][r - 1]) % mod;
						}
					}
				}
			}
		}  
	}
	for (int k = 1; k <= m; k++) {
		int r = k;
		if (1 == r) {
			ax1[1][r] = 1;
			continue;
		}
		for (int i = 1; i < r; i++) {
			(ax1[1][r] += (ll)ax1[1][i] * a21[i][r] % mod * C(r - 2, i - 1) % mod) %= mod;
		}
	} 
	F[0] = 1;
	for (int k = 0; k < n; k++) {
		H[k] = (ll)ifac[k] * b21[k + 2] % mod;
	}
	for (int k = 1; k <= n; k++) {
		int add = 0;
		for (int i = 0; i < std::min(k, m); i++)
			(add += (ll)ifac[k - i - 1] * (a21[i + 1][k + 1] - b21[k + 1 - i]) % mod
			* ax1[1][i + 1] % mod * ifac[i] % mod) %= mod;
		(add += mod) %= mod; G[k - 1] = add;
	}
	int k = 1; while (k <= n) k <<= 1; 
	cdq(0, k);
	for (int i = 0; i < n; ++i) Ax1[i + 1] = (ll)fac[i] * F[i] % mod;
	memset(F, 0, sizeof (F)); memset(G, 0, sizeof (G)); memset(H, 0, sizeof (H));
	F[0] = 1;
	for (int k = 0; k <= n; ++k) H[k] = (ll)ifac[k] * b12[k + 2] % mod;
	cdq(0, k); 
	for (int i = 0; i < n; ++i) B1x[i + 1] = (ll)fac[i] * F[i] % mod;
	for (int i = m + 1; i <= n; ++i) A1x[i] = B1x[n - i + 1];
	for (int k = n - m + 1; k <= n; ++k)
	{
		int l = n - k + 1;
		for (int i = l + 1; i <= n; ++i)
			(A1x[l] += (ll)a12[l][i] * A1x[i] % mod * C(n - l - 1, i - l - 1) % mod) %= mod;
	} 
	int ans = 0;
	for (int i = 1; i <= n; ++i) (ans += (ll)Ax1[i] * A1x[i] % mod * C(n - 1, i - 1) % mod) %= mod;
	printf("%d\n", ans); return 0;
}