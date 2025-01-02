// LUOGU_RID: 158493047
// MagicDark
#include <bits/stdc++.h>
#define debug cerr << "\033[32m[" << __LINE__ << "]\033[0m "
#define SZ(x) ((int) x.size() - 1)
#define all(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof x)
#define F(i, x, y) for (int i = (x); i <= (y); i++)
#define DF(i, x, y) for (int i = (x); i >= (y); i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> T& chkmax(T &x, T y) {return x = max(x, y);}
template <typename T> T& chkmin(T &x, T y) {return x = min(x, y);}
template <typename T> T& read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x *= f;
}
const int N = 1e7 + 10, MOD = 998244353, inv2 = (MOD + 1) >> 1;
inline int& add(int &x, ll y) {return x = (x + y) % MOD;}
inline int power(int x, int y = MOD - 2) {
	int ans = 1;
	for (; y; x = (ll) x * x % MOD, y >>= 1)
		if (y & 1) ans = (ll) ans * x % MOD;
	return ans;
}
int n, k, x, val[N], ival[N], fac[N], ifac[N];
void zhk() {
	read(n), read(k), read(x);
	if (!x) {
		if (n > k) {
			puts("0");
			return;
		}
		int t = power(2, k), c = 1;
		int ans = 1;
		F(i, 1, n) {
			ans = (ll) ans * (t - c + MOD) % MOD;
			c = c * 2 % MOD;
		}
		cout << ans << '\n';
		return;
	}
	int p = min(n + 1, k);
	int ans = 0;
	int w = power(2, k);
	int t1 = (w - 1 + MOD) % MOD, t2 = 1;
	fac[0] = 1;
	int t = 1;
	F(i, 1, p) {
		t = t * 2 % MOD;
		val[i] = (t - 1 + MOD) % MOD;
		fac[i] = (ll) fac[i - 1] * val[i] % MOD;
	}
	ifac[p] = power(fac[p]);
	DF(i, p - 1, 1) ifac[i] = (ll) ifac[i + 1] * val[i + 1] % MOD;
	F(i, 1, p) ival[i] = (ll) ifac[i] * fac[i - 1] % MOD;
	t = 1;
	int a = power(2, n);
	F(r, 1, p) {
		add(ans, (ll) t1 * t2);
		t = t * 2 % MOD;
		t1 = (ll) t1 * (w - t + MOD) % MOD;
		t2 = (ll) t2 * (a - 1) % MOD * ival[r] % MOD;
		a = (ll) a * inv2 % MOD;
	}
	cout << (ll) ans * power(w - 1) % MOD << '\n';
}
signed main() {
	int _ = 1;
	cin >> _;
	while (_--) zhk();
	return 0;
}
/* why?
*/