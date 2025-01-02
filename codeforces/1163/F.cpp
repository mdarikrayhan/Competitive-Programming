// LUOGU_RID: 158653398
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define pir pair <ll, ll>
#define mkp make_pair
#define pb push_back
using namespace std;
const ll maxn = 2e5 + 10, inf = 1e17;
ll n, m, q, x[maxn], y[maxn], z[maxn];
struct edge {ll v, w, id, nxt;} e[maxn << 1];
ll head[maxn], tot = 1, dis1[maxn], dis2[maxn], pre1[maxn], pre2[maxn];
void insert(ll u, ll v, ll w, ll id) {
	e[++tot] = (edge) {v, w, id, head[u]};
	head[u] = tot;
}
ll vis[maxn];
priority_queue <pir> Q; 
void dij(ll s, ll *dis, ll *pre) {
	for(ll i = 1; i <= n; i++) dis[i] = inf, vis[i] = 0;
	Q.push(mkp(0, s)), dis[s] = 0;
	while(!Q.empty()) {
		ll u = Q.top().se; Q.pop();
		if(vis[u]) continue; vis[u] = 1;
		for(ll i = head[u]; i; i = e[i].nxt) {
			ll v = e[i].v, w = e[i].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pre[v] = i;
				Q.push(mkp(-dis[v], v));
			}
		}
	}
}
vector <ll> edg, ver;
ll vid[maxn], ve[maxn], ans[maxn][20], res[maxn];
struct Tree {
	ll rt, d[maxn][20], dep[maxn];
	vector <ll> to[maxn];
	void dfs(ll u, ll fa) {
		d[u][0] = fa, dep[u] = dep[fa] + 1;
		for(ll i = 1; i < 20; i++)
			d[u][i] = d[d[u][i - 1]][i - 1];
		for(ll v: to[u]) {
			if(v == fa) continue;
			dfs(v, u);
		}
	}
	void build(ll *dis, ll *pre) {
		for(ll i = 1; i <= n; i++)
			if(dis[i] == 0) rt = i;
			else to[e[pre[i] ^ 1].v].pb(i); 
		dfs(rt, 0);
	}
	ll lca(ll u, ll v) {
		if(dep[u] < dep[v]) swap(u, v);
		ll tmp = dep[u] - dep[v];
		for(ll i = 19; ~i; i--)
			if(tmp & (1 << i)) u = d[u][i];
		if(u == v) return u;
		for(ll i = 19; ~i; i--)
			if(d[u][i] != d[v][i]) {
				u = d[u][i];
				v = d[v][i];
			}
		return d[u][0];
	}
} T1, T2;
int main() {
	scanf("%lld%lld%lld", &n, &m, &q);
	for(ll i = 1; i <= m; i++) {
		ll u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
		insert(u, v, w, i), insert(v, u, w, i);
		x[i] = u, y[i] = v, z[i] = w;
	}
	dij(1, dis1, pre1), dij(n, dis2, pre2);
	T1.build(dis1, pre1), T2.build(dis2, pre2);
	ll u = n;
	while(u > 1) {
		ver.pb(u), ve[e[pre1[u]].id] = 1;
		edg.pb(e[pre1[u]].id);
		u = e[pre1[u] ^ 1].v;
	} ver.pb(1);
	reverse(edg.begin(), edg.end());
	reverse(ver.begin(), ver.end());
	for(ll i = 0; i < ver.size(); i++)
		vid[ver[i]] = i + 1;
	memset(ans, 0x3f, sizeof ans);
	for(ll i = 1; i <= m; i++) {
		if(ve[i]) continue;
		ll l = vid[T1.lca(n, x[i])], r = vid[T2.lca(1, y[i])];
		if(l < r) {
			for(ll j = 19; ~j; j--) {
				if((1 << j) <= r - l) {
					ans[r][j] = min(ans[r][j], dis1[x[i]] + dis2[y[i]] + z[i]);
					r -= (1 << j);
				}
			}
		}
		l = vid[T1.lca(n, y[i])], r = vid[T2.lca(1, x[i])];
		if(l < r) {
			for(ll j = 19; ~j; j--) {
				if((1 << j) <= r - l) {
					ans[r][j] = min(ans[r][j], dis1[y[i]] + dis2[x[i]] + z[i]);
					r -= (1 << j);
				}
			}
		}
	}
	for(ll i = ver.size(); i; i--) {
		for(ll j = 19; j; j--) {
			if(ans[i][j] >= inf) continue;
			ans[i][j - 1] = min(ans[i][j - 1], ans[i][j]);
			ans[i - (1 << j - 1)][j - 1] = min(ans[i - (1 << j - 1)][j - 1], ans[i][j]); 
		}
	}
	for(ll i = 0; i < edg.size(); i++)
		res[edg[i]] = ans[i + 2][0];
	while(q--) {
		ll t, w; scanf("%lld%lld", &t, &w);
		ll ret = inf;
		if(!ve[t]) {
			ret = dis1[n];
			ret = min(ret, dis1[x[t]] + dis2[y[t]] + w);
			ret = min(ret, dis1[y[t]] + dis2[x[t]] + w);
		} else {
			ret = dis1[n] - z[t] + w;
			ret = min(ret, res[t]);
		}
		printf("%lld\n", ret);
	}
	return 0;
}