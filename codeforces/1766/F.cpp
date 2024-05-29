#include <bits/stdc++.h>
using namespace std;
const int N = 2333;
int n, m, u, v, f, w, p[N], d[N], s, t, D, edgenum = 1, Head[N], cur[N], Next[N], vet[N], flow[N], val[N], dis[N], inq[N], vis[N]; queue <int> q;
void add(int u, int v, int f, int w, bool r = 0) {
	Next[++edgenum] = Head[u];
	Head[u] = edgenum;
	vet[edgenum] = v;
	flow[edgenum] = f;
	val[edgenum] = w;
	if (! r) add(v, u, 0, - w, 1);
}
int bfs() {
	for (int i=0; i<=n+1; i++)
		dis[i] = 1e9, cur[i] = Head[i];
	dis[s] = 0, q. push(s), inq[s] = 1;
	while (! q. empty()) {
		int u = q. front(); q. pop(), inq[u] = 0;
		for (int e=Head[u]; e; e=Next[e]) if (flow[e]) {
			int v=vet[e], w=val[e];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (! inq[v]) q. push(v), inq[v] = 1;
			}
		}
	} return dis[t];
}
int dfs(int u, int f) {
	if (u == t) return f;
	int res = 0; vis[u] = 1;
	for (int &e=cur[u]; e; e=Next[e]) {
		int v=vet[e];
		if (! flow[e] || dis[v] != dis[u] + val[e] || vis[v]) continue;
		int d = dfs(v, min(f, flow[e]));
		if (d) {
			flow[e] -= d, flow[e^1] += d, f -= d, res += d;
			if (! f) break;
		}
	} vis[u] = 0; return res;
}
int Dinic(bool t) {
	int res = 0;
	while (bfs() < (t ? 0 : 1e9))
		res += dfs(s, 1e9);
	return res;
}
int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		scanf ("%d%d%d%d", &u, &v, &f, &w);
		add(u, v, f >> 1, w << 1);
		if (p[i] = f & 1) d[u] ++, d[v] --;
	} t = n + 1;
	if (d[1] & d[n] & 1) d[1] ++, d[n] --;
	for (int i=1; i<=n; i++) {
		if (d[i] & 1) return puts ("Impossible"), 0;
		d[i] >>= 1;
		if (d[i] > 0) add(i, t, d[i], 0), D += d[i];
		else if (d[i] < 0) add(s, i, - d[i], 0);
	}
	add(n, 1, 1e9, 1e8);
	if (Dinic(0) ^ D) return puts ("Impossible"), 0;
	s = 1, t = n, Dinic(1), puts ("Possible");
	for (int i=1; i<=m; i++)
		printf ("%d ", flow[i<<1|1] << 1 | p[i]);
}