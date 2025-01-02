// LUOGU_RID: 159816319
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
const int N = 60;
const ll inf = 1ll << 60;
namespace GRAPH {
	const int V = N << 1;
	class Edge {
	public:
		int v, r; ll w, c;
		Edge () = default;
		Edge (int v, ll w, ll c, int r) : v (v), r (r), w (w), c (c) {}
	};
	class Graph {
	private:
		std::vector <Edge> tu[V];
	public:
		void AddEdge (int u, int v, ll w, ll c) {
			// printf ("%d %d %lld,%lld\n", u, v, w, c);
			int p1 = tu[u].size (), p2 = tu[v].size ();
			tu[u].emplace_back (v, w, c, p2);
			tu[v].emplace_back (u, 0, -c, p1);
			return;
		}
	private:
		ll dis[V]; bool vis[V];
		bool DinicBFS (int S, int T) {
			memset (vis, 0, sizeof (vis));
			memset (dis, 0x3f, sizeof (dis));
			std::queue <int> q;
			q.push (S), dis[S] = 0, vis[S] = true;
			while (!q.empty ()) {
				ll u = q.front (); q.pop ();
				far (p, tu[u]) {
					if (!p.w || dis[u] + p.c >= dis[p.v]) continue;
					dis[p.v] = dis[u] + p.c;
					if (!vis[p.v]) q.push (p.v), vis[p.v] = 1;
				}
				vis[u] = false;
			}
			return dis[T] < inf;
		}
		ll DinicDFS (int u, int T, ll flow) {
			if (u == T || flow <= 0) return flow;
			ll sum = 0; vis[u] = true;
			far (&p, tu[u]) {
				if (!p.w || dis[p.v] != dis[u] + p.c || vis[p.v]) continue;
				ll k = DinicDFS (p.v, T, std::min (flow, p.w));
				sum += k, flow -= k;
				p.w -= k, tu[p.v][p.r].w += k;
				if (flow <= 0) break;
			}
			return sum;
		}
	public:
		pll Dinic (int S, int T) {
			ll maxflow = 0, mincost = 0;
			while (DinicBFS (S, T)) {
				ll f = DinicDFS (S, T, inf);
				maxflow += f, mincost += f * dis[T];
			}
			return pll (maxflow, mincost);
		}
	};
}
namespace SOLVE {
	using namespace IO;
	int n, q, rg[N][2], ans;
	GRAPH::Graph G;
	void In () {
		n = rnt (), q = rnt ();
		_for (i, 1, n) rg[i][0] = 1, rg[i][1] = n;
		_for (i, 1, q) {
			int op = rnt (), l = rnt (), r = rnt (), v = rnt ();
			_for (j, l, r) {
				if (op == 1) rg[j][0] = std::max (rg[j][0], v);
				else rg[j][1] = std::min (rg[j][1], v);
			}
		}
		return;
	}
	void Solve () {
		_for (i, 1, n) {
			if (rg[i][0] > rg[i][1]) {
				ans = -1;
				return;
			}
		}
		int S = n * 2 + 1, T = n * 2 + 2;
		_for (i, 1, n) {
			G.AddEdge (S, i, 1, 0);
			_for (j, 1, n)
				G.AddEdge (i + n, T, 1, j * 2 - 1);
			_for (j, rg[i][0], rg[i][1])
				G.AddEdge (i, j + n, 1, 0);
		}
		ans = G.Dinic (S, T).second;
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