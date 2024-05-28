// LUOGU_RID: 158673675
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct E {
	int v, l, r;
}p[500005];
struct N {
	int v, id;
	bool operator < (const N& x) const {return x.v < v;}
};
priority_queue<N> q;
bool vis[500005];
int a[500005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k, ans = 0;
	cin >> k >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		p[i].v = a[i] - a[i - 1];
		p[i].l = i - 1;
		p[i].r = i + 1;
		q.push({p[i].v, i});
	}
	p[0].v = p[n].v = INT_MAX;
	for (int i = 1; i <= k; i++) {
		while (vis[q.top().id]) q.pop();
		N u = q.top();
		q.pop();
		ans += u.v;
		vis[p[u.id].l] = vis[p[u.id].r] = 1;
		p[u.id].v = p[p[u.id].l].v + p[p[u.id].r].v - p[u.id].v;
		q.push({p[u.id].v, u.id});
		p[u.id].l = p[p[u.id].l].l;
		p[u.id].r = p[p[u.id].r].r;
		p[p[u.id].l].r = u.id;
		p[p[u.id].r].l = u.id;
	}
	cout << ans << '\n';
	return 0;
}