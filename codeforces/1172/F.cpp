// LUOGU_RID: 160486295
#include <bits/stdc++.h>
using namespace std;

#define ls p << 1
#define rs p << 1 | 1
#define PII pair<int, int>
#define _for(i, a, b) for (int i = (a); i <= (b); i++)
#define _pfor(i, a, b) for (int i = (a); i >= (b); i--)
#define int long long
const int N = 1e6 + 5, INF = 2e18;

int n, m, P, a[N];
vector<int> c[N << 2];

struct edge {
	int l, r, sum;
}tree[N * 4];

void push_up(int p) {
	tree[p].sum = tree[ls].sum + tree[rs].sum;
	int L = tree[p].l, R = tree[p].r, mid = (L + R) >> 1;
	int y = -1;
	_for(x, 0, mid - L + 1) {
		if (y >= 0) c[p][x + y] = min(c[p][x + y], max(c[ls][x], c[rs][y] - (tree[ls].sum - P * x)));
		while (y + 1 <= R - mid && c[ls][x + 1] - 1 + tree[ls].sum - P * x >= c[rs][y + 1]) {
			y++;
			c[p][x + y] = min(c[p][x + y], max(c[ls][x], c[rs][y] - (tree[ls].sum - P * x)));
		}
	}
}

void build(int p, int l, int r) {
	tree[p].l = l, tree[p].r = r;
	c[p].resize(r - l + 3); c[p][0] = -2e18;
	_for(i, 1, r - l + 2) c[p][i] = INF;
	if (l == r) {
		tree[p].sum = a[l];
		c[p][1] = (P - a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	push_up(p);
} 

int query(int p, int l, int r, int L, int R, int v) {
	if (l == L && r == R) {
		return v + tree[p].sum - (P * (upper_bound(begin(c[p]), end(c[p]), v) - begin(c[p]) - 1));
	}
	int mid = (L + R) >> 1;
	if (r <= mid) return query(ls, l, r, L, mid, v);
	if (l > mid) return query(rs, l, r, mid + 1, R, v);
	return query(rs, mid + 1, r, mid + 1, R, query(ls, l, mid, L, mid, v));
}

signed main() {
	scanf("%lld%lld%lld", &n, &m, &P);
	_for(i, 1, n) scanf("%lld", &a[i]);
	build(1, 1, n);
	while (m--) {
		int l, r;
		scanf("%lld%lld", &l, &r); 
		printf("%lld\n", query(1, l, r, 1, n, 0));
	} 
}