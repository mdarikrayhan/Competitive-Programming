#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, gen = 3;
namespace IO {
	inline char gc() {
		static const int IN_LEN = 1 << 18 | 1;
		static char buf[IN_LEN], *s, *t;
		return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
	}
	template <typename T>
	inline void read(T &x) {
		static char ch, ff;
		ch = gc(), ff = 0;
		for(; !isdigit(ch); ch = gc())
			ff |= ch == '-';
		for(x = 0; isdigit(ch); ch = gc())
			x = (x << 3) + (x << 1) + (ch ^ 48);
		ff && (x = -x);
		return;
	}
	template <typename T, typename ...t>
	void read(T&x, t& ...y) {
		read(x), read(y...);
		return;
	}
	template <typename T>
	inline void print(T x) {
		static int pr, pri[105], temp;
		pr = 0, temp = x;
		if(x < 0)
			fputc('-', stdout), x = -x;
		if(!x) {
			fputc(48, stdout);
			return;
		}
		while(x)
			pri[++pr] = x % 10, x /= 10;
		for(; pr; pr--)
			fputc(pri[pr] + 48, stdout);
		x = temp;
		return;
	}
	template <typename T, typename ...t>
	void print(T&x, t& ...y) {
		print(x), fputc(' ', stdout), print(y...);
		return;
	}
}
using namespace IO;
vector<int> ans;
bool vis[1000005];
int n, m, k, a[1000005], f[2100000], rev[2100000];
int fpow(int x, int y) {
	int s = 1;
	while(y) {
		if(y & 1)
			s = 1ll * s * x % mod;
		x = 1ll * x * x % mod, y >>= 1;
	}
	return s;
}
void ntt(int f[], int fl) {
	for(int i = 0; i < n; i++)
		if(i < rev[i])
			swap(f[i], f[rev[i]]);
	for(int l = 2; l <= n; l <<= 1) {
		int len = l >> 1, w = ~fl ? fpow(gen, (mod - 1) / l) : fpow(fpow(gen, (mod - 1) / l), mod - 2);
		for(int i = 0; i < n; i += l)
			for(int j = i, s = 1, tmp; j < i + len; tmp = 1ll * s * f[j + len] % mod, f[j + len] = (f[j] - tmp + mod) % mod, f[j] = (f[j] + tmp) % mod, s = 1ll * s * w % mod, j++);
	}
	if(!~fl) {
		int tmp = fpow(n, mod - 2);
		for(int i = 0; i < n; i++)
			f[i] = 1ll * f[i] * tmp % mod;
	}
	return;
}
int main() {
	read(k, m);
	for(int i = 1; i <= k; i++)
		read(a[i]), f[a[i]] = vis[a[i]] = 1;
	for(n = 1; n <= 2 * m; n <<= 1);
	for(int i = 0; i < n; i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1 ? n >> 1 : 0);
	ntt(f, 1);
	for(int i = 0; i < n; i++)
		f[i] = 1ll * f[i] * f[i] % mod;
	ntt(f, -1);
	for(int i = 0; i <= m; i++)
		if(vis[i] && !f[i])
			ans.push_back(i);
		else if(!vis[i] && f[i]) {
			puts("NO");
			return 0;
		}
	puts("YES"), print(ans.size()), fputc('\n', stdout);
	for(int i : ans)
		print(i), fputc(' ', stdout);
	return 0;
}