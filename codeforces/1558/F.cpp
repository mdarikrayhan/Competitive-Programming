// LUOGU_RID: 160009625
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
struct node {int len, sum, ans;};
node operator + (const node &lhs, const node &rhs) {
	return {lhs.len + rhs.len, lhs.sum + rhs.sum, max(lhs.ans + rhs.sum, rhs.ans + lhs.len - lhs.sum)};
}
namespace sgt {
	node val[MAXN << 2]; void pushup(int rt) {val[rt] = val[rt << 1] + val[rt << 1 | 1];}
	void build(int rt, int l, int r) {
		if (l == r) return val[rt] = {1, 0, -0x3f3f3f3f}, void();
		int mid = (l + r) >> 1; build(rt << 1, l, mid); build(rt << 1 | 1, mid + 1, r); pushup(rt);
	}
	void modify(int rt, int l, int r, int x) {
		if (l == r) return val[rt] = {1, 1, x % 2}, void();
		int mid = (l + r) >> 1; x <= mid ? modify(rt << 1, l, mid, x) : modify(rt << 1 | 1, mid + 1, r, x); pushup(rt);
	}
	int query1(int rt, int l, int r) {
		if (val[rt].sum == val[rt].len) return r + 1; if (l == r) return l;
		int mid = (l + r) >> 1, tmp = query1(rt << 1, l, mid); if (tmp <= mid) return tmp;
		else return query1(rt << 1 | 1, mid + 1, r);
	}
	node query2(int rt, int l, int r, int x, int y) {
		if (x <= l && r <= y) return val[rt]; int mid = (l + r) >> 1;
		if (y <= mid) return query2(rt << 1, l, mid, x, y);
		if (x > mid) return query2(rt << 1 | 1, mid + 1, r, x, y);
		return query2(rt << 1, l, mid, x, y) + query2(rt << 1 | 1, mid + 1, r, x, y);
	}
}
int inva[MAXN];
int main() {
	int t; scanf("%d", &t); while (t--) {
		int n; scanf("%d", &n); for (int i = 1; i <= n; i++) {
			int a; scanf("%d", &a); inva[a] = i;
		}
		sgt::build(1, 1, n); int ans = 0;
		for (int i = 1; i < n; i++) sgt::modify(1, 1, n, inva[i]), ans = max(ans, sgt::query2(1, 1, n, sgt::query1(1, 1, n), n).ans);
		printf("%d\n", ans);
	}
}