// LUOGU_RID: 160117992
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5, lN = 3e5, Mod = 998244353;
int n, a[N], fac[N], inv[N], f[N], mx, cnt[N], fn[N];
inline int quick_pow(int a, int p) {
	int res = 1;
	for(; p; res = res * (p & 1 ? a : 1) % Mod, p >>= 1, a = a * a % Mod);
	return res;
}
inline int c(int x, int y) {
	if(x < 0 || y < 0 || x < y) return 0;
	return fac[x] * inv[y] % Mod * inv[x - y] % Mod;
}
inline void Init() {
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= lN; ++ i) fac[i] = fac[i - 1] * i % Mod;
	inv[lN] = quick_pow(fac[lN], Mod - 2);
	for(int i = lN - 1; ~i; -- i) inv[i] = inv[i + 1] * (i + 1) % Mod;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); cin >> n, Init();
	for(int i = 1; i <= n; ++ i) cin >> a[i], mx = max(a[i], mx), cnt[a[i]] ++; n = mx;
	for(int i = 1; i <= n; ++ i) for(int j = i; j <= n; j += i) fn[i] += cnt[j];
	for(int k = 1; k <= 7; ++ k) {
		for(int i = n; i >= 1; -- i) {
			f[i] = c(fn[i], k);
			for(int j = i * 2; j <= n; j += i) f[i] = (f[i] + Mod - f[j]) % Mod;
			if(f[1]) {cout << k; exit(0);}
		}
	}
	cout << -1;
	return 0;
}