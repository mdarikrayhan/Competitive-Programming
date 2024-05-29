#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n, Fn = 1, d[2000006], ans;
inline int PLUS(int x, int y) {
	x += y;
	return x >= MOD ? x - MOD : x;
}
int main() {
	cin >> n, d[1] = n;
	for (int i=2; i<=n; i++)
		d[i] = 1ll * Fn * (1ll * (n - i + 1) * (n - i + 1) % MOD + 1) % MOD, Fn = 1ll * Fn * (n - i + 2) % MOD;
	d[0] = ans = 1ll * n * Fn % MOD, ans = (1ll * ans * (ans + 1) >> 1) % MOD;
	for (int i=n+1; i<n<<1; i++)
		d[i] = PLUS(Fn, MOD - d[i-n]);
	for (int i=1; i<n<<1; i++)
		d[i] = PLUS(d[i-1], MOD - d[i]), ans = PLUS(ans, MOD - d[i]);
	return cout << ans << endl, 0;
}