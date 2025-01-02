// LUOGU_RID: 160262489
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

int n, q, a[200005];
struct three {int a, b;} t[200005];
struct four {int a, b, c;} f[200005];
struct SegmentTree {
#define ls(x) (x * 2)
#define rs(x) (x * 2 + 1)

	int mx[800005], lzy[800005];
	int l[800005], r[800005];

	void build(int ll, int rr, int now = 1) {
		l[now] = ll, r[now] = rr;
		mx[now] = lzy[now] = 0;
		if (ll == rr) return ;
		int mid = (ll + rr) / 2;
		build(ll, mid, ls(now)), build(mid + 1, rr, rs(now));
		return ;
	}
	void down(int now) {
		mx[ls(now)] += lzy[now], mx[rs(now)] += lzy[now];
		lzy[ls(now)] += lzy[now], lzy[rs(now)] += lzy[now];
		lzy[now] = 0;
		return ;
	}
	void update(int ll, int rr, int val, int now = 1) {
		if (ll <= l[now] && r[now] <= rr) {mx[now] += val; lzy[now] += val; return ;}
		if (lzy[now]) down(now);
		int mid = (l[now] + r[now]) / 2;
		if (ll <= mid) update(ll, rr, val, ls(now));
		if (mid < rr) update(ll, rr, val, rs(now));
		mx[now] = max(mx[ls(now)], mx[rs(now)]);
		return ;
	}
	int query(int ll, int rr, int now = 1){
		if (ll <= l[now] && r[now] <= rr) return mx[now];
		if (lzy[now]) down(now);
		int mid = (l[now] + r[now]) / 2, res = 0;
		if (ll <= mid) res = max(res, query(ll, rr, ls(now)));
		if (mid < rr) res = max(res, query(ll, rr, rs(now)));
		return res;
	}
	int binarySearch(int ll, int rr, int val, int now = 1) {
		if (l[now] == r[now]) return mx[now] == val ? l[now] : 0;
		if (lzy[now]) down(now);
		if (ll <= l[now] && r[now] <= rr)
			return mx[rs(now)] == val ?
				binarySearch(ll, rr, val, rs(now)) : binarySearch(ll, rr, val, ls(now));
		int mid = (l[now] + r[now]) / 2;
		if (mid < rr) {
			int tmp = binarySearch(ll, rr, val, rs(now));
			if (tmp) return tmp;
		}
		return binarySearch(ll, rr, val, ls(now));
	}

#undef ls
#undef rs
} tr1, tr2;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector<int> mx, mn;
	tr1.build(1, n);
	mx.push_back(0), mn.push_back(0);
	for (int i = 1; i <= n; i++) {
		while (mx.size() > 1 && a[mx.back()] < a[i]) {
			int now = mx.back();
			mx.pop_back();
			if (mx.back() + 1 < now) tr1.update(mx.back() + 1, now - 1, -1);
		}
		while (mn.size() > 1 && a[mn.back()] > a[i]) {
			int now = mn.back();
			mn.pop_back();
			if (mn.back() + 1 < now) tr1.update(mn.back() + 1, now - 1, -1);
		}
		int rimx = *prev(lower_bound(mx.begin(), mx.end(), i, [](const int &x, const int &y) {
			int va = x ? a[x] : 0x3f3f3f3f, vb = y ? a[y] : 0x3f3f3f3f;
			return va > vb;
		}));
		// eputs("?");
		int rimn = *prev(lower_bound(mn.begin(), mn.end(), i, [](const int &x, const int &y) {
			return a[x] < a[y];
		}));
		if (min(rimx, rimn) >= 1) {
			int pos = tr1.binarySearch(1, min(rimx, rimn), 2);
			// eprintf("%d %d\n", i, pos);
			if (pos) {
				f[i].a = pos;
				int x, y;
				x = *lower_bound(mx.begin(), mx.end(), pos);
				y = *lower_bound(mn.begin(), mn.end(), pos);
				f[i].b = min(x, y), f[i].c = max(x, y);
			}
		}
		if (mx.back() + 1 < i) tr1.update(mx.back() + 1, i - 1, 1);
		if (mn.back() + 1 < i) tr1.update(mn.back() + 1, i - 1, 1);
		mx.push_back(i), mn.push_back(i);
	}
	vector<int>().swap(mx), vector<int>().swap(mn);
	mx.push_back(0), mn.push_back(0);
	tr1.build(1, n), tr2.build(1, n);
	for (int i = 1; i <= n; i++) {
		while (mx.size() > 1 && a[mx.back()] < a[i]) {
			int now = mx.back();
			mx.pop_back();
			if (mx.back() + 1 < now) tr1.update(mx.back() + 1, now - 1, -1);
		}
		while (mn.size() > 1 && a[mn.back()] > a[i]) {
			int now = mn.back();
			mn.pop_back();
			if (mn.back() + 1 < now) tr2.update(mn.back() + 1, now - 1, -1);
		}
		int rimx = *prev(lower_bound(mx.begin(), mx.end(), i, [](const int &x, const int &y) {
			int va = x ? a[x] : 0x3f3f3f3f, vb = y ? a[y] : 0x3f3f3f3f;
			return va > vb;
		}));
		int rimn = *prev(lower_bound(mn.begin(), mn.end(), i, [](const int &x, const int &y) {
			return a[x] < a[y];
		}));
		if (rimx >= 1) {
			int pos = tr1.binarySearch(1, rimx, 1);
			if (pos > t[i].a) {
				t[i].a = pos;
				t[i].b = *lower_bound(mx.begin(), mx.end(), pos);
			}
		}
		if (rimn >= 1) {
			int pos = tr2.binarySearch(1, rimn, 1);
			if (pos > t[i].a) {
				t[i].a = pos;
				t[i].b = *lower_bound(mn.begin(), mn.end(), pos);
			}
		}
		if (mx.back() + 1 < i) tr1.update(mx.back() + 1, i - 1, 1);
		if (mn.back() + 1 < i) tr2.update(mn.back() + 1, i - 1, 1);
		mx.push_back(i), mn.push_back(i);
	}
	tr1.build(1, n), tr2.build(1, n);
	for (int i = 1; i <= n; i++) tr1.update(i, i, f[i].a), tr2.update(i, i, t[i].a);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int val = tr1.query(l, r);
		if (val >= l) {
			int pos = tr1.binarySearch(l, r, val);
			printf("4\n%d %d %d %d\n", f[pos].a, f[pos].b, f[pos].c, pos);
			continue;
		}
		val = tr2.query(l, r);
		if (val >= l) {
			int pos = tr2.binarySearch(l, r, val);
			printf("3\n%d %d %d\n", t[pos].a, t[pos].b, pos);
			continue;
		}
		puts("0\n");
	}
	return 0;
}