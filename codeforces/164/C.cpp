// LUOGU_RID: 159814569
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
const int N = 1010;
const int inf = 1ll << 30;
namespace GRAPH {
	const int V = N << 1;
	class Edge {
	public:
		int v, r, w, c;
		Edge () = default;
		Edge (int v, int w, int c, int r) : v (v), r (r), w (w), c (c) {}
	};
	class Graph {
	private:
		std::vector <Edge> tu[V];
	public:
		void AddEdge (int u, int v, ll w, ll c) {
			int p1 = tu[u].size (), p2 = tu[v].size ();
			tu[u].emplace_back (v, w, c, p2);
			tu[v].emplace_back (u, 0, -c, p1);
			return;
		}
	private:
		int dis[V]; bool vis[V];
		bool DinicBFS (int S, int T) {
			memset (vis, 0, sizeof (vis));
			memset (dis, 0x80, sizeof (dis));
			std::queue <int> q;
			q.push (S), dis[S] = 0, vis[S] = true;
			while (!q.empty ()) {
				int u = q.front (); q.pop ();
				far (p, tu[u]) {
					if (!p.w || dis[u] + p.c <= dis[p.v]) continue;
					dis[p.v] = dis[u] + p.c;
					if (!vis[p.v]) q.push (p.v), vis[p.v] = 1;
				}
				vis[u] = false;
			}
			return dis[T] > -inf;
		}
		int DinicDFS (int u, int T, int flow) {
			if (u == T || flow <= 0) return flow;
			int sum = 0; vis[u] = true;
			far (&p, tu[u]) {
				if (!p.w || dis[p.v] != dis[u] + p.c || vis[p.v]) continue;
				int k = DinicDFS (p.v, T, std::min (flow, p.w));
				sum += k, flow -= k;
				p.w -= k, tu[p.v][p.r].w += k;
				if (flow <= 0) break;
			}
			return sum;
		}
	public:
		void Dinic (int S, int T) {
			while (DinicBFS (S, T))
				DinicDFS (S, T, inf);
			return;
		}
		std::bitset <N> State (int n) {
			std::bitset <N> ans (0);
			_for (i, 1, n) ans.set (i, !tu[i][0].w);
			return ans;
		}
	};
}
namespace SOLVE {
	using namespace IO;
	int n, K, rg[N][2], c[N];
	std::bitset <N> ans;
	GRAPH::Graph G;
	void In () {
		n = rnt (), K = rnt ();
		_for (i, 1, n) {
			rg[i][0] = rnt ();
			rg[i][1] = rg[i][0] + rnt () - 1;
			c[i] = rnt ();
		}
		return;
	}
	void Solve () {
		int _S = n * 2 + 1, S = n * 2 + 2, T = n * 2 + 3;
		G.AddEdge (_S, S, K, 0);
		_for (i, 1, n) {
			G.AddEdge (i, i + n, 1, c[i]);
			G.AddEdge (S, i, 1, 0);
			G.AddEdge (i + n, T, 1, 0);
		}
		_for (i, 1, n) _for (j, 1, n)
			if (rg[j][1] < rg[i][0])
				G.AddEdge (j + n, i, 1, 0);
		G.Dinic (_S, T);
		ans = G.State (n);
		return;
	}
	void Out () {
		_for (i, 1, n) printf ("%d ", ans.test (i));
		puts ("");
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