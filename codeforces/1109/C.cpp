#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second

#define N 100555
#define L 1000000009

struct Range {
	int l, r, f, c;
	LL low, su;
	bool has;
	Range() {}
	Range(int v) {
		l = 0, r = 0;
		f = r + 1, c = 0;
		low = su = v;
		has = 0;
	}
	Range(int a, int b) {
		l = a, r = b;
		f = r + 1, c = 0;
		low = su = 0;
		has = 0;
	}
	Range(int a, int b, int v) {
		l = a, r = b;
		f = l, c = v;
		low = su = v;
		has = 1;
	}
} qq;

Range operator + (const Range &a, const Range &b) {
	Range ret;
	ret.l = a.l;
	ret.r = b.r;
	ret.f = a.has ? a.f : b.f;
	ret.c = b.has ? b.c : a.c;
	LL mid = LL(b.f - b.l) * a.c;
	ret.low = min(a.low, a.su + mid + min(b.low, 0ll));
	ret.su = a.su + mid + b.su;
	ret.has = a.has | b.has;
	return ret;
}

struct Node {
	int l, r;
	Range v;
} t[N * 50];

int rt = 0, tcnt = 0;

int newNode(int l, int r) {
	t[++tcnt].v = Range(l, r);
	t[tcnt].l = t[tcnt].r = 0;
	return tcnt;
}


void upd(int &x, int l, int r, int p, int v) {
	if (!x) x = newNode(l, r);
	//cerr << x << " " << l << " " << r << " " << p << " " << v << endl;
	if (l < r) {
		int mid = (l + r) >> 1;
		if (p <= mid) upd(t[x].l, l, mid, p, v);
		else 		  upd(t[x].r, mid + 1, r, p, v);
		t[x].v = (t[x].l ? t[t[x].l].v : Range(l, mid)) + (t[x].r ? t[t[x].r].v : Range(mid + 1, r));
	}
	else {
		t[x].v = Range(p, p, v);
	}
}

void clr(int &x, int l, int r, int p) {
	if (!x) x = newNode(l, r);
	if (l < r) {
		int mid = (l + r) >> 1;
		if (p <= mid) clr(t[x].l, l, mid, p);
		else 		  clr(t[x].r, mid + 1, r, p);
		t[x].v = (t[x].l ? t[t[x].l].v : Range(l, mid)) + (t[x].r ? t[t[x].r].v : Range(mid + 1, r));
	}
	else {
		t[x].v = Range(p, p);
	}
}

bool ok;
double ans;
int RR;
void solve(int x, int l, int r) {
	if (ok) return;
//	cerr << "solve " << x<< " " << l << " " << r << " " << qq.su << " " << qq.c << " " <<t[x].v.f << endl;
	if (!t[x].v.has) {
		LL su = qq.su, vv = qq.c, tt = r - l + 1;
		if (su + vv * tt <= 0) {
			ok = 1;
			ans = l + double(su) / -vv;
		}
		else qq = qq + Range(l, r);
		return;
	}
	LL ins = qq.c * LL(min(r + 1, t[x].v.f) - l);
	if (qq.su + ins + min(t[x].v.low, 0ll) > 0) {
		qq = qq + t[x].v;
		return;
	}
//	cerr << "ins " << ins << endl;
	if (qq.su + ins <= 0) {
		ok = 1;
//		cerr << qq.su << " " << qq.c << endl;
		ans = l + double(qq.su) / -qq.c;
		return;
	}
	if (t[x].v.f > r) return;
	if (l == r) {
		if (qq.su + t[x].v.c <= 0) {
			ok = 1;
			ans = l + double(qq.su) / -t[x].v.c;
		}
	}
	else {
		int mid = (l + r) >> 1;
		solve(t[x].l, l, mid);
		if (ok) return;
		solve(t[x].r, mid + 1, r);
	}
	//assert ok
}

void qry(int x, int l, int r, int ql, int qr) {
	if (ok) return;
	if (!x || (l == ql && r == qr)) {
		solve(x, ql, qr);
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid) qry(t[x].l, l, mid, ql, min(mid, qr));
	if (qr >  mid) qry(t[x].r, mid + 1, r, max(mid + 1, ql), qr);
}


int Q;

const double eps = 1e-7;

int main() {
	cin >> Q;
	while (Q--) {
		int op, t, s, l, r, v;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &t, &s);
			upd(rt, 0, L, t, s);
		}
		else if (op == 2) {
			scanf("%d", &t);
			clr(rt, 0, L, t);
		}
		else {
			scanf("%d%d%d", &l, &r, &v);
			if (v == 0) {
				printf("%d\n", l);
				continue;
			}
			qq = v;
			ok = 0;
			RR = r;
			qry(rt, 0, L, l, r - 1);
			if (ok && ans + eps >= l && ans - eps <= r) printf("%.6lf\n", ans);
			else puts("-1");
		}
	}
	return 0;
}


