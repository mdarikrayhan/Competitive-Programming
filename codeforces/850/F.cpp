// Hydro submission #664a15fbe9f28a76335dbc99@1716731369598
#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, cnt[MAXN], m;
int f[MAXN], ans;

int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> m;
	int mx = 0;
	for (int i = 1; i <= m; i++) cin >> cnt[i], n += cnt[i], mx = max(mx, cnt[i]);
	f[1] = (n - 1) * (n - 1) % MOD * power(n, MOD - 2) % MOD;
	for (int i = 2; i <= mx; i++) {
		f[i] = (2 * f[i - 1] % MOD - f[i - 2] - (n - 1) * power(n - i + 1, MOD - 2) % MOD) % MOD;
		f[i] = (f[i] + MOD) % MOD;
	}
	for (int i = 1; i <= m; i++) ans = (ans + f[cnt[i]]) % MOD;
	cout << ans << '\n';
	
	return 0;
}