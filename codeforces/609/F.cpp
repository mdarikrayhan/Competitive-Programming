// LUOGU_RID: 160433220
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ansc[200005], ansv[200005];
struct st {
	int l, r, id;
	bool operator<(const st& a)const {
		return r == a.r ? l < a.l : r < a.r;
	}
}a[200005];
multiset<pair<int, int> >p;
multiset<st>s;
void calc(st v) {
	s.insert(v);
	auto x = s.lower_bound(v);
	while (x != s.begin()) {
		auto o = prev(x);
		if (o->l >= v.l && o->r <= v.r) s.erase(o);
		else break;
	}
}
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r, ansv[i] = a[i].r, a[i].r += a[i].l, a[i].id = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) calc(a[i]);
	for (int i = 1, x, v; i <= m; i++) {
		cin >> x >> v;
		auto t = s.lower_bound({ 0, x, 0 });
		if (t == s.end()) p.insert({ x,v });
		else if (t->l > x) p.insert({ x,v });
		else {
			int px = t->id, pl = t->l, pr = t->r;
			pr += v, ansc[px]++, ansv[px] += v;
			while (1) {
				auto to = p.lower_bound({ pl,0 });
				if (to == p.end()) break;
				if (to->first > pr) break;
				pr += to->second, ansc[px]++, ansv[px] += to->second;
				p.erase(to);
			}
			s.erase(t);
			calc({ pl, pr, px });
		}
	}
	for (int i = 1; i <= n; i++) cout << ansc[i] << ' ' << ansv[i] << '\n';
}