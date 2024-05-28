// LUOGU_RID: 160063889
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")

#include <bits/stdc++.h>
using namespace std;

namespace IO {
	static constexpr int S = (1 << 21);
	char b[S], *m = b, *n = b, g[S], *p = g;
	void f() { fwrite(g, 1, p - g, stdout), p = g; }
	struct R {
		bool w(char c) { return 47 < c && c < 58; }
		bool y(char c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t'; }
		char i() { if (m == n) n = (m = b) + fread(b, 1, S, stdin); return m == n ? ' ' : *m++; }
		template <class T> R &operator>>(T &x) { char c = i(); T f = 1; for (x = 0; !w(c);) { if(c == '-') f = -1; c = i(); } while (w(c)) x *= 10, x += c ^ 48, c = i(); x *= f; return *this; }
		R &operator>>(char *s) { int l = 0; char c; operator>>(c); for (; !y(c); s[l++] = c, c = i()) ; s[l] = '\0'; return *this; }
		R &operator>>(char &c) { do c = i(); while (y(c)); return *this; }
	} cin;
	struct W {
		void o(char c) { *p++ = c; if (p - g == S) f(); }
		template <class T> W &operator<<(T x) { if (!x) { o(48); return *this; } if(x < 0) o('-'), x = -x; int s[64], t = 0; while (x) s[++t] = x % 10, x /= 10; while (t) o(s[t--] + 48); return *this; }
		W &operator<<(char c) { o(c); return *this; }
		~W() { f(); }
	} cout;
} ;

#define cin IO::cin
#define cout IO::cout

#define _f(i, a, b) for (int i = a; i <= b; ++i)
#define _d(i, a, b) for (int i = a; i >= b; --i)
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second

static constexpr int N = 1e6 + 5;

int n, tr[N], a[N], pos[N];

int lowbit(int x) { return x & (-x); }

void add(int x, int k) {
	while(x <= n) tr[x] = max(tr[x], k), x += lowbit(x);
}

int query(int x) {
	int ret = 0;
	while(x) ret = max(ret, tr[x]), x -= lowbit(x);
	return ret;
}

void solve() {
	cin >> n;
	_f(i, 1, n) cin >> a[i], pos[a[i]] = i;
	_f(i, 1, n) cin >> a[i], a[i] = pos[a[i]];
	reverse(a + 1, a + n + 1);
	_f(i, 1, n) add(a[i], query(a[i]) + 1);
	cout << *max_element(tr + 1, tr + n + 1);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	solve();
	return 0;
}

// by zzzcr.
// rrrmmmjjj!!!