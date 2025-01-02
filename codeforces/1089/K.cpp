// LUOGU_RID: 157423411
// Problem: K. King Kog's Reception
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1089/K
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 1000100;
const int N = 1000010;

int q;
pii a[maxn];

namespace SGT {
	pii a[maxn << 2];
	ll tag[maxn << 2];
	
	inline void pushup(int x) {
		a[x] = max(a[x << 1], a[x << 1 | 1]);
	}
	
	inline void pushdown(int x) {
		if (!tag[x]) {
			return;
		}
		a[x << 1].fst += tag[x];
		a[x << 1 | 1].fst += tag[x];
		tag[x << 1] += tag[x];
		tag[x << 1 | 1] += tag[x];
		tag[x] = 0;
	}
	
	void build(int rt, int l, int r) {
		if (l == r) {
			a[rt] = mkp(l, l);
			return;
		}
		int mid = (l + r) >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		pushup(rt);
	}
	
	void update(int rt, int l, int r, int ql, int qr, int x) {
		if (ql <= l && r <= qr) {
			a[rt].fst += x;
			tag[rt] += x;
			return;
		}
		pushdown(rt);
		int mid = (l + r) >> 1;
		if (ql <= mid) {
			update(rt << 1, l, mid, ql, qr, x);
		}
		if (qr > mid) {
			update(rt << 1 | 1, mid + 1, r, ql, qr, x);
		}
		pushup(rt);
	}
	
	pii query(int rt, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			return a[rt];
		}
		pushdown(rt);
		int mid = (l + r) >> 1;
		pii res(-1e18, 0);
		if (ql <= mid) {
			res = max(res, query(rt << 1, l, mid, ql, qr));
		}
		if (qr > mid) {
			res = max(res, query(rt << 1 | 1, mid + 1, r, ql, qr));
		}
		return res;
	}
}

namespace BIT {
	ll c[maxn];
	
	inline void update(ll x, ll d) {
		for (int i = x; i < maxn; i += (i & (-i))) {
			c[i] += d;
		}
	}
	
	inline ll query(ll x) {
		ll res = 0;
		for (int i = x; i; i -= (i & (-i))) {
			res += c[i];
		}
		return res;
	}
	
	inline ll query(ll l, ll r) {
		return query(r) - query(l - 1);
	}
}

void solve() {
	scanf("%d", &q);
	SGT::build(1, 1, N);
	for (int i = 1; i <= q; ++i) {
		char op[9];
		int x, y;
		scanf("%s%d", op, &x);
		if (op[0] == '+') {
			scanf("%d", &y);
			a[i] = mkp(x, y);
			SGT::update(1, 1, N, 1, x, y);
			BIT::update(x, y);
		} else if (op[0] == '-') {
			BIT::update(a[x].fst, -a[x].scd);
			SGT::update(1, 1, N, 1, a[x].fst, -a[x].scd);
		} else {
			int t = SGT::query(1, 1, N, 1, x).scd;
			printf("%lld\n", BIT::query(t, x) - (x - t));
		}
	}
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
