// LUOGU_RID: 160422599
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
typedef long long LL; typedef pair <LL, int> PLI;
const int N = 1e5 + 10;
struct Line {LL k, b;} l[N];
LL Calc(int id, int x) {return l[id].k * x + l[id].b;}

struct Node {int id, ls, rs;} t[N << 7]; int tot;
struct LCSeg {
#define mid (l + r >> 1)
#define lrt (t[rt].ls)
#define rrt (t[rt].rs)
#define MAXN 1'000'000
	int Rt;
	void down(int u, int l, int r, int &rt) {
		if (!rt) rt = ++tot;
		int &v = t[rt].id; LL bmid = Calc(u, mid) - Calc(v, mid);
		if (bmid > 0) swap(u, v);
		LL bl = Calc(u, l) - Calc(v, l), br = Calc(u, r) - Calc(v, r);
		if (bl > 0) down(u, l, mid, lrt);
		if (br > 0) down(u, mid + 1, r, rrt);
	}
	void upd(int id) {down(id, 0, MAXN, Rt);}

	PLI qry(LL p, int l, int r, int rt) {
		if (!rt) return {0, 0};
		if (l == r) return {Calc(t[rt].id, p), t[rt].id};
		PLI res = {Calc(t[rt].id, p), t[rt].id};
		if (p <= mid) res = max(res, qry(p, l, mid, lrt));
		else res = max(res, qry(p, mid + 1, r, rrt));
		return res;
	}
	PLI qry(LL p) {return qry(p, 0, MAXN, Rt);}
#undef lrt
#undef rrt
#undef MAXN
} seg[N << 2];

#define lrt (rt << 1)
#define rrt (rt << 1 | 1)
void Upd(int p, int l, int r, int rt) {
	seg[rt].upd(p);
	if (l == r) return ;
	if (p <= mid) Upd(p, l, mid, lrt);
	else Upd(p, mid + 1, r, rrt);
}
PLI Qry(LL p, int ll, int rr, int l, int r, int rt) {
	if (ll <= l && r <= rr) {return seg[rt].qry(p);}
	if (rr <= mid) return Qry(p, ll, rr, l, mid, lrt);
	if (mid < ll) return Qry(p, ll, rr, mid + 1, r, rrt);
	return max(Qry(p, ll, rr, l, mid, lrt), Qry(p, ll, rr, mid + 1, r, rrt));
}
#undef mid
#undef lrt
#undef rrt

int n, q;

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> l[i].b >> l[i].k, Upd(i, 1, n, 1);
	for (int i = 1, l, r, t; i <= q; ++i) {
		cin >> l >> r >> t;
		cout << Qry(t, l, r, 1, n, 1).second << endl;
	}
	return 0;
}