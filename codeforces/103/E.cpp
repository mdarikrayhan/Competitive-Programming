#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define int ll
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

template <typename T = int>
struct Dinic {
	static constexpr int INF = 1e9; // change if 'long long' capacities

	struct Edge {
		int to;
		T cap, flow;
		Edge(int _to, T _cap) :
			to(_to), cap(_cap), flow(0) {}
	};

	int src,snk;
	vector<int> nxt, ptr, frst, dist, q;
	vector<Edge> edges;

	Dinic(int n) : 
		dist(n), frst(n,-1), q(n) {}

	void add(int u, int v, T cap = 1){
		edges.emplace_back(v,cap);
		nxt.push_back(frst[u]);
		frst[u] = edges.size()-1;

		edges.emplace_back(u,0);
		nxt.push_back(frst[v]);
		frst[v] = edges.size()-1;
	}

	bool bfs() {
		fill(dist.begin(), dist.end(), -1);
		int st=0,ed=0;
		q[ed++] = src;
		dist[src] = 0;
		while (st < ed) {
			int u = q[st++];
			for (int e = frst[u]; e != -1; e = nxt[e]) {
				int v = edges[e].to;
				if (dist[v] == -1 and edges[e].cap > edges[e].flow) {
					dist[v] = dist[u]+1;
					q[ed++] = v;
				}
			}
		}
		return dist[snk] != -1;
	}

	T dfs(int u, T f=INF) {
		if (u == snk or f == 0) return f;
		for (int &e = ptr[u]; e != -1; e = nxt[e]) {
			int v = edges[e].to;
			if (dist[u]+1 == dist[v] and edges[e].cap > edges[e].flow) {
				int df = dfs(v, min(f,edges[e].cap-edges[e].flow));
				if (df > 0) {
					edges[e].flow += df;
					edges[e^1].flow -= df;
					return df;
				}
			}
		}
		return 0;
	}

	T flow(int _src, int _snk) {
		src=_src, snk=_snk;
		T flow=0;
		while (bfs()) {
			ptr=frst;
			while (T add_flow=dfs(src)) flow += add_flow;
		}
		return flow;
	}
};

vector<int> get_matching(vector<vector<int>> &adj) {
	int n = adj.size(), src = 2*n, snk = 2*n+1;
	Dinic<int> dinic(snk+1);
	for (int i = 0; i < n; i++) {
		dinic.add(src, i, 1);
		dinic.add(i+n, snk, 1);
		for (int j: adj[i]) dinic.add(i, j, 1);
	}
	dinic.flow(src, snk);

	vector<int> M(n);
	for (int i = 0; i < n; i++) {
		for (int e = dinic.frst[i]; e != -1; e = dinic.nxt[e]) {
			if (dinic.edges[e].flow == 1) M[i] = dinic.edges[e].to;
		}
	}
	return M;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);

	int n; cin>>n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		int m; cin>>m;
		for (int j = 0; j < m; j++) {
			int u; cin>>u; adj[i].push_back(n+u-1);
		}
	}

	vector<int> w(n);
	for (int i = 0; i < n; i++) cin>>w[i];

	vector<int> M = get_matching(adj);

	vector<int> inv(2*n);
	for (int i = 0; i < n; i++) inv[M[i]] = i;

	int res = 0, src = 2*n, snk = 2*n+1;
	Dinic dinic(snk+1);
	for (int i = 0; i < n; i++) {
		if (w[i] > 0) dinic.add(i, snk, w[i]);
		else dinic.add(src, i, -w[i]), res += w[i];

		for (int j: adj[i]) if (j != M[i]) {
			dinic.add(i, inv[j], dinic.INF);
		}
	}
	cout<<(res+dinic.flow(src, snk))<<'\n';

	return 0;
}
