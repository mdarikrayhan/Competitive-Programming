// LUOGU_RID: 160006021
#include <bits/stdc++.h>
#define _for(i, a, b) for (int i = a; i <= b; ++i)
#define for_(i, a, b) for (int i = a; i >= b; --i)
#define far(i, vec) for (auto i : vec)
#define bdmd int mid = (l + r) >> 1
typedef long double ldb;
typedef long long ll;
typedef double db;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ll> pll;
namespace IO {
	int rnt () {
		int x = 0, w = 1; char c = getchar ();
		while (!isdigit (c)) { if (c == '-') w = -1; c = getchar (); }
		while (isdigit (c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar ();
		return x * w;
	}
}
const int N = 2e4 + 10;
const int inf = 1 << 30;
namespace GRAPH {
	const int V = N << 1;
	class Edge {
	public:
		int v, r, w;
		Edge () = default;
		Edge (int _v, int _w, int _r) : v(_v), w(_w), r(_r) {}
	};
	class Graph {
	public:
		int n;
	private:
		std::vector <Edge> tu[V];
	public:
		void AddEdge (int u, int v, int w) {
			// printf ("%d %d %d\n", u, v, w);
			int p1 = tu[u].size (), p2 = tu[v].size ();
			tu[u].emplace_back (v, w, p2);
			tu[v].emplace_back (u, 0, p1);
			return;
		}
	private:
		int dep[V], cur[V];
	private:
		bool DinicBFS (int S, int T) {
			memset (dep, 0, sizeof (dep));
			std::queue <int> q;
			q.push (S), dep[S] = 1, cur[S] = 0;
			while (!q.empty ()) {
				int u = q.front (); q.pop ();
				far (p, tu[u]) {
					if (!p.w || dep[p.v]) continue;
					dep[p.v] = dep[u] + 1, cur[p.v] = 0;
					if (p.v == T) return true;
					q.push (p.v);
				}
			}
			return false;
		}
		int DinicDFS (int u, int T, int flow) {
			if (u == T || flow <= 0) return flow;
			int sum = 0;
			int sz = tu[u].size () - 1;
			for (int& i = cur[u]; i <= sz; ++i) {
				Edge& p = tu[u][i];
				if (!p.w || dep[p.v] != dep[u] + 1) continue;
				int k = DinicDFS (p.v, T, std::min (flow, p.w));
				if (k <= 0) dep[p.v] = 0;
				p.w -= k, tu[p.v][p.r].w += k;
				sum += k, flow -= k;
				if (flow <= 0) break;
			}
			return sum;
		}
	public:
		int Dinic (int S, int T) {
			int maxflow = 0;
			while (DinicBFS (S, T))
				maxflow += DinicDFS (S, T, inf);
			return maxflow;
		}
	};
}
namespace SOLVE {
	using namespace IO;
	int n, m, tot, ans;
	int u[N], v[N], c[N], d[N];
	std::vector <pii> tu[N];
	int fa[N][2]; bool vis[N];
	std::multiset <int> cnt[N];
	GRAPH::Graph G;
	void Tag (int u, int R) {
		if (u == R) return;
		d[fa[u][1]] = tot;
		Tag (fa[u][0], R);
		return;
	}
	void DFS (int u) {
		vis[u] = true;
		far (p, tu[u]) {
			int v = p.first, i = p.second;
			if (v == fa[u][0]) continue;
			if (vis[v]) {
				if (d[i] != -1) continue;
				d[i] = ++tot;
				// printf ("%d %d %d\n", u, v, tot);
				Tag (u, v);
			}
			else {
				fa[v][0] = u;
				fa[v][1] = i;
				DFS (v);
			}
		}
		return;
	}
	void In () {
		n = rnt (), m = rnt ();
		_for (i, 1, m) {
			u[i] = rnt (), v[i] = rnt (), c[i] = rnt (), d[i] = -1;
			tu[u[i]].emplace_back (v[i], i);
			tu[v[i]].emplace_back (u[i], i);
		}
		return;
	}
	void Solve () {
		DFS (1);
		// _for (i, 1, m)
		// 	printf ("%d %d %d %d\n", u[i], v[i], c[i], d[i]);
		int S = tot + m + 1, T = tot + m + 2;
		_for (i, 1, m) cnt[c[i]].insert (d[i]);
		_for (i, 1, tot)
			G.AddEdge (S, i, 1);
		_for (i, 1, m) {
			if (cnt[i].empty ())
				continue;
			++ans;
			if (cnt[i].find (-1) != cnt[i].end ()) {
				cnt[i].erase (-1);
				G.AddEdge (i + tot, T, inf);
			}
			else
				G.AddEdge (i + tot, T, cnt[i].size () - 1);
			far (j, cnt[i])
				G.AddEdge (j, i + tot, 1);
		}
		ans -= tot - G.Dinic (S, T);
		return;
	}
	void Out () {
		printf ("%d\n", ans);
		return;
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("data.in", "r", stdin);
	// freopen ("data.out", "w", stdout);
#endif
	SOLVE::In ();
	SOLVE::Solve ();
	SOLVE::Out ();
	return 0;
} /*

*/