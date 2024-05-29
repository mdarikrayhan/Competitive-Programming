// LUOGU_RID: 160624259
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef unsigned long long ll;

int read() {
	int res = 0, flag = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') flag = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { res = res*10 + c-'0'; c = getchar(); }
	return res * flag;
}

const int maxn = 2e5 + 5;
const int maxm = 3e5 + 5;
const ll inf = 1e18;

struct node { int l, x; ll w;  bool operator < (const node& p) const { return l < p.l; } } ;
struct pnode { int u; ll w; bool operator < (const pnode& p) const { return w > p.w; } } b[maxn];
vector<int> vc[maxn];
set<node> z1, z2;

int n, m, t;
int al[maxn], ps[maxn], d[maxn], ord[maxn], id[maxn], s[maxn], R[maxn];
ll ans;
ll a[maxn], dis[maxn], ans1[maxn];
bool vis[maxn];

//G
struct edge { int to, w, nxt; } e[maxm<<1];
int tot = 1, head[maxn];
inline void add(int u, int v, int w) {
	e[++tot].to = v;
	e[tot].w = w;
	e[tot].nxt = head[u];
	head[u] = tot;
}

void Dijkstra(int s) {
	for(int i = 1; i <= n; i++) dis[i] = inf;
	priority_queue<pnode> q; q.push((pnode){ s, dis[s] = 0 });
	while(!q.empty()) {
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w)
				q.push((pnode){ v, dis[v] = dis[u]+e[i].w });
		}
	}
}

inline int query1(int l, int r, int x) {
	l = lower_bound(vc[x].begin(), vc[x].end(), l) - vc[x].begin();
	r = upper_bound(vc[x].begin(), vc[x].end(), r) - vc[x].begin();
	return r-l;
}

inline ll query(int l, int r, int x1, int x2, ll w1, ll w2) {
	return w1*(s[r] - s[l-1]) + (w2 - w1) * query1(l, r, x1);
}

void upd2(int l, int r, int x, int x1, int x2, ll w1, ll w2) {
	auto it = --z2.upper_bound((node){ l, 0, 0 }); node tmp = *it;
	if(tmp.w < a[x]) return; if(l > tmp.l) z2.insert((node){ l, tmp.x, tmp.w });
	it = z2.lower_bound((node){ r+1, 0, 0 });
	if(r+1 < it->l) tmp = *(--it), z2.insert((node){ r+1, tmp.x, tmp.w });
	while(true) {
		it = z2.lower_bound((node){ l, 0, 0 }); tmp = *it;
		if(tmp.l > r || tmp.w < a[x]) break; ++it; z2.erase(tmp);
		ans += query(tmp.l, it->l-1, x2, x, w2, a[x]) - query(tmp.l, it->l-1, x1, x, w1, tmp.w);
	}
	z2.insert((node){ l, x, a[x] });
}

void upd1(int l, int r, int x) {
	auto it = --z1.upper_bound((node){ l, 0, 0 }); node tmp = *it;
	if(tmp.w < a[x]) { upd2(l, r, x, tmp.x, tmp.x, tmp.w, tmp.w); return; }
	if(l > tmp.l) z1.insert((node){ l, tmp.x, tmp.w });
	it = z2.lower_bound((node){ r+1, 0, 0 });
	if(r+1 < it->l) tmp = *(--it), z2.insert((node){ r+1, tmp.x, tmp.w });
	while(true) {
		it = z1.lower_bound((node){ l, 0, 0 }); tmp = *it;
		if(tmp.l > r || tmp.w < a[x]) break; ++it; z1.erase(tmp);
		if(x != tmp.x) upd2(tmp.l, it->l-1, tmp.x, tmp.x, x, tmp.w, a[x]);
		else ans += (a[x] - tmp.w) * (s[it->l-1] - s[tmp.l-1] - query1(tmp.l, it->l-1, tmp.x));
	}
	z1.insert((node){ l, x, a[x] }); if(tmp.l <= r) upd2(tmp.l, r, x, tmp.x, tmp.x, tmp.w, tmp.w);
}

int main() {
	n = read(), m = read(), t = read();
	for(int i = 1; i <= n; i++) al[i] = read(), ord[i] = i;
	for(int i = 1, u, v, w; i <= m; i++) u = read(), v = read(), w = read(), add(u, v, w), add(v, u, w);
	Dijkstra(1); sort(ord+1, ord+1+n, [](int x, int y) { return dis[x] < dis[y]; });
	d[1] = 2, a[0] = inf;
	for(int u = 1; u <= n; u++) for(int i = head[u]; i; i = e[i].nxt)
		if(dis[u] + e[i].w == dis[e[i].to]) { d[e[i].to]++; if(u > 1) ps[e[i].to] = u; }
	for(int i = 1; i <= n; i++) id[ord[i]] = i, a[i] = al[ord[i]];
	for(int i = 1; i <= t; i++) b[i].u = id[read()], b[i].w = read(), a[b[i].u] += b[i].w;
	for(int i = 1; i <= n; i++) { s[i] = s[i-1]; if(d[ord[i]] < 2) vc[id[ps[ord[i]]]].push_back(i), ++s[i]; }
	for(int i = n, x = n; i; i--) { if(dis[ord[i]] < dis[ord[i+1]]) x = i; R[i] = x+1; }
	for(int i = 1, x = 1, x1 = 0, x2 = 0; i <= n; i++) {
		while(R[x] <= i) { if(a[x] < a[x1]) x2 = x1, x1 = x; else if(a[x] < a[x2]) x2 = x; ++x; }
		if(d[ord[i]] < 2) ans += a[x1 == id[ps[ord[i]]] ? x2 : x1];
		z1.insert((node){ i, x1, a[x1] }); z2.insert((node){ i, x2, a[x2] });
	}
	z1.insert((node){n+1, 0, 0}), z2.insert((node){n+1, 0, 0});
	for(int i = t; i; i--) ans1[i] = ans, a[b[i].u] -= b[i].w, upd1(R[b[i].u], n, b[i].u);
	ans1[0] = ans;
	for(int i = 0; i <= t; i++) printf("%llu\n", ans1[i]);
	return 0;
}
