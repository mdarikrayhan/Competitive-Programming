// LUOGU_RID: 160056522
// 長い夜の終わりを信じながら
// Think twice, code once.
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int n, m, q;
struct SegmentTree {
#define ls(x) (x * 2)
#define rs(x) (x * 2 + 1)

	int w[800005][2][15], lzy[800005];
	int l[800005], r[800005];

	void build(int ll, int rr, int now = 1) {
		l[now] = ll, r[now] = rr;
		if (ll == rr) {
			for (int i = 1; i <= m; i++) w[now][0][i] = i + 1, w[now][1][i] = i + 1;
			long long val;
			scanf("%lld", &val);
			w[now][(val & 1) ^ 1][m + 1] = 1, w[now][val & 1][m + 1] = m + 1;
			return ;
		}
		int mid = (ll + rr) / 2;
		build(ll, mid, ls(now)), build(mid + 1, rr, rs(now));
		for (int i = 1; i <= m + 1; i++) {
			w[now][0][i] = w[ls(now)][0][w[rs(now)][0][i]];
			w[now][1][i] = w[ls(now)][1][w[rs(now)][1][i]];
		}
		return ;
	}
	void down(int now) {
		swap(w[ls(now)][0], w[ls(now)][1]), swap(w[rs(now)][0], w[rs(now)][1]);
		lzy[ls(now)] ^= 1, lzy[rs(now)] ^= 1;
		lzy[now] = 0;
		return ;
	}
	void update(int ll, int rr, int now = 1) {
		if (ll <= l[now] && r[now] <= rr) {swap(w[now][0], w[now][1]); lzy[now] ^= 1; return ;}
		if (lzy[now]) down(now);
		int mid = (l[now] + r[now]) / 2;
		if (ll <= mid) update(ll, rr, ls(now));
		if (mid < rr) update(ll, rr, rs(now));
		for (int i = 1; i <= m + 1; i++) {
			w[now][0][i] = w[ls(now)][0][w[rs(now)][0][i]];
			w[now][1][i] = w[ls(now)][1][w[rs(now)][1][i]];
		}
		return ;
	}
	int query(int ll, int rr, int val, int now = 1) {
		if (ll <= l[now] && r[now] <= rr) return w[now][0][val];
		if (lzy[now]) down(now);
		int mid = (l[now] + r[now]) / 2;
		if (rr <= mid) return query(ll, rr, val, ls(now));
		else if (mid < ll) return query(ll, rr, val, rs(now));
		else return query(ll, rr, query(ll, rr, val, rs(now)), ls(now));
	}

#undef ls
#undef rs
} tr;

int main() {
	scanf("%d%d%d", &n, &m, &q);
	tr.build(1, n);
	// eprintf("%d\n", tr.query(2, 3, m + 1));
	while (q--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			long long val;
			scanf("%lld", &val);
			if (val % 2) tr.update(l, r);
		} else puts(tr.query(l, r, m + 1) != 1 ? "1" : "2");
	}
	return 0;
}
// 1 1 1 1 0