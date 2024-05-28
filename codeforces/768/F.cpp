// LUOGU_RID: 160481526
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mems(x, v) memset(x, v, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 2e5 + 5, mod = 1e9 + 7;
namespace Math {
	int qpow(int x, int y) {int ans = 1; while (y) {if (y & 1) ans = 1ll * ans * x % mod; x = 1ll * x * x % mod; y >>= 1;} return ans;}
	int inv(int x) {return qpow(x, mod - 2);}
	int fac[N], infac[N];
	void init(int n) {
		fac[0] = infac[0] = 1; for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
		infac[n] = inv(fac[n]); for (int i = n - 1; i >= 0; i--) infac[i] = 1ll * infac[i + 1] * (i + 1) % mod;
	}
	inline ll C(ll n, ll m) {if (n < 0 || m < 0 || n - m < 0) return 0; return 1ll * fac[n] * infac[m] % mod * infac[n - m] % mod;}
	inline ll G(ll n, ll m) {return C(n - 1, m - 1);}
} using namespace Math;
int main() {
	ll f, w, h, ans = 0;
	cin >> f >> w >> h, init(f + w);
	if (!w) return puts("1"), 0; if (!f) return puts(w > h ? "1" : "0");

	for (int i = 1; i <= f + w; i++) ans = (ans + (G(f, i - 1) + 2 * G(f, i) + G(f, i + 1)) * G(w - i * h, i)) % mod;
	cout << 1ll * ans * inv(C(f + w, w)) % mod;
	return 0;
}
