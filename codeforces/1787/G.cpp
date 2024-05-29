// LUOGU_RID: 160027738
// LUOGU_RID: 160027634
// 長い夜の終わりを信じながら
// Think twice, code once.
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int n, q, m, f[200005], vis[200005];
vector<int> vec[200005];
int fc[200005], le[200005], ri[200005];
long long sum[200005], a[200005];
struct graph {
	int tot, hd[200005];
	int nxt[400005], to[400005], dt[400005], clr[400005];

	void add(int u, int v, int w, int c) {
		nxt[++tot] = hd[u];
		hd[u] = tot;
		to[tot] = v;
		dt[tot] = w;
		clr[tot] = c;
		return ;
	}
} g;
struct SegmentTree {
#define ls(x) (x * 2)
#define rs(x) (x * 2 + 1)

	int mn[800005], lzy[800005];
	long long mx[800005];
	int l[800005], r[800005];

	void build(int ll, int rr, int now = 1) {
		l[now] = ll, r[now] = rr;
		if (ll == rr) {mx[now] = a[ll]; return ;}
		int mid = (ll + rr) / 2;
		build(ll, mid, ls(now)), build(mid + 1, rr, rs(now));
		mx[now] = max(mx[ls(now)], mx[rs(now)]);
		return ;
	}
	void down(int now) {
		mn[ls(now)] += lzy[now], mn[rs(now)] += lzy[now];
		lzy[ls(now)] += lzy[now], lzy[rs(now)] += lzy[now];
		lzy[now] = 0;
		return ;
	}
	void update(int ll, int rr, int val, int now = 1) {
		if (ll <= l[now] && r[now] <= rr) {mn[now] += val; lzy[now] += val; return ;}
		if (lzy[now]) down(now);
		int mid = (l[now] + r[now]) / 2;
		if(ll <= mid) update(ll, rr, val, ls(now));
		if (mid < rr) update(ll, rr, val, rs(now));
		mn[now] = min(mn[ls(now)], mn[rs(now)]);
		mx[now] = 0;
		if (mn[ls(now)] == mn[now]) mx[now] = max(mx[now], mx[ls(now)]);
		if (mn[rs(now)] == mn[now]) mx[now] = max(mx[now], mx[rs(now)]);
		return ;
	}
	long long query() {return mx[1];}

#undef ls
#undef rs
} tr;

void dfs(int now, int fa) {
	for (int i = g.hd[now]; i; i = g.nxt[i])
		if (!vis[g.clr[i]] && !f[g.clr[i]]) {
			a[++m] = sum[g.clr[i]], vis[g.clr[i]] = m;
			if (!le[now]) le[now] = m;
			ri[now] = m;
		} else if (g.to[i] == fa) fc[now] = vis[g.clr[i]];
	for (int i = g.hd[now]; i; i = g.nxt[i])
		if (g.to[i] != fa) dfs(g.to[i], now);
	return ;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int u, v, w, c;
		scanf("%d%d%d%d", &u, &v, &w, &c);
		g.add(u, v, w, c), g.add(v, u, w, c);
		sum[c] += w;
		vec[c].push_back(u), vec[c].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		int flag = 1, cnt = 0;
		for (int j : vec[i]) {
			cnt -= vis[j] == 1;
			vis[j]++;
			if (vis[j] > 2) flag = 0;
			cnt += vis[j] == 1;
		}
		if (!flag || cnt != 2) f[i] = 1;
		for (int j : vec[i]) vis[j]--;
		// eprintf("%d\n", f[i]);
	}
	dfs(1, 0);
	// for (int i = 1; i <= n; i++) eprintf("%d %d %d\n", fc[i], le[i], ri[i]);
	// eputs("");
	tr.build(1, m + 1);
	while (q--) {
		int val, x;
		scanf("%d%d", &val, &x);
		val ^= 1;
		if (!val) val = -1;
		if (le[x]) tr.update(le[x], ri[x], val);
		if (fc[x]) tr.update(fc[x], fc[x], val);
		printf("%lld\n", tr.query());
	}
	return 0;
}