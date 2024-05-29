#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define MP make_pair
#define ep emplace
#define eb emplace_back
#define int long long
#define rep(i, j, k) for (int i = j; i <= k; i++)
#define per(i, j, k) for (int i = j; i >= k; i--)
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef __int128 lll;
typedef unsigned long long ull;
typedef unsigned int ui;
using namespace std;

int read() {
	int s = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') f ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
	return f ? s : -s;
}
int fpow(int x, int k, int mod) {
	int res = 1;
	for (; k; k >>= 1) {
		if (k & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}
int n, m, t, w, o, lim = 1, tr[10000005], c[10000005], cnt[10000005], fr, ls[10000005], rs[10000005], cur, tot, s[10000005], rt;
struct node { 
	int type, pos, cnt; 
	int val(int mod) {
		if (type == 0) return fpow(2, (cnt + 1) * w, mod);
		else if (pos != -1) return fpow(2, w * cnt, mod);
		return 0;
	}
} tmp[35], a[10000005];
node operator+ (node x, node y) {
	if (x.type > y.type) swap(x, y);
	if (x.type == 0) {
		if (y.type == 0) return node{ 0, -1, x.cnt + y.cnt };
		else if (y.pos != -1) return node{ 1, y.pos, x.cnt + y.cnt };
	} else if (x.pos != -1 && x.pos == y.pos) return node{ 1, x.pos, x.cnt + y.cnt };
	return node{ 1, -1, 0 };
}
node operator* (node x, node y) {
	if (x.type > y.type) swap(x, y);
	if (x.type == 0) {
		if (y.type == 0) return node{ 0, -1, x.cnt + y.cnt + 1 };
		else if (y.pos != -1) return node{ 0, -1, x.cnt + y.cnt };
	} else if (x.pos != -1 && y.pos != -1) return node{ 1, x.pos ^ y.pos, x.cnt + y.cnt };
	return node{ 1, -1, 0 };
}
int newnode(int len) {
	a[++tot] = tmp[__lg(len)];
	return tot;
}
void pushup(int u, int l, int r) {
	if (t >> (o - __lg(r - l + 1)) & 1) a[u] = a[ls[u]] + a[rs[u]];
	else a[u] = a[ls[u]] * a[rs[u]];
}
int update(int l, int r, int pos, int v, int u) {
	if (!u) u = newnode(r - l + 1);
	if (l == r) return a[u] = v != -1 ? node{ 1, v, 0 } : node{ 0, -1, 0 }, u;
	int mid = (l + r) >> 1;
	if (mid >= pos) ls[u] = update(l, mid, pos, v, ls[u]);
	else rs[u] = update(mid + 1, r, pos, v, rs[u]);
	if (!ls[u]) ls[u] = newnode(mid - l + 1);
	if (!rs[u]) rs[u] = newnode(r - mid);
	return pushup(u, l, r), u;
}
void modify(int pos, int v) {
	int pre = c[pos]; c[pos] = v;
	pos %= lim, cur -= cnt[pos] == 0 && s[pos] > 0;
	if (pre != -1) s[pos] ^= pre;
	if (v != -1) {
		s[pos] ^= v;
		if (pre != -1 || !--cnt[pos]) rt = update(0, lim - 1, tr[pos], s[pos], rt);
		else fr--;
	} else {
		if (pre == -1 || !cnt[pos]++) rt = update(0, lim - 1, tr[pos], -1, rt);
		else fr++;
	}
	cur += cnt[pos] == 0 && s[pos] > 0;
}

signed main() {
	int r = n = read(); m = read(), t = read(), w = read();
	while (r % 2 == 0) r /= 2, lim *= 2, o++;
	rep(i, 0, lim - 1) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) << (o - 1));
	rep(i, 0, n - 1) {
		c[i] = -1;
		if (++cnt[i % lim] != 1) fr++;
	}
	tmp[0] = node{ 0, -1, 0 };
	rep(i, 1, o) if (t >> (o - i) & 1) tmp[i] = tmp[i - 1] + tmp[i - 1];
	else tmp[i] = tmp[i - 1] * tmp[i - 1];
	rt = newnode(lim);
	rep(i, 1, m) {
		int pos = read();
		modify(pos - 1, read());
	}
	int q = read();
	rep(i, 1, q) {
		int pos = read(), x = read(), mod = read();
		modify(pos - 1, x);
		int ans = 0;
		if (t < lim) ans = a[rt].val(mod) * fpow((1 << w) % mod, fr, mod) % mod;
		else if (!cur) ans = fpow((1 << w) % mod, fr, mod);
		printf("%lld\n", ans);
	}
	return 0;
}
			 			 					  		 			   			  	