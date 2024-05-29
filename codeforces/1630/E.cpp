// LUOGU_RID: 158165660
#include <bits/stdc++.h>
using namespace std;
#define _rep(i_,a_,b_) for(int i_ = (a_); i_ <= (b_); ++i_)
#define mid ((L+R) >> 1)
#define multiCase() int testCnt = in(); _rep(curCase,1,testCnt)
#ifdef ONLINE_JUDGE
#define debug(...) 0
#else
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#endif
using ll = long long;
using pii = pair<int,int>;

int in(void) { int x; scanf("%d", &x); return x; } ll inl(void) { ll x; scanf("%lld", &x); return x; }
void out(int x) { printf("%d ", x); } void outln(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld ", x); } void outln(ll x) { printf("%lld\n", x); }
template<typename T> void chkmax(T &a, const T &b) { a = max(a, b); } 
template<typename T> void chkmin(T &a, const T &b) { a = min(a, b); } 
const int kN = 1005000, p = 998244353;
int cnt[kN], ans[kN], ans2[kN];
int fac[2005000], iv[2005000], ifac[2005000];
void init(int n) {
	fac[0] = 1; _rep(i,1,n) fac[i] = 1ll * fac[i - 1] * i % p;
	iv[1] = 1; _rep(i,2,n) iv[i] = 1ll * iv[p % i] * (p - p / i) % p;
	ifac[0] = 1; _rep(i,1,n) ifac[i] = 1ll * ifac[i - 1] * iv[i] % p;
}
int C(int n, int m) {
	if(n < 0 || m > n) return 0;
	return 1ll * fac[n] * ifac[m] % p * ifac[n - m] % p;
}
int fpm(int a, int b) {
	int r = 1;
	for(;b;b >>= 1, a = 1ll * a * a % p) if(b & 1) r = 1ll * r * a % p;
	return r;
}
int main() {
	init(2000000);
	multiCase() {
		debug("Case %d\n", curCase);
		int n = in();
		_rep(i,1,n) ++cnt[in()];
		int period = n;
		_rep(i,1,n) period = gcd(period, cnt[i]);
		debug("period = %d\n", period);
		if(period == n) {
			outln(1);
			_rep(i,1,n) cnt[i] = 0;
			continue; 
		}
		// period = n / period;
		auto judge = [&period, &n](int x) {
			return n % x == 0 && period % (n / x) == 0;
		};
		vector<int> V;
		_rep(i,1,n) if(cnt[i]) V.emplace_back(i);
		sort(V.begin(), V.end()), V.erase(unique(V.begin(), V.end()), V.end());
		_rep(d,1,n) if(judge(d)) {
			debug("Test d = %d\n", d);
			int &cur = ans[d], mul_inv = 1, fd = n / d;
			cur = 0;
			for(auto &v : V) mul_inv = 1ll * mul_inv * ifac[cnt[v] / fd] % p; 
			for(auto &v : V) {
				int c = cnt[v] / fd;
				_rep(i,1,c) {
					int f1 = C(c - 1, i - 1);
					int f2 = 1ll * mul_inv * fac[c] % p * fac[n / fd - c] % p;
					int f3 = C(n / fd - c + 1, i);
					ans[d] = (ans[d] + 1ll * f1 * f2 % p * f3 % p * i) % p;
					debug("i = %d, ans[%d] = %d\n", i, d, ans[d]);
					debug("(%d, %d, %d)\n", f1, f2, f3);
				}
				if(c > 1) 
					ans[d] = (ans[d] - 1ll * mul_inv * c % p * (c - 1) % p * fac[d - 2] % p + p) % p;
				debug("ans[%d] = %d\n", d, ans[d]);
			}
			// ans[d] = 1ll * ans[d] * d % p; 
			ans2[d] = 1ll * mul_inv * fac[d] % p;
		}
		_rep(i,1,n) if(judge(i)) 
			debug("Tot cc of %d is %d, way is %d\n", i, ans[i], ans2[i]);
		debug("...\n");
		_rep(d,1,n) if(judge(d))
			for(int kd = d << 1; kd <= n; kd += d) if(judge(kd))
				ans[kd] = (ans[kd] - 1ll * ans[d] * (kd / d) % p + p) % p,
				ans2[kd] = (ans2[kd] - ans2[d] + p) % p;
		int a = 0, b = 0;
		_rep(i,1,n) if(judge(i)) 
			debug("Tot cc of %d is %d, way is %d\n", i, ans[i], ans2[i]),
			a = (a + 1ll * ans[i] * iv[i] % p * (n / i)) % p,
			b = (b + 1ll * ans2[i] * iv[i]) % p;
		outln(1ll * a * fpm(b, p - 2) % p);
		_rep(i,1,n) cnt[i] = 0;
	}	
	return 0;
}
